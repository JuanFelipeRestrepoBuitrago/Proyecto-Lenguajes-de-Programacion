//
// Created by Juan Felipe Restrepo Buitrago on 12/09/2022.
//

#include "Storage.h"
#include "../LinkedList/LinkedList.h"
#include <fstream>
#include <string>
#include "iostream"
using namespace std;

// Method to save the data of a file in a linked list
void Storage::loadData(LinkedList * list) {
    ifstream file;
    file.exceptions(ifstream::badbit | ifstream::failbit);
    try{
        file.open(("..\\usuarios.txt"));

        string line;

        string user;
        string pass;
        bool u = false;
        bool p = false;

        while (getline(file, line)) {
            if (!u) {
                user = line;
                u = true;
            }else{
                pass = line;
                p = true;
            }

            if (u && p) {
                list->addUserAtTheEnd(user, pass);
                u = false;
                p = false;
            }
        }

        file.close();

        cout << "Datos Cargados Exitosamente" << endl;
    }catch (ifstream::failure& e){
        cout << "No se Encuentra el Archivo, Puede que Aun no Exista" << endl;
    }
}

// Method to save the data of a linked list in a file
void Storage::saveData(LinkedList *list) {
    ofstream file("..\\usuarios.txt");
    Node * current = list -> getHead();

    while (current != nullptr) {
        file << current -> getUsername() << endl;
        file << current -> getPassword() << endl;
        current = current -> getNext();
    }

    file.close();
}