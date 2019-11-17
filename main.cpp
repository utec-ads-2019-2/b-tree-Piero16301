#include <iostream>

#include "ArbolB.h"

using namespace std;

int main() {
    ArbolB <double> arbolB(3);
    arbolB.insertar(1.1);
    arbolB.insertar(2.2);
    arbolB.insertar(3.3);
    arbolB.insertar(4.4);
    arbolB.insertar(5.5);
    arbolB.insertar(6.6);
    arbolB.insertar(7.7);
    arbolB.insertar(8.8);
    arbolB.imprimir();
    return 0;
}