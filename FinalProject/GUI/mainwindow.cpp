//
// Created by Juan Felipe Restrepo Buitrago on 04/11/2022.
//

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ui_mainwindow.h"
#include "notifydialog.h"
#include "board.h"
#include "../Exceptions/Exception.h"
#include "../Processing/Verify.h"
#include <QResizeEvent>

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

void MainWindow::resizeEvent(QResizeEvent *e)
{
    int windowDefault = 346;
    int textDefault = 25;

    int windowActual = e->size().height();

    int newTextSize = (int)textDefault*windowActual / windowDefault;
    ui ->mainText->setFont(QFont("Times New Roman", newTextSize));
}

void MainWindow::on_verifyButton_clicked()
{
    try{
        QString Qtext = ui->data->text();
        if (Qtext.toStdString() == ""){
            throw NoTextException();
        }else{
            ui->label->setText("Loading...");
            Board *board = new Board();

            board->printFEN(Qtext);
            board->printBoard(Verify::verifyBoard(Qtext.toStdString()));
            board->show();

            this->close();

        }
    }catch (NoTextException &e){
        e.what();
    }catch (InvalidLengthException &e){
        ui->label->setText("");
        e.what();
    }
}
