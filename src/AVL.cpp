//
// Created by Usuario on 5/12/2024.
//
#include "../includes/AVL.h"
#include <iostream>

AVL::AVL() : raiz(nullptr) {}

AVL::~AVL() {
    destruir(raiz);
}

void AVL::insertar(Activo* activo) {
    raiz = insertar(raiz, activo);
}

void AVL::eliminar(const std::string& id) {
    raiz = eliminar(raiz, id);
}

Activo* AVL::buscar(const std::string& id) const {
    Nodo* resultado = buscar(raiz, id);
    return resultado ? resultado->activo : nullptr;
}

void AVL::imprimirEnOrden() const {
    imprimirEnOrden(raiz);
}

AVL::Nodo* AVL::insertar(Nodo* nodo, Activo* activo) {
    if (!nodo) return new Nodo(activo);

    if (activo->getIdAlfa() < nodo->activo->getIdAlfa())
        nodo->izquierda = insertar(nodo->izquierda, activo);
    else if (activo->getIdAlfa() > nodo->activo->getIdAlfa())
        nodo->derecha = insertar(nodo->derecha, activo);
    else
        return nodo;

    nodo->altura = 1 + std::max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && activo->getIdAlfa() < nodo->izquierda->activo->getIdAlfa())
        return rotarDerecha(nodo);

    if (balance < -1 && activo->getIdAlfa() > nodo->derecha->activo->getIdAlfa())
        return rotarIzquierda(nodo);

    if (balance > 1 && activo->getIdAlfa() > nodo->izquierda->activo->getIdAlfa()) {
        nodo->izquierda = rotarIzquierda(nodo->izquierda);
        return rotarDerecha(nodo);
    }

    if (balance < -1 && activo->getIdAlfa() < nodo->derecha->activo->getIdAlfa()) {
        nodo->derecha = rotarDerecha(nodo->derecha);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

AVL::Nodo* AVL::eliminar(Nodo* nodo, const std::string& id) {
    if (!nodo) return nodo;

    if (id < nodo->activo->getIdAlfa())
        nodo->izquierda = eliminar(nodo->izquierda, id);
    else if (id > nodo->activo->getIdAlfa())
        nodo->derecha = eliminar(nodo->derecha, id);
    else {
        if (!nodo->izquierda || !nodo->derecha) {
            Nodo* temp = nodo->izquierda ? nodo->izquierda : nodo->derecha;
            if (!temp) {
                temp = nodo;
                nodo = nullptr;
            } else
                *nodo = *temp;
            delete temp;
        } else {
            Nodo* temp = minValorNodo(nodo->derecha);
            nodo->activo = temp->activo;
            nodo->derecha = eliminar(nodo->derecha, temp->activo->getIdAlfa());
        }
    }

    if (!nodo) return nodo;

    nodo->altura = 1 + std::max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && obtenerBalance(nodo->izquierda) >= 0)
        return rotarDerecha(nodo);

    if (balance > 1 && obtenerBalance(nodo->izquierda) < 0) {
        nodo->izquierda = rotarIzquierda(nodo->izquierda);
        return rotarDerecha(nodo);
    }

    if (balance < -1 && obtenerBalance(nodo->derecha) <= 0)
        return rotarIzquierda(nodo);

    if (balance < -1 && obtenerBalance(nodo->derecha) > 0) {
        nodo->derecha = rotarDerecha(nodo->derecha);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

AVL::Nodo* AVL::buscar(Nodo* nodo, const std::string& id) const {
    if (!nodo || nodo->activo->getIdAlfa() == id)
        return nodo;

    if (nodo->activo->getIdAlfa() < id)
        return buscar(nodo->derecha, id);

    return buscar(nodo->izquierda, id);
}

void AVL::imprimirEnOrden(Nodo* nodo) const {
    if (nodo) {
        imprimirEnOrden(nodo->izquierda);
        std::cout << "ID: " << nodo->activo->getId() << " | Nombre: " << nodo->activo->getName() << " | Descripción: " << nodo->activo->getDescription() << " | ID Alfanumérico: " << nodo->activo->getIdAlfa() << std::endl;
        imprimirEnOrden(nodo->derecha);
    }
}

int AVL::obtenerAltura(Nodo* nodo) const {
    return nodo ? nodo->altura : 0;
}

int AVL::obtenerBalance(Nodo* nodo) const {
    return nodo ? obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha) : 0;
}

AVL::Nodo* AVL::rotarDerecha(Nodo* y) {
    Nodo* x = y->izquierda;
    Nodo* T2 = x->derecha;

    x->derecha = y;
    y->izquierda = T2;

    y->altura = std::max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;
    x->altura = std::max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;

    return x;
}

AVL::Nodo* AVL::rotarIzquierda(Nodo* x) {
    Nodo* y = x->derecha;
    Nodo* T2 = y->izquierda;

    y->izquierda = x;
    x->derecha = T2;

    x->altura = std::max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;
    y->altura = std::max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;

    return y;
}

AVL::Nodo* AVL::minValorNodo(Nodo* nodo) {
    Nodo* actual = nodo;
    while (actual->izquierda)
        actual = actual->izquierda;
    return actual;
}

void AVL::destruir(Nodo* nodo) {
    if (nodo) {
        destruir(nodo->izquierda);
        destruir(nodo->derecha);
        delete nodo;
    }
}