/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *TreeBox;
    QTreeWidget *treeWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *Demod;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QWidget *Summary;
    QTableWidget *tableWidget;
    QLabel *label_2;
    QWidget *RawHex;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QPlainTextEdit *minorFrameBrowser;
    QWidget *Parity;
    QLabel *label_4;
    QWidget *SpaceCrft;
    QLabel *label_5;
    QWidget *SPC_ID;
    QGridLayout *gridLayout_4;
    QLabel *label_6;
    QwtPlot *SPIDPlot;
    QWidget *TStamp;
    QWidget *HIRS;
    QWidget *HChans;
    QWidget *HChanAll;
    QWidget *HTlm;
    QWidget *DCS;
    QTextEdit *textEdit;
    QWidget *DSum;
    QTextBrowser *textBrowser;
    QWidget *CPU;
    QTextBrowser *textBrowser_2;
    QWidget *CPUA;
    QWidget *CPUB;
    QWidget *SEM;
    QWidget *MEPED;
    QWidget *TED;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuExit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1055, 687);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        TreeBox = new QGroupBox(centralWidget);
        TreeBox->setObjectName(QStringLiteral("TreeBox"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TreeBox->sizePolicy().hasHeightForWidth());
        TreeBox->setSizePolicy(sizePolicy);
        TreeBox->setMinimumSize(QSize(256, 0));
        TreeBox->setMaximumSize(QSize(256, 16777215));
        TreeBox->setBaseSize(QSize(500, 0));
        treeWidget = new QTreeWidget(TreeBox);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem2);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem4);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem6);
        new QTreeWidgetItem(__qtreewidgetitem6);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(10, 20, 231, 571));
        treeWidget->setWordWrap(true);
        treeWidget->header()->setCascadingSectionResizes(true);
        treeWidget->header()->setProperty("showSortIndicator", QVariant(false));
        treeWidget->header()->setStretchLastSection(true);

        horizontalLayout->addWidget(TreeBox);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        stackedWidget = new QStackedWidget(groupBox);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        Demod = new QWidget();
        Demod->setObjectName(QStringLiteral("Demod"));
        gridLayout_3 = new QGridLayout(Demod);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(Demod);
        label->setObjectName(QStringLiteral("label"));
        label->setTextFormat(Qt::RichText);
        label->setWordWrap(true);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 0, 1, 1);

        stackedWidget->addWidget(Demod);
        Summary = new QWidget();
        Summary->setObjectName(QStringLiteral("Summary"));
        tableWidget = new QTableWidget(Summary);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 741, 561));
        label_2 = new QLabel(Summary);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 10, 71, 16));
        stackedWidget->addWidget(Summary);
        RawHex = new QWidget();
        RawHex->setObjectName(QStringLiteral("RawHex"));
        gridLayout_5 = new QGridLayout(RawHex);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_3 = new QLabel(RawHex);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);

        minorFrameBrowser = new QPlainTextEdit(RawHex);
        minorFrameBrowser->setObjectName(QStringLiteral("minorFrameBrowser"));
        minorFrameBrowser->setLineWrapMode(QPlainTextEdit::NoWrap);
        minorFrameBrowser->setReadOnly(true);

        gridLayout_5->addWidget(minorFrameBrowser, 1, 0, 1, 1);

        stackedWidget->addWidget(RawHex);
        Parity = new QWidget();
        Parity->setObjectName(QStringLiteral("Parity"));
        label_4 = new QLabel(Parity);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 0, 55, 16));
        stackedWidget->addWidget(Parity);
        SpaceCrft = new QWidget();
        SpaceCrft->setObjectName(QStringLiteral("SpaceCrft"));
        label_5 = new QLabel(SpaceCrft);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 10, 71, 16));
        stackedWidget->addWidget(SpaceCrft);
        SPC_ID = new QWidget();
        SPC_ID->setObjectName(QStringLiteral("SPC_ID"));
        gridLayout_4 = new QGridLayout(SPC_ID);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_6 = new QLabel(SPC_ID);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_4->addWidget(label_6, 0, 0, 1, 1);

        SPIDPlot = new QwtPlot(SPC_ID);
        SPIDPlot->setObjectName(QStringLiteral("SPIDPlot"));

        gridLayout_4->addWidget(SPIDPlot, 1, 0, 1, 1);

        stackedWidget->addWidget(SPC_ID);
        TStamp = new QWidget();
        TStamp->setObjectName(QStringLiteral("TStamp"));
        stackedWidget->addWidget(TStamp);
        HIRS = new QWidget();
        HIRS->setObjectName(QStringLiteral("HIRS"));
        stackedWidget->addWidget(HIRS);
        HChans = new QWidget();
        HChans->setObjectName(QStringLiteral("HChans"));
        stackedWidget->addWidget(HChans);
        HChanAll = new QWidget();
        HChanAll->setObjectName(QStringLiteral("HChanAll"));
        stackedWidget->addWidget(HChanAll);
        HTlm = new QWidget();
        HTlm->setObjectName(QStringLiteral("HTlm"));
        stackedWidget->addWidget(HTlm);
        DCS = new QWidget();
        DCS->setObjectName(QStringLiteral("DCS"));
        textEdit = new QTextEdit(DCS);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 751, 561));
        stackedWidget->addWidget(DCS);
        DSum = new QWidget();
        DSum->setObjectName(QStringLiteral("DSum"));
        textBrowser = new QTextBrowser(DSum);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 751, 561));
        stackedWidget->addWidget(DSum);
        CPU = new QWidget();
        CPU->setObjectName(QStringLiteral("CPU"));
        textBrowser_2 = new QTextBrowser(CPU);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(0, 0, 751, 561));
        stackedWidget->addWidget(CPU);
        CPUA = new QWidget();
        CPUA->setObjectName(QStringLiteral("CPUA"));
        stackedWidget->addWidget(CPUA);
        CPUB = new QWidget();
        CPUB->setObjectName(QStringLiteral("CPUB"));
        stackedWidget->addWidget(CPUB);
        SEM = new QWidget();
        SEM->setObjectName(QStringLiteral("SEM"));
        stackedWidget->addWidget(SEM);
        MEPED = new QWidget();
        MEPED->setObjectName(QStringLiteral("MEPED"));
        stackedWidget->addWidget(MEPED);
        TED = new QWidget();
        TED->setObjectName(QStringLiteral("TED"));
        stackedWidget->addWidget(TED);

        gridLayout_2->addWidget(stackedWidget, 0, 1, 1, 1);


        horizontalLayout->addWidget(groupBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1055, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuExit = new QMenu(menuBar);
        menuExit->setObjectName(QStringLiteral("menuExit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuExit->menuAction());
        menuFile->addAction(actionLoad);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load...", 0));
        TreeBox->setTitle(QApplication::translate("MainWindow", "Telem-Tree", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Instrument", 0));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Demodulation", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Summary", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "Raw Hex Frames", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "Parity Check", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "Spacecraft", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWindow", "Spacecraft ID", 0));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem5->child(1);
        ___qtreewidgetitem7->setText(0, QApplication::translate("MainWindow", "Timestamps", 0));
        QTreeWidgetItem *___qtreewidgetitem8 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem8->setText(0, QApplication::translate("MainWindow", "HIRS", 0));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem8->child(0);
        ___qtreewidgetitem9->setText(0, QApplication::translate("MainWindow", "Channels", 0));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem9->child(0);
        ___qtreewidgetitem10->setText(0, QApplication::translate("MainWindow", "All", 0));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem8->child(1);
        ___qtreewidgetitem11->setText(0, QApplication::translate("MainWindow", "Telemetry", 0));
        QTreeWidgetItem *___qtreewidgetitem12 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem12->setText(0, QApplication::translate("MainWindow", "DCS", 0));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem12->child(0);
        ___qtreewidgetitem13->setText(0, QApplication::translate("MainWindow", "DCS Summary", 0));
        QTreeWidgetItem *___qtreewidgetitem14 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem14->setText(0, QApplication::translate("MainWindow", "CPU", 0));
        QTreeWidgetItem *___qtreewidgetitem15 = ___qtreewidgetitem14->child(0);
        ___qtreewidgetitem15->setText(0, QApplication::translate("MainWindow", "CPU A", 0));
        QTreeWidgetItem *___qtreewidgetitem16 = ___qtreewidgetitem14->child(1);
        ___qtreewidgetitem16->setText(0, QApplication::translate("MainWindow", "CPU B", 0));
        QTreeWidgetItem *___qtreewidgetitem17 = treeWidget->topLevelItem(5);
        ___qtreewidgetitem17->setText(0, QApplication::translate("MainWindow", "SEM", 0));
        QTreeWidgetItem *___qtreewidgetitem18 = ___qtreewidgetitem17->child(0);
        ___qtreewidgetitem18->setText(0, QApplication::translate("MainWindow", "MEPED", 0));
        QTreeWidgetItem *___qtreewidgetitem19 = ___qtreewidgetitem17->child(1);
        ___qtreewidgetitem19->setText(0, QApplication::translate("MainWindow", "TED", 0));
        treeWidget->setSortingEnabled(__sortingEnabled);

        groupBox->setTitle(QApplication::translate("MainWindow", "The Good Stuff", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Demodulation Details</span></p><p><span style=\" font-size:10pt;\">The modulation scheme is a non orthagonal BPSK, also known as a preserved carrier PSK.</span></p><p><span style=\" font-size:10pt;\">The phase shift is between -67 and +67 degrees, which allows the carrier frequency to be preserved and tracked using a simple PLL. </span></p><p><span style=\" font-size:10pt;\">The bits are manchester coded for ease of clock recovery, which means there are two symbols per bit. </span></p><p><span style=\" font-size:10pt; font-weight:600;\">Summary: </span><span style=\" font-size:10pt;\">Dsplays the results of the demodulation</span></p><p><span style=\" font-size:10pt; font-weight:600;\">Raw Hex: </span><span style=\" font-size:10pt;\">Displays the raw minor frames in hex format for visualization or copy/paste into another application</span></p><p><span style=\" font-size:10pt; font-weight:600;\">Parity: </span><span style=\" font-size:10pt;"
                        "\">Calculates the errors in the bitstream in 5 chunks and verifies that there are at least an even or odd number of errors in each chunk.</span></p><p><span style=\" font-size:10pt;\"><br/></span></p></body></html>", 0));
        label_2->setText(QApplication::translate("MainWindow", "Summary", 0));
        label_3->setText(QApplication::translate("MainWindow", "RawHex", 0));
        label_4->setText(QApplication::translate("MainWindow", "Parity", 0));
        label_5->setText(QApplication::translate("MainWindow", "Spacecraft", 0));
        label_6->setText(QApplication::translate("MainWindow", "SPC_ID", 0));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">DCS transmitters are ground based transmitters that contain a short payload and geolocation information</p></body></html>", 0));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Transmitter Summary (lots and lots of stuff and stuff)</p></body></html>", 0));
        textBrowser_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">CPU Telemetry is still being reverse engineered and is probably impossible to completely understand given the amount of possible magic data</p></body></html>", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuExit->setTitle(QApplication::translate("MainWindow", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
