//
// Created by Octavio Carpineti on 17/10/2024.
//

#ifndef PROYECTO_LISTADOBLE_H
#define PROYECTO_LISTADOBLE_H

#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H

#include <iostream>
#include "Nodo.h"


template <class T>
class NodoDoble {
private:
    T dato;
    NodoDoble<T>* siguiente;
    NodoDoble<T>* anterior;

public:
    NodoDoble(T d) : dato(d), siguiente(nullptr), anterior(nullptr) {}

    T getDato() const { return dato; }
    void setDato(T d) { dato = d; }

    NodoDoble<T>* getSiguiente() const { return siguiente; }
    void setSiguiente(NodoDoble<T>* sig) { siguiente = sig; }

    NodoDoble<T>* getAnterior() const { return anterior; }
    void setAnterior(NodoDoble<T>* ant) { anterior = ant; }
};

template <class T>
class ListaDoble {
private:
    NodoDoble<T>* inicio;
    NodoDoble<T>* fin;
    int tam;

public:
    ListaDoble();
    ~ListaDoble();

    bool esVacia() const;
    int getTamanio() const;
    void insertarPrimero(T dato);
    void insertarUltimo(T dato);
    void remover(int pos);
    T getDato(int pos) const;
    void reemplazar(int pos, T dato);
    void imprimir() const;
    void vaciar();
    void insertar(int pos, const T& dato);
};

template <class T>
ListaDoble<T>::ListaDoble() : inicio(nullptr), fin(nullptr), tam(0) {}

template <class T>
ListaDoble<T>::~ListaDoble() {
    vaciar();
}

template <class T>
bool ListaDoble<T>::esVacia() const {
    return inicio == nullptr;
}

template <class T>
int ListaDoble<T>::getTamanio() const {
    return tam;
}

template <class T>
void ListaDoble<T>::insertarPrimero(T dato) {
    NodoDoble<T>* nuevo = new NodoDoble<T>(dato);

    if (esVacia()) {
        inicio = fin = nuevo;
    } else {
        nuevo->setSiguiente(inicio);
        inicio->setAnterior(nuevo);
        inicio = nuevo;
    }
    tam++;
}

template <class T>
void ListaDoble<T>::insertarUltimo(T dato) {
    NodoDoble<T>* nuevo = new NodoDoble<T>(dato);

    if (esVacia()) {
        inicio = fin = nuevo;
    } else {
        fin->setSiguiente(nuevo);
        nuevo->setAnterior(fin);
        fin = nuevo;
    }
    tam++;
}

template <class T>
void ListaDoble<T>::remover(int pos) {
    if (esVacia() || pos < 0 || pos >= getTamanio()) {
        throw std::out_of_range("Posición inválida");
    }

    NodoDoble<T>* aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == inicio) {
        inicio = inicio->getSiguiente();
        if (inicio != nullptr) {
            inicio->setAnterior(nullptr);
        }
    } else {
        aux->getAnterior()->setSiguiente(aux->getSiguiente());
        if (aux->getSiguiente() != nullptr) {
            aux->getSiguiente()->setAnterior(aux->getAnterior());
        }
    }

    if (aux == fin) {
        fin = fin->getAnterior();
        if (fin != nullptr) {
            fin->setSiguiente(nullptr);
        }
    }

    delete aux;
}

template <class T>
T ListaDoble<T>::getDato(int pos) const {
    if (pos < 0 || pos >= getTamanio()) {
        throw std::out_of_range("Posición inválida");
    }

    NodoDoble<T>* aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos) {
        aux = aux->getSiguiente();
        posActual++;
    }

    return aux->getDato();
}

template <class T>
void ListaDoble<T>::reemplazar(int pos, T dato) {
    if (pos < 0 || pos >= getTamanio()) {
        throw std::out_of_range("Posición inválida");
    }

    NodoDoble<T>* aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos) {
        aux = aux->getSiguiente();
        posActual++;
    }

    aux->setDato(dato);
}

template <class T>
void ListaDoble<T>::imprimir() const {
    NodoDoble<T>* aux = inicio;

    while (aux != nullptr) {
        std::cout << aux->getDato() << " <-> ";
        aux = aux->getSiguiente();
    }
    std::cout << "NULL" << std::endl;
}

template <class T>
void ListaDoble<T>::vaciar() {
    NodoDoble<T>* aux = inicio;

    while (aux != nullptr) {
        NodoDoble<T>* aBorrar = aux;
        aux = aux->getSiguiente();
        delete aBorrar;
    }

    inicio = fin = nullptr;
    tam = 0;
}

template <class T>
void ListaDoble<T>::insertar(int pos, const T& dato) {
    if (pos < 0 || pos > getTamanio()) throw std::out_of_range("Posición inválida");
    
    NodoDoble<T>* nuevo = new NodoDoble<T>(dato);
    if (pos == 0) {
        nuevo->setSiguiente(inicio);
        if (inicio) inicio->setAnterior(nuevo);
        inicio = nuevo;
    } else {
        NodoDoble<T>* aux = inicio;
        for (int i = 0; i < pos - 1; i++) aux = aux->getSiguiente();
        nuevo->setSiguiente(aux->getSiguiente());
        nuevo->setAnterior(aux);
        if (aux->getSiguiente()) aux->getSiguiente()->setAnterior(nuevo);
        aux->setSiguiente(nuevo);
    }
    tam++;
}

#endif // LISTA_DOBLE_H

#endif //PROYECTO_LISTADOBLE_H
