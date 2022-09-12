//
// Created by Juan Felipe Restrepo Buitrago on 7/09/2022.
//

#include <iostream>
#include "LinkedList.h"
#include "Storage.h"
using namespace std;

int main() {
    LinkedList * list = new LinkedList();
    Storage storage;
    storage.loadData(list);
    list -> printList(list -> getHead());

    list -> addUserAtTheEnd("Juan", "1234");
    list -> printList(list -> getHead());

    list ->deleteUserByUsername("Mateo");
    list -> printList(list -> getHead());

    storage.saveData(list);
}
