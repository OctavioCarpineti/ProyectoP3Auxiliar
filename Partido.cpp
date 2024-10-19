#include "Partido.h"

Partido::Partido(const std::string& fecha, const std::string& equipoLocal, int golesLocal, int golesVisitante, const std::string& equipoVisitante, const std::string& competicion)
    : fecha(fecha), equipoLocal(equipoLocal), golesLocal(golesLocal), golesVisitante(golesVisitante), equipoVisitante(equipoVisitante), competicion(competicion) {}

const std::string& Partido::getFecha() const {
    return fecha;
}

const std::string& Partido::getEquipoLocal() const {
    return equipoLocal;
}

const std::string& Partido::getEquipoVisitante() const {
    return equipoVisitante;
}

int Partido::getGolesLocal() const {
    return golesLocal;
}

int Partido::getGolesVisitante() const {
    return golesVisitante;
}

const std::string& Partido::getCompeticion() const {
    return competicion;
}