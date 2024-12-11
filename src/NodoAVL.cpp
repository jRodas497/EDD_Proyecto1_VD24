//
// Created by Usuario on 10/12/2024.
//
#include "../includes/NodoAVL.h"
#include "../includes/Activo.h"

NodoAVL::NodoAVL(Activo* activo)
    : activo(activo), hijoDer(nullptr), hijoIzq(nullptr), altura(0) {}

void NodoAVL::setActivo(Activo* activo) {
    this->activo = activo;
}

Activo* NodoAVL::getActivo() {
    return activo;
}

void NodoAVL::setHijoDer(NodoAVL* hijoDer) {
    this->hijoDer = hijoDer;
}

NodoAVL*& NodoAVL::getHijoDer() {
    return hijoDer;
}

void NodoAVL::setHijoIzq(NodoAVL* hijoIzq) {
    this->hijoIzq = hijoIzq;
}

NodoAVL*& NodoAVL::getHijoIzq() {
    return hijoIzq;
}

void NodoAVL::setAltura(int altura) {
    this->altura = altura;
}

int NodoAVL::getAltura() {
    return altura;
}