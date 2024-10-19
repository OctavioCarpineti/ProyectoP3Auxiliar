//
// Created by Octavio Carpineti on 18/10/2024.
//

// InterfazUsuario.cpp
#include "InterfazUsuario.h"
#include "iostream"
#include "GestorConsultas.h"

// Constructor de la clase InterfazUsuario
InterfazUsuario::InterfazUsuario(GestorConsultas* gestorConsultas)
    : gestorConsultas(gestorConsultas) {}

// Muestra el menú principal
void InterfazUsuario::mostrarMenu() {
    int opcion;
    do {
        std::cout << "1. Consultar resultados de un equipo" << std::endl;
        std::cout << "2. Salir" << std::endl;
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                consultarResultadosEquipo();
                break;
            case 2:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida." << std::endl;
        }
    } while (opcion != 2);
}

// Consulta los resultados de un equipo
void InterfazUsuario::consultarResultadosEquipo() {
    std::string nombreEquipo, nombreCompeticion;
    std::cout << "Ingrese el nombre del equipo: ";
    std::cin >> nombreEquipo;
    std::cout << "Ingrese el nombre de la competición: ";
    std::cin >> nombreCompeticion;

    gestorConsultas->consultarResultadosEquipo(nombreEquipo, nombreCompeticion);
}