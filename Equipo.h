#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>
#include <list>
#include "Partido.h"

class Equipo {
private:
    std::string nombre;
    std::list<Partido> partidos; // Usamos std::list para almacenar los partidos

public:
    Equipo(const std::string& nombre);
    const std::string& getNombre() const;
    void listarPartidos() const;
    void agregarPartido(const std::string& fecha, const std::string& oponente, int golesFavor, int golesContra, const std::string& competicion);
    double getPromedioGoles() const; // Nuevo método para obtener el promedio de goles
};

#endif // EQUIPO_H