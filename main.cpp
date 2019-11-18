#include <iostream>

#include "ArbolB.h"

using namespace std;

int main() {
    ArbolB <double> arbolB(3);
    arbolB.insertar(1);
    arbolB.insertar(2);
    arbolB.insertar(3);
    arbolB.insertar(4);
    arbolB.insertar(5);
    arbolB.insertar(6);
    arbolB.insertar(7);
    arbolB.insertar(8);
    arbolB.insertar(8);
    arbolB.imprimir();
    cout << arbolB.buscar(3) << endl;
    cout << arbolB.buscar(9) << endl;
    arbolB.eliminar(8);
    arbolB.imprimir();
    arbolB.eliminar(8);
    arbolB.imprimir();
    arbolB.eliminar(8);
    arbolB.imprimir();
    return 0;
}