//
// Created by Octavio Carpineti on 17/10/2024.
//

#ifndef PROYECTO_NODO_H
#define PROYECTO_NODO_H

template<class T>
class Nodo {
private:
    T dato;
    Nodo<T> *siguiente;
    Nodo<T> *anterior;

public:
    // Constructor por defecto con inicialización de dato
    Nodo() : dato(T()), siguiente(nullptr), anterior(nullptr) {}
    
    // Constructor con dato
    explicit Nodo(T d) : dato(d), siguiente(nullptr), anterior(nullptr) {}

    // Constructor copia
    Nodo(const Nodo<T> &n) : dato(n.dato), siguiente(nullptr), anterior(nullptr) {}

    T& getDato() {
        return dato;
    }

    void setDato(T d) {
        dato = d;
    }

    Nodo<T> *getSiguiente() const {
        return siguiente;
    }

    void setSiguiente(Nodo<T> *siguiente) {
        this->siguiente = siguiente;
    }

    Nodo<T> *getAnterior() const {
        return anterior;
    }

    void setAnterior(Nodo<T> *anterior) {
        this->anterior = anterior;
    }
};

#endif
