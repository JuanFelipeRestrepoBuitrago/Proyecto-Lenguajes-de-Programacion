//
// Created by Juan Felipe Restrepo on 9/11/2022.
//

#include "Exception.h"
#include "../GUI/notifydialog.h"
#include <iostream>

using namespace std;

const char *NoTextException::what() const noexcept {
    NotifyDialog dialog;

    dialog.setWindowTitle("Input Error");
    dialog.setPlainText(QString::fromStdString("No text was entered, please try again"));
    dialog.setModal(true);
    dialog.exec();

    return "No text was entered, please try again";
}

InvalidLengthException::InvalidLengthException(string row) {
    this -> row = row;
}

const char *InvalidLengthException::what() const noexcept {
    NotifyDialog dialog;

    dialog.setWindowTitle("Length Error");

    dialog.setPlainText(QString::fromStdString("Length of row '" + row + "' is invalid, please try again"));
    dialog.setModal(true);
    dialog.exec();

    return "Length of row is invalid, please try again";
}
