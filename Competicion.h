#ifndef COMPETICION_H
#define COMPETICION_H

#include <string>
#include <vector>
#include "Equipo.h"
#include "Partido.h"

class Competicion {
private:
    std::string nombre;
    std::vector<Equipo*> equipos;
    std::vector<Partido> partidos;

public:
    Competicion(const std::string& nombre);
    std::string getNombre() const;
    void agregarEquipo(Equipo* equipo);
    Equipo* buscarEquipo(const std::string& nombreEquipo);
    void agregarPartido(const Partido& partido);
    const std::vector<Equipo*>& getEquipos() const;
    const std::vector<Partido>& getPartidos() const;
};

#endif // COMPETICION_H