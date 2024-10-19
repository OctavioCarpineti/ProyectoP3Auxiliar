//
// Created by Octavio Carpineti on 17/10/2024.
//

#ifndef PROYECTO_NODOARBOL_H
#define PROYECTO_NODO_H

#ifndef NODO_H
#define NODO_H

template<class T>
class Nodo{
private:
    T dato;
    Nodo<T> *siguiente;

public:
    T getDato(){
        return dato;
    }

    void setDato(T d){
        dato = d;
    }

    Nodo<T> *getSiguiente(){
        return siguiente;
    }

    void setSiguiente(Nodo<T> *siguiente){
        this->siguiente = siguiente;
    }


};

#endif //NODO_H

#endif //PROYECTO_NODOARBOL_H
