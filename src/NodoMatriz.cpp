//
// Created by Usuario on 6/12/2024.
//
#include "../includes/NodoMatriz.h"

NodoMatriz::NodoMatriz(Usuario* usuario)
    : usuario(usuario), arriba(nullptr), abajo(nullptr), siguiente(nullptr), atras(nullptr), izquierda(nullptr), derecha(nullptr) {
}

// getters
Usuario* NodoMatriz::getUsuario() const {
    return usuario;
}

NodoMatriz* NodoMatriz::getArriba() const {
    return arriba;
}

NodoMatriz* NodoMatriz::getAbajo() const {
    return abajo;
}

NodoMatriz* NodoMatriz::getSiguiente() const {
    return siguiente;
}

NodoMatriz* NodoMatriz::getAtras() const {
    return atras;
}

NodoMatriz* NodoMatriz::getIzquierda() const {
    return izquierda;
}

NodoMatriz* NodoMatriz::getDerecha() const {
    return derecha;
}

// setters
void NodoMatriz::setUsuario(Usuario* usuario) {
    this->usuario = usuario;
}

void NodoMatriz::setArriba(NodoMatriz* arriba) {
    this->arriba = arriba;
}

void NodoMatriz::setAbajo(NodoMatriz* abajo) {
    this->abajo = abajo;
}

void NodoMatriz::setSiguiente(NodoMatriz* siguiente) {
    this->siguiente = siguiente;
}

void NodoMatriz::setAtras(NodoMatriz* atras) {
    this->atras = atras;
}

void NodoMatriz::setIzquierda(NodoMatriz* izquierda) {
    this->izquierda = izquierda;
}

void NodoMatriz::setDerecha(NodoMatriz* derecha) {
    this->derecha = derecha;
}