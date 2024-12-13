//
// Created by Usuario on 11/12/2024.
//

#ifndef NODOTRANSACCION_H
#define NODOTRANSACCION_H

#include "Transaccion.h"
class NodoTransaccion {
public:
    NodoTransaccion(Transaccion* transaccion);
    void insertarAlFinal(Transaccion* transaccion);

    // getters
    NodoTransaccion* getSig();
    NodoTransaccion* getAnt();
    Transaccion* getTransaccion();

    // setters
    void setSig(NodoTransaccion* sig);
    void setAnt(NodoTransaccion* ant);
    void setTransaccion(Transaccion* transaccion);

private:
    NodoTransaccion* sig;
    NodoTransaccion* ant;
    Transaccion* transaccion;
};

#endif //NODOTRANSACCION_H


