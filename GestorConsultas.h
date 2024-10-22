#ifndef GESTORCONSULTAS_H
#define GESTORCONSULTAS_H

#include "BaseDeDatos.h"
#include <string>

class GestorConsultas {
private:
    BaseDeDatos* baseDeDatos; // Puntero a la base de datos

public:
    GestorConsultas(BaseDeDatos* baseDeDatos);
    void cargarDatos(const std::string& nombreArchivo);
    void consultarResultadosEquipo(const std::string& nombreEquipo, const std::string& nombreCompeticion);
    void agregarCompeticion(const std::string& nombreCompeticion);
    void eliminarCompeticion(const std::string& nombreCompeticion);
    void agregarPartido(const std::string& nombreCompeticion, const std::string& fecha, const std::string& equipoLocal, int golesLocal, int golesVisitante, const std::string& equipoVisitante);
    void eliminarPartido(const std::string& nombreCompeticion, const std::string& fecha, const std::string& equipoLocal, const std::string& equipoVisitante);
    void modificarPartido(const std::string& nombreCompeticion, const std::string& fecha, const std::string& equipoLocal, int golesLocal, int golesVisitante, const std::string& equipoVisitante);
    void obtenerDatosCompeticion(const std::string& nombreCompeticion);

    // Nuevas funciones
    void mostrarPartidosConMasGoles();
    void mostrarGolesTotalesPorEquipo(const std::string& nombreEquipo);
    void mostrarPromedioGolesPorEquipo(const std::string& nombreEquipo);
    void mostrarDerrotasYTriunfosPorEquipo(const std::string& nombreEquipo);
    void mostrarFechasConMasYMenosGoles(const std::string& nombreEquipo);
    void mostrarCompeticionConMasGoles();
    void mostrarEquipoConMasYMenosGoles();
    void consultarResultadosEquipoFechas(const std::string& nombreEquipo, const std::string& fechaInicio, const std::string& fechaFin);
    void compararRendimientoGeneral(const std::string& equipo1, const std::string& equipo2);
    void compararRendimientoParticular(const std::string& equipo1, const std::string& equipo2);
    void filtrarEquiposPorUmbral(int umbral, bool porEncima);
};

#endif // GESTORCONSULTAS_H