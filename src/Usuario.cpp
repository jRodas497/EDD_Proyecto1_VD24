//
// Created by Usuario on 5/12/2024.
//
#include "../includes/Usuario.h"

int::Usuario::nextId = 1;

Usuario::Usuario(const std::string& nombre, const std::string& usuario, const std::string& contra)
    : id(nextId++), nombre(nombre), usuario(usuario), contra(contra) {
}

// getters
int Usuario::getId() const {
    return id;
}

const std::string& Usuario::getNombre() const {
    return nombre;
}

const std::string& Usuario::getUsuario() const {
    return usuario;
}

const std::string& Usuario::getContra() const {
    return contra;
}

// setters
void Usuario::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Usuario::setUsuario(const std::string& usuario) {
    this->usuario = usuario;
}

void Usuario::setContra(const std::string& contra) {
    this->contra = contra;
}