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
    string message;
public:
    explicit InvalidLengthException(string message);
    const char * what() const noexcept override;

};

class MissingSectionException: public exception {
private:
    string message;
public:
    explicit MissingSectionException(string message);
    const char * what() const noexcept override;
};

class RowsNumberException: public exception {
public:
    const char * what() const noexcept override;
};

class InvalidCharacterException: public exception {
private:
    string section;
    string character;
    string row;
public:
    InvalidCharacterException(string section, string character, string row);
    const char * what() const noexcept override;
};

class OrderException: public exception {
public:
    const char * what() const noexcept override;
};

class InvalidNumberException: public exception {
public:
    const char * what() const noexcept override;
};

#endif //FINALPROJECT_EXCEPTION_H
