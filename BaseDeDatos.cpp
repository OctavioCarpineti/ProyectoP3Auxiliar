#include "BaseDeDatos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <climits>

BaseDeDatos::BaseDeDatos() {
    // Implementar la lógica para constructor de base de datos
}

bool BaseDeDatos::cargarArchivo(const std::string& nombreArchivo) {
    try {
        std::ifstream archivo("/Users/octavio/Desktop/UCC/2do /P3/ProyectoAuxiliar/ProyectoP3Auxiliar/Recursos/Base_Datos_COMA.csv");        if (!archivo.is_open()) {
            throw std::runtime_error("Error al abrir el archivo: " + nombreArchivo);
        }

        std::string linea;
        int fila = 0;
        // Leer y descartar la primera línea (encabezados)
        std::getline(archivo, linea);

        while (std::getline(archivo, linea)) {
            fila++;
            try {
                std::istringstream ss(linea);
                std::string jornada, fecha, equipoLocal, equipoVisitante, competicion;
                std::string golesLocalStr, golesVisitanteStr;
                int golesLocal, golesVisitante;

                std::getline(ss, jornada, ',');
                std::getline(ss, fecha, ',');
                std::getline(ss, equipoLocal, ',');
                std::getline(ss, golesLocalStr, ',');
                std::getline(ss, golesVisitanteStr, ',');
                std::getline(ss, equipoVisitante, ',');
                std::getline(ss, competicion);

                // Convertir los goles de string a int
                try {
                    golesLocal = std::stoi(golesLocalStr);
                    golesVisitante = std::stoi(golesVisitanteStr);
                } catch (const std::invalid_argument& e) {
                    throw std::runtime_error("Error al convertir goles a número en la fila " + std::to_string(fila));
                }

                Partido partido(fecha, equipoLocal, golesLocal, golesVisitante, equipoVisitante, competicion);
                partidos.push_back(partido);
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
                // Puedes decidir si continuar o detener la lectura del archivo
                // return false; // Descomenta esta línea si deseas detener la lectura
            }
        }

        archivo.close();
        return true;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

std::vector<Partido> BaseDeDatos::obtenerPartidosConMasGoles() {
    std::vector<Partido> partidosConMasGoles = partidos;
    std::sort(partidosConMasGoles.begin(), partidosConMasGoles.end(), [](const Partido& a, const Partido& b) {
        return (a.getGolesLocal() + a.getGolesVisitante()) > (b.getGolesLocal() + b.getGolesVisitante());
    });

    if (partidosConMasGoles.size() > 5) {
        partidosConMasGoles.resize(5);
    }

    return partidosConMasGoles;
}

std::pair<int, int> BaseDeDatos::obtenerGolesTotalesPorEquipo(const std::string& nombreEquipo) {
    int golesFavor = 0, golesContra = 0;
    for (const auto& partido : partidos) {
        if (partido.getEquipoLocal() == nombreEquipo) {
            golesFavor += partido.getGolesLocal();
            golesContra += partido.getGolesVisitante();
        } else if (partido.getEquipoVisitante() == nombreEquipo) {
            golesFavor += partido.getGolesVisitante();
            golesContra += partido.getGolesLocal();
        }
    }
    return {golesFavor, golesContra};
}

std::pair<double, double> BaseDeDatos::obtenerPromedioGolesPorEquipo(const std::string& nombreEquipo) {
    int golesFavor = 0, golesContra = 0, partidosJugados = 0;
    for (const auto& partido : partidos) {
        if (partido.getEquipoLocal() == nombreEquipo || partido.getEquipoVisitante() == nombreEquipo) {
            partidosJugados++;
            if (partido.getEquipoLocal() == nombreEquipo) {
                golesFavor += partido.getGolesLocal();
                golesContra += partido.getGolesVisitante();
            } else {
                golesFavor += partido.getGolesVisitante();
                golesContra += partido.getGolesLocal();
            }
        }
    }
    if (partidosJugados == 0) return {0.0, 0.0};
    return {static_cast<double>(golesFavor) / partidosJugados, static_cast<double>(golesContra) / partidosJugados};
}

std::pair<int, int> BaseDeDatos::obtenerDerrotasYTriunfosPorEquipo(const std::string& nombreEquipo) {
    int derrotas = 0, triunfos = 0;
    for (const auto& partido : partidos) {
        if (partido.getEquipoLocal() == nombreEquipo) {
            if (partido.getGolesLocal() > partido.getGolesVisitante()) {
                triunfos++;
            } else if (partido.getGolesLocal() < partido.getGolesVisitante()) {
                derrotas++;
            }
        } else if (partido.getEquipoVisitante() == nombreEquipo) {
            if (partido.getGolesVisitante() > partido.getGolesLocal()) {
                triunfos++;
            } else if (partido.getGolesVisitante() < partido.getGolesLocal()) {
                derrotas++;
            }
        }
    }
    return {derrotas, triunfos};
}

std::pair<std::string, std::string> BaseDeDatos::obtenerFechasConMasYMenosGoles(const std::string& nombreEquipo) {
    std::string fechaMasGoles, fechaMenosGoles;
    int maxGoles = -1, minGoles = INT_MAX;
    for (const auto& partido : partidos) {
        int goles = 0;
        if (partido.getEquipoLocal() == nombreEquipo) {
            goles = partido.getGolesLocal() + partido.getGolesVisitante();
        } else if (partido.getEquipoVisitante() == nombreEquipo) {
            goles = partido.getGolesVisitante() + partido.getGolesLocal();
        }
        if (goles > maxGoles) {
            maxGoles = goles;
            fechaMasGoles = partido.getFecha();
        }
        if (goles < minGoles) {
            minGoles = goles;
            fechaMenosGoles = partido.getFecha();
        }
    }
    return {fechaMasGoles, fechaMenosGoles};
}

std::string BaseDeDatos::obtenerCompeticionConMasGoles() {
    std::unordered_map<std::string, int> golesPorCompeticion;
    for (const auto& partido : partidos) {
        golesPorCompeticion[partido.getCompeticion()] += partido.getGolesLocal() + partido.getGolesVisitante();
    }
    return std::max_element(golesPorCompeticion.begin(), golesPorCompeticion.end(),
                            [](const auto& a, const auto& b) { return a.second < b.second; })->first;
}

std::pair<std::string, std::string> BaseDeDatos::obtenerEquipoConMasYMenosGoles() {
    std::unordered_map<std::string, int> golesPorEquipo;
    for (const auto& partido : partidos) {
        golesPorEquipo[partido.getEquipoLocal()] += partido.getGolesLocal();
        golesPorEquipo[partido.getEquipoVisitante()] += partido.getGolesVisitante();
    }
    auto maxEquipo = std::max_element(golesPorEquipo.begin(), golesPorEquipo.end(),
                                      [](const auto& a, const auto& b) { return a.second < b.second; });
    auto minEquipo = std::min_element(golesPorEquipo.begin(), golesPorEquipo.end(),
                                      [](const auto& a, const auto& b) { return a.second < b.second; });
    return {maxEquipo->first, minEquipo->first};
}

std::vector<Partido> BaseDeDatos::obtenerResultadosEquipoFechas(const std::string& nombreEquipo, const std::string& fechaInicio, const std::string& fechaFin) {
    std::vector<Partido> resultados;
    for (const auto& partido : partidos) {
        if (partido.getFecha() >= fechaInicio && partido.getFecha() <= fechaFin &&
            (partido.getEquipoLocal() == nombreEquipo || partido.getEquipoVisitante() == nombreEquipo)) {
            resultados.push_back(partido);
        }
    }
    return resultados;
}

std::pair<std::pair<int, int>, std::pair<int, int>> BaseDeDatos::compararRendimientoGeneral(const std::string& equipo1, const std::string& equipo2) {
    auto golesEquipo1 = obtenerGolesTotalesPorEquipo(equipo1);
    auto golesEquipo2 = obtenerGolesTotalesPorEquipo(equipo2);
    return {golesEquipo1, golesEquipo2};
}

std::pair<int, int> BaseDeDatos::compararRendimientoParticular(const std::string& equipo1, const std::string& equipo2) {
    int partidosJugados = 0, empates = 0;
    for (const auto& partido : partidos) {
        if ((partido.getEquipoLocal() == equipo1 && partido.getEquipoVisitante() == equipo2) ||
            (partido.getEquipoLocal() == equipo2 && partido.getEquipoVisitante() == equipo1)) {
            partidosJugados++;
            if (partido.getGolesLocal() == partido.getGolesVisitante()) {
                empates++;
            }
        }
    }
    return {partidosJugados, empates};
}

std::vector<Equipo> BaseDeDatos::filtrarEquiposPorUmbral(int umbral, bool porEncima) {
    std::vector<Equipo> equiposFiltrados;
    for (const auto& equipo : equipos) {
        double promedioGoles = equipo.getPromedioGoles();
        if ((porEncima && promedioGoles > umbral) || (!porEncima && promedioGoles < umbral)) {
            equiposFiltrados.push_back(equipo);
        }
    }
    return equiposFiltrados;
}