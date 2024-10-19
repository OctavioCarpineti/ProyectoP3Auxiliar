#include <iostream>
#include "GestorConsultas.h"

void mostrarMenu() {
    std::cout << "Menu de opciones:\n";
    std::cout << "1. Cargar datos desde archivo CSV\n";
    std::cout << "2. Consultar resultados de un equipo en una competición\n";
    std::cout << "3. Agregar una competición\n";
    std::cout << "4. Eliminar una competición\n";
    std::cout << "5. Salir\n";
    std::cout << "Seleccione una opción: ";
}

int main() {
    BaseDeDatos baseDeDatos;
    GestorConsultas gestor(&baseDeDatos);
    int opcion;
    std::string nombreArchivo, nombreEquipo, nombreCompeticion;

    do {
        mostrarMenu();
        std::cin >> opcion;
        switch (opcion) {
            case 1:
                std::cout << "Ingrese el nombre del archivo CSV: ";
                std::cin >> nombreArchivo;
                gestor.cargarDatos(nombreArchivo);
                break;
            case 2:
                std::cout << "Ingrese el nombre del equipo: ";
                std::cin >> nombreEquipo;
                std::cout << "Ingrese el nombre de la competición: ";
                std::cin >> nombreCompeticion;
                gestor.consultarResultadosEquipo(nombreEquipo, nombreCompeticion);
                break;
            case 3:
                std::cout << "Ingrese el nombre de la competición: ";
                std::cin >> nombreCompeticion;
                gestor.agregarCompeticion(nombreCompeticion);
                break;
            case 4:
                std::cout << "Ingrese el nombre de la competición: ";
                std::cin >> nombreCompeticion;
                gestor.eliminarCompeticion(nombreCompeticion);
                break;
            case 5:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 5);

    return 0;
}