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
    QTableWidget *summaryTable;
    QWidget *RawHex;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QPlainTextEdit *minorFrameBrowser;
    QWidget *Parity;
    QLabel *label_4;
    QWidget *SpaceCrft;
    QGridLayout *gridLayout_10;
    QLabel *label_5;
    QWidget *SPC_ID;
    QGridLayout *gridLayout_4;
    QwtPlot *SPIDPlot;
    QPlainTextEdit *SPIDList;
    QWidget *MinorFrameIDs;
    QGridLayout *gridLayout_6;
    QwtPlot *minorFrameIDPlot;
    QPlainTextEdit *MinorFrameIDList;
    QWidget *TStamp;
    QGridLayout *gridLayout_11;
    QPlainTextEdit *TimeStampTextBox;
    QWidget *HIRS;
    QGridLayout *gridLayout_8;
    QLabel *label_8;
    QWidget *HChans;
    QWidget *HChanAll;
    QWidget *HTlm;
    QWidget *DCS;
    QGridLayout *gridLayout_7;
    QLabel *label_7;
    QWidget *DSum;
    QPlainTextEdit *DCSSumTextBrowser;
    QWidget *CPU;
    QGridLayout *gridLayout_9;
    QLabel *label_9;
    QWidget *CPUA;
    QWidget *CPUB;
    QWidget *SEM;
    QWidget *MEPED;
    QWidget *TED;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuExit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1055, 698);
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
        treeWidget->setGeometry(QRect(10, 20, 231, 581));
        treeWidget->setWordWrap(true);
        treeWidget->setExpandsOnDoubleClick(false);
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
        summaryTable = new QTableWidget(Summary);
        if (summaryTable->columnCount() < 2)
            summaryTable->setColumnCount(2);
        if (summaryTable->rowCount() < 3)
            summaryTable->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        summaryTable->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        summaryTable->setItem(1, 0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        summaryTable->setItem(2, 0, __qtablewidgetitem2);
        summaryTable->setObjectName(QStringLiteral("summaryTable"));
        summaryTable->setGeometry(QRect(0, 0, 741, 561));
        summaryTable->setCornerButtonEnabled(false);
        summaryTable->setRowCount(3);
        summaryTable->setColumnCount(2);
        summaryTable->horizontalHeader()->setVisible(false);
        summaryTable->horizontalHeader()->setMinimumSectionSize(75);
        summaryTable->verticalHeader()->setVisible(false);
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
        gridLayout_10 = new QGridLayout(SpaceCrft);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        label_5 = new QLabel(SpaceCrft);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_5->setWordWrap(true);

        gridLayout_10->addWidget(label_5, 0, 0, 1, 1);

        stackedWidget->addWidget(SpaceCrft);
        SPC_ID = new QWidget();
        SPC_ID->setObjectName(QStringLiteral("SPC_ID"));
        gridLayout_4 = new QGridLayout(SPC_ID);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        SPIDPlot = new QwtPlot(SPC_ID);
        SPIDPlot->setObjectName(QStringLiteral("SPIDPlot"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(7);
        sizePolicy2.setHeightForWidth(SPIDPlot->sizePolicy().hasHeightForWidth());
        SPIDPlot->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(SPIDPlot, 0, 0, 1, 1);

        SPIDList = new QPlainTextEdit(SPC_ID);
        SPIDList->setObjectName(QStringLiteral("SPIDList"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(SPIDList->sizePolicy().hasHeightForWidth());
        SPIDList->setSizePolicy(sizePolicy3);
        SPIDList->setMaximumSize(QSize(16777215, 87));

        gridLayout_4->addWidget(SPIDList, 1, 0, 1, 1);

        stackedWidget->addWidget(SPC_ID);
        MinorFrameIDs = new QWidget();
        MinorFrameIDs->setObjectName(QStringLiteral("MinorFrameIDs"));
        gridLayout_6 = new QGridLayout(MinorFrameIDs);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        minorFrameIDPlot = new QwtPlot(MinorFrameIDs);
        minorFrameIDPlot->setObjectName(QStringLiteral("minorFrameIDPlot"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(10);
        sizePolicy4.setHeightForWidth(minorFrameIDPlot->sizePolicy().hasHeightForWidth());
        minorFrameIDPlot->setSizePolicy(sizePolicy4);

        gridLayout_6->addWidget(minorFrameIDPlot, 0, 0, 1, 1);

        MinorFrameIDList = new QPlainTextEdit(MinorFrameIDs);
        MinorFrameIDList->setObjectName(QStringLiteral("MinorFrameIDList"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(1);
        sizePolicy5.setHeightForWidth(MinorFrameIDList->sizePolicy().hasHeightForWidth());
        MinorFrameIDList->setSizePolicy(sizePolicy5);

        gridLayout_6->addWidget(MinorFrameIDList, 1, 0, 1, 1);

        stackedWidget->addWidget(MinorFrameIDs);
        TStamp = new QWidget();
        TStamp->setObjectName(QStringLiteral("TStamp"));
        gridLayout_11 = new QGridLayout(TStamp);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        TimeStampTextBox = new QPlainTextEdit(TStamp);
        TimeStampTextBox->setObjectName(QStringLiteral("TimeStampTextBox"));

        gridLayout_11->addWidget(TimeStampTextBox, 0, 0, 1, 1);

        stackedWidget->addWidget(TStamp);
        HIRS = new QWidget();
        HIRS->setObjectName(QStringLiteral("HIRS"));
        gridLayout_8 = new QGridLayout(HIRS);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_8 = new QLabel(HIRS);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_8->setWordWrap(true);

        gridLayout_8->addWidget(label_8, 0, 0, 1, 1);

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
        gridLayout_7 = new QGridLayout(DCS);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_7 = new QLabel(DCS);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setTextFormat(Qt::RichText);
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_7->setWordWrap(true);

        gridLayout_7->addWidget(label_7, 0, 0, 1, 1);

        stackedWidget->addWidget(DCS);
        DSum = new QWidget();
        DSum->setObjectName(QStringLiteral("DSum"));
        DCSSumTextBrowser = new QPlainTextEdit(DSum);
        DCSSumTextBrowser->setObjectName(QStringLiteral("DCSSumTextBrowser"));
        DCSSumTextBrowser->setGeometry(QRect(0, 0, 751, 561));
        DCSSumTextBrowser->setLineWrapMode(QPlainTextEdit::NoWrap);
        DCSSumTextBrowser->setReadOnly(true);
        stackedWidget->addWidget(DSum);
        CPU = new QWidget();
        CPU->setObjectName(QStringLiteral("CPU"));
        gridLayout_9 = new QGridLayout(CPU);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_9 = new QLabel(CPU);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_9->setWordWrap(true);

        gridLayout_9->addWidget(label_9, 0, 0, 1, 1);

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
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuExit->menuAction());
        menuFile->addAction(actionLoad);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Project Desert Tortoise: NOAA Telemetry Explorer by KE7PHI", 0));
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
        ___qtreewidgetitem7->setText(0, QApplication::translate("MainWindow", "Minor Frame IDs", 0));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem5->child(2);
        ___qtreewidgetitem8->setText(0, QApplication::translate("MainWindow", "Timestamps", 0));
        QTreeWidgetItem *___qtreewidgetitem9 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem9->setText(0, QApplication::translate("MainWindow", "HIRS", 0));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem9->child(0);
        ___qtreewidgetitem10->setText(0, QApplication::translate("MainWindow", "Channels", 0));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem10->child(0);
        ___qtreewidgetitem11->setText(0, QApplication::translate("MainWindow", "All", 0));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem9->child(1);
        ___qtreewidgetitem12->setText(0, QApplication::translate("MainWindow", "Telemetry", 0));
        QTreeWidgetItem *___qtreewidgetitem13 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem13->setText(0, QApplication::translate("MainWindow", "DCS", 0));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem13->child(0);
        ___qtreewidgetitem14->setText(0, QApplication::translate("MainWindow", "DCS Summary", 0));
        QTreeWidgetItem *___qtreewidgetitem15 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem15->setText(0, QApplication::translate("MainWindow", "CPU", 0));
        QTreeWidgetItem *___qtreewidgetitem16 = ___qtreewidgetitem15->child(0);
        ___qtreewidgetitem16->setText(0, QApplication::translate("MainWindow", "CPU A", 0));
        QTreeWidgetItem *___qtreewidgetitem17 = ___qtreewidgetitem15->child(1);
        ___qtreewidgetitem17->setText(0, QApplication::translate("MainWindow", "CPU B", 0));
        QTreeWidgetItem *___qtreewidgetitem18 = treeWidget->topLevelItem(5);
        ___qtreewidgetitem18->setText(0, QApplication::translate("MainWindow", "SEM", 0));
        QTreeWidgetItem *___qtreewidgetitem19 = ___qtreewidgetitem18->child(0);
        ___qtreewidgetitem19->setText(0, QApplication::translate("MainWindow", "MEPED", 0));
        QTreeWidgetItem *___qtreewidgetitem20 = ___qtreewidgetitem18->child(1);
        ___qtreewidgetitem20->setText(0, QApplication::translate("MainWindow", "TED", 0));
        treeWidget->setSortingEnabled(__sortingEnabled);

        groupBox->setTitle(QApplication::translate("MainWindow", "The Good Stuff", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Demodulation Details</span></p><p><span style=\" font-size:10pt;\">The modulation scheme is a non orthagonal BPSK, also known as a preserved carrier PSK.</span></p><p><span style=\" font-size:10pt;\">The phase shift is between -67 and +67 degrees, which allows the carrier frequency to be preserved and tracked using a simple PLL. </span></p><p><span style=\" font-size:10pt;\">The bits are manchester coded for ease of clock recovery, which means there are two symbols per bit. </span></p><p><span style=\" font-size:10pt; font-weight:600;\">Summary: </span><span style=\" font-size:10pt;\">Dsplays the results of the demodulation</span></p><p><span style=\" font-size:10pt; font-weight:600;\">Raw Hex: </span><span style=\" font-size:10pt;\">Displays the raw minor frames in hex format for visualization or copy/paste into another application</span></p><p><span style=\" font-size:10pt; font-weight:600;\">Parity: </span><span style=\" font-size:10pt;"
                        "\">Calculates the errors in the bitstream in 5 chunks and verifies that there are at least an even or odd number of errors in each chunk.</span></p><p><span style=\" font-size:10pt;\"><br/></span></p></body></html>", 0));

        const bool __sortingEnabled1 = summaryTable->isSortingEnabled();
        summaryTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem = summaryTable->item(0, 0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Minor Frames", 0));
        QTableWidgetItem *___qtablewidgetitem1 = summaryTable->item(1, 0);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Recording Length", 0));
        QTableWidgetItem *___qtablewidgetitem2 = summaryTable->item(2, 0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Spacecraft ID", 0));
        summaryTable->setSortingEnabled(__sortingEnabled1);

        label_3->setText(QApplication::translate("MainWindow", "RawHex", 0));
        label_4->setText(QApplication::translate("MainWindow", "Parity", 0));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Spacecraft</span></p><p><span style=\" font-size:10pt;\">There are currently three operational (as of Sept 2016) NOAA POES satellites that transmit a direct sounder broadcast on 137.350 Mhz and 137.770 Mhz</span></p><p><span style=\" font-size:10pt; font-weight:600;\">NOAA-15</span><span style=\" font-size:10pt;\"> : 137.350 Mhz </span></p><p><span style=\" font-size:10pt; font-weight:600;\">NOAA-18</span><span style=\" font-size:10pt;\"> : 137.350 Mhz</span></p><p><span style=\" font-size:10pt; font-weight:600;\">NOAA-19</span><span style=\" font-size:10pt;\"> : 137.770 Mhz</span></p><p><span style=\" font-size:10pt;\">Sometimes NOAA-15 and NOAA-18 orbits overlap significantly resulting in overlapping transmissions, which is frustrating. </span></p><p><span style=\" font-size:10pt; font-weight:600;\">Spacecraft ID: </span><span style=\" font-size:10pt;\">Every minor frame contains a spacecraft ID, which is needed to properly decode the fr"
                        "ames as NOAA-15/18 is slightly different than NOAA-19 </span></p><p><span style=\" font-size:10pt; font-weight:600;\">Minor Frame ID: </span><span style=\" font-size:10pt;\">Every minor frame contains an ID which counts between 0 and 319 and is required to properly decommutate the subcommutated instrument data. It is also a useful plot of data quality.</span></p><p><span style=\" font-size:10pt; font-weight:600;\">Timestamps: </span><span style=\" font-size:10pt;\">Every major frame (minor frame 0/320) contains a day number and a clock in milliseconds. The data is useful for ephemris calculations, and the T(0) time is required for initializing the DCS geolocation model.</span></p></body></html>", 0));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">HIRS</span><span style=\" font-size:10pt; font-weight:600;\"> - High Resolution Infrared Sounder</span></p><p><span style=\" font-size:10pt;\">The High Resolution Infrared Sounder subsystem scans the earth view with a constant velocity scanning mirror which directs the view orthagonal to the path of travel of the spacecraft.</span></p><p><span style=\" font-size:10pt;\">The HIRS instrument measures spectral intensity over 20 different wavelengths. </span></p><p><span style=\" font-size:10pt; font-weight:600;\">Channels: </span><span style=\" font-size:10pt;\">Displays the per-channel data.</span></p><p><span style=\" font-size:10pt;\"><br/></span></p></body></html>", 0));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">DCS - Data Collection System</span></p><p><span style=\" font-size:10pt;\">The DCS subsystem captures packets from ground based transmitters deployed on a variety of environmental monitoring stations.</span></p><p><span style=\" font-size:10pt;\">Such stations include earth reference stations, wildlife tracking collars, fishing vessel trreaty enforcement transmitters, among (many) others. </span></p><p><span style=\" font-size:10pt;\">NOAA-19 contains an updated subsystem referred to as ADCS (Advanced DCS) which does use a slightly different packet format.</span></p><p><span style=\" font-size:10pt; font-weight:600;\">Summary: </span><span style=\" font-size:10pt;\">Dsplays a list of all heard stations and their payloads, sorted by number of recieved packets.</span></p><p><span style=\" font-size:10pt;\"><br/></span></p></body></html>", 0));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">CPU Telemetry</span></p><p><br/></p><p><span style=\" font-size:10pt;\">CPU Telemetry is still being reverse engineered and is probably impossible to completely understand given the amount of possible magic data</span></p></body></html>", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuExit->setTitle(QApplication::translate("MainWindow", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
