//
// Created by Usuario on 11/12/2024.
//
#include "Transaccion.h"

// Constructor por defecto
Transaccion::Transaccion() : idActivo(nullptr) {}

Transaccion::Transaccion(Activo* idActivo, std::string nombreUsuario, std::string departamento, std::string empresa, std::string fecha, std::string dias)
    : idActivo(idActivo), nombreUsuario(nombreUsuario), departamento(departamento), empresa(empresa), fecha(fecha), dias(dias) {}

// Setters y Getters
void Transaccion::setId(std::string id) {
    this->id = id;
}

std::string Transaccion::getId() {
    return id;
}

void Transaccion::setIdActivo(Activo* idActivo) {
    this->idActivo = idActivo;
}

Activo* Transaccion::getIdActivo() {
    return idActivo;
}

void Transaccion::setNombreUsuario(std::string nombreUsuario) {
    this->nombreUsuario = nombreUsuario;
}

std::string Transaccion::getNombreUsuario() {
    return nombreUsuario;
}

void Transaccion::setDepartamento(std::string departamento) {
    this->departamento = departamento;
}

std::string Transaccion::getDepartamento() {
    return departamento;
}

void Transaccion::setEmpresa(std::string empresa) {
    this->empresa = empresa;
}

std::string Transaccion::getEmpresa() {
    return empresa;
}

void Transaccion::setFecha(std::string fecha) {
    this->fecha = fecha;
}

std::string Transaccion::getFecha() {
    return fecha;
}

void Transaccion::setDias(std::string dias) {
    this->dias = dias;
}

std::string Transaccion::getDias() {
    return dias;
}