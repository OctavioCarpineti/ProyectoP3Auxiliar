#ifndef COMPETICION_H
#define COMPETICION_H

#include <string>
#include <map>
#include <list>
#include "Equipo.h"
#include "Partido.h"

class Competicion {
private:
    std::string nombre;
    std::map<std::string, Equipo*> equipos; // Usamos std::map para almacenar equipos
    std::list<Partido> partidos; // Usamos std::list para almacenar partidos

public:
    Competicion(const std::string& nombre);
    std::string getNombre() const;
    void agregarEquipo(Equipo* equipo);
    Equipo* buscarEquipo(const std::string& nombreEquipo);
    void agregarPartido(const Partido& partido);
    const std::map<std::string, Equipo*>& getEquipos() const;
    const std::list<Partido>& getPartidos() const;
};

#endif // COMPETICION_H