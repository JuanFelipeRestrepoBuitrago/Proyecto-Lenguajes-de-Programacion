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

    // Create a List We are Going to Work With
    LinkedList * list = new LinkedList();
    int option = 0;

    // Execute the Menu, While the User Want to
    while (option != 6){
        Output::menu();
        option = Processing::menuOption(list);
    }

    // Save Changes Made to the List
    Storage::saveData(list);
    return 0;
}
