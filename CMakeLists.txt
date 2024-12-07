cmake_minimum_required(VERSION 3.30)
project(Proyecto_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(Proyecto_1 main.cpp
        includes/Usuario.h
        includes/Activo.h
        includes/ListaUsuario.h
        includes/Matriz.h
        includes/AVL.h
        src/Activo.cpp
        src/AVL.cpp
        src/ListaUsuario.cpp
        src/Matriz.cpp
        src/Usuario.cpp
        includes/HistorialRenta.h
        includes/GestorDatos.h
        src/GestorDatos.cpp
        src/NodoMatriz.cpp
        includes/NodoMatriz.h
        src/HistorialRenta.cpp)
