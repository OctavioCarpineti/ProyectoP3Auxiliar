#include "BaseDeDatos.h"
#include <fstream>
#include <sstream>
#include <iostream>

BaseDeDatos::BaseDeDatos() : cargado(false) {}

bool BaseDeDatos::cargarArchivo(const std::string& nombreArchivo) {
    std::string rutaArchivo = "/Users/octavio/Desktop/UCC/2do /P3/ProyectoAuxiliar/ProyectoP3Auxiliar/Recursos/" + nombreArchivo;
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << rutaArchivo << std::endl;
        return false;
    }

    std::string linea;
    std::getline(archivo, linea); // Leer la cabecera

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string jornada, fecha, equipoLocal, equipoVisitante, competicion;
        int golesLocal, golesVisitante;

        std::getline(ss, jornada, ',');
        std::getline(ss, fecha, ',');
        std::getline(ss, equipoLocal, ',');
        ss >> golesLocal;
        ss.ignore(1);
        ss >> golesVisitante;
        ss.ignore(1);
        std::getline(ss, equipoVisitante, ',');
        std::getline(ss, competicion, ',');

        Competicion* competicionObj = buscarCompeticion(competicion);
        if (!competicionObj) {
            competicionObj = new Competicion(competicion);
            agregarCompeticion(competicionObj);
        }

        Equipo* equipoLocalObj = competicionObj->buscarEquipo(equipoLocal);
        if (!equipoLocalObj) {
            equipoLocalObj = new Equipo(equipoLocal);
            competicionObj->agregarEquipo(equipoLocalObj);
        }

        Equipo* equipoVisitanteObj = competicionObj->buscarEquipo(equipoVisitante);
        if (!equipoVisitanteObj) {
            equipoVisitanteObj = new Equipo(equipoVisitante);
            competicionObj->agregarEquipo(equipoVisitanteObj);
        }

        equipoLocalObj->agregarPartido(fecha, equipoVisitante, golesLocal, golesVisitante, competicion);
        equipoVisitanteObj->agregarPartido(fecha, equipoLocal, golesVisitante, golesLocal, competicion);
    }

    archivo.close();
    cargado = true;
    std::cout << "Archivo cargado exitosamente: " << rutaArchivo << std::endl;
    return true;
}

bool BaseDeDatos::estaCargado() const {
    return cargado;
}

void BaseDeDatos::cargarDatos(const std::string& nombreArchivo) {
    cargarArchivo(nombreArchivo);
}

Competicion* BaseDeDatos::buscarCompeticion(const std::string& nombre) {
    Competicion tempCompeticion(nombre);
    Competicion* competicion = competiciones.search(&tempCompeticion);
    return competicion;
}

void BaseDeDatos::agregarCompeticion(Competicion* competicion) {
    competiciones.put(competicion);
}

void BaseDeDatos::eliminarCompeticion(const std::string& nombre) {
    Competicion tempCompeticion(nombre);
    Competicion* competicion = competiciones.search(&tempCompeticion);
    if (competicion) {
        competiciones.remove(competicion);
    }
}