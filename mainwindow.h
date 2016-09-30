#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTreeWidgetItem>

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
    //QByteArray minorFrame[103];
    QList <float> minorFrameTimes;
    void displayMinorFramesHex();
    void displaySpaceCraftID();
};

#endif // MAINWINDOW_H
