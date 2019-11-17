#ifndef ARBOL_B_ARBOLB_H
#define ARBOL_B_ARBOLB_H

#include "Nodo.h"

template <typename T>
class ArbolB {
private:
    Nodo <T>* raiz;
    int grado;

public:
    explicit ArbolB(int grado) : grado(grado), raiz(nullptr) {};

    Nodo <T>* buscar(T valor) {
        return (raiz) ? raiz->buscar(valor) : nullptr;
    }

    bool insertar(T valor) {
        if (!raiz) {
            raiz = new Nodo<T>(grado, true);
            raiz->indices[0] = valor;
            raiz->actualGradoMinimo = 1;
            return true;
        }
        if (raiz->actualGradoMinimo == 2 * grado - 1) {
            auto *temporal = new Nodo<T>(grado, false);
            temporal->hijos[0] = raiz;
            temporal->separarHijo(0, raiz);
            int i = 0;
            if (temporal->indices[0] < valor) {
                i++;
            }
            temporal->hijos[i]->insertarNoLLeno(valor);
            raiz = temporal;
            return true;
        } else {
            raiz->insertarNoLLeno(valor);
            return true;
        }
    }

    bool eliminar(int k) {
        return true;
    }

    void imprimir() {
        if (raiz) {
            raiz->recorrerNodos();
            cout << endl;
        }
    }

    ~ArbolB() {
        if (raiz) {
            raiz->killSelf();
        }
    }
};

#endif //ARBOL_B_ARBOLB_H