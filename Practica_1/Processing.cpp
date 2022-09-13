//
// Created by Juan Felipe Restrepo Buitrago on 12/09/2022.
//

#include "Processing.h"
#include "Input.h"
#include "Storage.h"
#include "Exceptions.h"
#include <iostream>

using namespace std;

// This Method Executes the Respective Option Selected
int Processing::menuOption(LinkedList * list) {
    int option = 0;
    try {
        option = Input::readOption();
        switch (option) {
            case 1:
                option1(list);
                return option;
            case 2:
                option2(list);
                return option;
            case 3:
                option3(list);
                return option;
            case 4:
                option4(list);
                return option;
            case 5:
                option5(list);
                return option;
            default:
                cout << "Saliendo del Programa..." << endl;
                return option;
        }
    }catch (ExistingListException& e){
        cout << e.what() << endl;
        return option;
    }catch (EmptyListException& e){
        cout << e.what() << endl;
        return option;
    }catch (InvalidOptionException& e){
        cout << e.what() << endl;
        return option;
    }catch (ios_base::failure& e){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << e.what() << endl;
        return option;
    }
}

// Method to Load the Data From a File to the List Given, First Option
void Processing::option1(LinkedList * list) {
    if (list -> getHead() != nullptr) {
        throw ExistingListException();
    }else{
        Storage::loadData(list);
        cout << "Datos Cargados Exitosamente" << endl;
    }
}

// Method to Add a New User to the Given List
void Processing::option2(LinkedList * list) {
    string username = Input::readUsername();
    string password = Input::readPassword();

    list -> addUserAtTheEnd(username, password);
    cout << "Usuario Agregado Exitosamente" << endl;
}

// This Method Confirms Whether a User Exists or Not
void Processing::option3(LinkedList *list) {
    if (list -> getHead() == nullptr){
        throw EmptyListException();
    }else{
        Node * user = list ->searchUserByUsername(Input::readUsername());

        while (true){
            if (user == nullptr){
                cout << "No se Encontro ese Usuario" << endl;
                break;
            }else{
                string password = Input::readPassword();
                if (user -> getPassword() == password){
                    cout << "Bienvenido," << user ->getUsername() << endl;
                    break;
                }else{
                    cout << "Contraseña Incorrecta, Intentelo de Nuevo" << endl;
                }
            }
        }
    }
}

// Method to Delete an Existing User From the Given List
void Processing::option4(LinkedList *list) {
    if (list -> getHead() == nullptr){
        throw EmptyListException();
    }else{
        Node * user = list ->searchUserByUsername(Input::readUsername());

        while (true){
            if (user == nullptr){
                cout << "No se Encontro ese Usuario" << endl;
                break;
            }else{
                string password = Input::readPassword();
                if (user -> getPassword() == password){
                    if (list -> deleteUserByUsername(user -> getUsername())){
                      cout << "Usuario Eliminado Exitosamente" << endl;
                    }
                    break;
                }else{
                    cout << "Contraseña Incorrecta, Intentelo de Nuevo" << endl;
                }
            }
        }
//        if (list -> deleteUserByUsername(Input::readUsername())){
//            cout << "Usuario Eliminado Exitosamente" << endl;
//        }else{
//            cout << "No se Encontró ese Usuario" << endl;
//        }
    }
}

// This Method Prints the Given List
void Processing::option5(LinkedList *list) {
    list ->printList(list -> getHead());
}