//
// Created by Usuario on 12/09/2022.
//

#ifndef PROYECTOLENGUAJESPROGRAMACION_EXCEPTIONS_H
#define PROYECTOLENGUAJESPROGRAMACION_EXCEPTIONS_H

#include <exception>
using namespace std;

class InvalidOptionException: public exception {
private:
    const char * message;
public:
    explicit InvalidOptionException(const char * message);
    const char * what() const noexcept override;
};

class WrongPasswordException: public exception {
public:
    const char * what() const noexcept override;
};
}

#endif //PROYECTOLENGUAJESPROGRAMACION_EXCEPTIONS_H
