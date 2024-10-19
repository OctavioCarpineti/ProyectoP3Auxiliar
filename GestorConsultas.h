//
// Created by Octavio Carpineti on 18/10/2024.
//

#ifndef PROYECTO_GESTORCONSULTAS_H
#define PROYECTO_GESTORCONSULTAS_H
#include "string"

class GestorConsultas {
public:
    void consultarResultadosEquipo(const std::string& nombreEquipo, const std::string& nombreCompeticion);
    void consultarResultadosEntreFechas(const std::string& nombreEquipo, const std::string& fechaInicio, const std::string& fechaFin);
    void compararRendimientoGeneral(const std::string& equipo1, const std::string& equipo2);
    void compararRendimientoParticular(const std::string& equipo1, const std::string& equipo2);
    void filtrarPorUmbralGoles(double umbral, bool porEncima);
};


#endif //PROYECTO_GESTORCONSULTAS_H
