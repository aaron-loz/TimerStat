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
{//Closes the currently open file.Restarts openFileText and tempText
    file.close();
    tempText.remove(0,tempText.size());
    openFileText.remove(0,openFileText.size());
    ui->lineEdit->clear();
}

void MainWindow::on_lineEdit_returnPressed()
{//This will add on to a project list once I set up a file
    if(tempText.endsWith(":")){}
    else
        tempText +="\n"+ui->lineEdit->text()+"::";
}

void MainWindow::on_actionE_xit_triggered()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit", "Are you sure you wanna Quit?",
                                  QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
        QCoreApplication::exit();
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
        this->writeFile(file.fileName());
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
        this->writeFile(fileName);
    }
}

void MainWindow::ReadFile(const QString &fileName)
{
    file.setFileName(fileName);
    if(!file.open(QIODevice::ReadWrite| QIODevice::Text))
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

void MainWindow::writeFile(const QString &fileName)
{//This will write into a .txt file the project and the amount of time, in hours.
    QTextStream out(&file);
    if(file.isOpen())
    {
        out<<tempText;
    }
    else{
    file.setFileName(fileName);
        if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QMessageBox::information(this, tr("Unable to open file"), file.errorString());
            return;
        }
    QString textstream ="Projects    :   Time\n---------------------------" ;
    out<<textstream;
    out<<tempText;
    }
}

void MainWindow::on_spinBox_editingFinished()
{
    int spinValue = ui->spinBox->value();
    sleepTimer *thread = new sleepTimer();
    thread->num = spinValue;
    if(ui->lineEdit->text()== NULL)
     tempText+="\nno project title::";
    else
        on_lineEdit_returnPressed();
    QString s= QString::number(spinValue);
    tempText.append(s);
    tempText +=" minutes";
    on_spinBox_valueChanged(thread->num);
    connect(thread,SIGNAL(finished()),thread, SLOT(deleteLater()));
    connect(thread,SIGNAL(changeTime()),this, SLOT(changeLED()));
    //the second connect lets the thread control the LED in the ui
    thread->start();
}
void MainWindow::changeLED()
{
    ui->lcd1->display(1);
    qDebug()<<"It worked!";
    //!Make the digit change correctly
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
