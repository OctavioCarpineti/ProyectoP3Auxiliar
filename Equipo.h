#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>
#include "Partido.h"
#include "Listas/Lista.h"
#include "Listas/ListaDoble.h"

class Equipo {
private:
    std::string nombre;
    ListaDoble<Partido> partidos;

public:
    explicit Equipo(const std::string& nombre);
    const std::string& getNombre() const;
    void agregarPartido(const Partido& partido);
    const ListaDoble<Partido>& getPartidos() const;
    
    // Operadores necesarios para el árbol
    bool operator<(const Equipo& otro) const { return nombre < otro.nombre; }
    bool operator>(const Equipo& otro) const { return nombre > otro.nombre; }
    bool operator==(const Equipo& otro) const { return nombre == otro.nombre; }
    
    // Métodos para estadísticas
    std::pair<int, int> obtenerGolesTotales() const;
    std::pair<double, double> obtenerPromedioGoles() const;
    std::pair<int, int> obtenerDerrotasYTriunfos() const;
    std::pair<std::string, std::string> obtenerFechasExtremas() const;
};

#endif // EQUIPO_H
