#include "GestorConsultas.h"
#include <chrono>
#include <iostream>
#include <limits>

GestorConsultas::GestorConsultas(BaseDeDatos& bd) : baseDatos(bd) {}

ListaDoble<Partido> GestorConsultas::obtenerTop5PartidosPorGoles(const std::string& competicion) {
    ListaDoble<Partido> partidos = baseDatos.obtenerPartidosPorCompeticion(competicion);
    ListaDoble<Partido> top5;
    
    if (partidos.esVacia()) {
        return top5;
    }
    
    try {
        // Ordenar por goles y fecha (si hay empate en goles)
        for(int i = 0; i < partidos.getTamanio() - 1; i++) {
            for(int j = 0; j < partidos.getTamanio() - i - 1; j++) {
                const Partido& actual = partidos.getDato(j);
                const Partido& siguiente = partidos.getDato(j + 1);
                
                bool debeCambiar = false;
                if (actual.getTotalGoles() < siguiente.getTotalGoles()) {
                    debeCambiar = true;
                } else if (actual.getTotalGoles() == siguiente.getTotalGoles()) {
                    // Si hay empate en goles, comparar fechas (formato DD/MM/YYYY)
                    std::string fechaActual = actual.getFecha();
                    std::string fechaSiguiente = siguiente.getFecha();
                    
                    // Convertir a formato YYYYMMDD para comparación
                    std::string fechaActualComp = fechaActual.substr(6,4) + 
                                                 fechaActual.substr(3,2) + 
                                                 fechaActual.substr(0,2);
                    std::string fechaSiguienteComp = fechaSiguiente.substr(6,4) + 
                                                    fechaSiguiente.substr(3,2) + 
                                                    fechaSiguiente.substr(0,2);
                    
                    if (fechaActualComp < fechaSiguienteComp) {
                        debeCambiar = true;
                    }
                }
                
                if (debeCambiar) {
                    Partido temp = partidos.getDato(j);
                    partidos.getDato(j) = partidos.getDato(j + 1);
                    partidos.getDato(j + 1) = temp;
                }
            }
        }
        
        // Tomar los primeros 5
        int count = 0;
        for(int i = 0; i < partidos.getTamanio() && count < 5; i++) {
            top5.insertarUltimo(partidos.getDato(i));
            count++;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error al obtener top 5: " << e.what() << "\n";
    }
    
    return top5;
}

std::pair<int, int> GestorConsultas::consultarGolesTotalesPorEquipo(const std::string& equipo, const std::string& competicion) {
    ListaDoble<Partido> partidos = baseDatos.obtenerPartidosPorCompeticion(competicion);
    int golesFavor = 0, golesContra = 0;
    
    for(int i = 0; i < partidos.getTamanio(); i++) {
        const Partido& partido = partidos.getDato(i);
        if(partido.getEquipoLocal() == equipo) {
            golesFavor += partido.getGolesLocal();
            golesContra += partido.getGolesVisitante();
        } else if(partido.getEquipoVisitante() == equipo) {
            golesFavor += partido.getGolesVisitante();
            golesContra += partido.getGolesLocal();
        }
    }
    
    return {golesFavor, golesContra};
}

std::pair<double, double> GestorConsultas::consultarPromedioGolesPorEquipo(const std::string& equipo, const std::string& competicion) {
    auto [golesFavor, golesContra] = consultarGolesTotalesPorEquipo(equipo, competicion);
    int cantidadPartidos = 0;
    ListaDoble<Partido> partidos = baseDatos.obtenerPartidosPorCompeticion(competicion);
    
    for(int i = 0; i < partidos.getTamanio(); i++) {
        const Partido& partido = partidos.getDato(i);
        if(partido.getEquipoLocal() == equipo || partido.getEquipoVisitante() == equipo) {
            cantidadPartidos++;
        }
    }
    
    if(cantidadPartidos == 0) return {0.0, 0.0};
    
    return {
        static_cast<double>(golesFavor) / cantidadPartidos,
        static_cast<double>(golesContra) / cantidadPartidos
    };
}

std::pair<int, int> GestorConsultas::consultarGolesTotalesPorEquipo(const std::string& equipo) {
    ListaDoble<Partido> partidos = baseDatos.obtenerPartidosPorEquipo(equipo);
    int golesFavor = 0, golesContra = 0;
    
    for(int i = 0; i < partidos.getTamanio(); i++) {
        const Partido& partido = partidos.getDato(i);
        if(partido.getEquipoLocal() == equipo) {
            golesFavor += partido.getGolesLocal();
            golesContra += partido.getGolesVisitante();
        } else {
            golesFavor += partido.getGolesVisitante();
            golesContra += partido.getGolesLocal();
        }
    }
    
    return {golesFavor, golesContra};
}

std::pair<double, double> GestorConsultas::consultarPromedioGolesPorEquipo(const std::string& equipo) {
    auto [golesFavor, golesContra] = consultarGolesTotalesPorEquipo(equipo);
    ListaDoble<Partido> partidos = baseDatos.obtenerPartidosPorEquipo(equipo);
    int cantidadPartidos = partidos.getTamanio();
    
    if(cantidadPartidos == 0) return {0.0, 0.0};
    
    return {
        static_cast<double>(golesFavor) / cantidadPartidos,
        static_cast<double>(golesContra) / cantidadPartidos
    };
}

ArbolBinarioAVL<Partido> GestorConsultas::ordenarPartidosPorGoles(const ListaDoble<Partido>& partidos) {
    ArbolBinarioAVL<Partido> arbol;
    
    // Primero, verificar si hay partidos
    if (partidos.esVacia()) {
        return arbol;
    }
    
    try {
        for(int i = 0; i < partidos.getTamanio(); i++) {
            const Partido& partido = partidos.getDato(i);
            try {
                arbol.put(partido);
            } catch (...) {
                std::cerr << "Advertencia: No se pudo insertar un partido en el árbol\n";
                continue;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error al ordenar partidos: " << e.what() << "\n";
    }
    
    return arbol;
}

ListaDoble<Partido> GestorConsultas::consultarPartidosEntreFechas(
    const std::string& equipo, 
    const std::string& fechaInicio, 
    const std::string& fechaFin) {
    
    ListaDoble<Partido> resultado;
    ListaDoble<Partido> todosPartidos = baseDatos.obtenerPartidosPorEquipo(equipo);
    
    // Convertir fechas a formato comparable (YYYY-MM-DD)
    std::string fechaInicioComp = fechaInicio.substr(6,4) + fechaInicio.substr(3,2) + fechaInicio.substr(0,2);
    std::string fechaFinComp = fechaFin.substr(6,4) + fechaFin.substr(3,2) + fechaFin.substr(0,2);
    
    try {
        for(int i = 0; i < todosPartidos.getTamanio(); i++) {
            const Partido& partido = todosPartidos.getDato(i);
            std::string fechaPartido = partido.getFecha();
            
            // Convertir fecha del partido al mismo formato
            std::string fechaPartidoComp = fechaPartido.substr(6,4) + 
                                         fechaPartido.substr(3,2) + 
                                         fechaPartido.substr(0,2);
            
            if(fechaPartidoComp >= fechaInicioComp && fechaPartidoComp <= fechaFinComp) {
                resultado.insertarUltimo(partido);
            }
        }
        
        // Si no se encontraron partidos, mostrar mensaje
        if(resultado.esVacia()) {
            std::cout << "No se encontraron partidos para " << equipo 
                      << " entre " << fechaInicio << " y " << fechaFin << "\n";
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error al buscar partidos: " << e.what() << "\n";
    }
    
    return resultado;
}

std::string GestorConsultas::consultarCompeticionMasGoles() {
    Lista<std::string> competiciones = baseDatos.obtenerTodasLasCompeticiones();
    std::string competicionMax;
    int maxGoles = -1;
    
    for(int i = 0; i < competiciones.getTamanio(); i++) {
        const std::string& comp = competiciones.getDato(i);
        int golesCompeticion = 0;
        
        ListaDoble<Partido> partidos = baseDatos.obtenerPartidosPorCompeticion(comp);
        for(int j = 0; j < partidos.getTamanio(); j++) {
            const Partido& partido = partidos.getDato(j);
            golesCompeticion += partido.getTotalGoles();
        }
        
        if(golesCompeticion > maxGoles) {
            maxGoles = golesCompeticion;
            competicionMax = comp;
        }
    }
    
    return competicionMax;
}

std::pair<int, int> GestorConsultas::obtenerDerrotasYTriunfosPorEquipo(const std::string& equipo, const std::string& competicion) {
    ListaDoble<Partido> partidos = baseDatos.obtenerPartidosPorCompeticion(competicion);
    int victorias = 0, derrotas = 0;
    
    for(int i = 0; i < partidos.getTamanio(); i++) {
        const Partido& partido = partidos.getDato(i);
        
        if(partido.getEquipoLocal() == equipo) {
            if(partido.getGolesLocal() > partido.getGolesVisitante()) {
                victorias++;
            } else if(partido.getGolesLocal() < partido.getGolesVisitante()) {
                derrotas++;
            }
        } else if(partido.getEquipoVisitante() == equipo) {
            if(partido.getGolesVisitante() > partido.getGolesLocal()) {
                victorias++;
            } else if(partido.getGolesVisitante() < partido.getGolesLocal()) {
                derrotas++;
            }
        }
    }
    
    return {victorias, derrotas};
}

std::pair<std::string, std::string> GestorConsultas::obtenerFechasConMasYMenosGoles(const std::string& equipo, const std::string& competicion) {
    ListaDoble<Partido> partidos = baseDatos.obtenerPartidosPorCompeticion(competicion);
    std::string fechaMasGoles, fechaMenosGoles;
    int maxGoles = -1, minGoles = std::numeric_limits<int>::max();
    
    for(int i = 0; i < partidos.getTamanio(); i++) {
        const Partido& partido = partidos.getDato(i);
        if(partido.getEquipoLocal() == equipo || partido.getEquipoVisitante() == equipo) {
            int golesPartido = partido.getTotalGoles();
            
            if(golesPartido > maxGoles) {
                maxGoles = golesPartido;
                fechaMasGoles = partido.getFecha();
            }
            if(golesPartido < minGoles) {
                minGoles = golesPartido;
                fechaMenosGoles = partido.getFecha();
            }
        }
    }
    
    return {fechaMasGoles, fechaMenosGoles};
}

std::pair<std::string, std::string> GestorConsultas::consultarEquiposMaxMinGolesPorCompeticion(const std::string& competicion) {
    Lista<std::string> equipos = baseDatos.obtenerTodosLosEquipos();
    std::string equipoMax, equipoMin;
    int maxGoles = std::numeric_limits<int>::min();
    int minGoles = std::numeric_limits<int>::max();
    
    for(int i = 0; i < equipos.getTamanio(); i++) {
        const std::string& equipo = equipos.getDato(i);
        auto [golesFavor, _] = consultarGolesTotalesPorEquipo(equipo, competicion);
        
        if(golesFavor > maxGoles) {
            maxGoles = golesFavor;
            equipoMax = equipo;
        }
        if(golesFavor < minGoles && golesFavor > 0) { // Solo considerar equipos que hayan jugado
            minGoles = golesFavor;
            equipoMin = equipo;
        }
    }
    
    return {equipoMax, equipoMin};
}

Lista<std::string> GestorConsultas::obtenerListaEquipos() const {
    return baseDatos.obtenerTodosLosEquipos();
}

Lista<std::string> GestorConsultas::obtenerListaCompeticiones() const {
    return baseDatos.obtenerTodasLasCompeticiones();
}

std::pair<std::string, std::string> GestorConsultas::consultarEquiposMaxMinGoles() {
    Lista<std::string> equipos = baseDatos.obtenerTodosLosEquipos();
    std::string equipoMax, equipoMin;
    int maxGoles = std::numeric_limits<int>::min();
    int minGoles = std::numeric_limits<int>::max();
    
    for(int i = 0; i < equipos.getTamanio(); i++) {
        const std::string& equipo = equipos.getDato(i);
        auto [golesFavor, _] = consultarGolesTotalesPorEquipo(equipo);
        
        if(golesFavor > maxGoles) {
            maxGoles = golesFavor;
            equipoMax = equipo;
        }
        if(golesFavor < minGoles) {
            minGoles = golesFavor;
            equipoMin = equipo;
        }
    }
    
    return {equipoMax, equipoMin};
}

bool GestorConsultas::agregarPartido(const std::string& fecha, const std::string& equipoLocal,
                                    int golesLocal, int golesVisitante,
                                    const std::string& equipoVisitante, const std::string& competicion) {
    try {
        Partido nuevoPartido(fecha, equipoLocal, golesLocal, golesVisitante,
                           equipoVisitante, competicion);
        return baseDatos.agregarPartido(nuevoPartido);
    } catch (const std::exception& e) {
        std::cerr << "Error al crear partido: " << e.what() << "\n";
        return false;
    }
}

bool GestorConsultas::modificarPartido(const std::string& fecha, const std::string& equipoLocal,
                                     const std::string& equipoVisitante, int nuevosGolesLocal,
                                     int nuevosGolesVisitante) {
    return baseDatos.modificarPartido(fecha, equipoLocal, equipoVisitante,
                                    nuevosGolesLocal, nuevosGolesVisitante);
}

bool GestorConsultas::eliminarPartido(const std::string& fecha, const std::string& equipoLocal,
                                    const std::string& equipoVisitante) {
    return baseDatos.eliminarPartido(fecha, equipoLocal, equipoVisitante);
}