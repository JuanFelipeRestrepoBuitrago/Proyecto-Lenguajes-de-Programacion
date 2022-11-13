#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ui_mainwindow.h"
#include "notifydialog.h"
#include "board.h"
#include "../Exceptions/Exception.h"
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

            string x[8][8] = {
                {"r", "n", "b", "q", "k", "b", "n", "r"},
                {"p", "p", "p", "p", "p", "p", "p", "p"},
                {"", "", "", "", "", "", "", ""},
                {"", "", "", "", "", "", "", ""},
                {"", "", "", "", "", "", "", ""},
                {"", "", "", "", "", "", "", ""},
                {"P", "P", "P", "P", "P", "P", "P", "P"},
                {"R", "N", "B", "K", "Q", "B", "N", "R"}
            };
            board->printBoard(x);
            board->show();

            this->close();

        }
    }catch (const char* msg){
        NotifyDialog dialog;

        dialog.exec();
    }
}
