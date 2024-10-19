#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>
#include <vector>

class Equipo {
public:
    Equipo(const std::string& nombre) : nombre(nombre) {}
    const std::string& getNombre() const { return nombre; }
    void listarPartidos() const;
    void agregarPartido(const std::string& fecha, const std::string& oponente, int golesFavor, int golesContra, const std::string& competicion);
    // Otros métodos para procesar estadísticas

private:
    std::string nombre;
    struct Partido {
        std::string fecha;
        std::string oponente;
        int golesFavor;
        int golesContra;
        std::string competicion;
    };
    std::vector<Partido> partidos;
};

#endif // EQUIPO_H