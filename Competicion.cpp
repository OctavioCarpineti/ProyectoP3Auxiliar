//
// Created by Octavio Carpineti on 17/10/2024.
//

// Competicion.cpp
#include "Competicion.h"

// Constructor de la clase Competicion
Competicion::Competicion(const std::string& nombre, const std::string& temporada)
    : nombre(nombre), temporada(temporada) {}

// Agrega un equipo a la competición
void Competicion::agregarEquipo(Equipo* equipo) {
    equipos.insertar(equipo);
}

// Agrega un partido a la competición
void Competicion::agregarPartido(Partido* partido) {
    partidos.insertarUltimo(partido);
}

// Busca un equipo en la competición por nombre
Equipo* Competicion::buscarEquipo(const std::string& nombreEquipo) {
    NodoArbolAVL<Equipo*>* nodo = equipos.buscar(nombreEquipo);
    return nodo ? nodo->getData() : nullptr;
}

// Getters
std::string Competicion::getNombre() const {
    return nombre;
}

std::string Competicion::getTemporada() const {
    return temporada;
}

// Lista todos los equipos de la competición
void Competicion::listarEquipos() const {
    equipos.imprimir();
}

// Lista todos los partidos de la competición
void Competicion::listarPartidos() const {
    partidos.imprimir();
}