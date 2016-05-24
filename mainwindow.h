#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsWidget>
#include <QGraphicsItem>
#include <QLabel>
#include <QThread>
#include <QDebug>

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
    bool saveOpened;
private slots:

    void on_lineEdit_returnPressed();

    void on_actionE_xit_triggered();

    void on_actionO_pen_triggered();

    void on_actionS_ave_triggered();

    void on_actionS_ave_As_triggered();

    void on_actionA_bout_triggered();

    void ReadFile(const QString &fileName);
    void WriteFile(const QString &fileName);
    void on_actionNew_triggered();

    void on_spinBox_editingFinished();
    void on_spinBox_valueChanged(int &arg1);

private:
    //!This all depends on a specific file location. Need to change that.
    //! might need to create new file just to deal with this pixmap stuff.
    //! or function that looks for current file, and has it change the pixmaps accordingly
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

        for(int i=num*60;i>0;i-=10)
        {
            qDebug()<<i;
            sleepTimer::sleep(10);
        }
        qDebug()<<"Timer Done!";
    }
    void declareDeleted()
    {qDebug()<<"Thread deleted!";}
signals:
};

#endif // MAINWINDOW_H
