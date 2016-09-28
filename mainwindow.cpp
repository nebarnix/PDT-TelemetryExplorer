#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFont font("Monospace");
    font.setStyleHint(QFont::TypeWriter);
    ui->minorFrameBrowser->setFont(font);

    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(open()));
    connect(ui->treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(updateViewOnTreeClick(QTreeWidgetItem*,int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
            tr("Text Files (*.txt)"));

        if (fileName != "") {
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly)) {
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
                else
                    minorFramesHex.append(line);
            }
           ui->minorFrameBrowser->setPlainText(minorFramesHex.join('\n'));
           file.close();
        }
}

void MainWindow::updateViewOnTreeClick(QTreeWidgetItem *item, int column)
{
    QStringList myOptions;
    myOptions << "Duration" << "Raw Hex Frames" << "Number of Frames" <<\
                 "Parity Check" << "Spacecraft ID" << "Timestamps" <<\
                 "HIRS" << "DCS Summary" << "Channels" << "All" << "Telemetry" <<\
                 "DCS" << "DCS Summary" << "CPU" << "CPU A" << "CPU B" <<\
                 "SEM" << "MEPED" << "TED";

    switch(myOptions.indexOf(item->text(0)))
    {
    case 0:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 1:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 2:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 3:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 4:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 5:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 6:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 7:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 8:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 9:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 10:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 11:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 12:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 13:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 14:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 15:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 16:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 17:
        ui->groupBox->setTitle(item->text(0));
        break;
    case 18:
        ui->groupBox->setTitle(item->text(0));
        break;
    }
    //ui->textBrowser->setText(item->text(0));
}
