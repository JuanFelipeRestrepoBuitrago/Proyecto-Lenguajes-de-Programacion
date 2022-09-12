//
// Created by Usuario on 12/09/2022.
//

#include "Input.h"
#include "iostream"
#include "Exceptions.h"
using namespace std;

int Input::readOption() {
    int option;
    cin >> option;

    if (cin.fail()){
        throw ios_base::failure("Input no Valido");
    }else if(option < 1 || option > 6){
        throw InvalidOptionException("Opcion no Valida en el Menu, Intente de Nuevo con Valores Entre 1 y 6");
    }

    return option;
}

string Input::readPassword() {
    string password;
    cin >> password;

    if (cin.fail()){
        throw ios_base::failure("Input no Valido");
    }

    return password;
}

string Input::readUsername() {
    string username;
    cin >> username;

    if (cin.fail()){
        throw ios_base::failure("Input no Valido");
    }

    return username;
}