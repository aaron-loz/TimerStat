#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage myImage;
    setWindowTitle(tr("Clock In"));
    myImage.load(":/images/clock.png");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_returnPressed()
{
    QString project = ui->lineEdit->text();
    setWindowTitle(project);
}
