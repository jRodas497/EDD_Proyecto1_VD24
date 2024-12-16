//
// Created by Usuario on 5/12/2024.
//
#ifndef MATRIZ_H
#define MATRIZ_H

#include "NodoMatriz.h"

class Matriz {
public:
    Matriz();
    // Funciones de inserción de cabeceras
    NodoMatriz* insertarCabHorizontal(const std::string& depto); //
    NodoMatriz* insertarCabVertical(const std::string& company); //

    // Funciones de búsqueda
    NodoMatriz* buscarCabeceraVertical(NodoMatriz* nodoUser);
    NodoMatriz* buscarCabeceraHorizontal(NodoMatriz* nodoUser);
    NodoMatriz* deptoBuscar(const std::string& depto);
    NodoMatriz* companyBuscar(const std::string& company);
    NodoMatriz* existeEn(NodoMatriz* cabezaDepto, const std::string& company);
    NodoMatriz* deptoUltimo();
    NodoMatriz* companyUltimo();
    bool existenUsuarios(NodoMatriz* nodoUser, const std::string& usuario);

    // Funciones de inserción de Usuarios
    void insertarFinal(Usuario* usuario, NodoMatriz* deptoNodo, NodoMatriz* companyNodo, bool insertarAtras);
    void insertarUsuario(Usuario* usuario, const std::string& depto, const std::string& company, bool insertarAtras);
    void companyMidDeptoFin(NodoMatriz* deptoNodo, NodoMatriz* companyNodo, NodoMatriz* nuevoUsuario);
    void deptoMidCompanyFin(NodoMatriz* deptoNodo, NodoMatriz* companyNodo, NodoMatriz* nuevoUsuario);
    void deptoCompanyMid(NodoMatriz* deptoNodo, NodoMatriz* companyNodo, NodoMatriz* nuevoUsuario);

    // Funciones de listado
    void listarUsuarios(const std::string& depto, const std::string& company);
    void listarUsuariosPorCompany(const std::string& company);
    void listarUsuariosPorDepto(const std::string& depto);

    // Funciones de reporte
    void reporteMatrizDispersa();
    void reporteActivosDepto(const std::string& depto);
    void reporteActivosCompany(const std::string& company);

    // Funciones de activos
    NodoAVL* listadoActivos(Usuario* usuarioActual, bool bandera, std::string id);
    NodoAVL* listadoActivos(Usuario* usuarioActual, NodoMatriz* comienzo, bool bandera, std::string id);


    NodoMatriz* buscarUsuarioCabeza(NodoMatriz* usuarioActual);
private:
    NodoMatriz* inicial;
    NodoMatriz* cabeceraH;
    NodoMatriz* cabeceraV;
};

#endif // MATRIZ_H