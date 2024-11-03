#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include <string>
#include <utility>
#include "Partido.h"
#include "Equipo.h"
#include "Competicion.h"
#include "Listas/ListaDoble.h"
#include "Arbol/ArbolBinarioAVL.h"

class BaseDeDatos {
private:
    ArbolBinarioAVL<Competicion> competiciones;
    ArbolBinarioAVL<Equipo> equipos;
    ListaDoble<Partido> partidos;
    void actualizarEquiposYCompeticiones(const Partido& partido);
    Equipo* buscarEquipo(const std::string& nombreEquipo);
    Competicion* buscarCompeticion(const std::string& nombreCompeticion);

public:
    BaseDeDatos();
    ~BaseDeDatos();
    bool cargarArchivo(const std::string& nombreArchivo);
    void procesarDatos();
    ListaDoble<Partido> obtenerPartidosPorCompeticion(const std::string& competicion) const;
    std::pair<int, int> obtenerGolesTotalesPorEquipo(const std::string& nombreEquipo);
    std::pair<double, double> obtenerPromedioGolesPorEquipo(const std::string& nombreEquipo);
    std::pair<int, int> obtenerDerrotasYTriunfosPorEquipo(const std::string& nombreEquipo);
    std::pair<std::string, std::string> obtenerFechasConMasYMenosGoles(const std::string& nombreEquipo);
    std::string obtenerCompeticionConMasGoles();
    std::pair<std::string, std::string> obtenerEquipoConMasYMenosGoles();
    ListaDoble<Partido> obtenerResultadosEquipoFechas(const std::string& nombreEquipo, 
                                                     const std::string& fechaInicio, 
                                                     const std::string& fechaFin);
    std::pair<std::pair<int, int>, std::pair<int, int>> compararRendimientoGeneral(const std::string& equipo1, 
                                                                                   const std::string& equipo2);
    std::pair<int, int> compararRendimientoParticular(const std::string& equipo1, 
                                                     const std::string& equipo2);
    Lista<Equipo> filtrarEquiposPorUmbral(int umbral, bool porEncima);
    Lista<std::string> obtenerTodosLosEquipos() const;
    Lista<std::string> obtenerTodasLasCompeticiones() const;
    ListaDoble<Partido> obtenerResultadosEquipoCompeticion(const std::string& nombreEquipo, 
                                                          const std::string& competicion);
    ListaDoble<Partido> obtenerPartidosConMasGoles();
    ListaDoble<Partido> obtenerPartidosPorEquipo(const std::string& nombreEquipo) const;
    bool agregarPartido(const Partido& partido);
    bool modificarPartido(const std::string& fecha, const std::string& equipoLocal,
                         const std::string& equipoVisitante, int nuevosGolesLocal,
                         int nuevosGolesVisitante);
    bool eliminarPartido(const std::string& fecha, const std::string& equipoLocal,
                        const std::string& equipoVisitante);
};

#endif // BASEDEDATOS_H
