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
    Partido() = default; // Add this line
    Partido(const std::string& fecha, const std::string& equipoLocal, int golesLocal, int golesVisitante, const std::string& equipoVisitante, const std::string& competicion);
    const std::string& getFecha() const;
    const std::string& getEquipoLocal() const;
    const std::string& getEquipoVisitante() const;
    int getGolesLocal() const;
    int getGolesVisitante() const;
    const std::string& getCompeticion() const;
};

#endif // PARTIDO_H