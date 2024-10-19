#ifndef GESTORCONSULTAS_H
#define GESTORCONSULTAS_H

#include "BaseDeDatos.h"
#include <string>

class GestorConsultas {
private:
    BaseDeDatos* baseDeDatos; // Puntero a la base de datos

public:
    GestorConsultas(BaseDeDatos* baseDeDatos);
    void cargarDatos(const std::string& nombreArchivo);
    void consultarResultadosEquipo(const std::string& nombreEquipo, const std::string& nombreCompeticion);
    void agregarCompeticion(const std::string& nombreCompeticion);
    void eliminarCompeticion(const std::string& nombreCompeticion);
    void agregarPartido(const std::string& nombreCompeticion, const std::string& fecha, const std::string& equipoLocal, int golesLocal, int golesVisitante, const std::string& equipoVisitante);
    void eliminarPartido(const std::string& nombreCompeticion, const std::string& fecha, const std::string& equipoLocal, const std::string& equipoVisitante);
    void modificarPartido(const std::string& nombreCompeticion, const std::string& fecha, const std::string& equipoLocal, int golesLocal, int golesVisitante, const std::string& equipoVisitante);
};

#endif // GESTORCONSULTAS_H