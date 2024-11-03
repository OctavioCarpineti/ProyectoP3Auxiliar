#ifndef INTERFAZUSUARIO_H
#define INTERFAZUSUARIO_H

#include "GestorConsultas.h"
#include "BaseDeDatos.h"
#include "Partido.h"
#include "Listas/ListaDoble.h"
#include <string>
#include <utility>

class InterfazUsuario {
private:
    GestorConsultas& gestor;
    BaseDeDatos& baseDatos;

    // Menús principales
    void mostrarMenuPrincipal() const;
    void mostrarMenuConsultasDinamicas() const;
    void mostrarMenuModificacionDatos() const;

    void mostrarMenuRegistroDatos() const;
    void procesarMenuRegistroDatos();

    std::string solicitarFecha() const;  // Agregar esta declaración

    // Procesadores de menús
    void procesarMenuProcesamientoDatos();
    void procesarMenuConsultasDinamicas();
    void procesarMenuModificacionDatos();

    // Métodos de visualización existentes
    void mostrarPartidos(const ListaDoble<Partido>& partidos) const;
    void mostrarEstadisticasEquipo(const std::string& equipo) const;
    void mostrarTop5PorCompeticion(const std::string& competicion) const;
    void mostrarGolesTotalesPorEquipo(const std::string& equipo) const;
    void mostrarPromedioGolesPorEquipo(const std::string& equipo) const;
    void mostrarDerrotasYTriunfosPorEquipo(const std::string& equipo) const;
    void mostrarFechasExtremasPorEquipo(const std::string& equipo) const;
    void mostrarCompeticionMasGoles() const;
    void mostrarEquiposExtremosGeneralYPorCompeticion() const;

    // Métodos auxiliares existentes
    std::string solicitarEquipo() const;
    std::string solicitarCompeticion() const;
    std::pair<std::string, std::string> solicitarFechas() const;

    // Nuevos métodos para consultas dinámicas
    void mostrarResultadosEquipoCompeticion(const std::string& equipo, const std::string& competicion) const;
    void mostrarComparacionRendimientoGeneral(const std::string& equipo1, const std::string& equipo2) const;
    void mostrarComparacionRendimientoParticular(const std::string& equipo1, const std::string& equipo2) const;
    void mostrarEquiposPorUmbralGoles() const;

    // Nuevos métodos para modificación de datos
    void agregarPartido();
    void eliminarPartido();
    void modificarPartido();

public:
    InterfazUsuario(GestorConsultas& g, BaseDeDatos& bd);
    void iniciar();
};

#endif // INTERFAZUSUARIO_H
