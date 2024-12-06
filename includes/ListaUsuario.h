//
// Created by Usuario on 5/12/2024.
//
#ifndef LISTAUSUARIO_H
#define LISTAUSUARIO_H

#include "Usuario.h"

struct NodoUsuario {
    Usuario* usuario;
    NodoUsuario* siguiente;
};

class ListaUsuario {
public:
    ListaUsuario();
    void insertar(Usuario* usuario, bool alFinal);
    void imprimirLista();

private:
    NodoUsuario* cabeza;
};

#endif // LISTAUSUARIO_H