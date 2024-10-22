#include "GestorConsultas.h"
#include <iostream>

GestorConsultas::GestorConsultas(BaseDeDatos* baseDeDatos) : baseDeDatos(baseDeDatos) {}

// Implementación de las nuevas funciones

void GestorConsultas::mostrarPartidosConMasGoles() {
    auto partidos = baseDeDatos->obtenerPartidosConMasGoles();
    for (const auto& partido : partidos) {
        std::cout << partido.getFecha() << " - " << partido.getEquipoLocal() << " vs " << partido.getEquipoVisitante() << " - Goles: " << partido.getGolesLocal() + partido.getGolesVisitante() << std::endl;
    }
}

void GestorConsultas::mostrarGolesTotalesPorEquipo(const std::string& nombreEquipo) {
    auto goles = baseDeDatos->obtenerGolesTotalesPorEquipo(nombreEquipo);
    if (goles.first == 0 && goles.second == 0) {
        std::cout << "No se encontraron datos para el equipo: " << nombreEquipo << std::endl;
    } else {
        std::cout << "Goles a favor: " << goles.first << ", Goles en contra: " << goles.second << std::endl;
    }
}

void GestorConsultas::mostrarPromedioGolesPorEquipo(const std::string& nombreEquipo) {
    auto promedio = baseDeDatos->obtenerPromedioGolesPorEquipo(nombreEquipo);
    std::cout << "Promedio de goles a favor: " << promedio.first << ", Promedio de goles en contra: " << promedio.second << std::endl;
}

void GestorConsultas::mostrarDerrotasYTriunfosPorEquipo(const std::string& nombreEquipo) {
    auto resultados = baseDeDatos->obtenerDerrotasYTriunfosPorEquipo(nombreEquipo);
    std::cout << "Derrotas: " << resultados.first << ", Triunfos: " << resultados.second << std::endl;
}

void GestorConsultas::mostrarFechasConMasYMenosGoles(const std::string& nombreEquipo) {
    auto fechas = baseDeDatos->obtenerFechasConMasYMenosGoles(nombreEquipo);
    std::cout << "Fecha con más goles: " << fechas.first << ", Fecha con menos goles: " << fechas.second << std::endl;
}

void GestorConsultas::mostrarCompeticionConMasGoles() {
    auto competicion = baseDeDatos->obtenerCompeticionConMasGoles();
    std::cout << "Competición con más goles: " << competicion << std::endl;
}

void GestorConsultas::mostrarEquipoConMasYMenosGoles() {
    auto equipos = baseDeDatos->obtenerEquipoConMasYMenosGoles();
    std::cout << "Equipo con más goles: " << equipos.first << ", Equipo con menos goles: " << equipos.second << std::endl;
}

void GestorConsultas::consultarResultadosEquipoFechas(const std::string& nombreEquipo, const std::string& fechaInicio, const std::string& fechaFin) {
    auto partidos = baseDeDatos->obtenerResultadosEquipoFechas(nombreEquipo, fechaInicio, fechaFin);
    for (const auto& partido : partidos) {
        std::cout << partido.getFecha() << " - " << partido.getEquipoLocal() << " vs " << partido.getEquipoVisitante() << " - Resultado: " << partido.getGolesLocal() << " a " << partido.getGolesVisitante() << std::endl;
    }
}

void GestorConsultas::compararRendimientoGeneral(const std::string& equipo1, const std::string& equipo2) {
    auto rendimiento = baseDeDatos->compararRendimientoGeneral(equipo1, equipo2);
    std::cout << equipo1 << " - Goles a favor: " << rendimiento.first.first << ", Goles en contra: " << rendimiento.first.second << std::endl;
    std::cout << equipo2 << " - Goles a favor: " << rendimiento.second.first << ", Goles en contra: " << rendimiento.second.second << std::endl;
}

void GestorConsultas::compararRendimientoParticular(const std::string& equipo1, const std::string& equipo2) {
    auto resultados = baseDeDatos->compararRendimientoParticular(equipo1, equipo2);
    std::cout << "Partidos jugados: " << resultados.first << ", Empates: " << resultados.second << std::endl;
}

void GestorConsultas::filtrarEquiposPorUmbral(int umbral, bool porEncima) {
    auto equipos = baseDeDatos->filtrarEquiposPorUmbral(umbral, porEncima);
    for (const auto& equipo : equipos) {
        std::cout << equipo.getNombre() << " - Promedio de goles: " << equipo.getPromedioGoles() << std::endl;
    }
}