//
// Created by Juan Felipe Restrepo Buitrago on 04/11/2022.
//

#include "GUI/mainwindow.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return QApplication::exec();
}
