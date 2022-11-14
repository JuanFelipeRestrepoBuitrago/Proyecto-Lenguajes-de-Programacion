//
// Created by Juan Felipe Restrepo on 14/11/2022.
//

#include "Test.h"
#include "../GUI/mainwindow.h"
#include "../Processing/Verify.h"
#include <QApplication>
#include <iostream>

using namespace std;

// This test is used to test everything in the GUI
void Test::test(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    a.exec();

    // Cases to Prove
    // rnbkqbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1
    // rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1
    // rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2
    // pppppppp/pppppppp/pppppppp/pppppppp/pppppppp/pppppppp/pppppppp/pppppppp w KQkq - 0 1
    // rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w  - 0 1
    // rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - a 1
    // rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 a
    // rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKaNR w KQkt - 0 1

}

// This test is used to test the getRow function
void Test::testGetRowFunction() {
    string result = Verify::getRow("r3k2r");
    for_each(result.begin(), result.end(), [](char & c){
        cout << c << "-";
    });
    cout << endl;
    if (result == "r   k  r"){
        cout << "Test Passed" << endl;
    } else{
        cout << "Test Failed" << endl;
    }
}

void Test::testVerifyRowLengthFunction() {
    bool result = Verify::verifyRow("r3k2r");
    cout << result << endl;

    if (result){
        cout << "Test Passed" << endl;
    } else{
        cout << "Test Failed" << endl;
    }

}

