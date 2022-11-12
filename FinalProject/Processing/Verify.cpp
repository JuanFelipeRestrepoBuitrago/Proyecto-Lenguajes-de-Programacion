//
// Created by Juan Felipe Restrepo on 8/11/2022.
//

#include "Verify.h"

using namespace std;

bool Verify::verifyBoard(string chessBoard) {
    regex chessPattern(R"(((([1-7]?[PNBRQKpnbrqk][1-7]?){1,8}|8)/){7}(([1-7]?[PNBRQKpnbrqk][1-7]?){1,8}|8) (w|b) (-|[KQkq]{1,4}) ?(-|[a-h][36]) [0-9]{1,2} [1-9][0-9]{0,3})");

    bool isMatch = regex_match(chessBoard, chessPattern);

    if (isMatch) {
        stringstream s(chessBoard);
        string rows;
        s >> rows;

        stringstream a(rows);
        while (getline(a, rows, '/')){
            cout << rows << endl;
        }

//        while(rows != NULL){
//            cout << rows << endl;
//            verifyRow(rows);
//            rows = strtok(NULL, "/");
//            cout << "" << endl;
//        }

        return true;
    } else {
        return false;
    }
}

bool Verify::verifyRow(string row) {
    for (int i = 0; i < row.size(); i++){
        string failure = "";
        int length = 0;


    }
    return true;
}
