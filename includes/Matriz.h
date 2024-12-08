//
// Created by Usuario on 5/12/2024.
//
#ifndef MATRIZ_H
#define MATRIZ_H

#include "NodoMatriz.h"

class MatrizDispersa {
public:
    MatrizDispersa();
    NodoMatriz* insertarCabHorizontal(const std::string& depto);
    NodoMatriz* insertarCabVertical(const std::string& company);
    void insertarUsuario(Usuario* usuario, const std::string& depto, const std::string& company);
    NodoMatriz* deptoExiste(const std::string& depto);
    NodoMatriz* companyExiste(const std::string& company);



private:
    NodoMatriz* inicial;
    NodoMatriz* cabeceraH;
    NodoMatriz* cabeceraV;
};

#endif // MATRIZ_H