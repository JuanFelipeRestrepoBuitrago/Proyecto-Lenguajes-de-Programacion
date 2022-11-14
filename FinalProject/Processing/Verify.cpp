//
// Created by Juan Felipe Restrepo on 8/11/2022.
//

#include "Verify.h"
#include "../Exceptions/Exception.h"
#include "FindError.h"

using namespace std;


// Verify the FEN expression and return the error if there is one or return an array with the rows organized
array<string, 8> Verify::verifyBoard(string chessBoard) {
    regex chessPattern(R"(((([1-7]?[PNBRQKpnbrqk][1-7]?){1,8}|8)/){7}(([1-7]?[PNBRQKpnbrqk][1-7]?){1,8}|8) (w|b) (-|[KQkq]{1,4}) ?(-|[a-h][36]) [0-9]{1,2} [1-9][0-9]{0,})");

    bool isMatch = regex_match(chessBoard, chessPattern);

    if (isMatch) {
        stringstream s(chessBoard);
        string row;
        array<string, 8> rows;

        s >> row;

        stringstream a(row);
        int i = 0;
        while (getline(a, row, '/')){
            if (verifyRow(row)){
                rows[i] = getRow(row);
            }
            i++;
        }

        return rows;
    } else {
        FindError::findError(chessBoard);
        return {"", "", "", "", "", "", "", ""};
    }
}

// Verify if a row length is valid
bool Verify::verifyRow(string row) {
//    int length = 0;
//    for (int i = 0; i < row.size(); i++){
//        if (isdigit(row[i])){
//            length += stoi(string(1, row[i]));
//        }else{
//            length++;
//        }
//    }
    int length = 0;
    for_each(row.begin(), row.end(), [&length](char & c){
        if (isdigit(c)){
            length += stoi(string(1, c));
        }else{
            length++;
        }
    });

    if (length == 8){
        return true;
    } else {
        throw InvalidLengthException("Length of row '" + row + "' in 'Piece Placement' Section is invalid, please try again.");
    }
}

// Get the row with the pieces correctly, without numbers
string Verify::getRow(string chessBoard) {
    string row = "";
    for_each(chessBoard.begin(), chessBoard.end(), [&row](char & c){
        if (isdigit(c)){
            for (int i = 0; i < stoi(string(1, c)); i++){
                row += " ";
            }

        }else{
            row += c;
        }
    });

    return row;
//    for (int i = 0; i < chessBoard.size(); i++){
//        if (isdigit(chessBoard[i])){
//
//            int condition = stoi(string(1, chessBoard[i])) + i;
//            chessBoard.replace(i, 1, " ");
//            i++;
//
//            while (i < condition){
//                chessBoard.insert(i, " ");
//                i++;
//            }
//        }
//    }
//
//    return chessBoard;
}
