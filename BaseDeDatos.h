#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include <string>
#include <vector>
#include <utility>
#include "Partido.h"
#include "Equipo.h"

class BaseDeDatos {
public:
    BaseDeDatos();
    bool cargarArchivo(const std::string& nombreArchivo);
    std::vector<Partido> obtenerPartidosConMasGoles();
    std::pair<int, int> obtenerGolesTotalesPorEquipo(const std::string& nombreEquipo);
    std::pair<double, double> obtenerPromedioGolesPorEquipo(const std::string& nombreEquipo);
    std::pair<int, int> obtenerDerrotasYTriunfosPorEquipo(const std::string& nombreEquipo);
    std::pair<std::string, std::string> obtenerFechasConMasYMenosGoles(const std::string& nombreEquipo);
    std::string obtenerCompeticionConMasGoles();
    std::pair<std::string, std::string> obtenerEquipoConMasYMenosGoles();
    std::vector<Partido> obtenerResultadosEquipoFechas(const std::string& nombreEquipo, const std::string& fechaInicio, const std::string& fechaFin);
    std::pair<std::pair<int, int>, std::pair<int, int>> compararRendimientoGeneral(const std::string& equipo1, const std::string& equipo2);
    std::pair<int, int> compararRendimientoParticular(const std::string& equipo1, const std::string& equipo2);
    std::vector<Equipo> filtrarEquiposPorUmbral(int umbral, bool porEncima);

private:
    std::vector<Partido> partidos;
    std::vector<Equipo> equipos; // Add this line
};

#endif // BASEDEDATOS_H