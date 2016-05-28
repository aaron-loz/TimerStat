#ifndef FILEEDITDIALOG_H
#define FILEEDITDIALOG_H

#include <QDialog>

namespace Ui {
class fileEditDialog;
}

class fileEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit fileEditDialog(QWidget *parent = 0);
    ~fileEditDialog();
    QString fileText;

private slots:
    void on_buttonBox_accepted();
    void setTextEdits();

private:
    Ui::fileEditDialog *ui;
};

#endif // FILEEDITDIALOG_H
