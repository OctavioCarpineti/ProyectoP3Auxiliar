//
// Created by Octavio Carpineti on 17/10/2024.
//

#ifndef PROYECTO_NODOARBOLAVL_H
#define PROYECTO_NODOARBOLAVL_H


#ifndef U05_ARBOL_ARBOL_NODOARBOLAVL_H_
#define U05_ARBOL_ARBOL_NODOARBOLAVL_H_

#include <string.h>
#include <iostream>

using namespace std;

template <class T>
class NodoArbolAVL
{
private:
    T data;
    NodoArbolAVL<T>* left;
    NodoArbolAVL<T>* right;
    int height;

public:
    explicit NodoArbolAVL(const T& d) : data(d), height(1), left(nullptr), right(nullptr) {}

    T getData() const
    {
        return data;
    }

    void setData(T d)
    {
        this->data = d;
    }

    NodoArbolAVL<T>* getRight() const
    {
        return right;
    }

    void setRight(NodoArbolAVL<T>* r)
    {
        this->right = r;
    }

    NodoArbolAVL<T>* getLeft() const
    {
        return left;
    }

    void setLeft(NodoArbolAVL<T>* l)
    {
        this->left = l;
    }

    int getHeight(){
        return height;
    }

    void setHeight(int h){
        height = h;
    }

    void print(bool esDerecho, string identacion) {
        if (right != NULL) {
            right->print(true, identacion + (esDerecho ? "     " : "|    "));
        }
        cout << identacion;
        if (esDerecho) {
            cout << " /";
        } else {
            cout << " \\";
        }
        cout << "-- ";
        cout << data << endl;
        if (left != NULL) {
            left->print(false, identacion + (esDerecho ? "|    " : "     "));
        }
    }

};

#endif // U05_ARBOL_ARBOL_NODOARBOLAVL_H_
#endif //PROYECTO_NODOARBOLAVL_H
