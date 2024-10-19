#include "GestorConsultas.h"
#include "BaseDeDatos.h"
#include <iostream>

GestorConsultas::GestorConsultas(BaseDeDatos* baseDeDatos)
    : baseDeDatos(baseDeDatos) {}

void GestorConsultas::cargarDatos(const std::string& nombreArchivo) {
    baseDeDatos->cargarDatos(nombreArchivo);
}

void GestorConsultas::consultarResultadosEquipo(const std::string& nombreEquipo, const std::string& nombreCompeticion) {
    Competicion* competicion = baseDeDatos->buscarCompeticion(nombreCompeticion);
    if (competicion) {
        Equipo* equipo = competicion->buscarEquipo(nombreEquipo);
        if (equipo) {
            equipo->listarPartidos();
        } else {
            std::cout << "Equipo no encontrado." << std::endl;
        }
    } else {
        std::cout << "Competición no encontrada." << std::endl;
    }
}

void GestorConsultas::agregarCompeticion(const std::string& nombreCompeticion) {
    Competicion* competicion = new Competicion(nombreCompeticion);
    baseDeDatos->agregarCompeticion(competicion);
}

void GestorConsultas::eliminarCompeticion(const std::string& nombreCompeticion) {
    baseDeDatos->eliminarCompeticion(nombreCompeticion);
}

void GestorConsultas::agregarPartido(const std::string& nombreCompeticion, const std::string& fecha, const std::string& equipoLocal, int golesLocal, int golesVisitante, const std::string& equipoVisitante) {
    Competicion* competicion = baseDeDatos->buscarCompeticion(nombreCompeticion);
    if (competicion) {
        Equipo* equipoLocalObj = competicion->buscarEquipo(equipoLocal);
        if (!equipoLocalObj) {
            equipoLocalObj = new Equipo(equipoLocal);
            competicion->agregarEquipo(equipoLocalObj);
        }
        Equipo* equipoVisitanteObj = competicion->buscarEquipo(equipoVisitante);
        if (!equipoVisitanteObj) {
            equipoVisitanteObj = new Equipo(equipoVisitante);
            competicion->agregarEquipo(equipoVisitanteObj);
        }
        equipoLocalObj->agregarPartido(fecha, equipoVisitante, golesLocal, golesVisitante, nombreCompeticion);
        equipoVisitanteObj->agregarPartido(fecha, equipoLocal, golesVisitante, golesLocal, nombreCompeticion);
    } else {
        std::cout << "Competición no encontrada." << std::endl;
    }
}

void GestorConsultas::eliminarPartido(const std::string& nombreCompeticion, const std::string& fecha, const std::string& equipoLocal, const std::string& equipoVisitante) {
    // Implementar la lógica para eliminar un partido
}

void GestorConsultas::modificarPartido(const std::string& nombreCompeticion, const std::string& fecha, const std::string& equipoLocal, int golesLocal, int golesVisitante, const std::string& equipoVisitante) {
    // Implementar la lógica para modificar un partido
}

void GestorConsultas::obtenerDatosCompeticion(const std::string& nombreCompeticion) {
    Competicion* competicion = baseDeDatos->buscarCompeticion(nombreCompeticion);
    if (competicion) {
        std::cout << "Datos de la competición: " << nombreCompeticion << std::endl;
        std::cout << "Equipos participantes:" << std::endl;
        for (const auto& equipo : competicion->getEquipos()) {
            std::cout << "- " << equipo->getNombre() << std::endl;
        }
        std::cout << "Partidos:" << std::endl;
        for (const auto& partido : competicion->getPartidos()) {
            std::cout << partido.getFecha() << ": " << partido.getEquipoLocal() << " " << partido.getGolesLocal() << " - " << partido.getGolesVisitante() << " " << partido.getEquipoVisitante() << std::endl;
        }
    } else {
        std::cout << "Competición no encontrada." << std::endl;
    }
}