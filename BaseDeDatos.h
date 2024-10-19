#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include <string>
#include "Competicion.h"
#include "Arboles/ArbolBinarioAVL.h"

class BaseDeDatos {
public:
    void cargarDatos(const std::string& nombreArchivo);
    Competicion* buscarCompeticion(const std::string& nombre);
    void agregarCompeticion(Competicion* competicion);
    void eliminarCompeticion(const std::string& nombre);

private:
    ArbolBinarioAVL<Competicion*> competiciones;
};

#endif // BASEDEDATOS_H