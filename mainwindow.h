#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsWidget>
#include <QGraphicsItem>
#include <QLabel>
#include <QThread>
#include <QDebug>
#include <QFileDialog>
#include "fileeditdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString tempText;//tempText logs the file so far in current session
    QString openFileText;//currentText shows what is in file being opened by OpenFile()
public slots:
    void changeLCD(int i);
private slots:

    void on_lineEdit_returnPressed();

    void on_actionE_xit_triggered();

    void on_actionO_pen_triggered();

    void on_actionS_ave_triggered();

    void on_actionS_ave_As_triggered();

    void on_actionA_bout_triggered();

    void ReadFile(const QString &fileName);
    void writeFile(const QString &fileName);
    void on_actionNew_triggered();

    void on_spinBox_editingFinished();
    void on_spinBox_valueChanged(int &arg1);
    void on_actionV_iew_triggered();

    void on_actionE_dit_triggered();

private:

    Ui::MainWindow *ui;
    QPixmap pix0 =(":/TimerStat/images/images/clockHandTimerDefault.png");
    QPixmap pix1 =(":/TimerStat/images/images/clockHandTimer1.png");
    QPixmap pix2 =(":/TimerStat/images/images/clockHandTimer2.png");
    QPixmap pix3 =(":/TimerStat/images/images/clockHandTimer3.png");
    QPixmap pix4 =(":/TimerStat/images/images/clockHandTimer4.png");
    QPixmap pix5 =(":/TimerStat/images/images/clockHandTimer5.png");
    QPixmap pix6 =(":/TimerStat/images/images/clockHandTimer6.png");
    QPixmap pix7 =(":/TimerStat/images/images/clockHandTimer7.png");
    QPixmap pix8 =(":/TimerStat/images/images/clockHandTimer8.png");
    QPixmap pix9 =(":/TimerStat/images/images/clockHandTimer9.png");
    QPixmap pix10 = (":/TimerStat/images/images/clockHandTimer10.png");
    QPixmap pix11 = (":/TimerStat/images/images/clockHandTimer11.png");
    QPixmap pix12 = (":/TimerStat/images/images/clockHandTimer12.png");
    QFile file;
    fileEditDialog *fileDialog;
};

class sleepTimer: public QThread{
Q_OBJECT
public:
    int num;
public slots:
    static void sleep(unsigned long secs){
        QThread::sleep(secs);
    }
    void run()
    {//create result, and creates signal

        for(int i=num*60;i>=0;i-=5)
        {//counts the seconds
            qDebug()<<i;
            emit changeTime(i);
            if(i>0)
            sleepTimer::sleep(5);
        }
        qDebug()<<"Timer Done!";
    }
signals:
    void changeTime(int i);
};
#endif // MAINWINDOW_H
