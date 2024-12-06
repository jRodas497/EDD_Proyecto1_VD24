//
// Created by Usuario on 5/12/2024.
//
#ifndef MATRIZ_H
#define MATRIZ_H

#include "ListaUsuario.h"

struct NodoMatrizDispersa {
    int fila;
    int columna;
    ListaUsuario listaUsuarios;
    NodoMatrizDispersa* siguiente;
};

class MatrizDispersa {
public:
    MatrizDispersa(int filas, int columnas);
    void insertar(int fila, int columna, Usuario* usuario, bool alFinal);
    void imprimirMatriz();

private:
    int filas;
    int columnas;
    NodoMatrizDispersa* cabeza;
};

#endif // MATRIZ_H