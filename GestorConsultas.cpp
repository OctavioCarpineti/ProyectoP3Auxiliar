//
// Created by Octavio Carpineti on 18/10/2024.
//

// GestorConsultas.cpp
#include "GestorConsultas.h"
#include "BaseDeDatos.h"

// Constructor de la clase GestorConsultas
GestorConsultas::GestorConsultas(BaseDeDatos* baseDeDatos)
    : baseDeDatos(baseDeDatos) {}

// Realiza una consulta de resultados de un equipo en una competición específica
void GestorConsultas::consultarResultadosEquipo(const std::string& nombreEquipo, const std::string& nombreCompeticion) {
    Competicion* competicion = baseDeDatos->buscarCompeticion(nombreCompeticion);
    if (competicion) {
        Equipo* equipo = competicion->buscarEquipo(nombreEquipo);
        if (equipo) {
            equipo->listarPartidos();
        } else {
            std::cout << "Equipo no encontrado en la competición." << std::endl;
        }
    } else {
        std::cout << "Competición no encontrada." << std::endl;
    }
}

// Otros métodos de consulta se implementarán aquí