cmake_minimum_required(VERSION 3.28)
project(Proyecto)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto main.cpp
        Listas/CircList.h
        Listas/Nodo.h
        Listas/Lista.h
        Listas/ListaDoble.h
        Arboles/ArbolBinario.h
        Arboles/ArbolBinarioAVL.h
        Arboles/NodoArbol.h
        Arboles/NodoArbolAVL.h
        Partido.cpp
        Partido.h
        Competicion.cpp
        Competicion.h
        Equipo.cpp
        Equipo.h
        GestorConsultas.cpp
        GestorConsultas.h
        InterfazUsuario.cpp
        InterfazUsuario.h
        BaseDeDatos.cpp
        BaseDeDatos.h)
