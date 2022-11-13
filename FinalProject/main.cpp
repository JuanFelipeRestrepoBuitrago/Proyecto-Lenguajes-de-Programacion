//
// Created by Juan Felipe Restrepo Buitrago on 04/11/2022.
//

#include "GUI/mainwindow.h"
#include <QApplication>
#include "Processing/Verify.h"

using namespace std;

int main(int argc, char *argv[]){
    regex chessPattern(R"(((([1-7]?[PNBRQKpnbrqk][1-7]?){1,8}|8)/){7}(([1-7]?[PNBRQKpnbrqk][1-7]?){1,8}|8) (w|b) (-|[KQkq]{1,4}) ?(-|[a-h][36]) [0-9]{1,2} [1-9][0-9]{0,3})");

        string chessBoard = "rnbkqbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return QApplication::exec();
}
