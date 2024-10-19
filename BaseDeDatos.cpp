//
// Created by Octavio Carpineti on 18/10/2024.
//

// BaseDeDatos.cpp
#include "BaseDeDatos.h"
#include "Competicion.h"

// Constructor de la clase BaseDeDatos
BaseDeDatos::BaseDeDatos() {}

// Agrega una competición a la base de datos
void BaseDeDatos::agregarCompeticion(Competicion* competicion) {
    competiciones.insertarUltimo(competicion);
}

// Busca una competición en la base de datos por nombre
Competicion* BaseDeDatos::buscarCompeticion(const std::string& nombreCompeticion) {
    Nodo<Competicion*>* it = competiciones.getInicio();
    while (it != nullptr) {
        if (it->getData()->getNombre() == nombreCompeticion) {
            return it->getData();
        }
        it = it->getSiguiente();
    }
    return nullptr;
}

// Lista todas las competiciones en la base de datos
void BaseDeDatos::listarCompeticiones() const {
    competiciones.imprimir();
}