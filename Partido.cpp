//
// Created by Octavio Carpineti on 17/10/2024.
//

// Partido.cpp
#include "Partido.h"
#include "Competicion.h"

// Constructor de la clase Partido
Partido::Partido(const std::string& fecha, const std::string& equipoLocal, int golesLocal, int golesVisitante, const std::string& equipoVisitante, const std::string& competicion)
    : fecha(fecha), equipoLocal(equipoLocal), golesLocal(golesLocal), golesVisitante(golesVisitante), equipoVisitante(equipoVisitante), competicion(competicion) {}

// Getters
std::string Partido::getFecha() const {
    return fecha;
}

std::string Partido::getEquipoLocal() const {
    return equipoLocal;
}

int Partido::getGolesLocal() const {
    return golesLocal;
}

int Partido::getGolesVisitante() const {
    return golesVisitante;
}

std::string Partido::getEquipoVisitante() const {
    return equipoVisitante;
}

std::string Partido::getCompeticion() const {
    return competicion;
}