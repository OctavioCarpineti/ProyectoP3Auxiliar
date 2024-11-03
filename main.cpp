#include <iostream>
#include <chrono>
#include <stdexcept>
#include "GestorConsultas.h"
#include "InterfazUsuario.h"
#include "BaseDeDatos.h"

int main() {
    try {
        std::cout << "Iniciando programa...\n";
        std::cout << "Intentando cargar archivo de datos...\n";
        
        BaseDeDatos baseDeDatos;
        
        // Intentar cargar el archivo
        try {
            if (!baseDeDatos.cargarArchivo("Recursos/Base_Datos_COMA.csv")) {
                std::cerr << "Error: La carga del archivo retornó falso.\n";
                return 1;
            }
        } catch (const std::ios_base::failure& e) {
            std::cerr << "Error de E/S: " << e.what() << "\n";
            return 1;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error de formato: " << e.what() << "\n";
            return 1;
        } catch (const std::exception& e) {
            std::cerr << "Error durante la carga: " << e.what() << "\n";
            return 1;
        }

        // Crear gestor e interfaz
        try {
            GestorConsultas gestor(baseDeDatos);
            InterfazUsuario interfaz(gestor, baseDeDatos);
            std::cout << "Iniciando interfaz de usuario...\n\n";
            interfaz.iniciar();
        } catch (const std::exception& e) {
            std::cerr << "Error al iniciar la interfaz: " << e.what() << "\n";
            return 1;
        }

        return 0;
    } catch (const std::bad_alloc& e) {
        std::cerr << "Error: Sin memoria suficiente - " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error crítico: " << e.what() << "\n";
    } catch (...) {
        std::cerr << "Error desconocido no manejado\n";
    }
    return 1;
}
