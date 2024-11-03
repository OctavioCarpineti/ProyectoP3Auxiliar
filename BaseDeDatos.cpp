#include "BaseDeDatos.h"
#include "Listas/Lista.h"
#include "Partido.h"
#include "Equipo.h"
#include "Competicion.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <chrono>
#include <filesystem>
#include <set>

BaseDeDatos::BaseDeDatos() {}

BaseDeDatos::~BaseDeDatos() {
    // Limpieza de memoria si es necesaria
    partidos.vaciar();
}

bool BaseDeDatos::cargarArchivo(const std::string& nombreArchivo) {
    try {
        std::ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            std::cerr << "Error: No se pudo abrir el archivo: " << nombreArchivo << "\n";
            return false;
        }

        std::cout << "Archivo abierto correctamente.\n";
        int lineasProcesadas = 0;
        int partidosAgregados = 0;

        std::string linea;
        std::getline(archivo, linea); // Saltamos encabezados
        std::cout << "Encabezados leídos: " << linea << "\n";
        
        while (std::getline(archivo, linea)) {
            lineasProcesadas++;
            
            try {
                std::stringstream ss(linea);
                std::string jornada, fecha, equipoLocal, equipoVisitante, competicion;
                int golesLocal, golesVisitante;
                
                std::getline(ss, jornada, ',');
                std::getline(ss, fecha, ',');
                std::getline(ss, equipoLocal, ',');
                ss >> golesLocal;
                ss.ignore();
                ss >> golesVisitante;
                ss.ignore();
                std::getline(ss, equipoVisitante, ',');
                std::getline(ss, competicion);
                
                // Crear y agregar partido
                Partido partido(fecha, equipoLocal, golesLocal, golesVisitante, 
                              equipoVisitante, competicion);
                partidos.insertarUltimo(partido);
                
                // Agregar equipos
                try {
                    equipos.put(Equipo(equipoLocal));
                } catch (...) {}
                
                try {
                    equipos.put(Equipo(equipoVisitante));
                } catch (...) {}
                
                // Agregar competición
                try {
                    competiciones.put(Competicion(competicion));
                } catch (...) {}
                
                partidosAgregados++;
                
            } catch (const std::exception& e) {
                std::cerr << "Error en línea " << lineasProcesadas << ": " << e.what() << "\n";
                continue;
            }
        }
        
        std::cout << "\nResumen de carga:\n"
                  << "- Líneas procesadas: " << lineasProcesadas << "\n"
                  << "- Partidos agregados: " << partidosAgregados << "\n"
                  << "- Equipos únicos: " << equipos.obtenerElementos().getTamanio() << "\n"
                  << "- Competiciones únicas: " << competiciones.obtenerElementos().getTamanio() << "\n";
        
        return partidosAgregados > 0;
        
    } catch (const std::exception& e) {
        std::cerr << "Error crítico durante la carga del archivo: " << e.what() << "\n";
        throw;
    }
}

Lista<std::string> BaseDeDatos::obtenerTodosLosEquipos() const {
    Lista<std::string> listaEquipos;
    Lista<Equipo> equiposOrdenados = equipos.obtenerElementos();
    
    for(int i = 0; i < equiposOrdenados.getTamanio(); i++) {
        listaEquipos.insertarUltimo(equiposOrdenados.getDato(i).getNombre());
    }
    
    return listaEquipos;
}

Lista<std::string> BaseDeDatos::obtenerTodasLasCompeticiones() const {
    Lista<std::string> listaCompeticiones;
    Lista<Competicion> competicionesOrdenadas = competiciones.obtenerElementos();
    
    // Set para evitar duplicados
    std::set<std::string> competicionesUnicas;
    
    for(int i = 0; i < competicionesOrdenadas.getTamanio(); i++) {
        const std::string& nombreComp = competicionesOrdenadas.getDato(i).getNombre();
        // Solo agregar si no está vacío y no contiene caracteres especiales
        if(!nombreComp.empty() && nombreComp.find(',') == std::string::npos) {
            competicionesUnicas.insert(nombreComp);
        }
    }
    
    // Convertir el set a lista
    for(const auto& comp : competicionesUnicas) {
        listaCompeticiones.insertarUltimo(comp);
    }
    
    return listaCompeticiones;
}

ListaDoble<Partido> BaseDeDatos::obtenerPartidosPorEquipo(const std::string& nombreEquipo) const {
    ListaDoble<Partido> partidosEquipo;
    
    for(int i = 0; i < partidos.getTamanio(); i++) {
        const Partido& partido = partidos.getDato(i);
        if(partido.getEquipoLocal() == nombreEquipo || 
           partido.getEquipoVisitante() == nombreEquipo) {
            partidosEquipo.insertarUltimo(partido);
        }
    }
    
    return partidosEquipo;
}

ListaDoble<Partido> BaseDeDatos::obtenerPartidosPorCompeticion(const std::string& competicion) const {
    ListaDoble<Partido> partidosCompeticion;
    
    for(int i = 0; i < partidos.getTamanio(); i++) {
        const Partido& partido = partidos.getDato(i);
        if(partido.getCompeticion() == competicion) {
            partidosCompeticion.insertarUltimo(partido);
        }
    }
    
    return partidosCompeticion;
}

bool BaseDeDatos::agregarPartido(const Partido& partido) {
    try {
        // Verificar que los equipos existan o crearlos
        try {
            equipos.put(Equipo(partido.getEquipoLocal()));
            equipos.put(Equipo(partido.getEquipoVisitante()));
        } catch (...) {}

        // Verificar que la competición exista o crearla
        try {
            competiciones.put(Competicion(partido.getCompeticion()));
        } catch (...) {}

        // Agregar el partido
        partidos.insertarUltimo(partido);
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error al agregar partido: " << e.what() << "\n";
        return false;
    }
}

bool BaseDeDatos::modificarPartido(const std::string& fecha, const std::string& equipoLocal,
                                 const std::string& equipoVisitante, int nuevosGolesLocal,
                                 int nuevosGolesVisitante) {
    for(int i = 0; i < partidos.getTamanio(); i++) {
        const Partido& partido = partidos.getDato(i);
        if(partido.getFecha() == fecha &&
           partido.getEquipoLocal() == equipoLocal &&
           partido.getEquipoVisitante() == equipoVisitante) {
            // Crear nuevo partido con los datos actualizados
            Partido partidoModificado(fecha, equipoLocal, nuevosGolesLocal,
                                    nuevosGolesVisitante, equipoVisitante,
                                    partido.getCompeticion());
            partidos.reemplazar(i, partidoModificado);
            return true;
        }
    }
    return false;
}

bool BaseDeDatos::eliminarPartido(const std::string& fecha, const std::string& equipoLocal,
                                const std::string& equipoVisitante) {
    for(int i = 0; i < partidos.getTamanio(); i++) {
        const Partido& partido = partidos.getDato(i);
        if(partido.getFecha() == fecha &&
           partido.getEquipoLocal() == equipoLocal &&
           partido.getEquipoVisitante() == equipoVisitante) {
            partidos.remover(i);
            return true;
        }
    }
    return false;
}

// ... resto de implementaciones ...