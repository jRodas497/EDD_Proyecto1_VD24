//
// Created by Usuario on 5/12/2024.
//
#include <iostream>
#include <string>
#include "../includes/Matriz.h"

Matriz::Matriz()
    {
    inicial = new NodoMatriz("(0,0)");
}
// Inserta un nuevo depto al final de la cabecera horizontal
NodoMatriz* Matriz::insertarCabHorizontal(const std::string& depto) {
    NodoMatriz* nuevo = new NodoMatriz(depto);

    // si no hay nodos en la cabecera horizontal, se inserta a la derecha de inicial
    if (!cabeceraH) {
        cabeceraH = nuevo;
        inicial->setDerecha(cabeceraH);
        cabeceraH->setIzquierda(inicial);
        return cabeceraH;
    }

    NodoMatriz* aux = inicial;

    // recorre hasta el final de la cabecera horizontal
    while (aux->getDerecha()) {
        aux = aux->getDerecha();
    }

    // hace la conexión entre el último depto y el nuevo depto
    aux->setDerecha(nuevo);
    nuevo->setIzquierda(aux);

    return nuevo;
}
// Inserta una nueva company al final de la cabecera vertical
NodoMatriz* Matriz::insertarCabVertical(const std::string& company) {
    NodoMatriz* nuevo = new NodoMatriz(company);

    // si no hay nodos en la matriz crea uno de inmediato
    if (!cabeceraV) {
        cabeceraV = nuevo;
        inicial->setAbajo(cabeceraV);
        cabeceraV->setArriba(inicial);
        return cabeceraV;
    }

    NodoMatriz* aux = cabeceraV;

    // recorre hasta el final de la cabecera vertical
    while (aux->getAbajo()) {
        aux = aux->getAbajo();
    }

    // hace la conexión entre el último company y el nuevo company
    aux->setAbajo(nuevo);
    nuevo->setArriba(aux);

    return nuevo;
}
// Comprueba si el depto ya existe en la cabecera horizontal
NodoMatriz* Matriz::deptoBuscar(const std::string& depto) {
    NodoMatriz* aux = inicial;

    while (aux->getDerecha() != nullptr) {
        if (aux->getDerecha()->getCabecera() == depto) {
            aux = aux->getDerecha();
            return aux;
        }
        aux = aux->getDerecha();
    }

    return nullptr;
}
// Comprueba si la company ya existe en la cabecera vertical
NodoMatriz* Matriz::companyBuscar(const std::string& company) {
    NodoMatriz* aux = inicial;

    while (aux->getAbajo() != nullptr) {
        if (aux->getCabecera() == company) {
            aux = aux->getAbajo();
            return aux;
        }
        aux = aux->getAbajo();
    }

    return nullptr;
}
NodoMatriz *Matriz::existeEn(NodoMatriz *cabezaDepto, const std::string &company) {
    NodoMatriz* aux = cabezaDepto;

    while (aux->getAbajo() != nullptr) {
        if (aux->getCabecera() == company) {
            return aux;
        }
        aux = aux->getAbajo();
    }

    return nullptr;
}
// Busca el nodo de la cabecera vertical de un usuario (Company)
NodoMatriz *Matriz::buscarCabeceraVertical(NodoMatriz *nodoUser) {
    NodoMatriz* aux = nodoUser;

    while (aux->getIzquierda() != nullptr) {
        aux = aux->getIzquierda();
    }

    return aux;
}
// Busca el nodo de la cabecera horizontal de un usuario (Depto)
NodoMatriz *Matriz::buscarCabeceraHorizontal(NodoMatriz *nodoUser) {
    NodoMatriz* aux = nodoUser;

    while (aux->getArriba() != nullptr) {
        aux = aux->getArriba();
    }

    return aux;
}
// Inserta un nuevo usuario en la matriz
void Matriz::insertarUsuario(Usuario* usuarioNuevo, const std::string& depto, const std::string& company) {
    NodoMatriz* nuevo = new NodoMatriz(usuario);

    // Devuelve el nodo del depto y la company si ya existen
    NodoMatriz* deptoNodo = deptoBuscar(depto);
    NodoMatriz* companyNodo = companyBuscar(company);

    // Caso 1: Si no existe el depto ni la company, se crean
    if (deptoNodo == nullptr && companyNodo == nullptr) {
        deptoNodo = insertarCabHorizontal(depto);
        companyNodo = insertarCabVertical(company);

        insertarFinal(usuario, deptoNodo, companyNodo);
    }
    // Caso 2: Si no existe el depto pero si la company(de ultimo)
    else if (deptoNodo == nullptr && companyNodo->getAbajo() == nullptr) {
        deptoNodo = insertarCabHorizontal(depto);

        insertarFinal(usuario, deptoNodo, companyNodo);
    }
    // Caso3: Si existe el depto (de ultimo) pero no la company
    else if (deptoNodo->getDerecha() == nullptr && companyNodo == nullptr) {
        companyNodo = insertarCabVertical(company);

        insertarFinal(usuario, deptoNodo, companyNodo);
    }




    // Caso 4: Si ya existen ambos nodos al final se inserta el usuario
    else if (deptoNodo->getDerecha() == nullptr && companyNodo->getAbajo() == nullptr) {
        insertarFinal(usuario, deptoNodo, companyNodo);
    }




    // caso 5: Company en medio y depto al final
    else if (deptoNodo->getDerecha() == nullptr && companyNodo->getAbajo() != nullptr) {

    }
    // caso 6: Depto en medio y company al final
    else if (deptoNodo->getDerecha() != nullptr && companyNodo->getAbajo() == nullptr) {

    }
    // caso 7: Depto y company en medio
    else if (deptoNodo->getDerecha() != nullptr && companyNodo->getAbajo() != nullptr) {

    }
}
// Comprueba si el usuario ya existe en esa posición [Depto x Company]
bool Matriz::existenUsuarios(NodoMatriz* nodoUser, const std::string& usuario) {
    NodoMatriz* aux = nodoUser;

    while (aux->getAtras() != nullptr) {
        if (aux->getAtras()->getUsuario()->getUsuario() == usuario) {
            return true;
        }
        aux = aux->getAtras();
    }

    return false;
}
// Inserta un nuevo usuario al final de Company y Depto
void Matriz::insertarFinal(Usuario* usuario, NodoMatriz* deptoNodo, NodoMatriz* companyNodo) {
    NodoMatriz* nuevoUsuario = new NodoMatriz(usuario);

    NodoMatriz* auxDepto = deptoNodo;
    NodoMatriz* auxCompany = companyNodo;

    // recorre hasta el final del depto
    while (auxDepto->getDerecha()) {
        auxDepto = auxDepto->getDerecha();
    }

    // recorre hasta el final de la company
    while (auxCompany->getAbajo()) {
        auxCompany = auxCompany->getAbajo();
    }

    // verifica si ya existe un nodo en la posición [Depto x Company]
    if (auxDepto->getAbajo() == auxCompany->getDerecha()) {
        return;
    }

    // hace la conexión entre el último depto y el usuario
    auxDepto->setAbajo(nuevoUsuario);
    nuevoUsuario->setArriba(auxDepto);

    // hace la conexión entre el último usuario y el usuario
    auxCompany->setDerecha(nuevoUsuario);
    nuevoUsuario->setIzquierda(auxCompany);
}