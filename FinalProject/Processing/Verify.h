//
// Created by Juan Felipe Restrepo on 8/11/2022.
//

#ifndef FINALPROJECT_VERIFY_H
#define FINALPROJECT_VERIFY_H

#include "string"
#include "regex"
#include "iostream"

using namespace std;

class Verify {
public:
    static array<string, 8> verifyBoard(string chessBoard);
    static bool verifyRow(string row);
    static string getRow(string chessBoard);
};


#endif //FINALPROJECT_VERIFY_H
