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

InvalidLengthException::InvalidLengthException(string message) {
    this -> message = message;
}

const char *InvalidLengthException::what() const noexcept {
    NotifyDialog dialog;

    dialog.setWindowTitle("Length Error");

    dialog.setPlainText(QString::fromStdString(message));
    dialog.setModal(true);
    dialog.exec();

    return "Length of row is invalid, please try again";
}

MissingSectionException::MissingSectionException(string message) {
    this -> message = message;
}

const char *MissingSectionException::what() const noexcept {
    NotifyDialog dialog;

    dialog.setWindowTitle("Section Error");

    dialog.setPlainText(QString::fromStdString("Missing Section '" + message + "', please try again"));
    dialog.setModal(true);
    dialog.exec();

    return "Section is missing, please try again";
}

const char *RowsNumberException::what() const noexcept {
    NotifyDialog dialog;

    dialog.setWindowTitle("Rows Error");

    dialog.setPlainText(QString::fromStdString("Number of rows in 'Piece Placement' Section is invalid, please try again"));
    dialog.setModal(true);
    dialog.exec();

    return "Number of rows in 'Piece Placement' Section is invalid, please try again";
}
