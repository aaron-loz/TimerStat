#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsWidget>
#include <QGraphicsItem>
#include <QLabel>
#include <QTimer>
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
    int number;
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
private:
    Ui::MainWindow *ui;
    QTimer* timer;
};

class sleepTimer: public QThread{
Q_OBJECT
private:
    int num;
    int debugThread = 0;
public:
    void setnum(int &n){num=n;}
public slots:
    static void sleep(unsigned long secs){
        QThread::sleep(secs);
        //stops thread once the QTimer finishes. until, next run.
    }
    void run()
    {//create result, and creates signal
        debugThread++;
        qDebug()<<debugThread;
        for(int i=num;i>0;i--)
        {
            qDebug()<<i;
            sleepTimer::sleep(3);
        }//change back to 60
        qDebug()<<"Timer Done!";
    }
signals:
    void changeSpinBox();
};

#endif // MAINWINDOW_H
