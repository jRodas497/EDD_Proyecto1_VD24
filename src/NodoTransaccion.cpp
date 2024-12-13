//
// Created by Usuario on 11/12/2024.
//
#include "NodoTransaccion.h"

// Constructor
NodoTransaccion::NodoTransaccion(Transaccion* transaccion)
    : transaccion(transaccion), sig(nullptr), ant(nullptr) {}

// Getters
NodoTransaccion* NodoTransaccion::getSig() {
    return sig;
}

NodoTransaccion* NodoTransaccion::getAnt() {
    return ant;
}

Transaccion* NodoTransaccion::getTransaccion() {
    return transaccion;
}

// Setters
void NodoTransaccion::setSig(NodoTransaccion* sig) {
    this->sig = sig;
}

void NodoTransaccion::setAnt(NodoTransaccion* ant) {
    this->ant = ant;
}

void NodoTransaccion::setTransaccion(Transaccion* transaccion) {
    this->transaccion = transaccion;
}
