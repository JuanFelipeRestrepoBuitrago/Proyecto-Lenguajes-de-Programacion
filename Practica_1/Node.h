//
// Created by Juan Felipe Restrepo Buitrago on 7/09/2022.
//

#ifndef PROYECTOLENGUAJESPROGRAMACION_NODE_H
#define PROYECTOLENGUAJESPROGRAMACION_NODE_H
#include "string"
using namespace std;

class Node {
private:
    string username;
    string password;
    Node * next;
public:
    Node(string u, string p, Node * n);
    Node(string u, string p);
    string getUsername();
    string getPassword();
    Node * getNext();
    void setUsername(string u);
    void setPassword(string p);
    void setNext(Node * n);

    bool add_user_at_the_end(string u, string p);
//    bool search_user_by_username(string u);
//    bool search_user_by_password(string p);
//
//    bool delete_user_by_username(string u);
//    bool delete_user_by_password(string p);
//
    void print_list(Node * current);
};


#endif //PROYECTOLENGUAJESPROGRAMACION_NODE_H
