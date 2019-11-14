#ifndef ARBOL_B_ARBOL_B_H
#define ARBOL_B_ARBOL_B_H

#include "Nodo.h"

template <typename T>
class ArbolB {
private:
    Node <T>* raiz;
    unsigned int grado;

public:
    explicit ArbolB(unsigned int grado) : grado(grado), raiz(nullptr) {};

    Node <T>* buscar(T valor) {
        return (raiz) ? raiz->buscar(valor) : nullptr;
    }

    bool insertar(T valor) {
        if (!raiz) {
            raiz = new Node<T>(grado, true);
            raiz->indices[0] = valor;
            raiz->actualGradoMinimo = 1;
            return true;
        }
        if (raiz->indices == grado - 1) {
            Node <T> *temporal = new Node<T>(grado, false);
            temporal->hijos[0] = raiz;
            temporal->intercambiarHijo(0, raiz);
            int i = 0;
            if (temporal->indices[0] < valor) {
                i++;
            }
            temporal->hijos[i]->insertarNoLLeno(valor);
            raiz = temporal;
        } else {
            raiz->insertarNoLLeno(valor);
        }
    }

    bool eliminar(int k) {
        return true;
    }

    void imprimir() {
        if (raiz) {
            raiz->recorrerNodos();
        }
    }

    ~ArbolB() {};
};

#endif //ARBOL_B_ARBOL_B_H