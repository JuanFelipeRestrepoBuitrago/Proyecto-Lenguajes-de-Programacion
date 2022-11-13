//
// Created by Juan Felipe Restrepo on 9/11/2022.
//

#ifndef FINALPROJECT_EXCEPTION_H
#define FINALPROJECT_EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class NoTextException: public exception {
public:
    const char * what() const noexcept override;

};

class InvalidLengthException: public exception {
private:
    string row;
public:
    explicit InvalidLengthException(string row);
    const char * what() const noexcept override;

};


#endif //FINALPROJECT_EXCEPTION_H
