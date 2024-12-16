#pragma once
#include "NodoAVL.h"
#include <string>

class ArbolAVL {
public:
    NodoAVL* raiz;
    ArbolAVL();

    // Funciones de inserción
    void insertar(Activo* activo);
    void insertar(Activo* activo, NodoAVL*& raiz);

    // Funciones de eliminación
    void eliminar(const std::string& id);
    NodoAVL* eliminar(const std::string& id, NodoAVL*& raiz);

    // Funciones de búsqueda [Costados]
    NodoAVL* buscarMasDerecha(NodoAVL* nodo);
    NodoAVL* buscarMasIzquierda(NodoAVL* nodo);

    // Funciones de modificación
    bool modificarActivo(const std::string& id, const std::string& descripcion);

    // Funciones de búsqueda
    NodoAVL* buscar(const std::string& id, NodoAVL* nodo);
    void buscar(const std::string& id);

    // Funciones de verificación
    bool hoja(NodoAVL* nodo);

    // Funciones de Rotación [Simple]
    NodoAVL* simpleIzq(NodoAVL* nodo);
    NodoAVL* simpleDer(NodoAVL* nodo);
    // Funciones de Rotación [Doble]
    NodoAVL* dobleDer(NodoAVL* nodo);
    NodoAVL* dobleIzq(NodoAVL* nodo);

    // Funciones de impresión
    bool preOrden(bool bandera);
    void preOrden(NodoAVL* nodo, bool bandera);
    void listarActivosUsuario(const std::string& usuario);
    void listarActivosUsuario(NodoAVL* nodo, const std::string& usuario);

    // Funciones de altura
    int altoDer(NodoAVL* der);
    int altoIzq(NodoAVL* izq);

    // Funciones de balanceo
    int mayorHijo(int a, int b);

    // Funciones de factor de equilibrio
    int facEquilibrio(int hijo1, int hijo2);

    // Funciones de impresión de activos por usuario
    void activosUsuario(NodoAVL* usuarioActual, std::string usuario);
    std::string activosUsuarioPre(NodoAVL* usuarioActual, std::string dot);

    void listarActivosRentados(NodoAVL* nodo);
};