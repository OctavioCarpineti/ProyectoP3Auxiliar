#include "Competicion.h"
#include <iostream>

Competicion::Competicion(const std::string& nombre) : nombre(nombre) {}

std::string Competicion::getNombre() const {
    return nombre;
}

void Competicion::agregarEquipo(Equipo* equipo) {
    std::cout << "Agregando equipo: " << equipo->getNombre() << " a la competición: " << nombre << std::endl;
    equipos[equipo->getNombre()] = equipo;
}

Equipo* Competicion::buscarEquipo(const std::string& nombreEquipo) {
    std::cout << "Buscando equipo: " << nombreEquipo << " en la competición: " << nombre << std::endl;
    auto it = equipos.find(nombreEquipo);
    if (it != equipos.end()) {
        return it->second;
    }
    return nullptr;
}

void Competicion::agregarPartido(const Partido& partido) {
    std::cout << "Agregando partido: " << partido.getFecha() << " - " << partido.getEquipoLocal() << " vs " << partido.getEquipoVisitante() << " en " << partido.getCompeticion() << std::endl;
    partidos.push_back(partido);
}

const std::map<std::string, Equipo*>& Competicion::getEquipos() const {
    return equipos;
}

const std::list<Partido>& Competicion::getPartidos() const {
    return partidos;
}