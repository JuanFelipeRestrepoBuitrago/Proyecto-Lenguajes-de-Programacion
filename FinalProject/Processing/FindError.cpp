//
// Created by Juan Felipe Restrepo on 13/11/2022.
//

#include "FindError.h"
#include <string>
#include <regex>
#include "../Exceptions/Exception.h"

using namespace std;

void FindError::findError(string expression) {
    stringstream ss(expression);
    string word;
    string parts[6];

    int i = 0;
    while (getline(ss, word, ' ')) {
        parts[i] = word;
        i++;
    }

    string1(parts[0]);
    string2(parts[1]);
    string3(parts[2]);
    string4(parts[3]);
    string5(parts[4]);
    string6(parts[5]);
}

void FindError::string1(string expression) {
    regex rowsNumber("^.{1,8}/{7}.{1,8}$");
    if (expression == " " || expression == ""){
        throw MissingSectionException("Piece Placement");
    } else if (!regex_match(expression, rowsNumber)){
        throw RowsNumberException();Find
    }
}

void FindError::string2(string expression) {
    if (expression == " " || expression == ""){
        throw MissingSectionException("Side to Move");
    }
}

void FindError::string3(string expression) {
    if (expression == " " || expression == ""){
        throw MissingSectionException("Castling Availability");
    }
}

void FindError::string4(string expression) {
    if (expression == " " || expression == ""){
        throw MissingSectionException("En Passant Target Square");
    }
}

void FindError::string5(string expression) {
    if (expression == " " || expression == ""){
        throw MissingSectionException("Halfmove Clock");
    }
}

void FindError::string6(string expression) {
    if (expression == " " || expression == ""){
        throw MissingSectionException("Fullmove Counter");
    }
}
