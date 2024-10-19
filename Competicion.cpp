#include "Competicion.h"

// Implementación del método para agregar un equipo a la competición
void Competicion::agregarEquipo(Equipo* equipo) {
    equipos.push_back(equipo);
}

// Implementación del método para buscar un equipo por nombre en la competición
Equipo* Competicion::buscarEquipo(const std::string& nombreEquipo) {
    for (auto& equipo : equipos) {
        if (equipo->getNombre() == nombreEquipo) {
            return equipo;
        }
    }
    return nullptr;
}