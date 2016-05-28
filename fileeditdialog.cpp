#include "fileeditdialog.h"
#include "ui_fileeditdialog.h"
#include <QDebug>

fileEditDialog::fileEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fileEditDialog)
{
    ui->setupUi(this);
    ui->textEdit->setPlainText(fileText);
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
