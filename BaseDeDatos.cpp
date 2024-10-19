#include "BaseDeDatos.h"
#include <fstream>
#include <sstream>
#include <iostream>

void BaseDeDatos::cargarDatos(const std::string& nombreArchivo) {
    std::ifstream archivo("Recursos/" + nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }

    std::string linea;
    std::getline(archivo, linea);

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string jornada, fecha, equipoLocal, equipoVisitante, competicion;
        int golesLocal, golesVisitante;

        std::getline(ss, jornada, ',');
        std::getline(ss, fecha, ',');
        std::getline(ss, equipoLocal, ',');
        ss >> golesLocal;
        ss.ignore(1);
        ss >> golesVisitante;
        ss.ignore(1);
        std::getline(ss, equipoVisitante, ',');
        std::getline(ss, competicion, ',');

        Competicion* competicionObj = buscarCompeticion(competicion);
        if (!competicionObj) {
            competicionObj = new Competicion(competicion);
            competiciones.put(competicionObj);
        }

        Equipo* equipoLocalObj = competicionObj->buscarEquipo(equipoLocal);
        if (!equipoLocalObj) {
            equipoLocalObj = new Equipo(equipoLocal);
            competicionObj->agregarEquipo(equipoLocalObj);
        }

        Equipo* equipoVisitanteObj = competicionObj->buscarEquipo(equipoVisitante);
        if (!equipoVisitanteObj) {
            equipoVisitanteObj = new Equipo(equipoVisitante);
            competicionObj->agregarEquipo(equipoVisitanteObj);
        }

        equipoLocalObj->agregarPartido(fecha, equipoVisitante, golesLocal, golesVisitante, competicion);
        equipoVisitanteObj->agregarPartido(fecha, equipoLocal, golesVisitante, golesLocal, competicion);
    }

    archivo.close();
}

Competicion* BaseDeDatos::buscarCompeticion(const std::string& nombre) {
    // Implementar la lógica para buscar una competición
    // Ejemplo:
    // return competiciones.buscar(nombre);
    return nullptr; // Placeholder
}

void BaseDeDatos::agregarCompeticion(Competicion* competicion) {
    // Implementar la lógica para agregar una competición
    // Ejemplo:
    // competiciones.put(competicion);
}

void BaseDeDatos::eliminarCompeticion(const std::string& nombre) {
    // Implementar la lógica para eliminar una competición
    // Ejemplo:
    // competiciones.eliminar(nombre);
}