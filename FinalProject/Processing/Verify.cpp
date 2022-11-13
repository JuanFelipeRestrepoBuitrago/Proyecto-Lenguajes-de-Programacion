//
// Created by Juan Felipe Restrepo on 8/11/2022.
//

#include "Verify.h"
#include "../Exceptions/Exception.h"

using namespace std;

array<string, 8> Verify::verifyBoard(string chessBoard) {
    regex chessPattern(R"(((([1-7]?[PNBRQKpnbrqk][1-7]?){1,8}|8)/){7}(([1-7]?[PNBRQKpnbrqk][1-7]?){1,8}|8) (w|b) (-|[KQkq]{1,4}) ?(-|[a-h][36]) [0-9]{1,2} [1-9][0-9]{0,3})");

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
            } else {
                return {"", "", "", "", "", "", "", ""};
            }
            i++;
        }

        return rows;
    } else {
        return {"", "", "", "", "", "", "", ""};
    }
}

bool Verify::verifyRow(string row) {
    int length = 0;
    for (int i = 0; i < row.size(); i++){
        if (isdigit(row[i])){
            length += stoi(string(1, row[i]));
        }else{
            length++;
        }
    }
    if (length == 8){
        return true;
    } else {
        throw InvalidLengthException(row);
    }
}

string Verify::getRow(string chessBoard) {
    for (int i = 0; i < chessBoard.size(); i++){
        if (isdigit(chessBoard[i])){
            int condition = stoi(string(1, chessBoard[i])) + i;
            while (i < condition){
                chessBoard.insert(i, " ");
                i++;
            }
        }
    }

    return chessBoard;
}
