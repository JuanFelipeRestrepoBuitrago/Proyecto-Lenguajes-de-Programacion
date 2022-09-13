//
// Created by Juan Felipe Restrepo Buitrago on 12/09/2022.
//

#include "Processing.h"
#include "Input.h"
#include "Storage.h"
#include "Exceptions.h"
#include <iostream>

using namespace std;

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

void Processing::option1(LinkedList * list) {
    if (list -> getHead() != nullptr) {
        throw ExistingListException();
    }else{
        Storage::loadData(list);
    }
}

void Processing::option2(LinkedList * list) {
    string username = Input::readUsername();
    string password = Input::readPassword();

    list -> addUserAtTheEnd(username, password);
}

void Processing::option3(LinkedList *list) {
    if (list -> getHead() == nullptr){
        throw EmptyListException();
    }else{
        Node * user = list ->searchUserByUsername(Input::readUsername());

        while (true){
            if (user == nullptr){
                cout << "No se Encontró ese Usuario" << endl;
                break;
            }else{
                string password = Input::readPassword();
                if (user -> getPassword() == password){
                    cout << "Bienvenido," << user ->getUsername() << endl;
                    break;
                }else{
                    cout << "Contraseña Incorrecta, Inténtelo de Nuevo" << endl;
                }
            }
        }
    }
}

void Processing::option4(LinkedList *list) {
    if (list -> getHead() == nullptr){
        throw EmptyListException();
    }else{
        if (list -> deleteUserByUsername(Input::readUsername())){
            cout << "Usuario Eliminado Exitosamente" << endl;
        }else{
            cout << "No se Encontró ese Usuario" << endl;
        }
    }
}

void Processing::option5(LinkedList *list) {
    list ->printList(list -> getHead());
}