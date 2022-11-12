//
// Created by Juan Felipe Restrepo on 8/11/2022.
//

#include "Verify.h"

using namespace std;

bool Verify::verifyBoard(string chessBoard) {
    regex chessPattern(R"(((([1-7]?[PNBRQKpnbrqk][1-7]?){1,8}|8)/){7}(([1-7]?[PNBRQKpnbrqk][1-7]?){1,8}|8) (w|b) (-|[KQkq]{1,4}) ?(-|[a-h][36]) [0-9]{1,2} [1-9][0-9]{0,3})");

    bool isMatch = regex_match(chessBoard, chessPattern);

    if (isMatch) {
        char chessBoardChar[chessBoard.size()];
        strcpy(chessBoardChar, chessBoard.c_str());

        char *pieces = strtok(chessBoardChar, " ");
        string firstPiece = pieces;

        cout << firstPiece << endl;
        return true;
    } else {
        return false;
    }
}
