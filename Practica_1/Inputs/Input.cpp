//
// Created by Juan Felipe Restrepo Buitrago on 12/09/2022.
//

#include "Input.h"
#include "iostream"
#include "../Exceptions/Exceptions.h"
using namespace std;

// Method to Read an Integer as Option Given by the User and to Return it
int Input::readOption() {
    int option;
    cin >> option;

    if (cin.fail()){
        throw ios_base::failure("Debe Ingresar un Número Entero entre 1 y 6");
    }else if(option < 1 || option > 6){
        throw InvalidOptionException("Opcion no Valida en el Menu, Intente de Nuevo con Valores Entre 1 y 6");
    }

    return option;
}


// Method to Read and Return the Password Given by the User
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

// Method to Read and Return the Username Given by the User
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