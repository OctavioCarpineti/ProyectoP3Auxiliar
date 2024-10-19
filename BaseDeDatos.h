#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include <string>
#include "Competicion.h"
#include "Arboles/ArbolBinarioAVL.h"
#include <vector>
#include "Arboles/NodoArbol.h"
#include "Arboles/NodoArbolAVL.h"
#include "Arboles/ArbolBinario.h"
#include "Arboles/ArbolBinarioAVL.h"
#include "Listas/Lista.h"
#include "Listas/ListaDoble.h"
#include "Listas/Nodo.h"

class BaseDeDatos {
private:
    ArbolBinarioAVL<Competicion*> competiciones;
    std::vector<std::vector<std::string>> datos;
    bool cargado;

public:
    BaseDeDatos();
    bool cargarArchivo(const std::string& nombreArchivo);
    bool estaCargado() const;
    void cargarDatos(const std::string& nombreArchivo);
    Competicion* buscarCompeticion(const std::string& nombre);
    void agregarCompeticion(Competicion* competicion);
    void eliminarCompeticion(const std::string& nombre);
};

#endif // BASEDEDATOS_H