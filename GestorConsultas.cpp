#include "GestorConsultas.h"
#include <iostream>

GestorConsultas::GestorConsultas(BaseDeDatos* baseDeDatos) : baseDeDatos(baseDeDatos) {}

void GestorConsultas::cargarDatos(const std::string& nombreArchivo) {
    try {
        baseDeDatos->cargarDatos(nombreArchivo);
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada al cargar datos: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción desconocida capturada al cargar datos." << std::endl;
    }
}

void GestorConsultas::consultarResultadosEquipo(const std::string& nombreEquipo, const std::string& nombreCompeticion) {
    try {
        Competicion* competicion = baseDeDatos->buscarCompeticion(nombreCompeticion);
        if (competicion) {
            Equipo* equipo = competicion->buscarEquipo(nombreEquipo);
            if (equipo) {
                equipo->listarPartidos();
            } else {
                std::cout << "Equipo no encontrado." << std::endl;
            }
        } else {
            std::cout << "Competición no encontrada." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada al consultar resultados del equipo: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción desconocida capturada al consultar resultados del equipo." << std::endl;
    }
}

void GestorConsultas::agregarCompeticion(const std::string& nombreCompeticion) {
    try {
        Competicion* competicion = new Competicion(nombreCompeticion);
        baseDeDatos->agregarCompeticion(competicion);
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada al agregar competición: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción desconocida capturada al agregar competición." << std::endl;
    }
}

void GestorConsultas::eliminarCompeticion(const std::string& nombreCompeticion) {
    try {
        baseDeDatos->eliminarCompeticion(nombreCompeticion);
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada al eliminar competición: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción desconocida capturada al eliminar competición." << std::endl;
    }
}

void GestorConsultas::agregarPartido(const std::string& nombreCompeticion, const std::string& fecha, const std::string& equipoLocal, int golesLocal, int golesVisitante, const std::string& equipoVisitante) {
    try {
        Competicion* competicion = baseDeDatos->buscarCompeticion(nombreCompeticion);
        if (competicion) {
            Equipo* equipoLocalObj = competicion->buscarEquipo(equipoLocal);
            if (!equipoLocalObj) {
                equipoLocalObj = new Equipo(equipoLocal);
                competicion->agregarEquipo(equipoLocalObj);
            }
            Equipo* equipoVisitanteObj = competicion->buscarEquipo(equipoVisitante);
            if (!equipoVisitanteObj) {
                equipoVisitanteObj = new Equipo(equipoVisitante);
                competicion->agregarEquipo(equipoVisitanteObj);
            }
            equipoLocalObj->agregarPartido(fecha, equipoVisitante, golesLocal, golesVisitante, nombreCompeticion);
            equipoVisitanteObj->agregarPartido(fecha, equipoLocal, golesVisitante, golesLocal, nombreCompeticion);
        } else {
            std::cout << "Competición no encontrada." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada al agregar partido: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción desconocida capturada al agregar partido." << std::endl;
    }
}

void GestorConsultas::eliminarPartido(const std::string& nombreCompeticion, const std::string& fecha, const std::string& equipoLocal, const std::string& equipoVisitante) {
    try {
        // Implementar la lógica para eliminar un partido
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada al eliminar partido: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción desconocida capturada al eliminar partido." << std::endl;
    }
}

void GestorConsultas::modificarPartido(const std::string& nombreCompeticion, const std::string& fecha, const std::string& equipoLocal, int golesLocal, int golesVisitante, const std::string& equipoVisitante) {
    try {
        // Implementar la lógica para modificar un partido
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada al modificar partido: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción desconocida capturada al modificar partido." << std::endl;
    }
}

void GestorConsultas::obtenerDatosCompeticion(const std::string& nombreCompeticion) {
    try {
        Competicion* competicion = baseDeDatos->buscarCompeticion(nombreCompeticion);
        if (competicion) {
            std::cout << "Datos de la competición: " << nombreCompeticion << std::endl;
            std::cout << "Equipos participantes:" << std::endl;
            for (const auto& equipo : competicion->getEquipos()) {
                std::cout << "- " << equipo->getNombre() << std::endl;
            }
            std::cout << "Partidos:" << std::endl;
            for (const auto& partido : competicion->getPartidos()) {
                std::cout << partido.getFecha() << ": " << partido.getEquipoLocal() << " " << partido.getGolesLocal() << " - " << partido.getGolesVisitante() << " " << partido.getEquipoVisitante() << std::endl;
            }
        } else {
            std::cout << "Competición no encontrada." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada al obtener datos de la competición: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción desconocida capturada al obtener datos de la competición." << std::endl;
    }
}