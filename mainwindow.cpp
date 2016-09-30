#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{

QStringList minorFrameParts;

QRegularExpression re("^\\d+.\\d+");
QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
tr("Minor Frame Files (minorFrames*.txt)"));

//clear text window
ui->minorFrameBrowser->clear();

if (fileName != "")
   {
   QFile file(fileName);
   if (!file.open(QIODevice::ReadOnly))
      {
      QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
      return;
      }
   QTextStream in(&file);

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
         minorFramesHex.append(minorFrameParts[1]);        //Put the hex data right into the window
         minorFrameTimes.append(minorFrameParts[0].toFloat()); //Get the times and convert to float
         }
      }
   file.close();
   numFrames = minorFramesHex.length();

   displayMinorFramesHex();
   convertMinorFramesHex2Dec();
   //displayMinorFramesDec(); //no need to spit these out to the DCS box. Its not your box anyway!
   displaySpaceCraftID();
   plotMinorFrameID();
   getTimeStamps();
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

}

void MainWindow::updateViewOnTreeClick(QTreeWidgetItem *item, int column)
{
    QStringList myOptions;
    myOptions << "Demodulation" << "Summary" << "Raw Hex Frames" <<\
                 "Parity Check" << "Spacecraft" << "Spacecraft ID" << "Minor Frame IDs" << "Timestamps" <<\
                 "HIRS" << "Channels" << "All" << "Telemetry" <<\
                 "DCS" << "DCS Summary" << "CPU" << "CPU A" << "CPU B" <<\
                 "SEM" << "MEPED" << "TED";

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

    }    
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

   //this is fast
   windowContents.append(QString::number(i));
   windowContents.append(" ");
   //windowContents.append(" <font color = \"red\">");
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
       windowContents.append(QString::number(minorFramesDec[i][j]+128));
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
    QwtPlotCurve *curve1 = new QwtPlotCurve("Curve 1");
    QImage* image =  new QImage("noaageneral9.jpg");

    //ui->SPIDPlot->setFixedSize(image->width(),image->height());

    double *xdata;
    double *ydata;
    xdata = new double[numFrames];
    ydata = new double[numFrames];

    for(int i=0; i < numFrames; i++)
       xdata[i] = minorFrameTimes[i];

    for(int i=0; i < numFrames; i++)
       ydata[i] = SFIDRaw[i];

    //QVarLengthArray<double, 1024> xdata; I did this in allspice

    //pointer = QwtCPointerData(&xdata[0],&ydata[0], numFrames);
    //curve1->setData(new QwtCPointerData(&xdata[0],&ydata[0],(size_t)3));
    curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
    curve1->setRawSamples(&xdata[0], &ydata[0], numFrames);
    curve1->setPen( QColor( "Purple" ) );
    //curve1->setStyle( QwtPlotCurve::Dots );

    curve1->setStyle( QwtPlotCurve::NoCurve );

    QwtSymbol *marker = new QwtSymbol;
    //curve1->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor( "Purple" ),QColor( "Purple" ),4));
    marker->setStyle(QwtSymbol::Ellipse);
    marker->setSize(4);

    marker->setColor(QColor( "purple" ));
    marker->setPen(QColor( "cyan" ));
    curve1->setSymbol(marker);

    curve1->attach(ui->SPIDPlot);

    (void )new QwtPlotPanner( ui->SPIDPlot->canvas() );
    QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( ui->SPIDPlot->canvas() );
    magnifier->setMouseButton( Qt::NoButton );

    // finally, refresh the plot
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
    QwtPlotCurve *curve1 = new QwtPlotCurve("Curve 1");

    double *xdata;
    double *ydata;
    xdata = new double[numFrames];
    ydata = new double[numFrames];

    for(int i=0; i < numFrames; i++)
       xdata[i] = minorFrameTimes[i];

    for(int i=0; i < numFrames; i++)
       ydata[i] = minorFrameIDList[i];

    //QVarLengthArray<double, 1024> xdata; I did this in allspice

    //pointer = QwtCPointerData(&xdata[0],&ydata[0], numFrames);
    //curve1->setData(new QwtCPointerData(&xdata[0],&ydata[0],(size_t)3));
    curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
    curve1->setRawSamples(&xdata[0], &ydata[0], numFrames);

    curve1->setStyle( QwtPlotCurve::NoCurve );

    QwtSymbol *marker = new QwtSymbol;
    //curve1->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,QColor( "Purple" ),QColor( "Purple" ),4));
    marker->setStyle(QwtSymbol::Ellipse);
    marker->setSize(4);

    marker->setColor(QColor( "Purple" ));
    marker->setPen(QColor( "Magenta" ));
    curve1->setSymbol(marker);

    curve1->attach(ui->minorFrameIDPlot);

    (void )new QwtPlotPanner( ui->minorFrameIDPlot->canvas() );
    QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( ui->minorFrameIDPlot->canvas() );
    magnifier->setMouseButton( Qt::NoButton );

    // finally, refresh the plot
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
