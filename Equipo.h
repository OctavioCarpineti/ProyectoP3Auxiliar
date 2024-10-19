//
// Created by Octavio Carpineti on 18/10/2024.
//

#ifndef PROYECTO_EQUIPO_H

#include "Arboles/ArbolBinarioAVL.h"
#include "Listas/ListaDoble.h"
#include "Partido.h"
#include "Competicion.h"

class Equipo {
private:
    std::string nombre;
    int golesAFavor;
    int golesEnContra;
    int victorias;
    int derrotas;
    ListaDoble<Partido*> partidos;

public:
    Equipo(const std::string& nombre);

    // Getters y setters
    std::string getNombre() const;
    int getGolesAFavor() const;
    int getGolesEnContra() const;
    int getVictorias() const;
    int getDerrotas() const;

    void actualizarEstadisticas(int golesAFavor, int golesEnContra, bool esVictoria);
    void agregarPartido(Partido* partido);
    void listarPartidos() const;
};

#endif //PROYECTO_EQUIPO_H