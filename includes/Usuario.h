//
// Created by Usuario on 5/12/2024.
//
#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "AVL.h"

class Usuario {
public:
    Usuario(const std::string& nombre, const std::string& usuario, const std::string& contra);
    // getters
    int getId() const;
    const std::string& getNombre() const;
    const std::string& getUsuario() const;
    const std::string& getContra() const;
    // setters
    void setNombre(const std::string& nombre);
    void setUsuario(const std::string& usuario);
    void setContra(const std::string& contra);

private:
    static int nextId;
    int id;
    std::string nombre;
    std::string usuario;
    std::string contra;
};

#endif // USUARIO_H