//
// Created by Juan Felipe Restrepo Buitrago on 12/09/2022.
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

const char *ExistingListException::what() const noexcept {
    return "Ya se ha Cargado una Lista de Usuarios, Intente Otra Opcion";
}

const char *EmptyListException::what() const noexcept {
    return "No se ha Cargado una Lista de Usuarios, Intente Leer el Archivo o Agregar un Nuevo Usuario";
}