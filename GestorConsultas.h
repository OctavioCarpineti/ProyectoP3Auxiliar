#ifndef GESTOR_CONSULTAS_H
#define GESTOR_CONSULTAS_H

#include "BaseDeDatos.h"
#include "Listas/Lista.h"
#include "Arbol/ArbolBinarioAVL.h"
#include <string>

class GestorConsultas {
private:
    BaseDeDatos& baseDatos;
    
    // Métodos auxiliares para procesar consultas
    ArbolBinarioAVL<Partido> ordenarPartidosPorGoles(const ListaDoble<Partido>& partidos);
    bool compararPartidosPorGoles(const Partido& p1, const Partido& p2) const;

public:
    explicit GestorConsultas(BaseDeDatos& bd);
    
    // Consultas principales usando estructuras optimizadas
    ListaDoble<Partido> obtenerTop5PartidosPorGoles(const std::string& competicion);
    std::pair<int, int> consultarGolesTotalesPorEquipo(const std::string& equipo);
    std::pair<double, double> consultarPromedioGolesPorEquipo(const std::string& equipo);
    
    // Consultas de búsqueda y filtrado
    ListaDoble<Partido> consultarPartidosEntreFechas(const std::string& equipo, 
                                                    const std::string& fechaInicio, 
                                                    const std::string& fechaFin);
    std::pair<std::string, std::string> consultarEquiposMaxMinGoles();
    std::string consultarCompeticionMasGoles();
    
    // Métodos para obtener listas de datos
    Lista<std::string> obtenerListaEquipos() const;
    Lista<std::string> obtenerListaCompeticiones() const;

    // Agregar estos métodos:
    std::pair<int, int> consultarGolesTotalesPorEquipo(const std::string& equipo, const std::string& competicion);
    std::pair<double, double> consultarPromedioGolesPorEquipo(const std::string& equipo, const std::string& competicion);
    std::pair<int, int> obtenerDerrotasYTriunfosPorEquipo(const std::string& equipo, const std::string& competicion);
    std::pair<std::string, std::string> obtenerFechasConMasYMenosGoles(const std::string& equipo, const std::string& competicion);
    std::pair<std::string, std::string> consultarEquiposMaxMinGolesPorCompeticion(const std::string& competicion);

    // Agregar estos métodos para modificación de datos
    bool agregarPartido(const std::string& fecha, const std::string& equipoLocal,
                       int golesLocal, int golesVisitante,
                       const std::string& equipoVisitante, const std::string& competicion);
    bool modificarPartido(const std::string& fecha, const std::string& equipoLocal,
                         const std::string& equipoVisitante, int nuevosGolesLocal,
                         int nuevosGolesVisitante);
    bool eliminarPartido(const std::string& fecha, const std::string& equipoLocal,
                        const std::string& equipoVisitante);
};

#endif
