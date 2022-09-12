//
// Created by Juan Felipe Restrepo Buitrago on 7/09/2022.
//

#include <iostream>
#include "LinkedList.h"
#include "Storage.h"
#include "Output.h"
#include "Exceptions.h"
using namespace std;
#include "Input.h"


int main() {
    Output::menu();
    try {
        int option = Input::readOption();
    }catch (InvalidOptionException &e){
        cout << e.what() << endl;
    }
//    LinkedList * list = new LinkedList();
//    Storage storage;
//    storage.loadData(list);
//    list -> printList(list -> getHead());
//
//    list -> addUserAtTheEnd("Juan", "1234");
//    list -> printList(list -> getHead());
//
//    list ->deleteUserByUsername("Mateo");
//    list -> printList(list -> getHead());
//
//    storage.saveData(list);
}
