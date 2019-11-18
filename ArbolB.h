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

    bool buscar(T valor) {
        bool resultado = false;
        if (!raiz) {
            return false;
        } else {
            return raiz->buscar(valor) != nullptr;
        }
    }

    bool insertar(T valor) {
        if (!raiz) {
            raiz = new Nodo<T>(grado, true);
            raiz->indices[0] = valor;
            raiz->actualGradoMinimo = 1;
            return true;
        } else {
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
    }

    bool eliminar(T valor) {
        if (!raiz) {
            cout << "El arbol esta vacio" << endl;
            return false;
        }
        raiz->eliminar(valor);
        if (raiz->actualGradoMinimo == 0) {
            Nodo <T> *temporal = raiz;
            if (raiz->esHoja) {
                raiz = nullptr;
            } else {
                raiz = raiz->hijos[0];
            }
            delete temporal;
        }
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
        } else {
            cout << "El arbol esta vacio" << endl;
        }
    }
};

#endif //ARBOL_B_ARBOLB_H