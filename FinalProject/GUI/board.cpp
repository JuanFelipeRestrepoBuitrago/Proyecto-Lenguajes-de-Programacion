//
// Created by Juan Felipe Restrepo Buitrago on 04/11/2022.
//

#include "board.h"
#include "ui_board.h"
#include "mainwindow.h"
#include "regex"

Board::Board(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::Board)
{
    this->icons["p"] = QIcon(":/Resources/Images/Black Pawn.png");
    this->icons["n"] = QIcon(":/Resources/Images/Black Knight.png");
    this->icons["b"] = QIcon(":/Resources/Images/Black Bishop.png");
    this->icons["r"] = QIcon(":/Resources/Images/Black Rook.png");
    this->icons["q"] = QIcon(":/Resources/Images/Black Queen.png");
    this->icons["k"] = QIcon(":/Resources/Images/Black King.png");
    this->icons["P"] = QIcon(":/Resources/Images/White Pawn.png");
    this->icons["N"] = QIcon(":/Resources/Images/White Knight.png");
    this->icons["B"] = QIcon(":/Resources/Images/White Bishop.png");
    this->icons["R"] = QIcon(":/Resources/Images/White Rook.png");
    this->icons["Q"] = QIcon(":/Resources/Images/White Queen.png");
    this->icons["K"] = QIcon(":/Resources/Images/White King.png");

    ui->setupUi(this);
}

Board::~Board()
{
    delete ui;
}

void Board::printBoard(array<string, 8> s) {
    regex piecesPattern(R"([PNBRQKpnbrqk])");
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(regex_match(string(1, s[i][j]), piecesPattern)){
                this->ui->tableWidget->item(i, j)->setIcon(this->icons[string(1, s[i][j])]);
            }
        }
    }
}

void Board::resizeEvent(QResizeEvent *e)
{
    int windowDefault = 650;
    int textDefault = 20;
    int plainTextDefault = 12;

    int windowActual = this->size().height();

    this ->ui->label->setFont(QFont("Times New Roman", (int)textDefault*windowActual / windowDefault));
    this ->ui->label_2->setFont(QFont("Times New Roman", (int)textDefault*windowActual / windowDefault));
    this ->ui->plainTextEdit->setFont(QFont("Times New Roman", (int)plainTextDefault*windowActual / windowDefault));
}

void Board::on_yesButton_clicked(){
    MainWindow *mainWindow = new MainWindow();

    mainWindow->show();
    this -> close();
}


void Board::on_noButton_clicked()
{
    this -> close();
}

void Board::printFEN(QString fen) {
    ui->plainTextEdit->setPlainText(fen);
}

