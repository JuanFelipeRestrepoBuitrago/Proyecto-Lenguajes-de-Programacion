#include <iostream>
#include "Node.h"
int main() {
    Node *n = new Node("Juan", "1234", new Node("Pedro", "Dios lo bendiga"));
    n -> print_list(n);
}
