#include <iostream>

#include "Arbol_B.h"

using namespace std;

int main() {
    ArbolB <int> arbolB(3);
    arbolB.insertar(10);
    arbolB.insertar(20);
    arbolB.insertar(5);
    arbolB.insertar(6);
    arbolB.insertar(12);
    arbolB.insertar(30);
    arbolB.insertar(7);
    arbolB.insertar(17);
    arbolB.imprimir();

    return 0;
}