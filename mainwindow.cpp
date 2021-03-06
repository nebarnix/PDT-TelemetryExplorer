#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
   {
   ui->setupUi(this);
   SEMObj = new SEM(this);
   HIRSObj = new HIRS(this);

   QFont font("Monospace");
   font.setStyleHint(QFont::TypeWriter);
   font.setBold(true);
   ui->minorFrameBrowser->setFont(font);

   //speed increases?
   ui->minorFrameBrowser->setReadOnly(true);
   ui->minorFrameBrowser->setUndoRedoEnabled(false);
   ui->minorFrameBrowser->setContextMenuPolicy(Qt::NoContextMenu);

   ui->SPIDPlot->canvas()->setStyleSheet(
            "border: 2px solid Black;"

            "background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1,"
            "stop: 0 DarkSlateGray  , stop: 1 black );"
            );

   ui->minorFrameIDPlot->canvas()->setStyleSheet(
            "border: 2px solid Black;"

            "background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1,"
            "stop: 0 DarkSlateGray  , stop: 1 black );"
            );

   connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(open()));
   connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(updateViewOnTreeClick(QTreeWidgetItem*,int)));
   ui->treeWidget->expandAll(); //Show all trees expanded at the start

   (void )new QwtPlotPanner( ui->SPIDPlot->canvas() );
   QwtPlotMagnifier *zoom_x = new QwtPlotMagnifier(  ui->SPIDPlot->canvas()  );
   QwtPlotMagnifier *zoom_y = new QwtPlotMagnifier(  ui->SPIDPlot->canvas()  );
   zoom_x->setWheelModifiers(Qt::ControlModifier);
   zoom_x->setAxisEnabled(Qt::XAxis, true);
   zoom_x->setAxisEnabled(Qt::YAxis,false);

   zoom_y->setAxisEnabled(Qt::XAxis,false);
   zoom_y->setAxisEnabled(Qt::YAxis,true);



   (void )new QwtPlotPanner( ui->minorFrameIDPlot->canvas() );
   QwtPlotMagnifier *zoom_x2 = new QwtPlotMagnifier(  ui->minorFrameIDPlot->canvas()  );
   QwtPlotMagnifier *zoom_y2 = new QwtPlotMagnifier(  ui->minorFrameIDPlot->canvas()  );
   zoom_x2->setWheelModifiers(Qt::ControlModifier);
   zoom_x2->setAxisEnabled(Qt::XAxis, true);
   zoom_x2->setAxisEnabled(Qt::YAxis,false);

   zoom_y2->setAxisEnabled(Qt::XAxis,false);
   zoom_y2->setAxisEnabled(Qt::YAxis,true);


   }

MainWindow::~MainWindow()
   {
   delete ui;
   }

void MainWindow::clearAll()
   {

   knownGoodFrameIndices.clear();

   for(int i=0; i < 5; i++)
      parityChunkList[i].clear();

   minorFramesHex.clear();
   minorFramesDec.clear();
   minorFrameTimes.clear();
   minorFrameIDList.clear();
   timeStampList.clear();
   timeStampTimeList.clear();
   numFrames = 0;
   numGoodFrames = 0;
   SFID = 0;
   ui->TimeStampTextBox->clear();
   ui->parityTextEdit->clear();
   ui->minorFrameBrowser->clear();
   ui->DCSSumTextBrowser->clear();
   ui->SPIDList->clear();
   ui->MinorFrameIDList->clear();

   ui->minorFrameIDPlot->detachItems();
   ui->SPIDPlot->detachItems();

   SEMObj->clearAll();
   HIRSObj->clearAll();
   }

void MainWindow::open()
   {

   QStringList minorFrameParts;

   QRegularExpression re("^\\d+.\\d+");
   QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                                   tr("Minor Frame Files (minorFrames*.txt)"));


   if (fileName != "")
      {
      QFile file(fileName);
      if (!file.open(QIODevice::ReadOnly))
         {
         QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
         return;
         }
      QTextStream in(&file);
      clearAll();
      while (true)
         {
         QString line = in.readLine();
         if (line.isNull())
            break;
         else if(line.contains(re)) //only look at lines that start with a decimal number
            {
            //for now, get rid of the inverted flags. Maybe we can figure this out later if there is a need
            line.replace("i","");
            line[line.indexOf(' ')] = '\t'; //Replace the first space with a tab
            minorFrameParts = line.split('\t'); //Split on said tab
            minorFramesHex.append(minorFrameParts[1]);
            minorFrameTimes.append(minorFrameParts[0].toFloat()); //Get the times and convert to float
            }
         }
      file.close();
      numFrames = minorFramesHex.length();

      displayMinorFramesHex();
      convertMinorFramesHex2Dec();
      //displayMinorFramesDec(); //no need to spit these out to the DCS box. Its not your box anyway!
      checkParity();
      displaySpaceCraftID();
      plotMinorFrameID();
      getTimeStamps();
      decomSEM();
      decomHIRS();      
      populateSummaryTable();

      //Ok, we're done, go to Summary now
      ui->stackedWidget->setCurrentIndex(1);
      }
   }

void MainWindow::getTimeStamps()
   {
   //if((bitshift(bitand(minorFrames(frame,9+1),bin2dec('111')),24) + bitshift(minorFrames(frame,10+1),16) + bitshift(minorFrames(frame,11+1),8) + minorFrames(frame,12+1)) < 86400000)
   QString windowContents;
   unsigned char byte1, byte2, byte3, byte4;
   unsigned int dayNum;
   float timeStamp;
   float hour, minute, seconds;
   for(int i=0; i < numFrames; i++)
      {
      if(minorFrameIDList[i] == 0)
         {
         byte2 = minorFramesDec[i][8];
         byte1 = minorFramesDec[i][9];
         dayNum =(byte2<<1)+((byte1|128) >> 7);

         //byte1 = minorFramesDec[i][9];
         byte2 = minorFramesDec[i][10];
         byte3 = minorFramesDec[i][11];
         byte4 = minorFramesDec[i][12];
         timeStamp = (((byte1 & 0b111) << 24) + (byte2<<16) + (byte3<<8) + byte4) / 1000.0;
         if(timeStamp < 86400) //there aren't this many seconds in a day, clearly this is an error
            {
            timeStampList.append(timeStamp);
            timeStampTimeList.append(minorFrameTimes[i]);

            windowContents.append("Frame " + QString::number(i) + "\t");
            windowContents.append("Day " + QString::number(dayNum) + "\t");
            windowContents.append(QString::number(minorFrameTimes[i],'f',2));
            windowContents.append(" Local Seconds is ");
            windowContents.append(QString::number(timeStamp,'f',2));
            windowContents.append(" Spacecraft Day Seconds");


            hour = floor(timeStamp/(60.0*60.0));
            minute = floor((timeStamp/(60.0*60.0) - hour)*60.0);
            seconds = (((timeStamp/(60.0*60.0) - hour)*60.0) - minute) *60.0;
            windowContents.append(" which is ");
            windowContents.append(QString::number(hour));
            windowContents.append(":");
            windowContents.append(QString::number(minute));
            windowContents.append(":");
            windowContents.append(QString::number(seconds,'f',2));
            //fprintf(['' num2str(hour) ':' num2str(minute) ':' num2str(seconds)]);

            windowContents.append("\tt(0) => ");

            float deltaTimeSec = timeStamp-minorFrameTimes[i];
            hour = floor((deltaTimeSec)/(60.0*60.0));
            minute = floor(((deltaTimeSec)/(60.0*60.0) - hour)*60.0);
            seconds = ((((deltaTimeSec)/(60.0*60.0) - hour)*60.0) - minute) *60.0;

            //windowContents.append(QString::number(deltaTimeSec));
            //windowContents.append("deltasec ");
            windowContents.append(QString::number(hour));
            windowContents.append(":");
            windowContents.append(QString::number(minute));
            windowContents.append(":");
            windowContents.append(QString::number(seconds,'f',2));

            /* We can do better error detection than this, like deviation from T0 maybe
                    if idx > 1 && dayMSeconds(idx) <= dayMSeconds(idx-1)
                        fprintf(' ...but this might be an error');
                    else
                        hour = floor((dayMSeconds(idx)-frameTime(frame,1)*1000)/(1000*60*60));
                        minute = floor(((dayMSeconds(idx)-frameTime(frame,1)*1000)/(1000*60*60) - hour)*60);
                        seconds = ((((dayMSeconds(idx)-frameTime(frame,1)*1000)/(1000*60*60) - hour)*60) - minute) *60;
                        fprintf(['' num2str(hour) ':' num2str(minute) ':' num2str(seconds)]);
                    end
                    fprintf('\n');*/
            windowContents.append('\n');
            }
         }

      }
   ui->TimeStampTextBox->insertPlainText(windowContents);
   }

void MainWindow::checkParity()
   {
   //parityChunkList
   //QList <uchar> pByte1,pByte2,pByte3,pByte4,pByte5; //<- why does this need to be a whole list?
   uchar  pByte1,pByte2,pByte3,pByte4,pByte5,pByte6;
   QString windowContents;
   uchar byte;
   numGoodFrames = 0;
   //Word 103
   //Bit 1: CPU B data transfer incomplete bit
   //Bit 2: CPU A data transfer incomplete bit
   //Bit 3: Even parity check in words 2 through 18
   //Bit 4: Even parity check in words 19 thru 35
   //Bit 5: Even parity check in words 36 thru 52
   //Bit 6: Even parity check in words 53 thru 69
   //Bit 7: Even parity check in words 70 thru 86
   //Bit 8: Even parity check in words 87 thru bit 7 of word 103

   //Count ones. If the number of one's is odd, modulus will be 1. Even
   //parity bit will be set to change the number of ones to be even, so the
   //parity bit should match the modulus of the one count exactly.
   //clear goodFrames parity;
   //for frame=1:size(minorFrames,1)
   for(int frame=0; frame < numFrames; frame++)
      {
      //pByte1[frame]=0;
      //pByte1.append(0);
      pByte1=0;
      //words 2 through 18
      for(int word=2; word < 19; word++)
         {
         byte = minorFramesDec[frame][word];
         for(char bit=0; bit<8; bit++)
            //parity(frame,1) = parity(frame,1)+bitand(bitshift(byte,-shift),1);
            //pByte1[frame]=pByte1[frame] + ((byte>>bit) & 0x01);
            pByte1=pByte1 + ((byte>>bit) & 0x01);
         }

      //pByte2[frame]=0;
      //pByte2.append(0);
      pByte2=0;
      //words 19 thru 35
      for(int word=19; word < 36; word++)
         {
         byte = minorFramesDec[frame][word];
         for(char bit=0; bit<8; bit++)
            //parity(frame,1) = parity(frame,1)+bitand(bitshift(byte,-shift),1);
            //pByte2[frame]=pByte2[frame] + ((byte>>bit) & 0x01);
            pByte2=pByte2 + ((byte>>bit) & 0x01);
         }

      //pByte3[frame]=0;
      //pByte3.append(0);
      pByte3=0;
      //words 36 thru 52
      for(int word=36; word < 53; word++)
         {
         byte = minorFramesDec[frame][word];
         for(char bit=0; bit<8; bit++)
            //parity(frame,1) = parity(frame,1)+bitand(bitshift(byte,-shift),1);
            //pByte3[frame]=pByte3[frame] + ((byte>>bit) & 0x01);
            pByte3=pByte3 + ((byte>>bit) & 0x01);
         }

      //pByte4[frame]=0;
      //pByte4.append(0);
      pByte4=0;
      //words 53 thru 69
      for(int word=53; word < 70; word++)
         {
         byte = minorFramesDec[frame][word];
         for(char bit=0; bit<8; bit++)
            //parity(frame,1) = parity(frame,1)+bitand(bitshift(byte,-shift),1);
            //pByte4[frame]=pByte4[frame] + ((byte>>bit) & 0x01);
            pByte4=pByte4 + ((byte>>bit) & 0x01);
         }

      //pByte5[frame]=0;
      //pByte5.append(0);
      pByte5=0;
      //words 70 thru 86
      for(int word=70; word < 87; word++)
         {
         byte = minorFramesDec[frame][word];
         for(char bit=0; bit<8; bit++)
            //parity(frame,1) = parity(frame,1)+bitand(bitshift(byte,-shift),1);
            //pByte5[frame]=pByte5[frame] + ((byte>>bit) & 0x01);
            pByte5=pByte5 + ((byte>>bit) & 0x01);
         }

      //pByte6[frame]=0;
      //pByte6.append(0);
      pByte6=0;
      //words 87 thru bit 7 of word 103
      for(int word=87; word < 103; word++)
         {
         byte = minorFramesDec[frame][word];
         for(char bit=0; bit<8; bit++)
            //parity(frame,1) = parity(frame,1)+bitand(bitshift(byte,-shift),1);
            //pByte5[frame]=pByte5[frame] + ((byte>>bit) & 0x01);
            pByte6=pByte6 + ((byte>>bit) & 0x01);
         }

      //+ 103 (thru bit 7) -- bit 7 is actually the LSB, so bit0(!)
      byte = minorFramesDec[frame][103];
      for(char bit=1; bit<8; bit++) //we're looping LSB to MSB, so our bits are actually backwards
         //parity(frame,1) = parity(frame,1)+bitand(bitshift(byte,-shift),1);
         //pByte5[frame]=pByte5[frame] + ((byte>>bit) & 0x01);
         pByte6=pByte6 + ((byte>>bit) & 0x01);

      //we are re-using the pBytes to store the good/bad critera since we don't need the previous values anymore
      //if(mod(parity(frame,1),2) == bitand(bitshift(minorFrames(frame,104),-5),1)) %check if divisible by 2 (even)

      windowContents.append("Frame ");
      windowContents.append(QString::number(frame));

      /*
      windowContents.append("\t");
      windowContents.append(QString::number(pByte1[frame]));
      windowContents.append("\t");
      windowContents.append(QString::number(pByte2[frame]));
      windowContents.append("\t");
      windowContents.append(QString::number(pByte3[frame]));
      windowContents.append("\t");
      windowContents.append(QString::number(pByte4[frame]));
      windowContents.append("\t");
      windowContents.append(QString::number(pByte5[frame]));*/

      windowContents.append("\tChunk 1-");
      //if( (pByte1[frame] % 2) == (minorFramesDec[frame][103] >> 5) & 0x01) //check if divisible by 2 (even)
      if( (pByte1 % 2) == (minorFramesDec[frame][103] >> 5) & 0x01) //check if divisible by 2 (even)
         {
         //pByte1[frame] = 0; //%words might be good or might have an even number of bit errors
         pByte1 = 0; //%words might be good or might have an even number of bit errors
         windowContents.append(" OK");
         }
      else
         {
         //pByte1[frame] = 1; //%Words contain at least one error
         pByte1 = 1; //%Words contain at least one error
         windowContents.append(" Bad");
         }

      windowContents.append("\tChunk 2-");

      //if( (pByte2[frame] % 2) == ((minorFramesDec[frame][103] >> 4) & 0x01)) //check if divisible by 2 (even)
      if( (pByte2 % 2) == ((minorFramesDec[frame][103] >> 4) & 0x01)) //check if divisible by 2 (even)
         {
         //pByte2[frame] = 0; //%words might be good or might have an even number of bit errors
         pByte2 = 0; //%words might be good or might have an even number of bit errors
         windowContents.append(" OK");
         }
      else
         {
         //pByte2[frame] = 1; //%Words contain at least one error
         pByte2 = 1; //%Words contain at least one error
         windowContents.append(" Bad");
         }

      windowContents.append("\tChunk 3-");
      //if( (pByte3[frame] % 2) == ((minorFramesDec[frame][103] >> 3)&0x01)) //check if divisible by 2 (even)
      if( (pByte3 % 2) == ((minorFramesDec[frame][103] >> 3)&0x01)) //check if divisible by 2 (even)
         {
         //pByte3[frame] = 0; //%words might be good or might have an even number of bit errors
         pByte3 = 0; //%words might be good or might have an even number of bit errors
         windowContents.append(" OK");
         }
      else
         {
         //pByte3[frame] = 1; //%Words contain at least one error
         pByte3 = 1; //%Words contain at least one error
         windowContents.append(" Bad");
         }

      windowContents.append("\tChunk 4-");
      //if( (pByte4[frame] % 2) == ((minorFramesDec[frame][103] >> 2)&0x01)) //check if divisible by 2 (even)
      if( (pByte4 % 2) == ((minorFramesDec[frame][103] >> 2)&0x01)) //check if divisible by 2 (even)
         {
         //pByte4[frame] = 0; //%words might be good or might have an even number of bit errors
         pByte4 = 0; //%words might be good or might have an even number of bit errors
         windowContents.append(" OK");
         }
      else
         {
         //pByte4[frame] = 1; //%Words contain at least one error
         pByte4 = 1; //%Words contain at least one error
         windowContents.append(" Bad");
         }

      windowContents.append("\tChunk 5-");
      //if( (pByte5[frame] % 2) == ((minorFramesDec[frame][103] >> 1)&0x01)) //check if divisible by 2 (even)
      if( (pByte5 % 2) == ((minorFramesDec[frame][103] >> 1)&0x01)) //check if divisible by 2 (even)
         {
         //pByte5[frame] = 0; //%words might be good or might have an even number of bit errors
         pByte5 = 0; //%words might be good or might have an even number of bit errors
         windowContents.append(" OK");
         }
      else
         {
         //pByte5[frame] = 1; //%Words contain at least one error
         pByte5 = 1; //%Words contain at least one error
         windowContents.append(" Bad");
         }

      windowContents.append("\tChunk 6-");
      //if( (pByte6[frame] % 2) == ((minorFramesDec[frame][103] >> 1)&0x01)) //check if divisible by 2 (even)
      if( (pByte6 % 2) == ((minorFramesDec[frame][103] >> 0)&0x01)) //check if divisible by 2 (even)
         {
         //pByte6[frame] = 0; //%words might be good or might have an even number of bit errors
         pByte6 = 0; //%words might be good or might have an even number of bit errors
         windowContents.append(" OK");
         }
      else
         {
         //pByte6[frame] = 1; //%Words contain at least one error
         pByte6 = 1; //%Words contain at least one error
         windowContents.append(" Bad");
         }

      //if ((pByte1[frame] + pByte2[frame] + pByte3[frame] + pByte4[frame] + pByte5[frame]) == 0)
      if ((pByte1 + pByte2 + pByte3 + pByte4 + pByte5 + pByte6) == 0)
         {
         numGoodFrames++;
         knownGoodFrameIndices.append(frame);
         }

      parityChunkList[0].append(pByte1);
      parityChunkList[1].append(pByte2);
      parityChunkList[2].append(pByte3);
      parityChunkList[3].append(pByte4);
      parityChunkList[4].append(pByte5);
      parityChunkList[5].append(pByte6);

      windowContents.append("\n");
      }

   windowContents.append("\n");
   windowContents.append(QString::number(numGoodFrames)+" Good Frames\t");
   windowContents.append(QString::number(numFrames-numGoodFrames)+" Bad Frames");
   ui->parityTextEdit->insertPlainText(windowContents);
   }


void MainWindow::populateSummaryTable()
   {

   int i=0;
   ui->summaryTable->setRowCount(3);
   ui->summaryTable->setColumnCount(2);

   //Minor Frame Count
   ui->summaryTable->setItem(i, 0, new QTableWidgetItem("Minor Frames"));
   ui->summaryTable->setItem(i, 1, new QTableWidgetItem(QString::number(numFrames)));
   i++;

   //Time Length Frame Count
   ui->summaryTable->setItem(i, 0, new QTableWidgetItem("Recording Length"));
   ui->summaryTable->setItem(i, 1, new QTableWidgetItem(QString::number(minorFrameTimes[numFrames-1],'f',3)));
   i++;

   //Spacecraft ID
   ui->summaryTable->setItem(i, 0, new QTableWidgetItem("Spacecraft ID"));
   if (SFID == 8)
      ui->summaryTable->setItem(i, 1, new QTableWidgetItem(QString::number(SFID)+"=>NOAA-15"));
   else if (SFID == 13)
      ui->summaryTable->setItem(i, 1, new QTableWidgetItem(QString::number(SFID)+"=>NOAA-18"));
   else if (SFID == 15)
      ui->summaryTable->setItem(i, 1, new QTableWidgetItem(QString::number(SFID)+"=>NOAA-19"));
   else
      ui->summaryTable->setItem(i, 1, new QTableWidgetItem(QString::number(SFID)+"=>A UFO!"));

   i++;

   //Major Frames
   ui->summaryTable->setItem(i, 0, new QTableWidgetItem("Major Frames"));
   //ui->summaryTable->setItem(i, 1, new QTableWidgetItem(QString::number(minorFrameTimes[numFrames-1],'f',3)));
   i++;

   //
   ui->summaryTable->setItem(i, 0, new QTableWidgetItem("T(0) time"));
   //ui->summaryTable->setItem(i, 1, new QTableWidgetItem(QString::number(minorFrameTimes[numFrames-1],'f',3)));
   i++;

   }

void MainWindow::updateViewOnTreeClick(QTreeWidgetItem *item, int column)
   {
   QStringList myOptions;
   myOptions << "Demodulation" << "Summary" << "Raw Hex Frames" <<\
                "Parity Check" << "Spacecraft" << "Spacecraft ID" << "Minor Frame IDs" << "Timestamps" <<\
                "HIRS" << "Channels" << "All" << "Telemetry" <<\
                "DCS" << "DCS Summary" << "CPU" << "CPU A" << "CPU B" <<\
                "SEM" << "MEPED" << "TED" << "TED2";

   //Bring forward the item associated with each tab. Enumeration follows the order of the words above.
   //To add a new word it must be in the same order as the stacked widgets tab pages
   //Or one could add a label and somehow switch to the page label but I don't see a slot for that in stackedWidget
   switch(myOptions.indexOf(item->text(0)))
      {
   case 0: //Demodulation
      ui->stackedWidget->setCurrentIndex(0);
      ui->groupBox->setTitle(item->text(1));
      break;
   case 1: //Summary
      ui->stackedWidget->setCurrentIndex(1);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 2://Raw Hex Frames
      ui->stackedWidget->setCurrentIndex(2);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 3://Parity Check
      ui->stackedWidget->setCurrentIndex(3);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 4://Spacecraft
      ui->stackedWidget->setCurrentIndex(4);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 5://Spacecraft ID
      ui->stackedWidget->setCurrentIndex(5);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 6://Minorframe IDs
      ui->stackedWidget->setCurrentIndex(6);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 7://Timestamps
      ui->stackedWidget->setCurrentIndex(7);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 8://HIRS
      ui->stackedWidget->setCurrentIndex(8);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 9://Channels
      ui->stackedWidget->setCurrentIndex(9);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 10://All
      ui->stackedWidget->setCurrentIndex(10);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 11://Telemetry
      ui->stackedWidget->setCurrentIndex(11);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 12://DCS
      ui->stackedWidget->setCurrentIndex(12);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 13://DCS Summary
      ui->stackedWidget->setCurrentIndex(13);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 14://CPU
      ui->stackedWidget->setCurrentIndex(14);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 15://CPU A
      ui->stackedWidget->setCurrentIndex(15);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 16://CPU B
      ui->stackedWidget->setCurrentIndex(16);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 17://SEM
      ui->stackedWidget->setCurrentIndex(17);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 18://MEPED
      ui->stackedWidget->setCurrentIndex(18);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 19://TED
      ui->stackedWidget->setCurrentIndex(19);
      ui->groupBox->setTitle(item->text(0));
      break;
   case 20://TED2
      ui->stackedWidget->setCurrentIndex(20);
      ui->groupBox->setTitle(item->text(0));
      break;

      }
   }

void MainWindow::decomSEM()
   {

   for(uint frame=0; frame < numFrames; frame++)
      SEMObj->addSEMFrame(255-minorFramesDec[frame][20], 255-minorFramesDec[frame][21], minorFrameIDList[frame], minorFrameTimes[frame], knownGoodFrameIndices.contains(frame));

   SEMObj->processSEM();
   }

void MainWindow::decomHIRS()
   {
   uchar HIRSFrame[HIRS_BYTES_PER_FRAME];
   uchar HIRSParity[HIRS_BYTES_PER_FRAME];
   float HIRSFrameTime[HIRS_BYTES_PER_FRAME];

   uchar HIRSSequence[] = {16,17,22,23,26,27,30,31,34,35,38,39,42,43,54,55,58,59,62,63,66,67,70,71,74,75,78,79,82,83,84,85,88,89,92,93};
   uchar HIRSParitySequence[] = {0,0,1,1,1,1,1,1,1,1,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,5,5,5,5};

   //chunk 0: Bit 3: 2-18
   //chunk 1: Bit 4: 19-35
   //chunk 2: Bit 5: 36-52
   //chunk 3: Bit 6: 53-69
   //chunk 4: Bit 7: 70-86
   //chunk 5: Bit 8: 87-103

   for(uint frame=0; frame < numFrames; frame++)
      {
      for(uint i=0; i < HIRS_BYTES_PER_FRAME; i++)
         {
         HIRSFrame[i] = minorFramesDec[frame][HIRSSequence[i]];
         HIRSFrameTime[i] = minorFrameTimes[frame] + (1.0/8320.0)*HIRSSequence[i];
         HIRSParity[i] = parityChunkList[HIRSParitySequence[i]][frame];
         }
      //HIRSObj->addHIRSFrame(255-minorFramesDec[frame][20], 255-minorFramesDec[frame][21], minorFrameIDList[frame], minorFrameTimes[frame], knownGoodFrameIndices.contains(frame));
      HIRSObj->addHIRSFrame(HIRSFrame,HIRSFrameTime,HIRSParity);
      }
   HIRSObj->processHIRS();
   }

void MainWindow::displayMinorFramesHex()
   {
   QTextCursor cursor(ui->minorFrameBrowser->textCursor());
   QString windowContents;
   //format text for raw hex minor frames
   //0	1	2	3       4	5       6	7	8	9	10	11	12      13	14	15	16	17	18	19	20	21	22	23	24	25	26	27	28	29	30	31	32	33	34	35	36	37	38	39	40	41	42	43	44	45	46	47	48	49	50	51	52	53	54	55	56	57	58	59	60	61	62	63	64	65	66	67	68	69	70	71	72	73	74	75	76	77	78	79	80	81	82	83	84	85	86	87	88	89	90	91	92	93	94	95	96	97	98	99	100	101	102	103
   //Sync+ID	Stat	FrmCnt		CMD		TimeDay (frm 0)			A2	DAU		HIRS		DCS		SEM		HIRS		DCS		HIRS		DCS		HIRS		DCS		HIRS		SBUV		HIRS		DCS		HIRS		DCS		CPU A TLM						DCS		HIRS		DCS		HIRS		DCS		HIRS		DCS		HIRS		DCS		HIRS		DCS		HIRS		DCS		HIRS		SBUV		HIRS		HIRS		DCS		HIRS		DCS		HIRS		DCS		CPU B TLM						MIU	Parity

   for(int i=0; i < numFrames; i++)
      {
      //This is very slow
      //cursor.insertText(QString::number(minorFrameTimes[i],'f',4));
      //cursor.insertText("\t");
      //cursor.insertText(minorFramesHex[i]);
      //cursor.insertText("\n");

      //this meethod is fast

      //please look to see if QString has a padding option...
      if(i < 10 )
         windowContents.append("000");
      else if(i < 100)
         windowContents.append("00");
      else if(i < 1000)
         windowContents.append('0');

      windowContents.append(QString::number(i));
      windowContents.append(" ");
      //windowContents.append(" <font color = \"red\">");

      if(minorFrameTimes[i] < 10 )
         windowContents.append("000");
      else if(minorFrameTimes[i] < 100)
         windowContents.append("00");
      else if(minorFrameTimes[i] < 1000)
         windowContents.append('0');

      windowContents.append(QString::number(minorFrameTimes[i],'f',4));
      //windowContents.append("</font>\t");
      windowContents.append('\t');
      windowContents.append(minorFramesHex[i]);
      windowContents.append('\n');
      //windowContents.append("<br>");

      //why is this SO SLOW?!
      //ui->minorFrameBrowser->insertPlainText(QString::number(minorFrameTimes[i]));
      //ui->minorFrameBrowser->insertPlainText("\t");
      //ui->minorFrameBrowser->insertPlainText(minorFramesHex[i]);
      //ui->minorFrameBrowser->insertPlainText("\n");
      }

   //This is fast on plaintextedit, but can't color text, and is slow on qtextedit
   ui->minorFrameBrowser->insertPlainText(windowContents);

   //cursor.insertHtml(windowContents); //This is slow

   //setUpdatesEnabled(false);
   //ui->minorFrameBrowser->insertHtml(windowContents); //This is slow

   //setUpdatesEnabled(true);
   }

void MainWindow::displayMinorFramesDec()
   {
   unsigned char byte;
   QString windowContents;
   //format text for raw hex minor frames
   //0	1	2	3       4	5       6	7	8	9	10	11	12      13	14	15	16	17	18	19	20	21	22	23	24	25	26	27	28	29	30	31	32	33	34	35	36	37	38	39	40	41	42	43	44	45	46	47	48	49	50	51	52	53	54	55	56	57	58	59	60	61	62	63	64	65	66	67	68	69	70	71	72	73	74	75	76	77	78	79	80	81	82	83	84	85	86	87	88	89	90	91	92	93	94	95	96	97	98	99	100	101	102	103
   //Sync+ID	Stat	FrmCnt		CMD		TimeDay (frm 0)			A2	DAU		HIRS		DCS		SEM		HIRS		DCS		HIRS		DCS		HIRS		DCS		HIRS		SBUV		HIRS		DCS		HIRS		DCS		CPU A TLM						DCS		HIRS		DCS		HIRS		DCS		HIRS		DCS		HIRS		DCS		HIRS		DCS		HIRS		DCS		HIRS		SBUV		HIRS		HIRS		DCS		HIRS		DCS		HIRS		DCS		CPU B TLM						MIU	Parity


   for(int i=0; i < numFrames; i++)
      {
      //this is fast
      windowContents.append(QString::number(i));
      windowContents.append(" ");
      windowContents.append(QString::number(minorFrameTimes[i],'f',4));

      windowContents.append('\t');
      for(int j=0; j < minorFramesDec[i].length(); j++)
         {
         //const unsigned char *pdata = reinterpret_cast<const unsigned char *>(thearray.constData());
         byte = minorFramesDec[i][j];
         windowContents.append(QString::number(byte));
         windowContents.append('\t');
         }
      windowContents.append('\n');

      }

   ui->DCSSumTextBrowser->insertPlainText(windowContents);
   }

void MainWindow::displaySpaceCraftID()
   {
   QList<unsigned int> SFIDSorted, SFIDRaw;
   unsigned char byte;

   for(int i=0; i < numFrames; i++)
      {
      byte = minorFramesDec[i][2];
      SFIDSorted.append(byte);
      SFIDRaw.append(byte);
      }
   qSort(SFIDSorted.begin(), SFIDSorted.end());

   unsigned int bestValueSoFar=0, bestCountSoFar=0, instanceCounter=0, prev=0;
   for(int i=0; i < numFrames; i++)
      {
      if(SFIDSorted[i] == prev)
         instanceCounter++;
      else
         instanceCounter=0;

      if(instanceCounter > bestCountSoFar)
         {
         bestCountSoFar = instanceCounter;
         bestValueSoFar = SFIDSorted[i];
         }
      prev = SFIDSorted[i];
      }
   SFID = bestValueSoFar;

   //QList <unsigned int> minorFrameIDList;
   //QByteArray spaceCraftIDList;
   QString windowContents;

   for(int i=0; i < numFrames; i++)
      {
      windowContents.append(QString::number(SFIDRaw[i]));
      windowContents.append('\n');
      }

   ui->SPIDList->insertPlainText(windowContents);

   // add curves
   QwtPlotCurve *curveGood = new QwtPlotCurve("Good SPIDs");
   QwtPlotCurve *curveBad = new QwtPlotCurve("Bad SPIDs");
   //QImage* image =  new QImage("noaageneral9.jpg");

   //ui->SPIDPlot->setFixedSize(image->width(),image->height());

   double *xPointsGood, *xPointsBad;
   double *yPointsGood, *yPointsBad;
   unsigned int numPointsGood=numGoodFrames;
   unsigned int numPointsBad=abs(numFrames-numGoodFrames);

   xPointsGood = new double[numPointsGood];
   yPointsGood = new double[numPointsGood];

   xPointsBad = new double[numPointsBad];
   yPointsBad = new double[numPointsBad];

   for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
      {
      if(knownGoodFrameIndices.contains(frame))
         {
         xPointsGood[igood] = minorFrameTimes[frame];
         yPointsGood[igood] = SFIDRaw[frame];
         igood++;
         }
      else
         {
         xPointsBad[ibad] = minorFrameTimes[frame];
         yPointsBad[ibad] = SFIDRaw[frame];
         ibad++;
         }
      }

   //QVarLengthArray<double, 1024> xPointsGood; I did this in allspice

   QwtSymbol *markerGood = new QwtSymbol;
   QwtSymbol *markerBad = new QwtSymbol;
   //curveGood->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor( "Purple" ),QColor( "Purple" ),4));

   //plot good data
   markerGood->setStyle(QwtSymbol::Ellipse);
   markerGood->setSize(4);
   markerGood->setColor(QColor( "purple" ));
   markerGood->setPen(QColor( "cyan" ));

   //curveGood->setData(new QwtCPointerData(&xPointsGood[0],&yPointsGood[0],(size_t)3));
   curveGood->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curveGood->setRawSamples(&xPointsGood[0], &yPointsGood[0], numPointsGood);
   curveGood->setPen( QColor( "Purple" ) );
   //curveGood->setStyle( QwtPlotCurve::Dots );
   curveGood->setStyle( QwtPlotCurve::NoCurve );
   curveGood->setSymbol(markerGood);



   //plot bad data
   markerBad->setStyle(QwtSymbol::Star1);
   markerBad->setSize(3);
   markerBad->setColor(QColor( "purple" ));
   markerBad->setPen(QColor( "teal" ));

   //curveGood->setData(new QwtCPointerData(&xPointsGood[0],&yPointsGood[0],(size_t)3));
   curveBad->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curveBad->setRawSamples(&xPointsBad[0], &yPointsBad[0], numPointsBad);
   curveBad->setPen( QColor( "Purple" ) );
   //curveGood->setStyle( QwtPlotCurve::Dots );
   curveBad->setStyle( QwtPlotCurve::NoCurve );
   curveBad->setSymbol(markerBad);

   curveBad->attach(ui->SPIDPlot);
   curveGood->attach(ui->SPIDPlot);


   ui->SPIDPlot->autoFillBackground();
   // finally, refresh the plot
   ui->SPIDPlot->axisScaleEngine(QwtPlot::xBottom)->setAttribute(QwtScaleEngine::Floating,true);
   ui->SPIDPlot->axisScaleEngine(QwtPlot::yLeft)->setAttribute(QwtScaleEngine::Floating,true);
   ui->SPIDPlot->replot();
   ui->SPIDPlot->show();
   }

void MainWindow::plotMinorFrameID()
   {
   QByteArray spaceCraftIDList;
   QString windowContents;
   unsigned char byte1,byte2;
   for(int i=0; i < numFrames; i++)
      {
      //minorFrameID = bitor(bitshift(bitand(minorFrames(:,5),1),8),minorFrames(:,6)); %pull out minor frame counter, which is annoyingly 9 bits long
      byte1 = minorFramesDec[i][4];
      byte2 = minorFramesDec[i][5];
      minorFrameIDList.append(((byte1 & 0x01)<<8) | byte2);
      }

   for(int i=0; i < minorFrameIDList.length(); i++)
      {
      windowContents.append(QString::number(minorFrameIDList[i]));
      windowContents.append('\n');
      }

   ui->MinorFrameIDList->insertPlainText(windowContents);

   // add curves
   QwtPlotCurve *curveGood = new QwtPlotCurve("Good Frame IDs");
   QwtPlotCurve *curveBad = new QwtPlotCurve("Bad Frame IDs");

   double *xPointsGood, *xPointsBad;
   double *yPointsGood, *yPointsBad;
   unsigned int numPointsGood=numGoodFrames;
   unsigned int numPointsBad=abs(numFrames-numGoodFrames);

   xPointsGood = new double[numPointsGood];
   yPointsGood = new double[numPointsGood];

   xPointsBad = new double[numPointsBad];
   yPointsBad = new double[numPointsBad];

   for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
      {
      if(knownGoodFrameIndices.contains(frame))
         {
         xPointsGood[igood] = minorFrameTimes[frame];
         yPointsGood[igood] = minorFrameIDList[frame];
         igood++;
         }
      else
         {
         xPointsBad[ibad] = minorFrameTimes[frame];
         yPointsBad[ibad] = minorFrameIDList[frame];
         ibad++;
         }
      }

   //QVarLengthArray<double, 1024> xPointsGood; I did this in allspice

   QwtSymbol *markerGood = new QwtSymbol;
   QwtSymbol *markerBad = new QwtSymbol;
   //curveGood->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor( "Purple" ),QColor( "Purple" ),4));

   //plot good data
   markerGood->setStyle(QwtSymbol::Ellipse);
   markerGood->setSize(4);
   markerGood->setColor(QColor( "purple" ));
   markerGood->setPen(QColor( "magenta" ));

   //curveGood->setData(new QwtCPointerData(&xPointsGood[0],&yPointsGood[0],(size_t)3));
   curveGood->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curveGood->setRawSamples(&xPointsGood[0], &yPointsGood[0], numPointsGood);
   curveGood->setPen( QColor( "Purple" ) );
   //curveGood->setStyle( QwtPlotCurve::Dots );
   curveGood->setStyle( QwtPlotCurve::NoCurve );
   curveGood->setSymbol(markerGood);

   //plot bad data
   markerBad->setStyle(QwtSymbol::Star1);
   markerBad->setSize(3);
   markerBad->setColor(QColor( "purple" ));
   markerBad->setPen(QColor( "purple" ));

   //curveGood->setData(new QwtCPointerData(&xPointsGood[0],&yPointsGood[0],(size_t)3));
   curveBad->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curveBad->setRawSamples(&xPointsBad[0], &yPointsBad[0], numPointsBad);
   curveBad->setPen( QColor( "Purple" ) );
   //curveGood->setStyle( QwtPlotCurve::Dots );
   curveBad->setStyle( QwtPlotCurve::NoCurve );
   curveBad->setSymbol(markerBad);

   curveBad->attach(ui->minorFrameIDPlot);
   curveGood->attach(ui->minorFrameIDPlot);



   // finally, refresh the plot
   ui->minorFrameIDPlot->axisScaleEngine(QwtPlot::xBottom)->setAttribute(QwtScaleEngine::Floating,true);
   ui->minorFrameIDPlot->axisScaleEngine(QwtPlot::yLeft)->setAttribute(QwtScaleEngine::Floating,true);
   ui->minorFrameIDPlot->replot();
   ui->minorFrameIDPlot->show();
   }

void MainWindow::convertMinorFramesHex2Dec()
   {
   QString line, hexByte;
   QStringList splitLine;
   QByteArray frame;
   for(int i=0; i < numFrames; i++)
      {
      line=minorFramesHex[i];

      line.replace(" ","");
      frame = QByteArray::fromHex(line.toLatin1());

      minorFramesDec.append(frame);
      }
   }
