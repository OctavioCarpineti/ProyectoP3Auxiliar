#include <iostream>
#include "GestorConsultas.h"
#include "InterfazUsuario.h"
#include "BaseDeDatos.h"

int main() {
    try {
        BaseDeDatos baseDeDatos;
        if (!baseDeDatos.cargarArchivo("BaseDeDatosActCOMA.csv")) {
            std::cerr << "No se pudo cargar el archivo CSV." << std::endl;
            return 1;
        }

        GestorConsultas gestor(&baseDeDatos);
        InterfazUsuario interfaz(&gestor, &baseDeDatos);

        interfaz.mostrarMenuInicial();

        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl;
    } catch (int e) {
        std::cerr << "Excepción de tipo int capturada: " << e << std::endl;
    } catch (...) {
        std::cerr << "Excepción desconocida capturada." << std::endl;
    }
    return 1;
}