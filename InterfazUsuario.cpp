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
Nota: la muestra de estos resultados se harán cuando el usuario los solicite a través del men.
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
#include <iomanip>

// Implementar el constructor
InterfazUsuario::InterfazUsuario(GestorConsultas& g, BaseDeDatos& bd) 
    : gestor(g), baseDatos(bd) {}

void InterfazUsuario::iniciar() {
    int opcion;
    do {
        mostrarMenuPrincipal();
        std::cin >> opcion;
        std::cin.ignore();
        
        switch (opcion) {
            case 1:
                procesarMenuProcesamientoDatos();  // Ya existe
                break;
            case 2:
                procesarMenuConsultasDinamicas();  // Nueva implementación
                break;
            case 3:
                procesarMenuModificacionDatos();   // Nueva implementación
                break;
            case 0:
                std::cout << "¡Hasta luego!\n";
                break;
            default:
                std::cout << "Opción no válida\n";
        }
    } while (opcion != 0);
}

void InterfazUsuario::mostrarMenuPrincipal() const {
    std::cout << "\n=== Sistema de Gestión de Partidos ===\n";
    std::cout << "1. Procesamiento de datos\n";
    std::cout << "2. Consultas dinámicas\n";
    std::cout << "3. Modificación de datos\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opción: ";
}

void InterfazUsuario::procesarMenuProcesamientoDatos() {
    int opcion;
    do {
        mostrarMenuRegistroDatos();  // Usamos el menú nuevo
        std::cin >> opcion;
        std::cin.ignore();
        
        switch(opcion) {
            case 1: {
                std::string competicion = solicitarCompeticion();
                mostrarTop5PorCompeticion(competicion);
                break;
            }
            case 2: {
                std::string equipo = solicitarEquipo();
                mostrarGolesTotalesPorEquipo(equipo);
                break;
            }
            case 3: {
                std::string equipo = solicitarEquipo();
                mostrarPromedioGolesPorEquipo(equipo);
                break;
            }
            case 4: {
                std::string equipo = solicitarEquipo();
                mostrarDerrotasYTriunfosPorEquipo(equipo);
                break;
            }
            case 5: {
                std::string equipo = solicitarEquipo();
                mostrarFechasExtremasPorEquipo(equipo);
                break;
            }
            case 6:
                mostrarCompeticionMasGoles();
                break;
            case 7:
                mostrarEquiposExtremosGeneralYPorCompeticion();
                break;
            case 0:
                break;
            default:
                std::cout << "Opción no válida\n";
        }
    } while (opcion != 0);
}

void InterfazUsuario::procesarMenuConsultasDinamicas() {
    int opcion;
    do {
        mostrarMenuConsultasDinamicas();
        std::cin >> opcion;
        std::cin.ignore();
        
        std::string equipo1, equipo2, competicion;
        
        switch(opcion) {
            case 1: {
                equipo1 = solicitarEquipo();
                competicion = solicitarCompeticion();
                mostrarResultadosEquipoCompeticion(equipo1, competicion);
                break;
            }
            case 2: {
                equipo1 = solicitarEquipo();
                auto fechas = solicitarFechas();
                mostrarPartidos(gestor.consultarPartidosEntreFechas(equipo1, fechas.first, fechas.second));
                break;
            }
            case 3: {
                std::cout << "Primer equipo:\n";
                equipo1 = solicitarEquipo();
                std::cout << "Segundo equipo:\n";
                equipo2 = solicitarEquipo();
                mostrarComparacionRendimientoGeneral(equipo1, equipo2);
                break;
            }
            case 4: {
                std::cout << "Primer equipo:\n";
                equipo1 = solicitarEquipo();
                std::cout << "Segundo equipo:\n";
                equipo2 = solicitarEquipo();
                mostrarComparacionRendimientoParticular(equipo1, equipo2);
                break;
            }
            case 5:
                mostrarEquiposPorUmbralGoles();
                break;
            case 0:
                break;
            default:
                std::cout << "Opción no válida\n";
        }
    } while (opcion != 0);
}

void InterfazUsuario::procesarMenuModificacionDatos() {
    int opcion;
    do {
        mostrarMenuModificacionDatos();
        std::cin >> opcion;
        std::cin.ignore();
        
        switch(opcion) {
            case 1:
                agregarPartido();
                break;
            case 2:
                modificarPartido();
                break;
            case 3:
                eliminarPartido();
                break;
            case 0:
                break;
            default:
                std::cout << "Opción no válida\n";
        }
    } while (opcion != 0);
}

void InterfazUsuario::agregarPartido() {
    std::cout << "\n=== Agregar Nuevo Partido ===\n";
    
    std::string fecha, equipoLocal, equipoVisitante, competicion;
    int golesLocal, golesVisitante;
    
    std::cout << "Ingrese la fecha (DD/MM/YYYY): ";
    std::getline(std::cin, fecha);
    
    equipoLocal = solicitarEquipo();
    equipoVisitante = solicitarEquipo();
    
    std::cout << "Ingrese goles del equipo local: ";
    std::cin >> golesLocal;
    
    std::cout << "Ingrese goles del equipo visitante: ";
    std::cin >> golesVisitante;
    std::cin.ignore();
    
    competicion = solicitarCompeticion();
    
    if (gestor.agregarPartido(fecha, equipoLocal, golesLocal, golesVisitante, 
                             equipoVisitante, competicion)) {
        std::cout << "Partido agregado exitosamente.\n";
    } else {
        std::cout << "Error al agregar el partido.\n";
    }
}

void InterfazUsuario::modificarPartido() {
    std::cout << "\n=== Modificar Partido Existente ===\n";
    
    std::string fecha = solicitarFecha();
    std::string equipoLocal = solicitarEquipo();
    std::string equipoVisitante = solicitarEquipo();
    
    std::cout << "Ingrese nuevos goles del equipo local: ";
    int nuevosGolesLocal;
    std::cin >> nuevosGolesLocal;
    
    std::cout << "Ingrese nuevos goles del equipo visitante: ";
    int nuevosGolesVisitante;
    std::cin >> nuevosGolesVisitante;
    
    if (gestor.modificarPartido(fecha, equipoLocal, equipoVisitante, 
                               nuevosGolesLocal, nuevosGolesVisitante)) {
        std::cout << "Partido modificado exitosamente.\n";
    } else {
        std::cout << "Error al modificar el partido. Verifique los datos ingresados.\n";
    }
}

void InterfazUsuario::eliminarPartido() {
    std::cout << "\n=== Eliminar Partido ===\n";
    
    std::string fecha = solicitarFecha();
    std::string equipoLocal = solicitarEquipo();
    std::string equipoVisitante = solicitarEquipo();
    
    if (gestor.eliminarPartido(fecha, equipoLocal, equipoVisitante)) {
        std::cout << "Partido eliminado exitosamente.\n";
    } else {
        std::cout << "Error al eliminar el partido. Verifique los datos ingresados.\n";
    }
}

// Método auxiliar adicional
std::string InterfazUsuario::solicitarFecha() const {
    std::string fecha;
    std::cout << "Ingrese la fecha (DD/MM/YYYY): ";
    std::getline(std::cin, fecha);
    return fecha;
}

void InterfazUsuario::mostrarPartidos(const ListaDoble<Partido>& partidos) const {
    for (int i = 0; i < partidos.getTamanio(); i++) {
        Partido p = partidos.getDato(i);
        std::cout << p.getFecha() << " - " 
                  << p.getEquipoLocal() << " " << p.getGolesLocal() 
                  << " vs " << p.getGolesVisitante() << " " 
                  << p.getEquipoVisitante() << "\n";
    }
}

// ... implementación de los demás métodos ...

void InterfazUsuario::mostrarEstadisticasEquipo(const std::string& equipo) const {
    auto [golesFavor, golesContra] = gestor.consultarGolesTotalesPorEquipo(equipo);
    auto [promedioFavor, promedioContra] = gestor.consultarPromedioGolesPorEquipo(equipo);
    
    std::cout << "\nEstadísticas de " << equipo << ":\n";
    std::cout << "Goles a favor: " << golesFavor << "\n";
    std::cout << "Goles en contra: " << golesContra << "\n";
    std::cout << "Promedio goles a favor: " << std::fixed << std::setprecision(2) << promedioFavor << "\n";
    std::cout << "Promedio goles en contra: " << promedioContra << "\n";
}

std::string InterfazUsuario::solicitarEquipo() const {
    // Usamos nuestra Lista personalizada
    Lista<std::string> equipos = gestor.obtenerListaEquipos();
    
    // Mostrar tabla de equipos
    std::cout << "\n+------------------------+\n";
    std::cout << "| Equipos disponibles    |\n";
    std::cout << "+------------------------+\n";
    
    for(int i = 0; i < equipos.getTamanio(); i++) {
        const std::string& equipo = equipos.getDato(i);
        std::cout << "| " << std::setw(2) << i + 1 << ". " 
                  << std::left << std::setw(18) << equipo 
                  << "|\n";
    }
    std::cout << "+------------------------+\n";

    std::string equipoSeleccionado;
    bool equipoValido = false;
    
    while (!equipoValido) {
        std::cout << "\nIngrese el nombre del equipo o su número: ";
        std::getline(std::cin >> std::ws, equipoSeleccionado);
        
        // Si ingresó un número
        bool esNumero = true;
        for(char c : equipoSeleccionado) {
            if(!isdigit(c)) {
                esNumero = false;
                break;
            }
        }
        
        if (esNumero) {
            int opcion = std::stoi(equipoSeleccionado);
            if (opcion >= 1 && opcion <= equipos.getTamanio()) {
                return equipos.getDato(opcion - 1);
            }
        } else {
            // Convertir a minúsculas para comparar
            std::string equipoBuscado = equipoSeleccionado;
            for(char& c : equipoBuscado) {
                c = tolower(c);
            }
            
            // Buscar en nuestra Lista
            for(int i = 0; i < equipos.getTamanio(); i++) {
                std::string equipoActual = equipos.getDato(i);
                for(char& c : equipoActual) {
                    c = tolower(c);
                }
                
                if(equipoActual == equipoBuscado) {
                    return equipos.getDato(i);  // Retorna el nombre original
                }
            }
        }
        
        std::cout << "Equipo no encontrado. Por favor, intente nuevamente.\n";
    }
    
    return "";
}

std::string InterfazUsuario::solicitarCompeticion() const {
    Lista<std::string> competiciones = gestor.obtenerListaCompeticiones();
    std::cout << "\nCompeticiones disponibles:\n";
    
    for(int i = 0; i < competiciones.getTamanio(); i++) {
        std::cout << i + 1 << ". " << competiciones.getDato(i) << "\n";
    }
    
    int opcion;
    do {
        std::cout << "Seleccione una competición (1-" << competiciones.getTamanio() << "): ";
        std::cin >> opcion;
    } while(opcion < 1 || opcion > competiciones.getTamanio());
    
    return competiciones.getDato(opcion - 1);
}

std::pair<std::string, std::string> InterfazUsuario::solicitarFechas() const {
    std::string fechaInicio, fechaFin;
    std::cout << "Ingrese fecha inicial (DD-MM-YYYY): ";
    std::getline(std::cin, fechaInicio);
    std::cout << "Ingrese fecha final (DD-MM-YYYY): ";
    std::getline(std::cin, fechaFin);
    return {fechaInicio, fechaFin};
}

void InterfazUsuario::procesarMenuRegistroDatos() {
    int opcion;
    do {
        mostrarMenuRegistroDatos();
        std::cin >> opcion;
        std::cin.ignore();
        
        switch(opcion) {
            case 1: {
                std::string competicion = solicitarCompeticion();
                mostrarTop5PorCompeticion(competicion);
                break;
            }
            case 2: {
                std::string equipo = solicitarEquipo();
                mostrarGolesTotalesPorEquipo(equipo);
                break;
            }
            case 3: {
                std::string equipo = solicitarEquipo();
                mostrarPromedioGolesPorEquipo(equipo);
                break;
            }
            case 4: {
                std::string equipo = solicitarEquipo();
                mostrarDerrotasYTriunfosPorEquipo(equipo);
                break;
            }
            case 5: {
                std::string equipo = solicitarEquipo();
                mostrarFechasExtremasPorEquipo(equipo);
                break;
            }
            case 6:
                mostrarCompeticionMasGoles();
                break;
            case 7:
                mostrarEquiposExtremosGeneralYPorCompeticion();
                break;
            case 0:
                break;
            default:
                std::cout << "Opción no válida\n";
        }
    } while (opcion != 0);
}

void InterfazUsuario::mostrarTop5PorCompeticion(const std::string& competicion) const {
    std::cout << "\n=== Top 5 Partidos con Más Goles en " << competicion << " ===\n";
    std::cout << "----------------------------------------\n";
    
    ListaDoble<Partido> top5 = gestor.obtenerTop5PartidosPorGoles(competicion);
    if(top5.esVacia()) {
        std::cout << "No hay partidos registrados en esta competición.\n";
        return;
    }
    
    for(int j = 0; j < top5.getTamanio(); j++) {
        const Partido& partido = top5.getDato(j);
        std::cout << j + 1 << ". " << partido.getFecha() << ": "
                 << partido.getEquipoLocal() << " " << partido.getGolesLocal()
                 << " - " << partido.getGolesVisitante() << " " 
                 << partido.getEquipoVisitante()
                 << " (Total: " << partido.getTotalGoles() << " goles)\n";
    }
}

void InterfazUsuario::mostrarGolesTotalesPorEquipo(const std::string& equipo) const {
    std::cout << "\n=== Goles Totales de " << equipo << " por Competición ===\n";
    
    Lista<std::string> competiciones = gestor.obtenerListaCompeticiones();
    bool encontrado = false;
    
    for(int i = 0; i < competiciones.getTamanio(); i++) {
        const std::string& competicion = competiciones.getDato(i);
        auto [golesFavor, golesContra] = gestor.consultarGolesTotalesPorEquipo(equipo, competicion);
        
        if(golesFavor > 0 || golesContra > 0) {
            encontrado = true;
            std::cout << "\nCompetición: " << competicion << "\n";
            std::cout << "----------------------------------------\n";
            std::cout << "Goles a favor: " << golesFavor << "\n";
            std::cout << "Goles en contra: " << golesContra << "\n";
            std::cout << "Diferencia de goles: " << golesFavor - golesContra << "\n";
        }
    }
    
    if(!encontrado) {
        std::cout << "El equipo no ha participado en ninguna competición registrada.\n";
    }
}

void InterfazUsuario::mostrarPromedioGolesPorEquipo(const std::string& equipo) const {
    std::cout << "\n=== Promedio de Goles de " << equipo << " por Competición ===\n";
    
    Lista<std::string> competiciones = gestor.obtenerListaCompeticiones();
    bool encontrado = false;
    
    for(int i = 0; i < competiciones.getTamanio(); i++) {
        const std::string& competicion = competiciones.getDato(i);
        auto [promedioFavor, promedioContra] = gestor.consultarPromedioGolesPorEquipo(equipo, competicion);
        
        if(promedioFavor > 0 || promedioContra > 0) {
            encontrado = true;
            std::cout << "\nCompetición: " << competicion << "\n";
            std::cout << "----------------------------------------\n";
            std::cout << "Promedio goles a favor: " << std::fixed << std::setprecision(2) << promedioFavor << "\n";
            std::cout << "Promedio goles en contra: " << promedioContra << "\n";
        }
    }
    
    if(!encontrado) {
        std::cout << "El equipo no ha participado en ninguna competición registrada.\n";
    }
}

void InterfazUsuario::mostrarDerrotasYTriunfosPorEquipo(const std::string& equipo) const {
    std::cout << "\n=== Derrotas y Triunfos de " << equipo << " por Competición ===\n";
    
    Lista<std::string> competiciones = gestor.obtenerListaCompeticiones();
    bool encontrado = false;
    
    for(int i = 0; i < competiciones.getTamanio(); i++) {
        const std::string& competicion = competiciones.getDato(i);
        auto [victorias, derrotas] = gestor.obtenerDerrotasYTriunfosPorEquipo(equipo, competicion);
        
        if(victorias > 0 || derrotas > 0) {
            encontrado = true;
            std::cout << "\nCompetición: " << competicion << "\n";
            std::cout << "----------------------------------------\n";
            std::cout << "Victorias: " << victorias << "\n";
            std::cout << "Derrotas: " << derrotas << "\n";
        }
    }
    
    if(!encontrado) {
        std::cout << "El equipo no ha participado en ninguna competición registrada.\n";
    }
}

void InterfazUsuario::mostrarFechasExtremasPorEquipo(const std::string& equipo) const {
    std::cout << "\n=== Fechas con Más y Menos Goles de " << equipo << " por Competición ===\n";
    
    Lista<std::string> competiciones = gestor.obtenerListaCompeticiones();
    bool encontrado = false;
    
    for(int i = 0; i < competiciones.getTamanio(); i++) {
        const std::string& competicion = competiciones.getDato(i);
        auto [fechaMasGoles, fechaMenosGoles] = 
            gestor.obtenerFechasConMasYMenosGoles(equipo, competicion);
        
        if(!fechaMasGoles.empty() && !fechaMenosGoles.empty()) {
            encontrado = true;
            std::cout << "\nCompetición: " << competicion << "\n";
            std::cout << "----------------------------------------\n";
            std::cout << "Fecha con más goles: " << fechaMasGoles << "\n";
            std::cout << "Fecha con menos goles: " << fechaMenosGoles << "\n";
        }
    }
    
    if(!encontrado) {
        std::cout << "El equipo no ha participado en ninguna competición registrada.\n";
    }
}

void InterfazUsuario::mostrarCompeticionMasGoles() const {
    std::string competicion = gestor.consultarCompeticionMasGoles();
    std::cout << "\nCompetición con más goles:\n";
    std::cout << "----------------------------------------\n";
    std::cout << competicion << "\n";
}

void InterfazUsuario::mostrarEquiposExtremosGeneralYPorCompeticion() const {
    // Primero mostrar estadísticas generales
    auto [equipoMaxGeneral, equipoMinGeneral] = gestor.consultarEquiposMaxMinGoles();
    std::cout << "\nEstadísticas generales (todas las competiciones):\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Equipo con más goles: " << equipoMaxGeneral << "\n";
    std::cout << "Equipo con menos goles: " << equipoMinGeneral << "\n\n";

    // Luego mostrar por cada competición
    std::cout << "Estadísticas por competición:\n";
    std::cout << "----------------------------------------\n";
    auto competiciones = gestor.obtenerListaCompeticiones();
    for(int i = 0; i < competiciones.getTamanio(); i++) {
        const std::string& comp = competiciones.getDato(i);
        auto [equipoMax, equipoMin] = gestor.consultarEquiposMaxMinGolesPorCompeticion(comp);
        std::cout << "\nCompetición: " << comp << "\n";
        std::cout << "  Equipo con más goles: " << equipoMax << "\n";
        std::cout << "  Equipo con menos goles: " << equipoMin << "\n";
    }
}

void InterfazUsuario::mostrarMenuRegistroDatos() const {
    std::cout << "\nMenú de Registro de Datos:\n";
    std::cout << "1. Top 5 partidos con más goles por cada competición\n";
    std::cout << "2. Goles totales a favor y en contra por equipo (discriminado por competición)\n";
    std::cout << "3. Promedio de goles a favor y en contra por equipo (discriminado por competición)\n";
    std::cout << "4. Total de derrotas y triunfos por equipo (discriminado por competición)\n";
    std::cout << "5. Fechas con más/menos goles por equipo (discriminado por competición)\n";
    std::cout << "6. Competición con más goles convertidos\n";
    std::cout << "7. Equipos con más/menos goles (general y por competición)\n";
    std::cout << "0. Volver al menú principal\n";
    std::cout << "Ingrese su opción: ";
}

void InterfazUsuario::mostrarMenuConsultasDinamicas() const {
    std::cout << "\n=== Consultas Dinámicas ===\n";
    std::cout << "1. Ver resultados de un equipo en una competición\n";
    std::cout << "2. Ver resultados de un equipo entre fechas\n";
    std::cout << "3. Comparar rendimiento general entre equipos\n";
    std::cout << "4. Comparar rendimiento particular entre equipos\n";
    std::cout << "5. Filtrar equipos por umbral de goles\n";
    std::cout << "0. Volver al menú principal\n";
    std::cout << "Ingrese su opción: ";
}

void InterfazUsuario::mostrarResultadosEquipoCompeticion(const std::string& equipo, const std::string& competicion) const {
    std::cout << "\nResultados de " << equipo << " en " << competicion << ":\n";
    std::cout << "----------------------------------------\n";
    
    ListaDoble<Partido> partidos = baseDatos.obtenerPartidosPorCompeticion(competicion);
    for(int i = 0; i < partidos.getTamanio(); i++) {
        const Partido& partido = partidos.getDato(i);
        if(partido.getEquipoLocal() == equipo || partido.getEquipoVisitante() == equipo) {
            std::cout << partido.getFecha() << " - ";
            if(partido.getEquipoLocal() == equipo) {
                std::cout << partido.getGolesLocal() << " - " << partido.getGolesVisitante() 
                         << " vs " << partido.getEquipoVisitante();
            } else {
                std::cout << partido.getGolesVisitante() << " - " << partido.getGolesLocal() 
                         << " vs " << partido.getEquipoLocal();
            }
            std::cout << "\n";
        }
    }
}

void InterfazUsuario::mostrarComparacionRendimientoGeneral(const std::string& equipo1, const std::string& equipo2) const {
    std::cout << "\nComparación de rendimiento general entre " << equipo1 << " y " << equipo2 << ":\n";
    std::cout << "----------------------------------------\n";
    
    auto [golesFavor1, golesContra1] = gestor.consultarGolesTotalesPorEquipo(equipo1);
    auto [golesFavor2, golesContra2] = gestor.consultarGolesTotalesPorEquipo(equipo2);
    
    std::cout << equipo1 << ":\n";
    std::cout << "  Goles a favor: " << golesFavor1 << "\n";
    std::cout << "  Goles en contra: " << golesContra1 << "\n\n";
    
    std::cout << equipo2 << ":\n";
    std::cout << "  Goles a favor: " << golesFavor2 << "\n";
    std::cout << "  Goles en contra: " << golesContra2 << "\n";
}

void InterfazUsuario::mostrarComparacionRendimientoParticular(const std::string& equipo1, const std::string& equipo2) const {
    std::cout << "\nEnfrentamientos directos entre " << equipo1 << " y " << equipo2 << ":\n";
    std::cout << "----------------------------------------\n";
    
    ListaDoble<Partido> todosPartidos = baseDatos.obtenerPartidosPorEquipo(equipo1);
    int victorias1 = 0, victorias2 = 0, empates = 0;
    
    for(int i = 0; i < todosPartidos.getTamanio(); i++) {
        const Partido& partido = todosPartidos.getDato(i);
        if((partido.getEquipoLocal() == equipo1 && partido.getEquipoVisitante() == equipo2) ||
           (partido.getEquipoLocal() == equipo2 && partido.getEquipoVisitante() == equipo1)) {
            
            std::cout << partido.getFecha() << ": " 
                      << partido.getEquipoLocal() << " " << partido.getGolesLocal() 
                      << " - " << partido.getGolesVisitante() << " " 
                      << partido.getEquipoVisitante() << "\n";
            
            if(partido.getGolesLocal() > partido.getGolesVisitante()) {
                if(partido.getEquipoLocal() == equipo1) victorias1++;
                else victorias2++;
            } else if(partido.getGolesLocal() < partido.getGolesVisitante()) {
                if(partido.getEquipoVisitante() == equipo1) victorias1++;
                else victorias2++;
            } else {
                empates++;
            }
        }
    }
    
    std::cout << "\nResumen:\n";
    std::cout << equipo1 << " victorias: " << victorias1 << "\n";
    std::cout << equipo2 << " victorias: " << victorias2 << "\n";
    std::cout << "Empates: " << empates << "\n";
}

void InterfazUsuario::mostrarEquiposPorUmbralGoles() const {
    int umbral;
    std::cout << "Ingrese el umbral de goles: ";
    std::cin >> umbral;
    std::cin.ignore();
    
    std::cout << "\nEquipos que han marcado más de " << umbral << " goles:\n";
    std::cout << "----------------------------------------\n";
    
    Lista<std::string> equipos = gestor.obtenerListaEquipos();
    for(int i = 0; i < equipos.getTamanio(); i++) {
        const std::string& equipo = equipos.getDato(i);
        auto [golesFavor, _] = gestor.consultarGolesTotalesPorEquipo(equipo);
        if(golesFavor > umbral) {
            std::cout << equipo << ": " << golesFavor << " goles\n";
        }
    }
}

void InterfazUsuario::mostrarMenuModificacionDatos() const {
    std::cout << "\n=== Modificación de Datos ===\n";
    std::cout << "1. Agregar nuevo partido\n";
    std::cout << "2. Modificar partido existente\n";
    std::cout << "3. Eliminar partido\n";
    std::cout << "0. Volver al menú principal\n";
    std::cout << "Ingrese su opción: ";
}