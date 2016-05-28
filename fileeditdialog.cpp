#include "fileeditdialog.h"
#include "ui_fileeditdialog.h"
#include <QDebug>

fileEditDialog::fileEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fileEditDialog)
{
    ui->setupUi(this);
}

fileEditDialog::~fileEditDialog()
{
    delete ui;
}

void fileEditDialog::on_buttonBox_accepted()
{
    fileText =ui->textEdit->toPlainText();
    qDebug()<<fileText;
}

void fileEditDialog::setTextEdits()
{//using a signal, the function runs before the app is exec()
    ui->textEdit->setHtml(fileText);
}
