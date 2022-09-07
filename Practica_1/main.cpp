#include <iostream>
#include "Node.h"
int main() {
    Node *n = new Node("Juan", "1234", new Node("Pedro", "Dios lo bendiga"));
    n -> add_user_at_the_end("Felipe", "1234");
    n -> print_list(n);
}
