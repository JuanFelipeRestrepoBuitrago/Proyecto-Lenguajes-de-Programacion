//
// Created by Juan Felipe Restrepo Buitrago on 7/09/2022.
//

#include "LinkedList.h"
#include "Storage.h"
#include "Output.h"
#include "Exceptions.h"
#include "Processing.h"
using namespace std;



int main() {

    LinkedList * list = new LinkedList();
    int option = 0;

    while (option != 6){
        Output::menu();
        option = Processing::menuOption(list);
    }

    Storage::saveData(list);
    return 0;

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
