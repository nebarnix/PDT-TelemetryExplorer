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

    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(open()));
    connect(ui->treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(updateViewOnTreeClick(QTreeWidgetItem*,int)));
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
   //QTextStream textStream(&textFile);
   while (true)
      {
      QString line = in.readLine();
      if (line.isNull())
      break;
      else if(line.contains(re)) //only look at lines that start with a decimal number
         {
         line[line.indexOf(' ')] = '\t'; //Replace the first space with a tab
         minorFrameParts = line.split('\t'); //Split on said tab
         minorFramesHex.append(minorFrameParts[1]);        //Put the hex data right into the window
         minorFrameTimes.append(minorFrameParts[0].toFloat()); //Get the times and convert to float
         }
      }
   file.close();
   displayMinorFramesHex();
   }
}

void MainWindow::updateViewOnTreeClick(QTreeWidgetItem *item, int column)
{
    QStringList myOptions;
    myOptions << "Demodulation" << "Summary" << "Raw Hex Frames" <<\
                 "Parity Check" << "Spacecraft" << "Spacecraft ID" << "Timestamps" <<\
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
    case 6://Timestamps
        ui->stackedWidget->setCurrentIndex(6);
        ui->groupBox->setTitle(item->text(0));
        break;
    case 7://HIRS
        ui->stackedWidget->setCurrentIndex(7);
        ui->groupBox->setTitle(item->text(0));
        break;
    case 8://Channels
        ui->stackedWidget->setCurrentIndex(8);
        ui->groupBox->setTitle(item->text(0));
        break;
    case 9://All
        ui->stackedWidget->setCurrentIndex(9);
        ui->groupBox->setTitle(item->text(0));
        break;
    case 10://Telemetry
        ui->stackedWidget->setCurrentIndex(10);
        ui->groupBox->setTitle(item->text(0));
        break;
    case 11://DCS
        ui->stackedWidget->setCurrentIndex(11);
        ui->groupBox->setTitle(item->text(0));
        break;
    case 12://DCS Summary
        ui->stackedWidget->setCurrentIndex(12);
        ui->groupBox->setTitle(item->text(0));
        break;
    case 13://CPU
        ui->stackedWidget->setCurrentIndex(13);
        ui->groupBox->setTitle(item->text(0));
        break;
    case 14://CPU A
        ui->stackedWidget->setCurrentIndex(14);
        ui->groupBox->setTitle(item->text(0));
        break;
    case 15://CPU B
        ui->stackedWidget->setCurrentIndex(15);
        ui->groupBox->setTitle(item->text(0));
        break;
    case 16://SEM
        ui->stackedWidget->setCurrentIndex(16);
        ui->groupBox->setTitle(item->text(0));
        break;
    case 17://MEPED
        ui->stackedWidget->setCurrentIndex(17);
        ui->groupBox->setTitle(item->text(0));
        break;
    case 18://TED
        ui->stackedWidget->setCurrentIndex(17);
        ui->groupBox->setTitle(item->text(0));
        break;

    }
    //ui->textBrowser->setText(item->text(0));
}

void MainWindow::displayMinorFramesHex()
{
QTextCursor cursor(ui->minorFrameBrowser->textCursor());
QString windowContents;
//format text for raw hex minor frames
//0	1	2	3       4	5       6	7	8	9	10	11	12      13	14	15	16	17	18	19	20	21	22	23	24	25	26	27	28	29	30	31	32	33	34	35	36	37	38	39	40	41	42	43	44	45	46	47	48	49	50	51	52	53	54	55	56	57	58	59	60	61	62	63	64	65	66	67	68	69	70	71	72	73	74	75	76	77	78	79	80	81	82	83	84	85	86	87	88	89	90	91	92	93	94	95	96	97	98	99	100	101	102	103
//Sync+ID	Stat	FrmCnt		CMD		TimeDay (frm 0)			A2	DAU		HIRS		DCS		SEM		HIRS		DCS		HIRS		DCS		HIRS		DCS		HIRS		SBUV		HIRS		DCS		HIRS		DCS		CPU A TLM						DCS		HIRS		DCS		HIRS		DCS		HIRS		DCS		HIRS		DCS		HIRS		DCS		HIRS		DCS		HIRS		SBUV		HIRS		HIRS		DCS		HIRS		DCS		HIRS		DCS		CPU B TLM						MIU	Parity

for(int i=0; i < minorFramesHex.length(); i++)
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

void MainWindow::displaySpaceCraftID()
{
}

