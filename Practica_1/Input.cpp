//
// Created by Juan Felipe Restrepo Buitrago on 12/09/2022.
//

#include "Input.h"
#include "iostream"
#include "Exceptions.h"
using namespace std;

int Input::readOption() {
    int option;
    cin >> option;

    if (cin.fail()){
        throw ios_base::failure("Debe Ingresar un Número Entero entre 1 y 6");
    }else if(option < 1 || option > 6){
        throw InvalidOptionException("Opción no Válida en el Menu, Intente de Nuevo con Valores Entre 1 y 6");
    }

    return option;
}

string Input::readPassword() {
    string password;
    cout << "Digite la Contraseña: ";
    cin >> password;

    if (cin.fail()){
        cin.clear();
        cin.ignore();
        throw ios_base::failure("Input no Válido");
    }

    return password;
}

string Input::readUsername() {
    string username;
    cout << "Digite el Usuario: ";
    cin >> username;

    if (cin.fail()){
        cin.clear();
        cin.ignore();
        throw ios_base::failure("Input no Valido");
    }

    return username;
}