//
// Created by Usuario on 5/12/2024.
//
#include "../includes/Activo.h"

Activo::Activo(const std::string& nombre, const std::string& descripcion, const std::string& id)
    : nombre(nombre), descripcion(descripcion), id(id), rentado(false){
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

bool Activo::getRentado() {
    return rentado;
}

// setters
void Activo::setId(const std::string& idAlfa) {
    this->id = id;
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