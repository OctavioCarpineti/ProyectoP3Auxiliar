#include "BaseDeDatos.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <algorithm>

// Definición de la función auxiliar para limpiar y convertir los valores de goles
int BaseDeDatos::convertirGoles(const std::string& str) {
    std::string limpio;
    std::remove_copy_if(str.begin(), str.end(), std::back_inserter(limpio), [](char c) { return !std::isdigit(c); });
    return std::stoi(limpio);
}

BaseDeDatos::BaseDeDatos() : cargado(false) {}

bool BaseDeDatos::cargarArchivo(const std::string& nombreArchivo) {
    std::string rutaArchivo = "/Users/octavio/Desktop/UCC/2do /P3/ProyectoAuxiliar/ProyectoP3Auxiliar/Recursos/" + nombreArchivo;
    std::cout << "Intentando abrir el archivo: " << rutaArchivo << std::endl;
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << rutaArchivo << std::endl;
        return false;
    }

    try {
        std::string linea;
        std::getline(archivo, linea); // Leer la cabecera
        std::cout << "Cabecera leída: " << linea << std::endl;

        int lineaNum = 1;
        while (std::getline(archivo, linea)) {
            lineaNum++;
            std::cout << "Procesando línea " << lineaNum << ": " << linea << std::endl;

            std::istringstream ss(linea);
            std::string campo;
            std::vector<std::string> campos;

            while (std::getline(ss, campo, ',')) {
                campos.push_back(campo);
            }

            if (campos.size() < 10) {
                std::cerr << "Error en línea " << lineaNum << ": número incorrecto de campos." << std::endl;
                continue;
            }

            std::string jornada = campos[0];
            std::string fecha = campos[1];
            std::string equipoLocal = campos[2];
            int golesLocal, golesVisitante;

            try {
                golesLocal = convertirGoles(campos[3]);
                golesVisitante = convertirGoles(campos[4]);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error en línea " << lineaNum << " al convertir goles a entero: " << e.what() << std::endl;
                continue;
            } catch (const std::out_of_range& e) {
                std::cerr << "Error en línea " << lineaNum << " al convertir goles a entero: " << e.what() << std::endl;
                continue;
            }

            std::string equipoVisitante = campos[5];
            std::string competicion = campos[6];

            Competicion* competicionObj = nullptr;
            try {
                competicionObj = buscarCompeticion(competicion);
                if (!competicionObj) {
                    competicionObj = new Competicion(competicion);
                    agregarCompeticion(competicionObj);
                    std::cout << "Nueva competición creada: " << competicion << std::endl;
                }
            } catch (const std::exception& e) {
                std::cerr << "Error al buscar/crear competición en línea " << lineaNum << ": " << e.what() << std::endl;
                continue;
            }

            Equipo* equipoLocalObj = nullptr;
            try {
                equipoLocalObj = competicionObj->buscarEquipo(equipoLocal);
                if (!equipoLocalObj) {
                    equipoLocalObj = new Equipo(equipoLocal);
                    competicionObj->agregarEquipo(equipoLocalObj);
                    std::cout << "Nuevo equipo local creado: " << equipoLocal << std::endl;
                }
            } catch (const std::exception& e) {
                std::cerr << "Error al buscar/crear equipo local en línea " << lineaNum << ": " << e.what() << std::endl;
                continue;
            }

            Equipo* equipoVisitanteObj = nullptr;
            try {
                equipoVisitanteObj = competicionObj->buscarEquipo(equipoVisitante);
                if (!equipoVisitanteObj) {
                    equipoVisitanteObj = new Equipo(equipoVisitante);
                    competicionObj->agregarEquipo(equipoVisitanteObj);
                    std::cout << "Nuevo equipo visitante creado: " << equipoVisitante << std::endl;
                }
            } catch (const std::exception& e) {
                std::cerr << "Error al buscar/crear equipo visitante en línea " << lineaNum << ": " << e.what() << std::endl;
                continue;
            }

            try {
                equipoLocalObj->agregarPartido(fecha, equipoVisitante, golesLocal, golesVisitante, competicion);
                equipoVisitanteObj->agregarPartido(fecha, equipoLocal, golesVisitante, golesLocal, competicion);
                std::cout << "Partido agregado: " << fecha << ", " << equipoLocal << " vs " << equipoVisitante << ", " << golesLocal << "-" << golesVisitante << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Error al agregar partido en línea " << lineaNum << ": " << e.what() << std::endl;
                continue;
            }
        }

        archivo.close();
        cargado = true;
        std::cout << "Archivo cargado exitosamente: " << rutaArchivo << std::endl;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada al procesar el archivo: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción desconocida capturada al procesar el archivo." << std::endl;
    }

    return false;
}

bool BaseDeDatos::estaCargado() const {
    return cargado;
}

void BaseDeDatos::cargarDatos(const std::string& nombreArchivo) {
    cargarArchivo(nombreArchivo);
}

Competicion* BaseDeDatos::buscarCompeticion(const std::string& nombre) {
    auto it = competiciones.find(nombre);
    if (it != competiciones.end()) {
        return it->second;
    }
    return nullptr;
}

void BaseDeDatos::agregarCompeticion(Competicion* competicion) {
    competiciones[competicion->getNombre()] = competicion;
}

void BaseDeDatos::eliminarCompeticion(const std::string& nombre) {
    auto it = competiciones.find(nombre);
    if (it != competiciones.end()) {
        delete it->second;
        competiciones.erase(it);
    }
}