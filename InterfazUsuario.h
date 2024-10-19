//
// Created by Octavio Carpineti on 18/10/2024.
//

#ifndef PROYECTO_INTERFAZUSUARIO_H
#define PROYECTO_INTERFAZUSUARIO_H

#include "GestorConsultas.h"

class InterfazUsuario {
private:
    GestorConsultas* gestorConsultas;

public:
    InterfazUsuario(GestorConsultas* gestorConsultas);
    void mostrarMenu();
    void consultarResultadosEquipo();
    // Otros métodos para manejar la interacción con el usuario
};

#endif //PROYECTO_INTERFAZUSUARIO_H