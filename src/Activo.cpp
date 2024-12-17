//
// Created by Usuario on 5/12/2024.
//
#include "../includes/Activo.h"

Activo::Activo(const std::string& nombre, const std::string& descripcion, const std::string& id, const std::string& usuario, const std::string& diasMax)
    : id(id), nombre(nombre), descripcion(descripcion), diasMax(diasMax), rentado(false), usuario(usuario) {
}
// getters
const std::string& Activo::getId() {
    return id;
}

const std::string& Activo::getNombre() {
    return nombre;
}

const std::string& Activo::getDescripcion() {
    return descripcion;
}

const std::string& Activo::getDiasMax() {
    return diasMax;
}

bool Activo::getRentado() const {
    return rentado;
}

const std::string& Activo::getUsuario() {
    return usuario;
}

const std::string& Activo::getDiasRenta() {
    return diasRenta;
}

// setters
void Activo::setId(const std::string& id) {
    this->id = id;
}

void Activo::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Activo::setDescripcion(const std::string& descripcion) {
    this->descripcion = descripcion;
}

void Activo::setDiasMax(const std::string& diasMax) {
    this->diasMax = diasMax;
}

void Activo::setRentado(bool rentado) {
    this->rentado = rentado;
}

void Activo::setUsuario(const std::string& usuario) {
    this->usuario = usuario;
}

void Activo::setDiasRenta(const std::string& diasRenta) {
    this->diasRenta = diasRenta;
}