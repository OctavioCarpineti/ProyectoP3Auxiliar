#ifndef COMPETICION_H
#define COMPETICION_H

#include <string>
#include "Equipo.h"
#include "Partido.h"
#include "Listas/ListaDoble.h"
#include "Arbol/ArbolBinarioAVL.h"

class Competicion {
private:
    std::string nombre;
    ArbolBinarioAVL<Equipo> equipos;
    ListaDoble<Partido> partidos;

    void actualizarEstadisticas(const Partido& partido);

public:
    explicit Competicion(const std::string& nombre);
    std::string getNombre() const;
    void agregarEquipo(const Equipo& equipo);
    void agregarPartido(const Partido& partido);
    Equipo* buscarEquipo(const std::string& nombreEquipo);
    const ArbolBinarioAVL<Equipo>& getEquipos() const;
    const ListaDoble<Partido>& getPartidos() const;

    int getTotalGoles() const;
    std::pair<std::string, int> getEquipoMaxGoles() const;
    std::pair<std::string, int> getEquipoMinGoles() const;

    bool operator<(const Competicion& otra) const { return nombre < otra.nombre; }
    bool operator>(const Competicion& otra) const { return nombre > otra.nombre; }
    bool operator==(const Competicion& otra) const { return nombre == otra.nombre; }
};

#endif // COMPETICION_H
