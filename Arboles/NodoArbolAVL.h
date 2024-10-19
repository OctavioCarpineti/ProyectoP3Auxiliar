//
// Created by Octavio Carpineti on 17/10/2024.
//

#ifndef PROYECTO_NODOARBOLAVL_H
#define PROYECTO_NODOARBOLAVL_H


#ifndef U05_ARBOL_ARBOL_NODOARBOLAVL_H_
#define U05_ARBOL_ARBOL_NODOARBOLAVL_H_

#include <iostream> // Para std::cout y std::endl
#include <string>   // Para std::string
using namespace std;

template <class T>
class NodoArbolAVL
{
private:
    T data;
    NodoArbolAVL *left, *right;
    int height;

public:
    NodoArbolAVL()
    {
        left = nullptr;
        right = nullptr;
        height=1;
    }

    NodoArbolAVL(T d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
        height = 1;
    }

    T getData() const
    {
        return data;
    }

    void setData(T d)
    {
        this->data = d;
    }

    NodoArbolAVL *getRight() const
    {
        return right;
    }

    void setRight(NodoArbolAVL *r)
    {
        this->right = r;
    }
    NodoArbolAVL *getLeft() const
    {
        return left;
    }

    void setLeft(NodoArbolAVL *l)
    {
        this->left = l;
    }

    int getHeight(){
        return height;
    }

    void setHeight(int h){
        height = h;
    }
/*
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
*/
    void print(bool esDerecho, std::string identacion) {
        if (esDerecho) {
            std::cout << identacion << " /";
            identacion += "  ";
        } else {
            std::cout << identacion << " \\";
            identacion += "  ";
        }
        std::cout << "-- " << data << std::endl;
    }

};

#endif // U05_ARBOL_ARBOL_NODOARBOLAVL_H_
#endif //PROYECTO_NODOARBOLAVL_H
