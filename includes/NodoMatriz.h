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
    Usuario* getUsuario();
    NodoMatriz* getArriba();
    NodoMatriz* getAbajo();
    NodoMatriz* getDelante();
    NodoMatriz* getAtras();
    NodoMatriz* getIzquierda();
    NodoMatriz* getDerecha();
    const std::string& getCabecera();

    // setters
    void setUsuario(Usuario* usuario);
    void setArriba(NodoMatriz* arriba);
    void setAbajo(NodoMatriz* abajo);
    void setDelante(NodoMatriz* siguiente);
    void setAtras(NodoMatriz* atras);
    void setIzquierda(NodoMatriz* izquierda);
    void setDerecha(NodoMatriz* derecha);
    void setCabecera(const std::string& cabecera);

private:
    Usuario* usuario;
    std::string cabecera;
    NodoMatriz* arriba; // company
    NodoMatriz* abajo; // company
    NodoMatriz* delante; //usuario
    NodoMatriz* atras; //usuario
    NodoMatriz* izquierda; // depto
    NodoMatriz* derecha; // depto
};

#endif // NODOMATRIZ_H

/*
// Crear un nodo matriz de cabecera con un valor para la cabecera y sin usuario
NodoMatriz* nodoCabecera = new NodoMatriz(nullptr, "NombreDeLaCabecera");

// Crear un usuario
Usuario* usuario = new Usuario("nombre", "usuario", "contra");

// Crear un nodo matriz con el usuario y una cabecera vacía
NodoMatriz* nodoUsuario = new NodoMatriz(usuario, "");

// Crear un usuario
Usuario* usuario = new Usuario("nombre", "usuario", "contra");

// Crear un nodo matriz con el usuario y una cabecera vacía
NodoMatriz* nodoUsuario = new NodoMatriz(usuario);

// Crear un nodo matriz de cabecera con un valor para la cabecera y sin usuario
NodoMatriz* nodoCabecera = new NodoMatriz("NombreDeLaCabecera");
*/