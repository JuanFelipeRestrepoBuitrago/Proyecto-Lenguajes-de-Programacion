//
// Created by Juan Felipe Restrepo Buitrago on 12/09/2022.
//

#ifndef PROYECTOLENGUAJESPROGRAMACION_EXCEPTIONS_H
#define PROYECTOLENGUAJESPROGRAMACION_EXCEPTIONS_H

#include <exception>
using namespace std;

// Exception for the Case When an Option is Not in the Menu
class InvalidOptionException: public exception {
private:
    const char * message;
public:
    explicit InvalidOptionException(const char * message);
    const char * what() const noexcept override;
};

// Exception for the Case When the Password is Not Correct
class WrongPasswordException: public exception {
public:
    const char * what() const noexcept override;
};

// Exception for the Case When a List Already Exists
class ExistingListException: public exception {
public:
    const char * what() const noexcept override;
};

// Exception for the Case When a List Does Not Exist
class EmptyListException : public exception {
public:
    const char * what() const noexcept override;
};

#endif //PROYECTOLENGUAJESPROGRAMACION_EXCEPTIONS_H
