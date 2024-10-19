#include "Equipo.h"
#include <iostream>

void Equipo::listarPartidos() const {
    std::cout << "Listando partidos del equipo: " << nombre << std::endl;
    for (const auto& partido : partidos) {
        std::cout << partido.fecha << " - " << partido.oponente << " - " << partido.golesFavor << " a " << partido.golesContra << " en " << partido.competicion << std::endl;
    }
}

void Equipo::agregarPartido(const std::string& fecha, const std::string& oponente, int golesFavor, int golesContra, const std::string& competicion) {
    partidos.push_back({fecha, oponente, golesFavor, golesContra, competicion});
}