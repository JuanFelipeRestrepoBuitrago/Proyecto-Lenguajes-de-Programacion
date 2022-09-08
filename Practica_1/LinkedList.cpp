//
// Created by Juan Felipe Restrepo Buitrago on 7/09/2022.
//

#include "LinkedList.h"
#include "string"
#include "iostream"
using namespace std;

// Constructor
LinkedList::LinkedList() {
    this -> head = nullptr;
}

// Method to get the head of the list
Node* LinkedList::getHead() {
    return this -> head;
}

// Method to set the head of the list
void LinkedList::setHead(Node * h) {
    this -> head = h;
}

// Method to add a user at the end of the list
bool LinkedList::addUserAtTheEnd(string u, string p) {
    Node * newNode = new Node(std::move(u), std::move(p));
    Node * current = this -> head;

    if (current == nullptr) {
        this -> head = newNode;
        return true;
    }else{
        while (current -> getNext() != nullptr) {
            current = current -> getNext();
        }
        if (current -> getNext() == nullptr) {
            current -> setNext(newNode);
            return true;
        }else{
            return false;
        }
    }
}

// Search a username in the list and return the Node if it exists, otherwise return nullptr
Node* LinkedList::searchUserByUsername(string u) {
    Node * current = this -> head;

    while (current != nullptr){
        if (current -> getUsername() == u){
            return current;
        }
        current = current -> getNext();
    }
    return current;
}

// Search a password in the list and return the node if it exists, otherwise return nullptr
Node *LinkedList::searchUserByPassword(std::string p) {
    Node * current = this -> head;

    while (current != nullptr){
        if (current -> getPassword() == p){
            return current;
        }
        current = current -> getNext();
    }
    return current;
}