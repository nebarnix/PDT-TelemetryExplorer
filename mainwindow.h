#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTreeWidgetItem>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void open();
    void updateViewOnTreeClick(QTreeWidgetItem *item, int column);
//void QTreeWidget::itemDoubleClicked(QTreeWidgetItem *item, int column)

private:
    Ui::MainWindow *ui;

    QStringList minorFramesHex;

    QByteArrayList minorFramesDec;

    QList <float> minorFrameTimes;
    QList <int> knownGoodFrameIndices;
    QList <unsigned int> minorFrameIDList;
    QList <float> timeStampList;
    QList <unsigned long> timeStampTimeList;

    unsigned int numFrames;
    unsigned int numGoodFrames;
    unsigned char SFID;

    void displayMinorFramesHex();
    void displayMinorFramesDec();
    void convertMinorFramesHex2Dec();
    void displaySpaceCraftID();
    void plotMinorFrameID();
    void checkParity();
    void getTimeStamps();
    void populateSummaryTable();
    void clearAll();


};

#endif // MAINWINDOW_H
