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

// Method to create a new list if it is empty
bool LinkedList::createList(string u, string p) {
    if (this -> head == nullptr) {
        this -> head = new Node(u, p);
        return true;
    } else {
        return false;
    }
}

// Method to add a user at the end of the list
bool LinkedList::addUserAtTheEnd(string u, string p) {
    Node * newNode = new Node(u, p);
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
Node *LinkedList::searchUserByPassword(string p) {
    Node * current = this -> head;

    while (current != nullptr){
        if (current -> getPassword() == p){
            return current;
        }
        current = current -> getNext();
    }
    return current;
}

// Recursive method to print the linked list by username
void LinkedList::printList(Node *current) {
    if (current == nullptr){
        cout << "NULL" << endl;
    }else if (current -> getNext() == nullptr) {
        cout << current->getUsername() << endl;
    }else{
        cout << current->getUsername() << " -> ";
        printList(current -> getNext());
    }
}

// Method to delete a user by password
bool LinkedList::deleteUserByPassword(string p) {
    Node * current = this -> head;
    Node * previous = nullptr;

    while (current != nullptr){
        if (current -> getPassword() == p){
            if (previous == nullptr){
                this -> head = current -> getNext();

            }else{
                previous -> setNext(current -> getNext());

            }
            delete current;
            return true;
        }
        previous = current;
        current = current -> getNext();
    }
    return false;
}

// Method to delete a user by username
bool LinkedList::deleteUserByUsername(string u) {
    Node * current = this -> head;
    Node * previous = nullptr;

    while (current != nullptr){
        if (current -> getUsername() == u){
            if (previous == nullptr){
                this -> head = current -> getNext();
            }else{
                previous -> setNext(current -> getNext());
            }
            delete current;
            return true;
        }
        previous = current;
        current = current -> getNext();
    }
    return false;
}