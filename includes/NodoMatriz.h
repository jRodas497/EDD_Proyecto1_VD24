//
// Created by Usuario on 6/12/2024.
//

#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H

#include <string>
#include "Usuario.h"

class NodoMatriz {
public:
    NodoMatriz(Usuario* usuario);
    NodoMatriz(const std::string& cabecera);

    // getters
    Usuario* getUsuario() const;
    NodoMatriz* getArriba() const;
    NodoMatriz* getAbajo() const;
    NodoMatriz* getSiguiente() const;
    NodoMatriz* getAtras() const;
    NodoMatriz* getIzquierda() const;
    NodoMatriz* getDerecha() const;
    const std::string& getCabecera() const;

    // setters
    void setUsuario(Usuario* usuario);
    void setArriba(NodoMatriz* arriba);
    void setAbajo(NodoMatriz* abajo);
    void setSiguiente(NodoMatriz* siguiente);
    void setAtras(NodoMatriz* atras);
    void setIzquierda(NodoMatriz* izquierda);
    void setDerecha(NodoMatriz* derecha);
    void setCabecera(const std::string& cabecera);

private:
    Usuario* usuario;
    std::string cabecera;
    NodoMatriz* arriba;
    NodoMatriz* abajo;
    NodoMatriz* siguiente;
    NodoMatriz* atras;
    NodoMatriz* izquierda;
    NodoMatriz* derecha;
};

#endif // NODOMATRIZ_H

/*
// Crear un nodo matriz de cabecera con un valor para la cabecera y sin usuario
NodoMatriz* nodoCabecera = new NodoMatriz(nullptr, "NombreDeLaCabecera");

// Crear un usuario
Usuario* usuario = new Usuario("nombre", "usuario", "contra");

// Crear un nodo matriz con el usuario y una cabecera vacía
NodoMatriz* nodoUsuario = new NodoMatriz(usuario, "");
*/


// Crear un usuario
Usuario* usuario = new Usuario("nombre", "usuario", "contra");

// Crear un nodo matriz con el usuario y una cabecera vacía
NodoMatriz* nodoUsuario = new NodoMatriz(usuario);

// Crear un nodo matriz de cabecera con un valor para la cabecera y sin usuario
NodoMatriz* nodoCabecera = new NodoMatriz("NombreDeLaCabecera");
