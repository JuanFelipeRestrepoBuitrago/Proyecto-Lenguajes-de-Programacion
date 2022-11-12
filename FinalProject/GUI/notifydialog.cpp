#include "notifydialog.h"
#include "ui_notifydialog.h"

NotifyDialog::NotifyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NotifyDialog)
{
    ui->setupUi(this);
}

NotifyDialog::~NotifyDialog()
{
    delete ui;
}

void NotifyDialog::setPlainText(QString text){
    ui ->plainTextEdit->setPlainText(text);
}
