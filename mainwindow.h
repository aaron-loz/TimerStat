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
private:
    Ui::MainWindow *ui;
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

        for(int i=num*60;i>0;i--)
        {
            qDebug()<<i;
            sleepTimer::sleep(10);
            qDebug()<<"have ui element update";
        }
        qDebug()<<"Timer Done!";
    }
    void declareDeleted()
    {qDebug()<<"Thread deleted!";}
signals:
};

#endif // MAINWINDOW_H
