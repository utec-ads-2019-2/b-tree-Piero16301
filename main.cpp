#include <iostream>

#include "ArbolB.h"

using namespace std;

int main() {
    ArbolB <int> arbolB(3);
    arbolB.insertar(10);
    arbolB.insertar(20);
    arbolB.insertar(30);
    arbolB.insertar(40);
    arbolB.insertar(50);
    arbolB.insertar(60);
    arbolB.insertar(70);
    arbolB.insertar(80);
    arbolB.imprimir();
    return 0;
}