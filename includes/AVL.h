//
// Created by Usuario on 5/12/2024.
//
#ifndef AVL_H
#define AVL_H

#include <iostream>
#include "Activo.h"
#include "../includes/NodoAVL.h"

class AVL {
public:
    AVL();
    ~AVL();
    void insertar(Activo* activo);
    void eliminar(const std::string& id);
    Activo* buscar(const std::string& id) const;
    void imprimirEnOrden() const;

private:
    struct Nodo {
        Activo* activo;
        Nodo* izquierda;
        Nodo* derecha;
        int altura;
        Nodo(Activo* act) : activo(act), izquierda(nullptr), derecha(nullptr), altura(1) {}
    };

    Nodo* raiz;

    Nodo* insertar(Nodo* nodo, Activo* activo);
    Nodo* eliminar(Nodo* nodo, const std::string& id);
    Nodo* buscar(Nodo* nodo, const std::string& id) const;
    void imprimirEnOrden(Nodo* nodo) const;
    int obtenerAltura(Nodo* nodo) const;
    int obtenerBalance(Nodo* nodo) const;
    Nodo* rotarDerecha(Nodo* y);
    Nodo* rotarIzquierda(Nodo* x);
    Nodo* minValorNodo(Nodo* nodo);
    void destruir(Nodo* nodo);
};

#endif // AVL_H