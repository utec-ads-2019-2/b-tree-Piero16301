#ifndef ARBOL_B_NODO_H
#define ARBOL_B_NODO_H

#include <vector>
#include <algorithm>
#include <iterator>
#include <queue> 

using namespace std;

template <typename T>
class ArbolB;

template <typename T>
class Nodo {
private:
    int gradoMinimo;
    int actualGradoMinimo;
    vector <T> indices;
    vector < Nodo<T>* > hijos;
    bool esHoja;

public:
    explicit Nodo(int gradoMinimo, bool esHoja) : gradoMinimo(gradoMinimo), esHoja(esHoja), indices(2 * gradoMinimo - 1), hijos(2 * gradoMinimo), actualGradoMinimo{0} {}

    int encontrarIndice(T indice) {
        int indiceTemporal = 0;
        while (indiceTemporal < actualGradoMinimo && indices[indiceTemporal] < indice) {
            ++indiceTemporal;
        }
        return indiceTemporal;
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
            if (hijos[i + 1]->actualGradoMinimo == 2 * gradoMinimo - 1) {
                separarHijo(i + 1, hijos[i + 1]);
                if (indices[i + 1] < valor) {
                    i++;
                }
            }
            hijos[i + 1]->insertarNoLLeno(valor);
        }
    }

    void separarHijo(T indice, Nodo <T> *hermano) {
        auto *temporal = new Nodo<T>(hermano->gradoMinimo, hermano->esHoja);
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

    /*
    El tamaño de los nodos no es el correcto,
    hay también un segmentation fault
    */
    void recorrerNodos() {
        /*int i;
        for (i = 0; i < actualGradoMinimo; ++i) {
            if (!esHoja) {
                hijos[i]->recorrerNodos();
            }
            cout << indices[i] << " ";
        }
        if (!esHoja) {
            hijos[i]->recorrerNodos();
        }*/

        /*queue<Nodo<T>*> next;
        next.push(this);

        while (!next.empty()) {
            Nodo<T>* temp = next.front();
            next.pop();

            temp->printIndexes();

            for (int i = 0; i < temp->hijos.size(); i++) {
                next.push(temp->hijos[i]);
            }

            cout << endl << endl;
        }  */
    }

    void printIndexes() {
        for (int i = 0; i < indices.size(); i++) {
            cout << indices[i] << " ";
        }
    }

    Nodo <T>* buscar(T valor) {
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

    T obtenerPadre(int indice) {
        Nodo <T> *actual = hijos[indice];
        while (!actual->esHoja) {
            actual = actual->hijos[actual->actualGradoMinimo];
        }
        return actual->indices[actual->actualGradoMinimo - 1];
    }

    T obtenerHijo(int indice) {
        Nodo <T> *actual = hijos[indice + 1];
        while (!actual->esHoja) {
            actual = actual->hijos[0];
        }
        return actual->indices[0];
    }

    void unir(int indice) {
        Nodo <T> *hijo = hijos[indice];
        Nodo <T> *hermano = hijos[indice + 1];
        hijo->indices[gradoMinimo - 1] = indices[indice];
        for (int i = 0; i < hermano->actualGradoMinimo; ++i) {
            hijo->indices[i + gradoMinimo] = hermano->indices[i];
        }
        if (!hijo->esHoja) {
            for (int i = 0; i <= hermano->actualGradoMinimo; ++i) {
                hijo->hijos[i + gradoMinimo] = hermano->hijos[i];
            }
        }
        for (int i = indice + 1; i < actualGradoMinimo; ++i) {
            indices[i - 1] = indices[i];
        }
        for (int i = indice + 2; i <= actualGradoMinimo; ++i) {
            hijos[i - 1] = hijos[i];
        }
        hijo->actualGradoMinimo += hermano->actualGradoMinimo + 1;
        actualGradoMinimo--;
        delete hermano;
    }

    void prestarAnterior(int indice) {
        Nodo <T> *hijo = hijos[indice];
        Nodo <T> *hermano = hijos[indice - 1];
        for (int i = hijo->actualGradoMinimo - 1; i >= 0; --i) {
            hijo->indices[i + 1] = hijo->indices[i];
        }
        if (!hijo->esHoja) {
            for (int i = hijo->actualGradoMinimo; i >= 0; --i) {
                hijo->hijos[i + 1] = hijo->hijos[i];
            }
        }
        hijo->indices[0] = indices[indice - 1];
        if (!hijo->esHoja) {
            hijo->hijos[0] = hermano->hijos[hermano->actualGradoMinimo];
        }
        indices[indice - 1] = hermano->indices[hermano->actualGradoMinimo - 1];
        hijo->actualGradoMinimo++;
        hermano->actualGradoMinimo--;
    }

    void prestarSiguiente(int indice) {
        Nodo <T> *hijo = hijos[indice];
        Nodo <T> *hermano = hijos[indice + 1];
        hijo->indices[hijo->actualGradoMinimo] = indices[indice];
        if (!hijo->esHoja) {
            hijo->hijos[hijo->actualGradoMinimo + 1] = hermano->hijos[0];
        }
        indices[indice] = hermano->indices[0];
        for (int i = 1; i < hermano->actualGradoMinimo; ++i) {
            hermano->indices[i - 1] = hermano->indices[i];
        }
        if (!hermano->esHoja) {
            for (int i = 1; i <= hermano->actualGradoMinimo; ++i) {
                hermano->hijos[i - 1] = hermano->hijos[i];
            }
        }
        hijo->actualGradoMinimo++;
        hermano->actualGradoMinimo--;
    }

    void llenarHijo(int indice) {
        if (indice != 0 && hijos[indice - 1]->actualGradoMinimo >= gradoMinimo) {
            prestarAnterior(indice);
        }
        else if (indice != actualGradoMinimo && hijos[indice + 1]->actualGradoMinimo >= gradoMinimo) {
            prestarSiguiente(indice);
        }
        else {
            if (indice != actualGradoMinimo) {
                unir(indice);
            } else {
                unir(indice - 1);
            }
        }
    }

    void eliminarNoHoja(int indice) {
        T temporal = indices[indice];
        if (hijos[indice]->actualGradoMinimo >= gradoMinimo) {
            T padre = obtenerPadre(indice);
            indices[indice] = padre;
            hijos[indice]->eliminar(padre);
        }
        else if (hijos[indice + 1]->actualGradoMinimo >= gradoMinimo) {
            T hijo = obtenerHijo(indice);
            indices[indice] = hijo;
            hijos[indice + 1]->eliminar(hijo);
        }
        else {
            unir(indice);
            hijos[indice]->eliminar(temporal);
        }
    }

    void eliminarHoja(int indice) {
        for (int i = indice + 1; i < actualGradoMinimo; ++i) {
            indices[i - 1] = indices[i];
        }
        actualGradoMinimo--;
    }

    void eliminar(T valor) {
        int indiceBase = encontrarIndice(valor);
        if (indiceBase < actualGradoMinimo && indices[indiceBase] == valor) {
            if (esHoja) {
                eliminarHoja(indiceBase);
            } else {
                eliminarNoHoja(indiceBase);
            }
        } else {
            if (esHoja) {
                cout << "El valor " << valor << " no se encuentra en el arbol" << endl;
                return;
            }
            bool puntoPartida = indiceBase == actualGradoMinimo;
            if (hijos[indiceBase]->actualGradoMinimo < gradoMinimo) {
                llenarHijo(indiceBase);
            }
            if (puntoPartida && indiceBase > actualGradoMinimo) {
                hijos[indiceBase - 1]->eliminar(valor);
            } else {
                hijos[indiceBase]->eliminar(valor);
            }
        }
    }

    void killSelf() {
        if (!esHoja) {
            for (int i = 0; i < hijos.size(); ++i) {
                if (hijos[i]) {
                    hijos[i]->killSelf();
                }
            }
        }
        delete this;
    }

    friend class ArbolB <T>;
};

#endif //ARBOL_B_NODO_H