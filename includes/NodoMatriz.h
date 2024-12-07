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

    // getters
    Usuario* getUsuario() const;
    NodoMatriz* getArriba() const;
    NodoMatriz* getAbajo() const;
    NodoMatriz* getSiguiente() const;
    NodoMatriz* getAtras() const;
    NodoMatriz* getIzquierda() const;
    NodoMatriz* getDerecha() const;

    // setters
    void setUsuario(Usuario* usuario);
    void setArriba(NodoMatriz* arriba);
    void setAbajo(NodoMatriz* abajo);
    void setSiguiente(NodoMatriz* siguiente);
    void setAtras(NodoMatriz* atras);
    void setIzquierda(NodoMatriz* izquierda);
    void setDerecha(NodoMatriz* derecha);

private:
    Usuario* usuario;
    NodoMatriz* arriba;
    NodoMatriz* abajo;
    NodoMatriz* siguiente;
    NodoMatriz* atras;
    NodoMatriz* izquierda;
    NodoMatriz* derecha;
};

#endif // NODOMATRIZ_H
