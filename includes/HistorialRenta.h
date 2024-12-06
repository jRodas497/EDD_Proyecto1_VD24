//
// Created by Usuario on 5/12/2024.
//
#ifndef HISTORIALRENTA_H
#define HISTORIALRENTA_H

#include "Usuario.h"
#include "Activo.h"
#include <string>

struct NodoHistorial {
    Usuario* usuario;
    Activo* activo;
    NodoHistorial* siguiente;
};

class HistorialRentas {
public:
    HistorialRentas();
    void registrarRenta(Usuario* usuario, Activo* activo);
    void imprimirHistorial();

private:
    NodoHistorial* cabeza;
};

#endif // HISTORIALRENTA_H