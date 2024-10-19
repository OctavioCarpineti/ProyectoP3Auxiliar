#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>
#include <vector>
#include "Partido.h"

class Equipo {
public:
    Equipo(const std::string& nombre);
    const std::string& getNombre() const;
    void listarPartidos() const;
    void agregarPartido(const std::string& fecha, const std::string& oponente, int golesFavor, int golesContra, const std::string& competicion);

private:
    std::string nombre;
    std::vector<Partido> partidos;
};

#endif // EQUIPO_H