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

