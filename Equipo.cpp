//
// Created by Octavio Carpineti on 18/10/2024.
//

// Equipo.cpp
#include "Equipo.h"

// Constructor de la clase Equipo
Equipo::Equipo(const std::string& nombre)
    : nombre(nombre), golesAFavor(0), golesEnContra(0), victorias(0), derrotas(0) {}

// Getters
std::string Equipo::getNombre() const {
    return nombre;
}

int Equipo::getGolesAFavor() const {
    return golesAFavor;
}

int Equipo::getGolesEnContra() const {
    return golesEnContra;
}

int Equipo::getVictorias() const {
    return victorias;
}

int Equipo::getDerrotas() const {
    return derrotas;
}

// Actualiza las estadísticas del equipo
void Equipo::actualizarEstadisticas(int golesAFavor, int golesEnContra, bool esVictoria) {
    this->golesAFavor += golesAFavor;
    this->golesEnContra += golesEnContra;
    if (esVictoria) {
        victorias++;
    } else {
        derrotas++;
    }
}

// Agrega un partido a la lista de partidos del equipo
void Equipo::agregarPartido(Partido* partido) {
    partidos.insertarUltimo(partido);
}

// Lista todos los partidos del equipo
void Equipo::listarPartidos() const {
    partidos.imprimir();
}