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
    regex rowsNumber(R"(^(.{1,8}/){7}.{1,8}$)");
    regex character(R"([PNBRQKpnbrqk1-8])");
    if (expression == " " || expression == ""){
        throw MissingSectionException("Piece Placement");
    } else if (!regex_match(expression, rowsNumber)){
        throw RowsNumberException();
    }else{
        stringstream ss(expression);
        string row;

        while (getline(ss, row, '/')){
            for_each(row.begin(), row.end(), [&character, &row](char & c){
                if (!regex_match(string(1, c), character)){
                    throw InvalidCharacterException("Piece Placement", string(1, c), row);
                }
            });
        }
    }
}

void FindError::string2(string expression) {
    regex turn(R"(^(w|b)$)");
    if (expression == " " || expression == ""){
        throw MissingSectionException("Side to Move");
    } else if (!regex_match(expression, turn)){
        throw InvalidCharacterException("Side to Move", expression, expression);
    }
}

void FindError::string3(string expression) {
    regex castling(R"(^([KQkq]{1,4}|-)$)");
    regex castlingCharacters(R"([KQkq])");

    if (expression == " " || expression == ""){
        throw MissingSectionException("Castling Availability");

    }else if (!regex_match(expression, castling)){
        for_each(expression.begin(), expression.end(), [&expression, &castlingCharacters](char & c){
            if (!regex_match(string(1, c), castlingCharacters)){
                throw InvalidCharacterException("Castling Availability", string(1, c), expression);
            }
        });
    }
}

void FindError::string4(string expression) {
    regex enPassant(R"(^([a-h][36]|-)$)");
    regex enPassantOrder(R"(^\D\d$)");
    regex enPassantCharacters(R"([a-h36])");

    if (expression == " " || expression == ""){
        throw MissingSectionException("En Passant Target Square");

    }else if (!regex_match(expression, enPassant)){
        if (!regex_match(expression, enPassantOrder)){
            throw OrderException();

        }else{
            for_each(expression.begin(), expression.end(), [&expression, &enPassantCharacters](char & c){
                if (!regex_match(string(1, c), enPassantCharacters)){
                    throw InvalidCharacterException("En Passant Target Square", string(1, c), expression);
                }
            });
        }
    }
}

void FindError::string5(string expression) {
    regex halfMove(R"(^\d{1,2}$)");
    regex halfMoveCharacters(R"(\d)");

    if (expression == " " || expression == ""){
        throw MissingSectionException("Halfmove Clock");

    }else if(expression.size() > 2) {
        throw InvalidLengthException("Invalid length for Halfmove Clock Section, must be 1 or 2 digits, please try again.");

    }else if (!regex_match(expression, halfMove)){
        for_each(expression.begin(), expression.end(), [&expression, &halfMoveCharacters](char & c){
            if (!regex_match(string(1, c), halfMoveCharacters)){
                throw InvalidCharacterException("Halfmove Clock", string(1, c), expression);
            }
        });

    }
}

void FindError::string6(string expression) {
    try {
        if (expression == " " || expression == ""){
            throw MissingSectionException("Fullmove Counter");

        }else if (stoi(expression) < 1){
            throw InvalidNumberException();
        }
    }catch (const invalid_argument& ia){
        for_each(expression.begin(), expression.end(), [&expression](char & c){
            if (!isdigit(c)){
                throw InvalidCharacterException("Fullmove Counter", string(1, c), expression);
            }
        });
    }
}
