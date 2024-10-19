//
// Created by Octavio Carpineti on 17/10/2024.
//

// Competicion.h
#ifndef PROYECTO_COMPETICION_H
#define PROYECTO_COMPETICION_H

#include <string>
#include "Listas/ListaDoble.h"
#include "Arboles/ArbolBinarioAVL.h"
#include "Partido.h"

class Competicion {
private:
    std::string nombre;
    std::string temporada;
    ArbolBinarioAVL<Equipo*> equipos;
    ListaDoble<Partido*> partidos;

public:
    Competicion(const std::string& nombre, const std::string& temporada);

    void agregarEquipo(Equipo* equipo);
    void agregarPartido(Partido* partido);
    Equipo* buscarEquipo(const std::string& nombreEquipo);

    // Getters
    std::string getNombre() const;
    std::string getTemporada() const;

    // Métodos para acceder a los datos
    void listarEquipos() const;
    void listarPartidos() const;
};

#endif // PROYECTO_COMPETICION_H

