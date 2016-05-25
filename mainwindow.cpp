#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("Clock In!"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    //Closes the currently open file.Restarts openFileText and tempText
    tempText.remove(0,tempText.size());
    openFileText.remove(0,openFileText.size());
    ui->lineEdit->clear();
}

void MainWindow::on_lineEdit_returnPressed()
{//This will add on to a project list once I set up a file
    tempText +="\n"+ui->lineEdit->text()+"::";
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
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                   QDir::currentPath(), tr("Text File(*.txt)"));
    if(!fileName.isNull())
    {
        this->ReadFile(fileName);
    }
}

void MainWindow::on_actionS_ave_triggered()
{
    if(file.isOpen())
    {//need another function to write or do if statments in writeFile()
        this->WriteFile(file.fileName());
    }
    else
    {
        this->on_actionS_ave_As_triggered();
    }
}

void MainWindow::on_actionS_ave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save file"),
                                                    QDir::currentPath(), tr("Text FIle (*.txt)"));
    if(!fileName.isNull())
    {
        this->WriteFile(fileName);
    }
}

void MainWindow::ReadFile(const QString &fileName)
{
    file.setFileName(fileName);
    if(!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        QMessageBox::information(this, tr("Unable to open"),
                                 file.errorString());
        return;
    }
    QTextStream in(&file);
    openFileText=in.readAll();
    QMessageBox::about(this, "current Stats!", openFileText);
        //figure out what you want to do once you open the file.
        //Maybe tells person it is opened and current written time.
}

void MainWindow::WriteFile(const QString &fileName)
{//This will write into a .txt file the project and the amount of time, in hours.
    //Such that The first line says "Projects *Spacex4* Amount of time". Then a list of projects and the numbers
    if(file.isOpen())
    {

    }
    else{
    file.setFileName(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }
    QString textstream ="Projects    Time\n---------------------------\n" ;
    //!Add in a dummy QString that logs time used and project titles, which will then write into out.
    QTextStream out(&file);
    out<<textstream;
    out<<tempText;
    }
}

void MainWindow::on_spinBox_editingFinished()
{
    sleepTimer *thread = new sleepTimer();
    thread->num = ui->spinBox->value();
    on_spinBox_valueChanged(thread->num);
    connect(thread, SIGNAL(finished()),thread, SLOT(declareDeleted()));
    connect(thread,SIGNAL(finished()),thread, SLOT(deleteLater()));
    thread->start();
}

void MainWindow::on_spinBox_valueChanged(int &arg1)
{
    switch(arg1)
    {
    case 1:
        ui->clock->setPixmap(pix1);
    break;
    case 2:
        ui->clock->setPixmap(pix2);
        break;
    case 3:
        ui->clock->setPixmap(pix3);
        break;
    case 4:
        ui->clock->setPixmap(pix4);
        break;
    case 5:
        ui->clock->setPixmap(pix5);
        break;
    case 6:
        ui->clock->setPixmap(pix6);
        break;
    case 7:
        ui->clock->setPixmap(pix7);
        break;
    case 8:
        ui->clock->setPixmap(pix8);
        break;
    case 9:
        ui->clock->setPixmap(pix9);
        break;
    case 10:
        ui->clock->setPixmap(pix10);
        break;
    case 11:
        ui->clock->setPixmap(pix11);
        break;
    case 12:
        ui->clock->setPixmap(pix12);
        break;
    default:
        if(arg1==0){
        ui->clock->setPixmap(pix0);
        }
        else{
            ui->clock->setPixmap(pix12);
        }
        break;
    }
}
