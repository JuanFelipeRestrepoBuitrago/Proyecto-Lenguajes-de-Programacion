//
// Created by Usuario on 12/09/2022.
//

#include "Exceptions.h"

const char *InvalidOptionException::what() const noexcept {
    return this -> message;
}

InvalidOptionException::InvalidOptionException(const char *message) {
    this -> message = message;
}

const char *WrongPasswordException::what() const noexcept {
    return "Contraseña Incorrecta, Intente de Nuevo";
}