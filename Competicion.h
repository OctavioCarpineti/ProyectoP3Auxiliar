#ifndef COMPETICION_H
#define COMPETICION_H

#include <string>
#include <vector>
#include "Equipo.h"

class Competicion {
public:
    // Constructor que inicializa el nombre de la competición
    Competicion(const std::string& nombre) : nombre(nombre) {}

    // Agrega un equipo a la competición
    void agregarEquipo(Equipo* equipo);

    // Busca un equipo por nombre en la competición
    Equipo* buscarEquipo(const std::string& nombreEquipo);

private:
    std::string nombre; // Nombre de la competición
    std::vector<Equipo*> equipos; // Lista de equipos en la competición
};

#endif // COMPETICION_H