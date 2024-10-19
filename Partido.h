//
// Created by Octavio Carpineti on 17/10/2024.
//

#ifndef PROYECTO_PARTIDO_H
#define PROYECTO_PARTIDO_H


// Partido.h
#ifndef PARTIDO_H
#define PARTIDO_H

#include <string>
#include "Equipo.h"
#include "Competicion.h"

class Partido {
private:
    std::string fecha;
    int golesLocal;
    int golesVisitante;
    Equipo* equipoLocal;
    Equipo* equipoVisitante;
    Competicion* competicion;

public:
    Partido(const std::string& fecha, int golesLocal, int golesVisitante,
            Equipo* equipoLocal, Equipo* equipoVisitante, Competicion* competicion);

    // Getters y setters
    std::string getFecha() const;
    int getGolesLocal() const;
    int getGolesVisitante() const;
    Equipo* getEquipoLocal() const;
    Equipo* getEquipoVisitante() const;
    Competicion* getCompeticion() const;

    void setFecha(const std::string& fecha);
    void setGolesLocal(int goles);
    void setGolesVisitante(int goles);
    void setEquipoLocal(Equipo* equipo);
    void setEquipoVisitante(Equipo* equipo);
    void setCompeticion(Competicion* competicion);
};

#endif // PARTIDO_H

#endif //PROYECTO_PARTIDO_H
