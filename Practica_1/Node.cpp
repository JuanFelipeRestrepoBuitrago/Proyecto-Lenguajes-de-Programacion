//
// Created by Juan Felipe Restrepo Buitrago on 7/09/2022.
//

#include "Node.h"
#include "string"
#include "iostream"
using namespace std;

// Constructor having a next node
Node::Node(string u, string p, Node *n) {
    this -> username = u;
    this -> password = p;
    this -> next = n;
}

// Constructor without a next node
Node::Node(std::string u, std::string p) {
    this -> username = u;
    this -> password = p;
    this -> next = nullptr;
}

// Method to get the next node of the current one
Node *Node::getNext() {
    return this -> next;
}

// Method to set the next of the current node
void Node::setNext(Node * n) {
    this -> next = n;
}

// Method to get the password of the current node
string Node::getPassword() {
    return this -> password;
}

// Method to set the password of the current node
void Node::setPassword(string p) {
    this -> password = p;
}

// Method to get the username of the current node
string Node::getUsername() {
    return this->username;
}

// Method to set the username of the current node
void Node::setUsername(string u) {
    this -> username = u;
}

