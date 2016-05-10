#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage myImage;
    setWindowTitle(tr("Clock In!"));
    myImage.load(":/images/clock.png");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_returnPressed()
{//This will add on to a project list once I set up a file
    QString project = ui->lineEdit->text();
    qDebug()<<project;
}

void MainWindow::on_actionE_xit_triggered()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit", "Are you sure you wanna Quit?",
                                  QMessageBox::Yes | QMessageBox::No);
    switch(reply)
    {
    case QMessageBox::Yes:
        QCoreApplication::exit();
        break;
    default:
        break;
    }
}

void MainWindow::on_actionA_bout_triggered()
{
    QMessageBox::about(this, "About...", "\nClock In!\nCreated using Qt 5.4\nAaron Lopez circa 2016.");
}

void MainWindow::on_actionO_pen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this);
    if(!filename.isEmpty())
    {
        //ReadFile();
    }
}

void MainWindow::on_actionS_ave_triggered()
{

}

void MainWindow::on_actionS_ave_As_triggered()
{
//opens a dialog that asks for line edit input. Then Input becomes filename
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save file"),
                                                    QDir::currentPath(), tr("Text FIle (*.txt)"));
    if(!fileName.isNull())
    {
        this->WriteFile(fileName);
    }
}

void MainWindow::ReadFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this, tr("Unable to open"),
                                 file.errorString());
        return;
    }
    else
    {
        //figure out what you want to do once you open the file.
        //Maybe tells person it is opened and current written time.
    }
}

void MainWindow::WriteFile(const QString &fileName)
{//This will write into a .txt file the project and the amount of time, in hours.
    //Such that The first line says "Projects *Spacex4* Amount of time". Then a list of projects and the numbers
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }
    QString textstream ="Projects    Time\n---------------------------" ;
    //textstream = textstream + ui->lineEdit->text();
    QTextStream out(&file);
    out<<textstream;

}
