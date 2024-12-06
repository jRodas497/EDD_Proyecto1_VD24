//
// Created by Usuario on 5/12/2024.
//
#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
public:
    Usuario(int id, const std::string& nombre);
    int obtenerId() const;
    std::string obtenerNombre() const;

private:
    int id;
    std::string nombre;
};

#endif // USUARIO_H