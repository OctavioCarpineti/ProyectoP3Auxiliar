#include "Equipo.h"
#include <limits>

Equipo::Equipo(const std::string& nombre) : nombre(nombre) {}

const std::string& Equipo::getNombre() const {
    return nombre;
}

const ListaDoble<Partido>& Equipo::getPartidos() const {
    return partidos;
}

void Equipo::agregarPartido(const Partido& partido) {
    // Insertar manteniendo orden cronológico
    int pos = 0;
    bool insertado = false;
    
    for(int i = 0; i < partidos.getTamanio() && !insertado; i++) {
        if(partido.getFecha() < partidos.getDato(i).getFecha()) {
            partidos.insertar(i, partido);
            insertado = true;
        }
        pos++;
    }
    
    if(!insertado) {
        partidos.insertarUltimo(partido);
    }
}

std::pair<int, int> Equipo::obtenerGolesTotales() const {
    int golesFavor = 0, golesContra = 0;
    
    for(int i = 0; i < partidos.getTamanio(); i++) {
        const Partido& partido = partidos.getDato(i);
        if(partido.getEquipoLocal() == nombre) {
            golesFavor += partido.getGolesLocal();
            golesContra += partido.getGolesVisitante();
        } else {
            golesFavor += partido.getGolesVisitante();
            golesContra += partido.getGolesLocal();
        }
    }
    
    return {golesFavor, golesContra};
}

std::pair<double, double> Equipo::obtenerPromedioGoles() const {
    auto totales = obtenerGolesTotales();
    int cantPartidos = partidos.getTamanio();
    
    if(cantPartidos == 0) return {0.0, 0.0};
    
    return {
        static_cast<double>(totales.first) / cantPartidos,
        static_cast<double>(totales.second) / cantPartidos
    };
}

std::pair<int, int> Equipo::obtenerDerrotasYTriunfos() const {
    int derrotas = 0, triunfos = 0;
    
    for(int i = 0; i < partidos.getTamanio(); i++) {
        const Partido& partido = partidos.getDato(i);
        int golesPropios, golesRival;
        
        if(partido.getEquipoLocal() == nombre) {
            golesPropios = partido.getGolesLocal();
            golesRival = partido.getGolesVisitante();
        } else {
            golesPropios = partido.getGolesVisitante();
            golesRival = partido.getGolesLocal();
        }
        
        if(golesPropios > golesRival) triunfos++;
        else if(golesPropios < golesRival) derrotas++;
    }
    
    return {derrotas, triunfos};
}

std::pair<std::string, std::string> Equipo::obtenerFechasExtremas() const {
    if(partidos.esVacia()) return {"", ""};
    
    std::string fechaMasGoles = partidos.getDato(0).getFecha();
    std::string fechaMenosGoles = partidos.getDato(0).getFecha();
    int maxGoles = -1, minGoles = std::numeric_limits<int>::max();
    
    for(int i = 0; i < partidos.getTamanio(); i++) {
        const Partido& partido = partidos.getDato(i);
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
    
    return {fechaMasGoles, fechaMenosGoles};
}
