//
// Created by Juan Felipe Restrepo on 9/11/2022.
//

#include "Exception.h"
#include "../GUI/notifydialog.h"

using namespace std;

// This exception is thrown when the user tries to run the program without a writing a text in the text box
const char *NoTextException::what() const noexcept {
    NotifyDialog dialog;

    dialog.setWindowTitle("Input Error");
    dialog.setPlainText(QString::fromStdString("No text was entered, please try again."));
    dialog.setModal(true);
    dialog.exec();

    return "No text was entered, please try again.";
}

// Constructor
InvalidLengthException::InvalidLengthException(string message) {
    this -> message = message;
}

// This exception is thrown when the length something is not right
const char *InvalidLengthException::what() const noexcept {
    NotifyDialog dialog;

    dialog.setWindowTitle("Length Error");

    dialog.setPlainText(QString::fromStdString(message));
    dialog.setModal(true);
    dialog.exec();

    return "Length of row is invalid, please try again.";
}

// Constructor
MissingSectionException::MissingSectionException(string message) {
    this -> message = message;
}

// This exception is thrown when a section is missing
const char *MissingSectionException::what() const noexcept {
    NotifyDialog dialog;

    dialog.setWindowTitle("Section Error");

    dialog.setPlainText(QString::fromStdString("Missing Section '" + message + "', please try again."));
    dialog.setModal(true);
    dialog.exec();

    return "Section is missing, please try again.";
}

// This exception is thrown when the number of rows is not 8
const char *RowsNumberException::what() const noexcept {
    NotifyDialog dialog;

    dialog.setWindowTitle("Rows Error");

    dialog.setPlainText(QString::fromStdString("Number of rows in 'Piece Placement' Section is invalid, please try again."));
    dialog.setModal(true);
    dialog.exec();

    return "Number of rows in 'Piece Placement' Section is invalid, please try again.";
}

// Constructor
InvalidCharacterException::InvalidCharacterException(string section, string character, string row) {
    this -> section = section;
    this -> character = character;
    this -> row = row;
}

// This exception is thrown when a character is not valid in a section
const char *InvalidCharacterException::what() const noexcept {
    NotifyDialog dialog;

    dialog.setWindowTitle("Character Error");

    dialog.setPlainText(QString::fromStdString("Invalid character '" + character + "' in '" + section + "' Section, expression '" + row + "', please try again."));
    dialog.setModal(true);
    dialog.exec();

    return "Invalid character in Section, please try again.";
}

// This exception is thrown when the order of the En Passant is not right
const char *OrderException::what() const noexcept {
    NotifyDialog dialog;

    dialog.setWindowTitle("Order Error");

    dialog.setPlainText(QString::fromStdString("Order of characters in 'En Passant Target Square' section is wrong, the non-digit character must come before the digit character, please try again."));
    dialog.setModal(true);
    dialog.exec();

    return "Number of rows in 'Piece Placement' Section is invalid, please try again.";
}

// This exception is thrown when the number of the Full Move Number is not right
const char *InvalidNumberException::what() const noexcept {
    NotifyDialog dialog;

    dialog.setWindowTitle("Number Error");

    dialog.setPlainText(QString::fromStdString("The 'Fullmove' Section number must be greater than 0, please try again."));
    dialog.setModal(true);
    dialog.exec();

    return "The 'Fullmove' Section number must be greater than 0, please try again.";
}
