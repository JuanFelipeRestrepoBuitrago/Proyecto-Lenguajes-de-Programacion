//
// Created by Juan Felipe Restrepo Buitrago on 7/09/2022.
//

#include "Node.h"
#include "string"
#include "iostream"
using namespace std;

Node::Node(string u, string p, Node *n) {
    this -> username = std::move(u);
    this -> password = std::move(p);
    this -> next = n;
}

Node::Node(std::string u, std::string p) {
    this -> username = std::move(u);
    this -> password = std::move(p);
    this -> next = nullptr;
}

Node *Node::getNext() {
    return this -> next;
}

void Node::setNext(Node * n) {
    this -> next = n;
}

string Node::getPassword() {
    return this -> password;
}

void Node::setPassword(string p) {
    this -> password = std::move(p);
}

string Node::getUsername() {
    return this->username;
}

void Node::setUsername(string u) {
    this -> username = std::move(u);
}

bool Node::add_user_at_the_end(string u, string p) {
    Node * newNode = new Node(std::move(u), std::move(p));
    Node * current = this -> next;

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

void Node::print_list(Node *current) {
    if (current != nullptr) {
        cout << current -> getUsername() << " -> ";
        this -> print_list(current -> getNext());
    }else{
        cout << "NULL" <<endl;
    }
}