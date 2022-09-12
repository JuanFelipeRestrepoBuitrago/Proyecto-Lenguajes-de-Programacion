//
// Created by Juan Felipe Restrepo Buitrago on 12/09/2022.
//

#include "Output.h"
#include "iostream"
#include "thread"
using namespace std;

void Output::menu() {
    this_thread::sleep_for(chrono::milliseconds(2500));
    cout << "****** Menu ******" << endl;
    cout << "1. Leer Archivo de Usuarios" << endl;
    cout << "2. Ingresar un Nuevo Usuario" << endl;
    cout << "3. Buscar Usuario" << endl;
    cout << "4. Eliminar Usuario" << endl;
    cout << "5. Imprimir Usuarios" << endl;
    cout << "6. Salir" << endl;

    cout << "Ingrese una Opcion: ";
}