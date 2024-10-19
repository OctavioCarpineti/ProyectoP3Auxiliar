#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H
#include "Competicion.h"
#include <string>
#include <vector>

class BaseDeDatos {
private:
    bool cargado;

    // Función auxiliar para limpiar y convertir los valores de goles
    static int convertirGoles(const std::string& str);

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