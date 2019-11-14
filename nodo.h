#ifndef ARBOL_B_NODO_H
#define ARBOL_B_NODO_H

#include <vector>
#include "Arbol_B.h"

using namespace std;

template <typename T>
class Node {
private:
    unsigned int gradoMinimo;
    unsigned int actualGradoMinimo;
    vector <unsigned int> indices;
    vector < Node<T>* > hijos;
    bool esHoja;

public:
    explicit Node(unsigned int gradoMinimo, bool esHoja) : gradoMinimo(gradoMinimo), esHoja(esHoja), indices(gradoMinimo - 1), hijos(gradoMinimo) {
        actualGradoMinimo = 0;
    }

    void insertarNoLLeno(T valor) {
        int i = actualGradoMinimo - 1;
        if (esHoja) {
            while (i >= 0 && indices[i] > valor) {
                indices[i + 1] = indices[i];
                i--;
            }
            indices[i + 1] = valor;
            actualGradoMinimo++;
        } else {
            while (i >= 0 && indices[i] > valor) {
                i--;
            }
            if (hijos[i + 1]->actualGradoMinimo == gradoMinimo - 1) {
                intercambiarHijo(i + 1, hijos[i + 1]);
                if (indices[i + 1] < valor) {
                    i++;
                }
            }
            hijos[i + 1]->insertarNoLLeno(valor);
        }
    }

    void intercambiarHijo(T indice, Node <T> *hermano) {
        auto *temporal = new Node<T>(hermano->gradoMinimo, hermano->esHoja);
        temporal->actualGradoMinimo = gradoMinimo - 1;
        for (int i = 0; i < gradoMinimo - 1; ++i) {
            temporal->indices[i] = hermano->indices[i + gradoMinimo];
        }
        if (!hermano->esHoja) {
            for (int i = 0; i < gradoMinimo; ++i) {
                temporal->hijos[i] = hermano->hijos[i + gradoMinimo];
            }
        }
        hermano->actualGradoMinimo = gradoMinimo - 1;
        for (int i = actualGradoMinimo; i >= indice + 1; --i) {
            hijos[i + 1] = hijos[i];
        }
        hijos[indice + 1] = temporal;
        for (int i = actualGradoMinimo - 1; i >= indice; --i) {
            indices[i + 1] = indices[i];
        }
        indices[indice] = hermano->indices[gradoMinimo - 1];
        actualGradoMinimo++;
    }

    void recorrerNodos() {
        int i;
        for (i = 0; i < actualGradoMinimo; ++i) {
            if (!esHoja) {
                hijos[i]->recorrerNodos();
            }
            cout << ' ' << indices[i];
        }
        if (!esHoja) {
            hijos[i]->recorrerNodos();
        }
    }

    Node <T>* buscar(T valor) {
        int i = 0;
        while (i < actualGradoMinimo && valor > indices[i]) {
            i++;
        }
        if (indices[i] == valor) {
            return this;
        }
        if (esHoja) {
            return nullptr;
        }
        return hijos[i]->buscar(valor);
    }

    friend class ArbolB;
};

#endif //ARBOL_B_NODO_H