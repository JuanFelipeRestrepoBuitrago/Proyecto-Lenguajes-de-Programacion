//
// Created by Juan Felipe Restrepo on 14/11/2022.
//

#include "Test.h"
#include "../GUI/mainwindow.h"
#include <QApplication>

void Test::test(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    a.exec();
}

// Cases to Prove
// rnbkqbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1
// pppppppp/pppppppp/pppppppp/pppppppp/pppppppp/pppppppp/pppppppp/pppppppp w KQkq - 0 1
// rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w  - 0 1
// rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - a 1
// rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 a
// rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKaNR w KQkt - 0 1
