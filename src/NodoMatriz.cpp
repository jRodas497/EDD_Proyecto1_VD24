//
// Created by Usuario on 6/12/2024.
//
#include "../includes/NodoMatriz.h"

Usuario* usuario = nullptr;
NodoMatriz* nodoUsuario = nullptr;
NodoMatriz* nodoCabecera = nullptr;

NodoMatriz::NodoMatriz(Usuario* usuario)
    : usuario(usuario), cabecera(""), arriba(nullptr), abajo(nullptr), delante(nullptr), atras(nullptr), izquierda(nullptr), derecha(nullptr) {
}

NodoMatriz::NodoMatriz(const std::string& cabecera)
    : usuario(nullptr), cabecera(cabecera), arriba(nullptr), abajo(nullptr), delante(nullptr), atras(nullptr), izquierda(nullptr), derecha(nullptr) {
}

// getters
Usuario* NodoMatriz::getUsuario() {
    return usuario;
}

NodoMatriz* NodoMatriz::getArriba() {
    return arriba;
}

NodoMatriz* NodoMatriz::getAbajo() {
    return abajo;
}

NodoMatriz* NodoMatriz::getDelante() {
    return delante;
}

NodoMatriz* NodoMatriz::getAtras() {
    return atras;
}

NodoMatriz* NodoMatriz::getIzquierda() {
    return izquierda;
}

NodoMatriz* NodoMatriz::getDerecha() {
    return derecha;
}

const std::string& NodoMatriz::getCabecera() {
    return cabecera;
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

void NodoMatriz::setDelante(NodoMatriz* delante) {
    this->delante = delante;
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

void NodoMatriz::setCabecera(const std::string& cabecera) {
    this->cabecera = cabecera;
}