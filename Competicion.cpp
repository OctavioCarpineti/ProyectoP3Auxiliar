#include "Competicion.h"

Competicion::Competicion(const std::string& nombre) : nombre(nombre) {}

std::string Competicion::getNombre() const {
    return nombre;
}

void Competicion::agregarEquipo(Equipo* equipo) {
    equipos.push_back(equipo);
}

Equipo* Competicion::buscarEquipo(const std::string& nombreEquipo) {
    for (auto& equipo : equipos) {
        if (equipo->getNombre() == nombreEquipo) {
            return equipo;
        }
    }
    return nullptr;
}

void Competicion::agregarPartido(const Partido& partido) {
    partidos.push_back(partido);
}

const std::vector<Equipo*>& Competicion::getEquipos() const {
    return equipos;
}

const std::vector<Partido>& Competicion::getPartidos() const {
    return partidos;
}