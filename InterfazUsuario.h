#ifndef PROYECTO_INTERFAZUSUARIO_H
#define PROYECTO_INTERFAZUSUARIO_H

#include "GestorConsultas.h"
#pragma once
#include "BaseDeDatos.h"
#include <iostream>
#include <string>
#include <vector>
#include "Arboles/NodoArbol.h"
#include "Arboles/NodoArbolAVL.h"
#include "Arboles/ArbolBinario.h"
#include "Arboles/ArbolBinarioAVL.h"
#include "Listas/Lista.h"
#include "Listas/ListaDoble.h"
#include "Listas/Nodo.h"

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
    std::string obtenerNombreCompeticion(int opcion);  // Nueva función
};

#endif //PROYECTO_INTERFAZUSUARIO_H