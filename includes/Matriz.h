//
// Created by Usuario on 5/12/2024.
//
#ifndef MATRIZ_H
#define MATRIZ_H

#include "NodoMatriz.h"

class Matriz {
public:
    Matriz();
    // Funciones de inserción de cabeceras
    NodoMatriz* insertarCabHorizontal(const std::string& depto); //
    NodoMatriz* insertarCabVertical(const std::string& company); //

    // Funciones de búsqueda
    NodoMatriz* buscarCabeceraVertical(NodoMatriz* nodoUser);
    NodoMatriz* buscarCabeceraHorizontal(NodoMatriz* nodoUser);
    NodoMatriz* deptoBuscar(const std::string& depto);
    NodoMatriz* companyBuscar(const std::string& company);
    NodoMatriz* existeEn(NodoMatriz* cabezaDepto, const std::string& company);
    bool existeUsuario(NodoMatriz* nodoUser, const std::string& usuario);

    // Funciones de inserción de Usuarios
    void insertarFinal(Usuario* usuario, NodoMatriz* deptoNodo, NodoMatriz* companyNodo);
    void insertarUsuario(Usuario* usuario, const std::string& depto, const std::string& company);
private:
    NodoMatriz* inicial;
    NodoMatriz* cabeceraH;
    NodoMatriz* cabeceraV;
};

#endif // MATRIZ_H