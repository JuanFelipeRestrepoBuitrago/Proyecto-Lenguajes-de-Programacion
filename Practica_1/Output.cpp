//
// Created by Usuario on 12/09/2022.
//

#include "Output.h"
#include <string>
#include "iostream"
#include "chrono"
#include "thread"
using namespace std;

void Output::menu() {
    this_thread::sleep_for(chrono::milliseconds(2500));
    cout << "1. Leer Archivo de Usuarios" << endl;
    cout << "2. Ingresar un Nuevo Usuario" << endl;
    cout << "3. Buscar Usuario" << endl;
}