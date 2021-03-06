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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwt_counter.h"
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
    QGridLayout *gridLayout_16;
    QTreeWidget *treeWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *Demod;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLabel *label_2;
    QWidget *Summary;
    QTableWidget *summaryTable;
    QWidget *RawHex;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QPlainTextEdit *minorFrameBrowser;
    QWidget *Parity;
    QGridLayout *gridLayout_2;
    QPlainTextEdit *parityTextEdit;
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
    QGridLayout *gridLayout_18;
    QListWidget *HIRSRawHex;
    QLabel *label_26;
    QWidget *HTlm;
    QGridLayout *gridLayout_17;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_17;
    QwtCounter *Counter;
    QwtPlot *HIRSRawPlot;
    QwtPlot *HIRSElemPlot;
    QwtPlot *HIRSScanPosPlot;
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
    QGridLayout *gridLayout_12;
    QLabel *label_4;
    QWidget *MEPED;
    QGridLayout *gridLayout_15;
    QLabel *label_10;
    QLabel *label_11;
    QwtPlot *MEPED0EPlot;
    QwtPlot *MEPED90EPlot;
    QLabel *label_12;
    QLabel *label_13;
    QwtPlot *MEPED0PPlot;
    QwtPlot *MEPED90PPlot;
    QLabel *label_6;
    QwtPlot *MEPEDOmniPPlot;
    QWidget *TED;
    QGridLayout *gridLayout_14;
    QLabel *label_14;
    QLabel *label_15;
    QwtPlot *TEDLowPlot;
    QwtPlot *TEDHighPlot;
    QLabel *label_16;
    QLabel *label_18;
    QwtPlot *TEDMaxDEPlot;
    QwtPlot *TEDEMaxDEPlot;
    QwtPlot *TEDBackPlot;
    QLabel *label_19;
    QWidget *TED2;
    QGridLayout *gridLayout_13;
    QLabel *label_20;
    QLabel *label_21;
    QwtPlot *TEDFluxSpecPlotE1;
    QwtPlot *TEDFluxSpecPlotE2;
    QLabel *label_22;
    QLabel *label_23;
    QwtPlot *TEDFluxSpecPlotP1;
    QwtPlot *TEDFluxSpecPlotP2;
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
        TreeBox->setMinimumSize(QSize(200, 0));
        TreeBox->setMaximumSize(QSize(200, 16777215));
        TreeBox->setBaseSize(QSize(500, 0));
        gridLayout_16 = new QGridLayout(TreeBox);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
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
        new QTreeWidgetItem(__qtreewidgetitem6);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setWordWrap(true);
        treeWidget->setExpandsOnDoubleClick(false);
        treeWidget->header()->setCascadingSectionResizes(true);
        treeWidget->header()->setProperty("showSortIndicator", QVariant(false));
        treeWidget->header()->setStretchLastSection(true);

        gridLayout_16->addWidget(treeWidget, 0, 0, 1, 1);


        horizontalLayout->addWidget(TreeBox);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
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
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(Demod);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../vmshare/POES/POES_view_spectrumsm.png")));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

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
        gridLayout_2 = new QGridLayout(Parity);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        parityTextEdit = new QPlainTextEdit(Parity);
        parityTextEdit->setObjectName(QStringLiteral("parityTextEdit"));

        gridLayout_2->addWidget(parityTextEdit, 0, 0, 1, 1);

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
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(7);
        sizePolicy3.setHeightForWidth(SPIDPlot->sizePolicy().hasHeightForWidth());
        SPIDPlot->setSizePolicy(sizePolicy3);
        SPIDPlot->setAutoReplot(false);

        gridLayout_4->addWidget(SPIDPlot, 0, 0, 1, 1);

        SPIDList = new QPlainTextEdit(SPC_ID);
        SPIDList->setObjectName(QStringLiteral("SPIDList"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(SPIDList->sizePolicy().hasHeightForWidth());
        SPIDList->setSizePolicy(sizePolicy4);
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
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(10);
        sizePolicy5.setHeightForWidth(minorFrameIDPlot->sizePolicy().hasHeightForWidth());
        minorFrameIDPlot->setSizePolicy(sizePolicy5);

        gridLayout_6->addWidget(minorFrameIDPlot, 0, 0, 1, 1);

        MinorFrameIDList = new QPlainTextEdit(MinorFrameIDs);
        MinorFrameIDList->setObjectName(QStringLiteral("MinorFrameIDList"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(1);
        sizePolicy6.setHeightForWidth(MinorFrameIDList->sizePolicy().hasHeightForWidth());
        MinorFrameIDList->setSizePolicy(sizePolicy6);

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
        TimeStampTextBox->setLineWrapMode(QPlainTextEdit::NoWrap);

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
        gridLayout_18 = new QGridLayout(HChanAll);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        HIRSRawHex = new QListWidget(HChanAll);
        HIRSRawHex->setObjectName(QStringLiteral("HIRSRawHex"));

        gridLayout_18->addWidget(HIRSRawHex, 1, 0, 1, 1);

        label_26 = new QLabel(HChanAll);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_18->addWidget(label_26, 0, 0, 1, 1);

        stackedWidget->addWidget(HChanAll);
        HTlm = new QWidget();
        HTlm->setObjectName(QStringLiteral("HTlm"));
        gridLayout_17 = new QGridLayout(HTlm);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        label_24 = new QLabel(HTlm);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_17->addWidget(label_24, 2, 0, 1, 1);

        label_25 = new QLabel(HTlm);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_17->addWidget(label_25, 0, 0, 1, 1);

        label_17 = new QLabel(HTlm);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_17->addWidget(label_17, 5, 0, 1, 1);

        Counter = new QwtCounter(HTlm);
        Counter->setObjectName(QStringLiteral("Counter"));
        Counter->setMaximumSize(QSize(150, 16777215));
        Counter->setMinimum(2);
        Counter->setMaximum(63);
        Counter->setSingleStep(1);

        gridLayout_17->addWidget(Counter, 5, 1, 1, 1);

        HIRSRawPlot = new QwtPlot(HTlm);
        HIRSRawPlot->setObjectName(QStringLiteral("HIRSRawPlot"));
        HIRSRawPlot->setMinimumSize(QSize(10, 10));

        gridLayout_17->addWidget(HIRSRawPlot, 6, 0, 1, 2);

        HIRSElemPlot = new QwtPlot(HTlm);
        HIRSElemPlot->setObjectName(QStringLiteral("HIRSElemPlot"));
        HIRSElemPlot->setMinimumSize(QSize(0, 10));

        gridLayout_17->addWidget(HIRSElemPlot, 3, 0, 1, 2);

        HIRSScanPosPlot = new QwtPlot(HTlm);
        HIRSScanPosPlot->setObjectName(QStringLiteral("HIRSScanPosPlot"));
        HIRSScanPosPlot->setMinimumSize(QSize(10, 10));

        gridLayout_17->addWidget(HIRSScanPosPlot, 1, 0, 1, 2);

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
        gridLayout_12 = new QGridLayout(SEM);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        label_4 = new QLabel(SEM);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_4->setWordWrap(true);

        gridLayout_12->addWidget(label_4, 0, 0, 1, 1);

        stackedWidget->addWidget(SEM);
        MEPED = new QWidget();
        MEPED->setObjectName(QStringLiteral("MEPED"));
        MEPED->setEnabled(true);
        MEPED->setBaseSize(QSize(744, 588));
        gridLayout_15 = new QGridLayout(MEPED);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        label_10 = new QLabel(MEPED);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_15->addWidget(label_10, 0, 0, 1, 1);

        label_11 = new QLabel(MEPED);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_15->addWidget(label_11, 0, 1, 1, 1);

        MEPED0EPlot = new QwtPlot(MEPED);
        MEPED0EPlot->setObjectName(QStringLiteral("MEPED0EPlot"));
        MEPED0EPlot->setMinimumSize(QSize(10, 10));
        MEPED0EPlot->setFrameShape(QFrame::NoFrame);
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        MEPED0EPlot->setCanvasBackground(brush);

        gridLayout_15->addWidget(MEPED0EPlot, 1, 0, 1, 1);

        MEPED90EPlot = new QwtPlot(MEPED);
        MEPED90EPlot->setObjectName(QStringLiteral("MEPED90EPlot"));
        MEPED90EPlot->setMinimumSize(QSize(10, 10));
        MEPED90EPlot->setFrameShape(QFrame::NoFrame);
        MEPED90EPlot->setCanvasBackground(brush);

        gridLayout_15->addWidget(MEPED90EPlot, 1, 1, 1, 1);

        label_12 = new QLabel(MEPED);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_15->addWidget(label_12, 2, 0, 1, 1);

        label_13 = new QLabel(MEPED);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_15->addWidget(label_13, 2, 1, 1, 1);

        MEPED0PPlot = new QwtPlot(MEPED);
        MEPED0PPlot->setObjectName(QStringLiteral("MEPED0PPlot"));
        MEPED0PPlot->setMinimumSize(QSize(10, 10));
        MEPED0PPlot->setFrameShape(QFrame::NoFrame);
        MEPED0PPlot->setCanvasBackground(brush);

        gridLayout_15->addWidget(MEPED0PPlot, 3, 0, 1, 1);

        MEPED90PPlot = new QwtPlot(MEPED);
        MEPED90PPlot->setObjectName(QStringLiteral("MEPED90PPlot"));
        MEPED90PPlot->setMinimumSize(QSize(10, 10));
        MEPED90PPlot->setFrameShape(QFrame::NoFrame);
        MEPED90PPlot->setCanvasBackground(brush);

        gridLayout_15->addWidget(MEPED90PPlot, 3, 1, 1, 1);

        label_6 = new QLabel(MEPED);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_15->addWidget(label_6, 4, 0, 1, 1);

        MEPEDOmniPPlot = new QwtPlot(MEPED);
        MEPEDOmniPPlot->setObjectName(QStringLiteral("MEPEDOmniPPlot"));
        MEPEDOmniPPlot->setMinimumSize(QSize(10, 10));
        MEPEDOmniPPlot->setFrameShape(QFrame::NoFrame);
        MEPEDOmniPPlot->setCanvasBackground(brush);

        gridLayout_15->addWidget(MEPEDOmniPPlot, 5, 0, 1, 2);

        stackedWidget->addWidget(MEPED);
        TED = new QWidget();
        TED->setObjectName(QStringLiteral("TED"));
        gridLayout_14 = new QGridLayout(TED);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        label_14 = new QLabel(TED);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(0, 21));

        gridLayout_14->addWidget(label_14, 0, 0, 1, 1);

        label_15 = new QLabel(TED);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(0, 21));

        gridLayout_14->addWidget(label_15, 0, 1, 1, 1);

        TEDLowPlot = new QwtPlot(TED);
        TEDLowPlot->setObjectName(QStringLiteral("TEDLowPlot"));
        TEDLowPlot->setMinimumSize(QSize(10, 10));
        TEDLowPlot->setCanvasBackground(brush);

        gridLayout_14->addWidget(TEDLowPlot, 1, 0, 1, 1);

        TEDHighPlot = new QwtPlot(TED);
        TEDHighPlot->setObjectName(QStringLiteral("TEDHighPlot"));
        TEDHighPlot->setMinimumSize(QSize(10, 10));
        TEDHighPlot->setCanvasBackground(brush);

        gridLayout_14->addWidget(TEDHighPlot, 1, 1, 1, 1);

        label_16 = new QLabel(TED);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(0, 21));

        gridLayout_14->addWidget(label_16, 2, 0, 1, 1);

        label_18 = new QLabel(TED);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMinimumSize(QSize(0, 21));

        gridLayout_14->addWidget(label_18, 2, 1, 1, 1);

        TEDMaxDEPlot = new QwtPlot(TED);
        TEDMaxDEPlot->setObjectName(QStringLiteral("TEDMaxDEPlot"));
        TEDMaxDEPlot->setMinimumSize(QSize(10, 10));
        TEDMaxDEPlot->setCanvasBackground(brush);

        gridLayout_14->addWidget(TEDMaxDEPlot, 3, 0, 1, 1);

        TEDEMaxDEPlot = new QwtPlot(TED);
        TEDEMaxDEPlot->setObjectName(QStringLiteral("TEDEMaxDEPlot"));
        TEDEMaxDEPlot->setMinimumSize(QSize(10, 10));
        TEDEMaxDEPlot->setCanvasBackground(brush);

        gridLayout_14->addWidget(TEDEMaxDEPlot, 3, 1, 1, 1);

        TEDBackPlot = new QwtPlot(TED);
        TEDBackPlot->setObjectName(QStringLiteral("TEDBackPlot"));
        TEDBackPlot->setMinimumSize(QSize(10, 10));
        TEDBackPlot->setCanvasBackground(brush);

        gridLayout_14->addWidget(TEDBackPlot, 5, 0, 1, 2);

        label_19 = new QLabel(TED);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMinimumSize(QSize(0, 21));

        gridLayout_14->addWidget(label_19, 4, 0, 1, 1);

        stackedWidget->addWidget(TED);
        TED2 = new QWidget();
        TED2->setObjectName(QStringLiteral("TED2"));
        gridLayout_13 = new QGridLayout(TED2);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        label_20 = new QLabel(TED2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMinimumSize(QSize(10, 21));

        gridLayout_13->addWidget(label_20, 0, 0, 1, 1);

        label_21 = new QLabel(TED2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMinimumSize(QSize(10, 21));

        gridLayout_13->addWidget(label_21, 0, 1, 1, 1);

        TEDFluxSpecPlotE1 = new QwtPlot(TED2);
        TEDFluxSpecPlotE1->setObjectName(QStringLiteral("TEDFluxSpecPlotE1"));
        TEDFluxSpecPlotE1->setMinimumSize(QSize(10, 10));
        TEDFluxSpecPlotE1->setBaseSize(QSize(10, 10));
        TEDFluxSpecPlotE1->setCanvasBackground(brush);

        gridLayout_13->addWidget(TEDFluxSpecPlotE1, 1, 0, 1, 1);

        TEDFluxSpecPlotE2 = new QwtPlot(TED2);
        TEDFluxSpecPlotE2->setObjectName(QStringLiteral("TEDFluxSpecPlotE2"));
        TEDFluxSpecPlotE2->setMinimumSize(QSize(10, 10));
        TEDFluxSpecPlotE2->setBaseSize(QSize(10, 10));
        TEDFluxSpecPlotE2->setCanvasBackground(brush);

        gridLayout_13->addWidget(TEDFluxSpecPlotE2, 1, 1, 1, 1);

        label_22 = new QLabel(TED2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMinimumSize(QSize(50, 21));

        gridLayout_13->addWidget(label_22, 2, 0, 1, 1);

        label_23 = new QLabel(TED2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMinimumSize(QSize(50, 21));

        gridLayout_13->addWidget(label_23, 2, 1, 1, 1);

        TEDFluxSpecPlotP1 = new QwtPlot(TED2);
        TEDFluxSpecPlotP1->setObjectName(QStringLiteral("TEDFluxSpecPlotP1"));
        TEDFluxSpecPlotP1->setMinimumSize(QSize(10, 10));
        TEDFluxSpecPlotP1->setBaseSize(QSize(10, 10));
        TEDFluxSpecPlotP1->setCanvasBackground(brush);

        gridLayout_13->addWidget(TEDFluxSpecPlotP1, 3, 0, 1, 1);

        TEDFluxSpecPlotP2 = new QwtPlot(TED2);
        TEDFluxSpecPlotP2->setObjectName(QStringLiteral("TEDFluxSpecPlotP2"));
        TEDFluxSpecPlotP2->setMinimumSize(QSize(10, 10));
        TEDFluxSpecPlotP2->setBaseSize(QSize(10, 10));
        TEDFluxSpecPlotP2->setCanvasBackground(brush);

        gridLayout_13->addWidget(TEDFluxSpecPlotP2, 3, 1, 1, 1);

        stackedWidget->addWidget(TED2);

        verticalLayout->addWidget(stackedWidget);


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
        menuExit->setEnabled(false);
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuExit->menuAction());
        menuFile->addAction(actionLoad);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(10);


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
        QTreeWidgetItem *___qtreewidgetitem21 = ___qtreewidgetitem18->child(2);
        ___qtreewidgetitem21->setText(0, QApplication::translate("MainWindow", "TED2", 0));
        treeWidget->setSortingEnabled(__sortingEnabled);

        groupBox->setTitle(QApplication::translate("MainWindow", "The Good Stuff", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Demodulation Details</span></p><p><span style=\" font-size:10pt;\">The modulation scheme is a non orthagonal BPSK, also known as a preserved carrier PSK.</span></p><p><span style=\" font-size:10pt;\">The phase shift is between -67 and +67 degrees, which allows the carrier frequency to be preserved and tracked using a simple PLL. </span></p><p><span style=\" font-size:10pt;\">The bits are manchester coded for ease of clock recovery, which means there are two symbols per bit. </span></p><p><span style=\" font-size:10pt; font-weight:600;\">Summary: </span><span style=\" font-size:10pt;\">Dsplays the results of the demodulation</span></p><p><span style=\" font-size:10pt; font-weight:600;\">Raw Hex: </span><span style=\" font-size:10pt;\">Displays the raw minor frames in hex format for visualization or copy/paste into another application</span></p><p><span style=\" font-size:10pt; font-weight:600;\">Parity: </span><span style=\" font-size:10pt;"
                        "\">Calculates the errors in the bitstream in 5 chunks and verifies that there are at least an even or odd number of errors in each chunk.</span></p><p><span style=\" font-size:10pt;\"><br/></span></p></body></html>", 0));
        label_2->setText(QString());

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
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Spacecraft</span></p><p><span style=\" font-size:10pt;\">There are currently three operational (as of Sept 2016) NOAA POES satellites that transmit a direct sounder broadcast on 137.350 Mhz and 137.770 Mhz</span></p><p><span style=\" font-size:10pt; font-weight:600;\">NOAA-15</span><span style=\" font-size:10pt;\"> : 137.350 Mhz </span></p><p><span style=\" font-size:10pt; font-weight:600;\">NOAA-18</span><span style=\" font-size:10pt;\"> : 137.350 Mhz</span></p><p><span style=\" font-size:10pt; font-weight:600;\">NOAA-19</span><span style=\" font-size:10pt;\"> : 137.770 Mhz</span></p><p><span style=\" font-size:10pt;\">Sometimes NOAA-15 and NOAA-18 orbits overlap significantly resulting in overlapping transmissions, which is frustrating. </span></p><p><span style=\" font-size:10pt; font-weight:600;\">Spacecraft ID: </span><span style=\" font-size:10pt;\">Every minor frame contains a spacecraft ID, which is needed to properly decode the fr"
                        "ames as NOAA-15/18 is slightly different than NOAA-19 </span></p><p><span style=\" font-size:10pt; font-weight:600;\">Minor Frame ID: </span><span style=\" font-size:10pt;\">Every minor frame contains an ID which counts between 0 and 319 and is required to properly decommutate the subcommutated instrument data. It is also a useful plot of data quality.</span></p><p><span style=\" font-size:10pt; font-weight:600;\">Timestamps: </span><span style=\" font-size:10pt;\">Every major frame (minor frame 0/320) contains a day number and a clock in milliseconds. The data is useful for ephemris calculations, and the T(0) time is required for initializing the DCS geolocation model.</span></p></body></html>", 0));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">HIRS</span><span style=\" font-size:10pt; font-weight:600;\"> - High Resolution Infrared Sounder</span></p><p><span style=\" font-size:10pt;\">The High Resolution Infrared Sounder subsystem scans the earth view with a constant velocity scanning mirror which directs the view orthagonal to the path of travel of the spacecraft.</span></p><p><span style=\" font-size:10pt;\">The HIRS instrument measures spectral intensity over 20 different wavelengths. </span></p><p><span style=\" font-size:10pt; font-weight:600;\">Channels: </span><span style=\" font-size:10pt;\">Displays the per-channel data.</span></p><p><span style=\" font-size:10pt;\"><br/></span></p></body></html>", 0));
        label_26->setText(QApplication::translate("MainWindow", "HIRS Raw Hex Frames : sign converted data", 0));
        label_24->setText(QApplication::translate("MainWindow", "Element Number", 0));
        label_25->setText(QApplication::translate("MainWindow", "Mirror Scan Position", 0));
        label_17->setText(QApplication::translate("MainWindow", "Element X Data", 0));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">DCS - Data Collection System</span></p><p><span style=\" font-size:10pt;\">The DCS subsystem captures packets from ground based transmitters deployed on a variety of environmental monitoring stations.</span></p><p><span style=\" font-size:10pt;\">Such stations include earth reference stations, wildlife tracking collars, fishing vessel trreaty enforcement transmitters, among (many) others. </span></p><p><span style=\" font-size:10pt;\">NOAA-19 contains an updated subsystem referred to as ADCS (Advanced DCS) which does use a slightly different packet format.</span></p><p><span style=\" font-size:10pt; font-weight:600;\">Summary: </span><span style=\" font-size:10pt;\">Dsplays a list of all heard stations and their payloads, sorted by number of recieved packets.</span></p><p><span style=\" font-size:10pt;\"><br/></span></p></body></html>", 0));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">CPU Telemetry</span></p><p><br/></p><p><span style=\" font-size:10pt;\">CPU Telemetry is still being reverse engineered and is probably impossible to completely understand given the amount of possible magic data</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">SEM - </span></p><p><span style=\" font-size:10pt;\">The SEM package contains two instruments for monitoring the space weather charged particle environemnt. The neat thing about the MEPED instrument is that one can use this data (perhaps along with epheris queries) to discover if there is an aurora borealis visible, and how intense, over one's current location. </span></p><p><span style=\" font-size:10pt; font-weight:600;\">MEPED </span><span style=\" font-size:10pt;\">- MEPED Digital A data consists of six directional proton measurements and three directional electron measurements for each of two directions of incidence (0 and 90 degrees) and four omni-directional proton measurements. All but the two highest energy omni-directional proton measurements are read out every two seconds. The two highest energy omnidirectional proton measurements are read out every four seconds. The MEPED Digital A data and readout rates are summarized in Table"
                        " 4.3.4.2-2.</span></p><p><span style=\" font-size:10pt; font-weight:600;\">TED - </span><span style=\" font-size:10pt;\">TED Digital A data consists of a 0.05 to 1 keV partial energy flux measurement, a 1 to 20 keV partial energy flux measurement, maximum differential energy fluxes, four-point differential energy spectra and background measurements for electrons and protons, each at two angles of incidence (0 and 30 degrees).</span></p></body></html>", 0));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">0 Deg Electron Count</span></p></body></html>", 0));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">90 Deg Electron Count</span></p></body></html>", 0));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">0 Deg Proton Count</span></p></body></html>", 0));
        label_13->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">90 Deg Proton Count</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Omni-Directional Proton Count</span></p></body></html>", 0));
        label_14->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">0.05-1 keV Partial Energy Flux</span></p></body></html>", 0));
        label_15->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">2-10 keV Partial Energy Flux</span></p></body></html>", 0));
        label_16->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">Maximum Differential Energy Flux</span></p></body></html>", 0));
        label_18->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">Energy of Maximum Differential Energy Flux</span></p></body></html>", 0));
        label_19->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Background</span></p></body></html>", 0));
        label_20->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">0 Degree Electron Spectrum</span></p></body></html>", 0));
        label_21->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">30 Degree Electron Spectrum</span></p></body></html>", 0));
        label_22->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">0 Degree Proton Spectrum</span></p></body></html>", 0));
        label_23->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">30 Degree Proton Spectrum</span></p></body></html>", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuExit->setTitle(QApplication::translate("MainWindow", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
