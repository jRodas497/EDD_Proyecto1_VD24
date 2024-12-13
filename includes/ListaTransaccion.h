//
// Created by Usuario on 11/12/2024.
//

#ifndef LISTRATRANSACCION_H
#define LISTRATRANSACCION_H

#pragma once
#include "NodoTransaccion.h"

using namespace std;

class ListaTransaccion
{
    NodoTransaccion* ini;
    NodoTransaccion* fin;

public:
    ListaTransaccion();

    // Métodos de inserción
    void insertarTransaccion(Transaccion* transaccion);
    void insertarAlFinal(NodoTransaccion* elemento);
    void insertarAlFrente(NodoTransaccion* elemento);
    void insertarAlMedio(NodoTransaccion* elemento, NodoTransaccion* transaccionSiguiente);

    // Método para recorrer la lista
    bool recorrerLista(string usuario);
    void reporteActivosRentadosUsuario(string usuario);
    string reporteActivosRentadosUsuario(string dot, string usuario);

    // Métodos de reporte
    void reporteTransacciones();
    void reporteTransaccionesAscendente();
    void reporteTransaccionesDescendente();

    bool estaVacia() const;
};



#endif //LISTRATRANSACCION_H
