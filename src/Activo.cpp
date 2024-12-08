//
// Created by Usuario on 5/12/2024.
//
#include "../includes/Activo.h"

int::Activo::nextId = 1;

Activo::Activo(const std::string& nombre, const std::string& descripcion, const std::string& idAlfa)
    : id(nextId++), nombre(nombre), descripcion(descripcion), idAlfa(idAlfa), rentado(false), eliminado(false) {
}

// getters
int Activo::getId() {
    return id;
}

const std::string& Activo::getIdAlfa() {
    return idAlfa;
}

const std::string& Activo::getNombre() {
    return nombre;
}

const std::string& Activo::getDescripcion() {
    return descripcion;
}

bool Activo::isRentado() {
    return rentado;
}

bool Activo::isEliminado() {
    return eliminado;
}

// setters
void Activo::setIdAlfa(const std::string& idAlfa) {
    this->idAlfa = idAlfa;
}

void Activo::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Activo::setDescripcion(const std::string& descripcion) {
    this->descripcion = descripcion;
}

void Activo::setRentado(bool rentado) {
    this->rentado = rentado;
}

void Activo::setEliminado(bool eliminado) {
    this->eliminado = eliminado;
}