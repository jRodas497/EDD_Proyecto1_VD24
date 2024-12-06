//
// Created by Usuario on 5/12/2024.
//

#ifndef GESTORDATOS_H
#define GESTORDATOS_H

#include <vector>
#include "Activo.h"
#include "AVL.h"

class GestorDatos {
public:
    GestorDatos();
    void agregarActivo(const std::string& nombre, const std::string& descripcion, const std::string& idAlfa);
    void eliminarActivo(int id);
    void mostrarActivos() const;
    bool existeActivo(int id) const;

private:
    AVL arbolActivos;
    int idCounter;
};

#endif // GESTORDATOS_H