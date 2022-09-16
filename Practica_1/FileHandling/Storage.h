//
// Created by Juan Felipe Restrepo Buitrago on 12/09/2022.
//

#ifndef PROYECTOLENGUAJESPROGRAMACION_STORAGE_H
#define PROYECTOLENGUAJESPROGRAMACION_STORAGE_H
#include "../LinkedList/LinkedList.h"

class Storage {
public:

    static void saveData(LinkedList * list);
    static void loadData(LinkedList * list);
};


#endif //PROYECTOLENGUAJESPROGRAMACION_STORAGE_H
