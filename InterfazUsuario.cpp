/*
Menu de busqueda sobre base de datos:
    1. Procesamiento de datos durante lectura archivo CSV:
Durante la lectura3 del archivo CSV el cliente necesita que se preparen los siguientes resultados principales:
i. Los primeros 5 partidos con mayor cantidad de goles (sumar goles de ambos equipos) y de cada competición que haya en la base de datos. De haber más de 5 por igualdad en cantidad de goles, filtrar por fecha, dejando los más recientes. De haber similitud de fechas, filtrar por criterio programador.
ii. Los goles totales a favor y en contra de cada equipo por competición. El usuario pedirá que se muestren por pantalla, de un equipo por vez y deberá mostrar discriminando por competición.
iii. Promedio de goles a favor y en contra de cada equipo por competición. El usuario pedirá que se muestren por pantalla, de un equipo por vez y deberá mostrar discriminando por competición.
iv. La cantidad total de derrotas y de triunfos de cada equipo por competición. El usuario pedirá que se muestren por pantalla, de un equipo por vez y deberá mostrar discriminando por competición.
v. La fecha con más goles y la fecha con menos goles de cada equipo por competición. El usuario pedirá que se muestren por pantalla, de un equipo por vez y deberá mostrar discriminando por competición.
vi. La competición con más goles convertidos.
vii. El equipo con más goles convertidos y el equipo con menos goles convertidos de
todas las competiciones y por competición.
Nota: la muestra de estos resultados se harán cuando el usuario los solicite a través del menú.
3 Este procesamiento inicial deberá anunciarse por pantalla como lo indica el punto 1: cantidad de condicionales, tiempo de ejecución y estructura/s y/o algoritmo/s utilizados.

2. Consultas dinámicas:
 7. Consultas dinámicas:
a. Todos los Resultados de un equipo y en una competición específica ingresado por el usuario.
Ejemplo:
Usuario ingresa: Milán y Champions League
Por pantalla: se listan todos los resultados de ese equipo En la Champions League:
● Milán 01-01-2023 0 a 1 perdió con Arsenal.
● Milán 02-01-2023 1 a 0 ganó a Austria Wein
● Milán 03-01-2023 3 a 2 ganó a Porto
● .........
● .........
b. Resultados de un equipo entre dos fechas ingresadas por el usuario.
Ejemplo:
Usuario ingresa: 01-01-2023 al 01-03-2023 Equipo: Real Madrid.
Por pantalla: se listan todos los resultados de ese equipo durante esas fechas (incluidas)
● Real Madrid 01-01-2023 2 a 0 ganó a Roma en Champions League
● Real Madrid 05-01-2023 0 a 0 empató con PSG en Champions League
● Real Madrid 01-03-2023 3 a 0 ganó a Granada CF en LALIGA
 4 Aplica lo mismo que la nota al pie N° 3.
6

 ● .....
c. Comparación de rendimiento general (cantidad de goles a favor y en contra) entre dos equipos ingresados por el usuario. Ambos equipos no necesariamente se han enfrentado entre ellos y pueden estar en diferentes competiciones. Discriminar por competición.
Ejemplo: Usuario ingresa: Real Madrid y Milán Por pantalla:
● Real Madrid Goles a favor: 42 Goles en contra: 35 en Champions League
● Milán Goles a favor: 37 Goles en contra 47 en Champions League
● Real Madrid Goles a favor: 25 Goles en contra: 5 en LALIGA.
d. Comparación de rendimiento particular de dos equipos. Analizando sólo los partidos en los que se han enfrentado esos dos equipos indicar cantidad de partidos que han jugado en contra, la cantidad de empates y cuál de los dos ha ganado más partidos.
e. Umbral: el usuario podrá ingresar un umbral de cantidad de goles convertidos por partido en promedio, especificar si quiere por arriba o por debajo de ese umbral y el programa deberá filtrar a todos los equipos de todas las competiciones que hayan convertido dentro de ese umbral, incluyéndose. Discriminar por competición
Ejemplo:
Usuario ingresa umbral de 3 como máximo.
Por pantalla: se listan todos los equipos que hayan convertido de 0 a 3 goles en promedio por partido:
● Porto 3 goles promedio por partido en Champions League
● Milán 1 gol promedio por partido en Champions League
● Real Madrid 2 goles promedio por partido en Champions League
● Real Madrid 1 gol promedio por partido en LALIGA
● .......
● .......

 Menu sobre modificacion de datos de la base:
1. Modificación de datos y reprocesamiento:
El cliente solicita que el usuario podrá agregar, eliminar y modificar los datos. Por ello, el punto 5 deberá ejecutarse automáticamente cada vez que se haga una modificación4.
a. Agregar un partido, con fecha, equipo local, goles local, goles visitante, equipo visitante, competición. Guiar al usuario para que no se olvide ningún dato y también bloqueando que introduzca errores a la base de datos.
b. Eliminar un partido completo. Guiar al usuario en la selección del partido a eliminar facilitando con opciones el alcanzar la eliminación.
c. Modificar un partido. Guiar al usuario en la selección del partido a modificar facilitando opciones para alcanzar la modificación. Podrá modificar cualquier campo.

 */

#include "InterfazUsuario.h"
#include "GestorConsultas.h"
#include "BaseDeDatos.h"
#include <iostream>

InterfazUsuario::InterfazUsuario(GestorConsultas* gestorConsultas, BaseDeDatos* baseDeDatos)
    : gestorConsultas(gestorConsultas), baseDeDatos(baseDeDatos) {}

    //Implementar manejo de exepciones con try and catch

void InterfazUsuario::mostrarMenuInicial() {
    std::cout << "\n===== Menu Inicial =====\n";
    std::cout << "1. Busqueda y consulta sobre base de datos " << std::endl;
    std::cout << "2. Modificacion de datos de la base " << std::endl;
    std::cout << "3. Salir " << std::endl;

    int opcion;

    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;
    switch (opcion) {
        case 1:
            mostrarMenuBusqueda();
            break;
        case 2:
            //();
            break;
        case 3:
            std::cout << "Saliendo..." << std::endl;
            break;
        default:
            std::cout << "Opcion invalida" << std::endl;
            break;
    }
}

void InterfazUsuario::mostrarMenuBusqueda() {
    while (true){
        std::cout << "\n===== Menu de busqueda =====\n";
        std::cout << "1. Procesamiento de datos y estadisticas generales " << std::endl;
        std::cout << "2. Consultas dinamicas " << std::endl;
        std::cout << "3. Salir " << std::endl;

        int opcion;

        std::cout << "Seleccione una opcion: " << std::endl;

        std::cin >> opcion;

        try {
            switch (opcion) {
                case 1:
                    mostrarMenuResultadosPrincipales();
                    break;
                case 2:
                    mostrarMenuConsultasDinamicas();
                    break;
                case 3:
                    std::cout << "Saliendo..." << std::endl;
                    break;
                default:
                    std::cout << "Opcion invalida" << std::endl;
                    break;
            }
        } catch (const std::exception& e) {
            std::cerr << "Excepción capturada: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Excepción desconocida capturada." << std::endl;
        }
        }
}

void InterfazUsuario::mostrarMenuResultadosPrincipales() {
    while (true) {
        std::cout << "\n===== Resultados Principales =====\n";
        std::cout << "1. Primeros 5 partidos con mayor cantidad de goles\n";
        std::cout << "2. Goles totales a favor y en contra de cada equipo\n";
        std::cout << "3. Promedio de goles a favor y en contra de cada equipo\n";
        std::cout << "4. Total de derrotas y triunfos de cada equipo\n";
        std::cout << "5. Fecha con más y menos goles de cada equipo\n";
        std::cout << "6. Competición con más goles convertidos\n";
        std::cout << "7. Equipo con más y menos goles convertidos\n";
        std::cout << "8. Volver al menú de búsqueda\n";
        std::cout << "Seleccione una opción: ";

        int opcion;
        std::cin >> opcion;

        try {
            switch (opcion) {
                case 1:
                    mostrarPartidosConMasGoles();
                    break;
                case 2:
                    mostrarGolesTotalesPorEquipo();
                    break;
                case 3:
                    mostrarPromedioGolesPorEquipo();
                    break;
                case 4:
                    mostrarDerrotasYTriunfosPorEquipo();
                    break;
                case 5:
                    mostrarFechasConMasYMenosGoles();
                    break;
                case 6:
                    mostrarCompeticionConMasGoles();
                    break;
                case 7:
                    mostrarEquipoConMasYMenosGoles();
                    break;
                case 8:
                    return;
                default:
                    std::cerr << "Opción no válida. Intente de nuevo.\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "Excepción capturada: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Excepción desconocida capturada." << std::endl;
        }
    }
}

void InterfazUsuario::mostrarPartidosConMasGoles() {
    // Implementar logica para mostrar partidos con mas goles
    gestorConsultas->mostrarPartidosConMasGoles();
}

void InterfazUsuario::mostrarGolesTotalesPorEquipo() {
    std::string nombreEquipo;
    std::cout << "Ingrese el nombre del equipo: ";
    std::cin >> nombreEquipo;
    gestorConsultas->mostrarGolesTotalesPorEquipo(nombreEquipo);
}

void InterfazUsuario::mostrarPromedioGolesPorEquipo() {
    std::string nombreEquipo;
    std::cout << "Ingrese el nombre del equipo: ";
    std::cin >> nombreEquipo;
    gestorConsultas->mostrarPromedioGolesPorEquipo(nombreEquipo);
}

void InterfazUsuario::mostrarDerrotasYTriunfosPorEquipo() {
    std::string nombreEquipo;
    std::cout << "Ingrese el nombre del equipo: ";
    std::cin >> nombreEquipo;
    gestorConsultas->mostrarDerrotasYTriunfosPorEquipo(nombreEquipo);
}

void InterfazUsuario::mostrarFechasConMasYMenosGoles() {
    std::string nombreEquipo;
    std::cout << "Ingrese el nombre del equipo: ";
    std::cin >> nombreEquipo;
    gestorConsultas->mostrarFechasConMasYMenosGoles(nombreEquipo);
}

void InterfazUsuario::mostrarCompeticionConMasGoles() {
    // Implementar logica para mostrar competiciones con mas goles
    gestorConsultas->mostrarCompeticionConMasGoles();
}

void InterfazUsuario::mostrarEquipoConMasYMenosGoles() {
    // Implementar logica para mostrar equipos con mas y menos goles
    gestorConsultas->mostrarEquipoConMasYMenosGoles();
}

void InterfazUsuario::mostrarMenuConsultasDinamicas() {
    while (true) {
        std::cout << "\n===== Consultas Dinámicas =====\n";
        std::cout << "1. Resultados de un equipo en una competición específica\n";
        std::cout << "2. Resultados de un equipo entre dos fechas\n";
        std::cout << "3. Comparación de rendimiento general entre dos equipos\n";
        std::cout << "4. Comparación de rendimiento particular entre dos equipos\n";
        std::cout << "5. Filtrar equipos por umbral de goles\n";
        std::cout << "6. Volver al menú de búsqueda\n";
        std::cout << "Seleccione una opción: ";

        int opcion;
        std::cin >> opcion;

        try {
            switch (opcion) {
                case 1:
                    consultarResultadosEquipoCompeticion();
                    break;
                case 2:
                    consultarResultadosEquipoFechas();
                    break;
                case 3:
                    compararRendimientoGeneral();
                    break;
                case 4:
                    compararRendimientoParticular();
                    break;
                case 5:
                    filtrarEquiposPorUmbral();
                    break;
                case 6:
                    return;
                default:
                    std::cerr << "Opción no válida. Intente de nuevo.\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "Excepción capturada: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Excepción desconocida capturada." << std::endl;
        }
    }
}

void InterfazUsuario::mostrarMenuModificacion() {
    // Implement the logic
}



void InterfazUsuario::consultarResultadosEquipoCompeticion() {
    // Implement the logic
}

void InterfazUsuario::consultarResultadosEquipoFechas() {
    // Implement the logic
}

void InterfazUsuario::compararRendimientoGeneral() {
    // Implement the logic
}

void InterfazUsuario::compararRendimientoParticular() {
    // Implement the logic
}

void InterfazUsuario::filtrarEquiposPorUmbral() {
    // Implement the logic
}

void InterfazUsuario::buscarPorCompeticion() {
    // Implement the logic
}

void InterfazUsuario::buscarPorEquipo() {
    // Implement the logic
}

void InterfazUsuario::buscarPorTemporada() {
    // Implement the logic
}

void InterfazUsuario::buscarPorFecha() {
    // Implement the logic
}

void InterfazUsuario::mostrarEstadisticasGenerales() {
    // Implement the logic
}

void InterfazUsuario::mostrarPartidosDestacados() {
    // Implement the logic
}

void InterfazUsuario::mostrarClasificaciones() {
    // Implement the logic
}

void InterfazUsuario::agregarPartido() {
    // Implement the logic
}

void InterfazUsuario::eliminarPartido() {
    // Implement the logic
}

void InterfazUsuario::modificarPartido() {
    // Implement the logic
}

void InterfazUsuario::mostrarCompeticiones() {
    // Implement the logic
}

void InterfazUsuario::mostrarEquipos() {
    // Implement the logic
}

void InterfazUsuario::mostrarTemporadas() {
    // Implement the logic
}

std::string InterfazUsuario::solicitarFecha() {
    // Implement the logic
    return "";
}

std::string InterfazUsuario::obtenerNombreCompeticion(int opcion) {
    // Implement the logic
    return "";
}