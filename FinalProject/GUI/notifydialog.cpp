//
// Created by Juan Felipe Restrepo Buitrago on 04/11/2022.
//

#include "notifydialog.h"
#include "ui_notifydialog.h"

// Constructor, this class is used to show a message to the user
NotifyDialog::NotifyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NotifyDialog)
{
    ui->setupUi(this);
}

// Destructor
NotifyDialog::~NotifyDialog()
{
    delete ui;
}

// Sets the text of the message it wants to show
void NotifyDialog::setPlainText(QString text){
    ui ->plainTextEdit->setPlainText(text);
}
