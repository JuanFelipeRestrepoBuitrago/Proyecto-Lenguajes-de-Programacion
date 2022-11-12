#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ui_mainwindow.h"
#include "notifydialog.h"
#include "../Exceptions/Exception.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_verifyButton_clicked()
{
    try{
        QString Qtext = ui->data->text();
        if (Qtext.toStdString() == ""){
            throw NoTextException();
        }else{
            ui->mainText->hide();
            ui->data->hide();
            ui->verifyButton->hide();
        }
    }catch (NoTextException& e){
        e.what();
    }
}
