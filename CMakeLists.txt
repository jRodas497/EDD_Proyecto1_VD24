cmake_minimum_required(VERSION 3.28)
project(EDD)

set(CMAKE_CXX_STANDARD 23)

include_directories(includes)

set(SOURCES
        main.cpp
        src/Usuario.cpp
        src/Matriz.cpp
        src/NodoMatriz.cpp
        src/Activo.cpp
        src/AVL.cpp
)

# Add executable
add_executable(EDD ${SOURCES})