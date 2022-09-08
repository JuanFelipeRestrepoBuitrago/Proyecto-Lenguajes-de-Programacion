//
// Created by Juan Felipe Restrepo Buitrago on 7/09/2022.
//

#ifndef PROYECTOLENGUAJESPROGRAMACION_LINKEDLIST_H
#define PROYECTOLENGUAJESPROGRAMACION_LINKEDLIST_H
#include "string"
#include "Node.h"


class LinkedList {
protected:
    Node * head;
public:
    LinkedList();

    Node* getHead();
    void setHead(Node * h);

    bool addUserAtTheEnd(string u, string p);
    Node * searchUserByUsername(string u);
    Node * searchUserByPassword(string p);

    bool deleteUserByUsername(string u);
    bool deleteUserByPassword(string p);

    void printList(Node * current);

};


#endif //PROYECTOLENGUAJESPROGRAMACION_LINKEDLIST_H
