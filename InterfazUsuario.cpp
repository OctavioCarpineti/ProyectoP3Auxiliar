#include "InterfazUsuario.h"
#include <iostream>
#include "GestorConsultas.h"
#include "BaseDeDatos.h"

// Constructor de la clase InterfazUsuario
InterfazUsuario::InterfazUsuario(GestorConsultas* gestorConsultas, BaseDeDatos* baseDeDatos)
    : gestorConsultas(gestorConsultas), baseDeDatos(baseDeDatos) {}

void InterfazUsuario::mostrarMenuInicial() {
    while (true) {
        std::cout << "\n===== Bienvenido a la Base de Datos de Fútbol =====\n";
        std::cout << "1. Buscar en la base de datos\n";
        std::cout << "2. Modificar la base de datos\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opción: ";

        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1: mostrarMenuPrincipal(); break;
            case 2:
                std::cout << "Funcionalidad de modificación aún no implementada.\n";
                break;
            case 3: std::cout << "Saliendo del programa...\n"; return;
            default: std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    }
}

void InterfazUsuario::consultarResultadosEquipo() {
    std::string nombreEquipo, nombreCompeticion;
    std::cout << "Ingrese el nombre del equipo: ";
    std::cin >> nombreEquipo;
    std::cout << "Ingrese el nombre de la competición: ";
    std::cin >> nombreCompeticion;

    gestorConsultas->consultarResultadosEquipo(nombreEquipo, nombreCompeticion);
}

void InterfazUsuario::mostrarMenuPrincipal() {
    while (true) {
        std::cout << "\n===== Base de Datos de Fútbol =====\n";
        std::cout << "1. Buscar por competición\n";
        std::cout << "2. Buscar por equipo\n";
        std::cout << "3. Buscar por temporada\n";
        std::cout << "4. Buscar por fecha\n";
        std::cout << "5. Mostrar estadísticas generales\n";
        std::cout << "6. Mostrar partidos destacados\n";
        std::cout << "7. Mostrar clasificaciones\n";
        std::cout << "8. Salir\n";
        std::cout << "Seleccione una opción: ";

        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1: buscarPorCompeticion(); break;
            case 2: buscarPorEquipo(); break;
            case 3: buscarPorTemporada(); break;
            case 4: buscarPorFecha(); break;
            case 5: mostrarEstadisticasGenerales(); break;
            case 6: mostrarPartidosDestacados(); break;
            case 7: mostrarClasificaciones(); break;
            case 8: std::cout << "Saliendo del programa...\n"; return;
            default: std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    }
}

void InterfazUsuario::buscarPorCompeticion() {
    std::cout << "\n----- Búsqueda por Competición -----\n";
    mostrarCompeticiones();
    std::cout << "Seleccione una competición: ";
    int opcionCompeticion;
    std::cin >> opcionCompeticion;

    // Llamada al gestor para obtener y mostrar los datos de la competición seleccionada
    std::string nombreCompeticion = obtenerNombreCompeticion(opcionCompeticion);
    if (!nombreCompeticion.empty()) {
        gestorConsultas->obtenerDatosCompeticion(nombreCompeticion);
    } else {
        std::cout << "Opción no válida. Intente de nuevo.\n";
    }
}

void InterfazUsuario::buscarPorEquipo() {
    std::cout << "\n----- Búsqueda por Equipo -----\n";
    mostrarEquipos();
    std::cout << "Seleccione un equipo: ";
    int opcionEquipo;
    std::cin >> opcionEquipo;

    // Llamada al gestor para obtener y mostrar los datos del equipo seleccionado
}

void InterfazUsuario::buscarPorTemporada() {
    std::cout << "\n----- Búsqueda por Temporada -----\n";
    mostrarTemporadas();
    std::cout << "Seleccione una temporada: ";
    int opcionTemporada;
    std::cin >> opcionTemporada;

    // Llamada al gestor para obtener y mostrar los datos de la temporada seleccionada
}

void InterfazUsuario::buscarPorFecha() {
    std::cout << "\n----- Búsqueda por Fecha -----\n";
    std::string fecha = solicitarFecha();

    // Llamada al gestor para obtener y mostrar los partidos en la fecha especificada
}

void InterfazUsuario::mostrarEstadisticasGenerales() {
    std::cout << "\n----- Estadísticas Generales -----\n";
    // Implementar lógica para mostrar estadísticas generales
    // Por ejemplo, total de goles, promedio de goles por partido, etc.
}

void InterfazUsuario::mostrarPartidosDestacados() {
    std::cout << "\n----- Partidos Destacados -----\n";
    // Implementar lógica para mostrar partidos con más goles o resultados sorprendentes
}

void InterfazUsuario::mostrarClasificaciones() {
    std::cout << "\n----- Clasificaciones -----\n";
    // Implementar lógica para mostrar clasificaciones
    // Por ejemplo, tabla de posiciones de equipos en una competición
}

// Implementaciones de las funciones auxiliares
void InterfazUsuario::mostrarCompeticiones() {
    std::cout << "Competiciones disponibles:\n";
    std::cout << "1. Champions League\n2. LALIGA\n3. Premier League\n4. Bundesliga\n";
}

void InterfazUsuario::mostrarEquipos() {
    // Aquí deberías obtener la lista de equipos del gestor o la base de datos
    std::cout << "Lista de equipos:\n";
    // Mostrar la lista de equipos numerada
}

void InterfazUsuario::mostrarTemporadas() {
    std::cout << "Temporadas disponibles:\n";
    // Mostrar las temporadas disponibles (3 para cada competición)
}

std::string InterfazUsuario::solicitarFecha() {
    std::string fecha;
    std::cout << "Ingrese la fecha (formato DD-MM-YYYY): ";
    std::cin >> fecha;
    return fecha;
}

std::string InterfazUsuario::obtenerNombreCompeticion(int opcion) {
    switch (opcion) {
        case 1: return "Champions League";
        case 2: return "LALIGA";
        case 3: return "Premier League";
        case 4: return "Bundesliga";
        default: return "";
    }
}