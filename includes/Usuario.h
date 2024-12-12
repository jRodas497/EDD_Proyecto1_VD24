//
// Created by Usuario on 5/12/2024.
//
#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "ArbolAVL.h"
#include "Activo.h"

class Usuario {
public:
    Usuario(const std::string& nombre, const std::string& usuario, const std::string& contra);
    // getters
    int getId();
    const std::string& getNombre();
    const std::string& getUsuario();
    const std::string& getContra();
    ArbolAVL* getArbol();
    // setters
    void setNombre(const std::string& nombre);
    void setUsuario(const std::string& usuario);
    void setContra(const std::string& contra);
    void setArbol(ArbolAVL* arbolActivos);

private:
    static int nextId;
    int id;
    std::string nombre;
    std::string usuario;
    std::string contra;
    ArbolAVL* arbolActivos;
};

#endif // USUARIO_H