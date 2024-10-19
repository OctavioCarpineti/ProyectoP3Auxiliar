#include "Equipo.h"
#include <iostream>

Equipo::Equipo(const std::string& nombre) : nombre(nombre) {}

const std::string& Equipo::getNombre() const {
    return nombre;
}

void Equipo::listarPartidos() const {
    std::cout << "Listando partidos del equipo: " << nombre << std::endl;
    for (const auto& partido : partidos) {
        std::cout << partido.getFecha() << " - " << partido.getEquipoVisitante() << " - " << partido.getGolesLocal() << " a " << partido.getGolesVisitante() << " en " << partido.getCompeticion() << std::endl;
    }
}

void Equipo::agregarPartido(const std::string& fecha, const std::string& oponente, int golesFavor, int golesContra, const std::string& competicion) {
    partidos.emplace_back(fecha, nombre, golesFavor, golesContra, oponente, competicion);
}