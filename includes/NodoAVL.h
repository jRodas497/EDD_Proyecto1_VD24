//
// Created by Usuario on 10/12/2024.
//

#ifndef NODOAVL_H
#define NODOAVL_H

#pragma once
#include "Activo.h"

class NodoAVL
{
public:
    NodoAVL(Activo* activo);

    // getters
    Activo* getActivo();
    NodoAVL*& getHijoDer();
    NodoAVL*& getHijoIzq();
    int getAlto();
    //setters
    void setActivo(Activo* activo);
    void setHijoDer(NodoAVL* hijoDer);
    void setHijoIzq(NodoAVL* hijoIzq);
    void setAlto(int altura);

private:
    Activo* activo;
    NodoAVL* hijoDer;
    NodoAVL* hijoIzq;
    int alto;
};

#endif //NODOAVL_H
