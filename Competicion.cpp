#include "Competicion.h"
#include <iostream>
#include <algorithm>

Competicion::Competicion(const std::string& nombre) : nombre(nombre) {}

std::string Competicion::getNombre() const {
    return nombre;
}

const ArbolBinarioAVL<Equipo>& Competicion::getEquipos() const {
    return equipos;
}

const ListaDoble<Partido>& Competicion::getPartidos() const {
    return partidos;
}

void Competicion::agregarEquipo(const Equipo& equipo) {
    try {
        equipos.put(equipo);
    } catch(...) {
        // El equipo ya existe en el árbol
    }
}

void Competicion::agregarPartido(const Partido& partido) {
    // Convertir ambos strings a minúsculas para comparar
    std::string comp1 = partido.getCompeticion();
    std::string comp2 = nombre;
    std::transform(comp1.begin(), comp1.end(), comp1.begin(), ::tolower);
    std::transform(comp2.begin(), comp2.end(), comp2.begin(), ::tolower);
    
    // Verificar que el partido pertenece a esta competición
    if(comp1 != comp2) {
        std::cerr << "Competición del partido: " << partido.getCompeticion() 
                  << ", Competición actual: " << nombre << std::endl;
        throw std::invalid_argument("El partido no pertenece a esta competición");
    }
    
    // Agregar el partido a la lista
    partidos.insertarUltimo(partido);
    
    // Actualizar equipos
    Equipo* equipoLocal = buscarEquipo(partido.getEquipoLocal());
    Equipo* equipoVisitante = buscarEquipo(partido.getEquipoVisitante());
    
    if(equipoLocal) {
        equipoLocal->agregarPartido(partido);
    } else {
        agregarEquipo(Equipo(partido.getEquipoLocal()));
    }
    
    if(equipoVisitante) {
        equipoVisitante->agregarPartido(partido);
    } else {
        agregarEquipo(Equipo(partido.getEquipoVisitante()));
    }
}

Equipo* Competicion::buscarEquipo(const std::string& nombreEquipo) {
    try {
        Equipo equipoBuscado(nombreEquipo);
        equipos.put(equipoBuscado);  // Intentar insertar, si ya existe no hará nada
        return nullptr;  // Por ahora retornamos nullptr, ya que el equipo está en el árbol
    } catch (...) {
        return nullptr;
    }
}

int Competicion::getTotalGoles() const {
    int total = 0;
    for(int i = 0; i < partidos.getTamanio(); i++) {
        const Partido& partido = partidos.getDato(i);
        total += partido.getTotalGoles();
    }
    return total;
}

std::pair<std::string, int> Competicion::getEquipoMaxGoles() const {
    if (equipos.esVacio()) {
        return {"", 0};
    }

    std::string equipoMax;
    int maxGoles = -1;
    
    // Obtener lista de equipos usando el nuevo método
    Lista<Equipo> listaEquipos = equipos.obtenerElementos();
    
    for(int i = 0; i < listaEquipos.getTamanio(); i++) {
        const Equipo& equipo = listaEquipos.getDato(i);
        auto [golesFavor, _] = equipo.obtenerGolesTotales();
        
        if(golesFavor > maxGoles) {
            maxGoles = golesFavor;
            equipoMax = equipo.getNombre();
        }
    }
    
    return {equipoMax, maxGoles};
}

std::pair<std::string, int> Competicion::getEquipoMinGoles() const {
    if (equipos.esVacio()) {
        return {"", 0};
    }

    std::string equipoMin;
    int minGoles = std::numeric_limits<int>::max();
    
    // Obtener lista de equipos usando el nuevo método
    Lista<Equipo> listaEquipos = equipos.obtenerElementos();
    
    for(int i = 0; i < listaEquipos.getTamanio(); i++) {
        const Equipo& equipo = listaEquipos.getDato(i);
        auto [golesFavor, _] = equipo.obtenerGolesTotales();
        
        if(golesFavor < minGoles) {
            minGoles = golesFavor;
            equipoMin = equipo.getNombre();
        }
    }
    
    return {equipoMin, minGoles};
}
