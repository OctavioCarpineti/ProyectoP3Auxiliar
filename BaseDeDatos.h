#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include <string>
#include <vector>
#include <map>
#include "Competicion.h"

class BaseDeDatos {
private:
    bool cargado;
    std::map<std::string, Competicion*> competiciones; // Mapa para almacenar competiciones

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