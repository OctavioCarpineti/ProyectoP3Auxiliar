//
// Created by Octavio Carpineti on 18/10/2024.
//

#ifndef PROYECTO_BASEDEDATOS_H
#define PROYECTO_BASEDEDATOS_H
#include "Arboles/ArbolBinarioAVL.h"
#include "Competicion.h"

class BaseDeDatos {
private:
    ArbolBinarioAVL<Competicion*> competiciones;

public:
    void cargarDatos(const std::string& nombreArchivo);
    void procesarEstadisticas();
    // Métodos para realizar consultas
};

#endif //PROYECTO_BASEDEDATOS_H
