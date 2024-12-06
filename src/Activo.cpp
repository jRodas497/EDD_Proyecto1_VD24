//
// Created by Usuario on 5/12/2024.
//
#include "../includes/Activo.h"

Activo::Activo(int id, const std::string& nombre, const std::string& descripcion, const std::string& idAlfa)
    : id(id), nombre(nombre), descripcion(descripcion), idAlfa(idAlfa), rentado(false), eliminado(false) {}

int Activo::getId() const {
    return id;
}

const std::string& Activo::getIdAlfa() const {
    return idAlfa;
}

const std::string& Activo::getName() const {
    return nombre;
}

const std::string& Activo::getDescription() const {
    return descripcion;
}

void Activo::setIdAlfa(const std::string& idAlfa) {
    this->idAlfa = idAlfa;
}

void Activo::setName(const std::string& nombre) {
    this->nombre = nombre;
}

void Activo::setDescription(const std::string& descripcion) {
    this->descripcion = descripcion;
}

bool Activo::isRented() const {
    return rentado;
}

void Activo::setRented(bool rentado) {
    this->rentado = rentado;
}

bool Activo::isDeleted() const {
    return eliminado;
}

void Activo::setDeleted(bool eliminado) {
    this->eliminado = eliminado;
}