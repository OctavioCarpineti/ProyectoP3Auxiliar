#ifndef PARTIDO_H
#define PARTIDO_H

#include <string>

class Partido {
private:
    std::string fecha;
    std::string equipoLocal;
    int golesLocal;
    int golesVisitante;
    std::string equipoVisitante;
    std::string competicion;

public:
    Partido(const std::string& fecha, const std::string& equipoLocal, 
            int golesLocal, int golesVisitante, 
            const std::string& equipoVisitante, const std::string& competicion);

    // Getters
    const std::string& getFecha() const;
    const std::string& getEquipoLocal() const;
    const std::string& getEquipoVisitante() const;
    const std::string& getCompeticion() const;
    int getGolesLocal() const;
    int getGolesVisitante() const;
    int getTotalGoles() const;

    // Operadores de comparación mejorados para usar en el árbol AVL
    bool operator<(const Partido& otro) const {
        // Primero comparar por total de goles
        int totalThis = getTotalGoles();
        int totalOtro = otro.getTotalGoles();
        if (totalThis != totalOtro) {
            return totalThis < totalOtro;
        }
        // Si hay empate en goles, comparar por fecha
        return fecha < otro.fecha;
    }
    
    bool operator>(const Partido& otro) const {
        return otro < *this;
    }
    
    bool operator==(const Partido& otro) const {
        return fecha == otro.fecha && 
               equipoLocal == otro.equipoLocal && 
               equipoVisitante == otro.equipoVisitante;
    }
};

#endif // PARTIDO_H
