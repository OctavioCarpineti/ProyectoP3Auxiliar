#ifndef PROYECTO_INTERFAZUSUARIO_H
#define PROYECTO_INTERFAZUSUARIO_H

#include "GestorConsultas.h"
#include <iostream>
#include <string>
#include <vector>

class InterfazUsuario {
private:
    GestorConsultas* gestorConsultas;
    BaseDeDatos* baseDeDatos;

public:
    InterfazUsuario(GestorConsultas* gestorConsultas, BaseDeDatos* baseDeDatos);
    void mostrarMenuInicial();
    void mostrarMenuPrincipal();
    void consultarResultadosEquipo();

    void buscarPorCompeticion();
    void buscarPorEquipo();
    void buscarPorTemporada();
    void buscarPorFecha();
    void mostrarEstadisticasGenerales();
    void mostrarPartidosDestacados();
    void mostrarClasificaciones();

    // Funciones auxiliares
    void mostrarCompeticiones();
    void mostrarEquipos();
    void mostrarTemporadas();
    std::string solicitarFecha();
    std::string obtenerNombreCompeticion(int opcion);
};

#endif //PROYECTO_INTERFAZUSUARIO_H