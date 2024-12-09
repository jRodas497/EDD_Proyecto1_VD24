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
    NodoMatriz* nuevoDepto = new NodoMatriz(depto);

    // si no hay nodos en la cabecera horizontal, se inserta a la derecha de inicial
    if (!cabeceraH) {
        cabeceraH = nuevoDepto;
        inicial->setDerecha(cabeceraH);
        cabeceraH->setIzquierda(inicial);
        return cabeceraH;
    }

    NodoMatriz* nodoInicial = inicial;

    // recorre hasta el final de la cabecera horizontal
    while (nodoInicial->getDerecha()) {
        nodoInicial = nodoInicial->getDerecha();
    }

    // hace la conexión entre el último depto y el nuevo depto
    nodoInicial->setDerecha(nuevoDepto);
    nuevoDepto->setIzquierda(nodoInicial);

    return nuevoDepto;
}
// Inserta una nueva company al final de la cabecera vertical
NodoMatriz* Matriz::insertarCabVertical(const std::string& company) {
    NodoMatriz* nuevoCompany = new NodoMatriz(company);

    // si no hay nodos en la matriz crea uno de inmediato
    if (!cabeceraV) {
        cabeceraV = nuevoCompany;
        inicial->setAbajo(cabeceraV);
        cabeceraV->setArriba(inicial);
        return cabeceraV;
    }

    NodoMatriz* nodoInicial = inicial;

    // recorre hasta el final de la cabecera vertical
    while (nodoInicial->getAbajo()) {
        nodoInicial = nodoInicial->getAbajo();
    }

    // hace la conexión entre el último company y el nuevo company
    nodoInicial->setAbajo(nuevoCompany);
    nuevoCompany->setArriba(nodoInicial);

    return nuevoCompany;
}
// Cabecera depto más a la derecha
NodoMatriz* Matriz::deptoUltimo(const std::string& depto) {
    NodoMatriz* aux = inicial;

    while (aux->getDerecha()) {
        aux = aux->getDerecha();
    }

    return aux;
}
// Cabecera company más abajo
NodoMatriz* Matriz::companyUltimo(const std::string& company) {
    NodoMatriz* aux = inicial;

    while (aux->getAbajo()) {
        aux = aux->getAbajo();
    }

    return aux;
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
        if (aux->getAbajo()->getCabecera() == company) {
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
void Matriz::insertarUsuario(Usuario* usuarioNuevo, const std::string& depto, const std::string& company, bool insertarAtras) {
    // Devuelve el nodo del depto y la company si ya existen, si no, devuelve nullptr
    NodoMatriz* deptoNodo = deptoBuscar(depto);
    NodoMatriz* companyNodo = companyBuscar(company);

    // Caso 1: Si no existe el depto ni la company, se crean
    if (deptoNodo == nullptr && companyNodo == nullptr) {
        deptoNodo = insertarCabHorizontal(depto);
        companyNodo = insertarCabVertical(company);
        insertarFinal(usuarioNuevo, deptoNodo, companyNodo, false);
    }
    // Caso 2: Si no existe el depto pero si la company(de ultimo)
    else if ( (deptoNodo == nullptr) && (companyNodo == companyUltimo(company)) && (deptoNodo != deptoUltimo(depto)) ) {

        deptoNodo = insertarCabHorizontal(depto);
        insertarFinal(usuarioNuevo, deptoNodo, companyNodo, false);
    }
    // Caso3: Si existe el depto (de ultimo) pero no la company
    else if ((deptoNodo == deptoUltimo(depto)) && (companyNodo == nullptr)) {
        companyNodo = insertarCabVertical(company);

        insertarFinal(usuarioNuevo, deptoNodo, companyNodo, false);
    }
    // Caso 4: Si ya existen ambos (depto y company) al final se inserta el usuario detras/adelante del(los) usuario/s existente/s
    else if (deptoNodo == deptoUltimo(depto) && companyNodo == companyUltimo(company)) {
        insertarFinal(usuarioNuevo, deptoNodo, companyNodo, insertarAtras);
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
void Matriz::insertarFinal(Usuario* usuario, NodoMatriz* deptoNodo, NodoMatriz* companyNodo, bool insertarAtras) {
    NodoMatriz* nuevoUsuario = new NodoMatriz(usuario);

    NodoMatriz* auxDepto = deptoNodo;
    NodoMatriz* auxCompany = companyNodo;

/*
    // ya se está al final de la cabecera horizontal, borrar más adelante
    // recorre hasta el final del depto
    while (auxDepto->getDerecha()) {
        auxDepto = auxDepto->getDerecha();
    }
	// ya se está al final de la cabecera vertical, borrar más adelante
    // recorre hasta el final de la company
    while (auxCompany->getAbajo()) {
        auxCompany = auxCompany->getAbajo();
    }
*/

    // Llega hasta el usuario más abajo del ultimo depto
    while (auxDepto->getAbajo()) {
        auxDepto = auxDepto->getAbajo();
    }

    // Llega hasta el usuario más a la derecha de la última company
    while (auxCompany->getDerecha()) {
        auxCompany = auxCompany->getDerecha();
    }

    // verifica si ya existe un nodo en la posición [Depto x Company]
    if (auxDepto == auxCompany) {
        // Si se desea insertar al final del usuario existente
        if (insertarAtras) {
        	// recorre hasta el final de la lista de usuarios en la posición [Depto x Company]
        	NodoMatriz* ultimoUsuario = auxDepto; // ó auxCompany
        	while (ultimoUsuario->getAtras() != nullptr) {
            	ultimoUsuario = ultimoUsuario->getAtras();
        	}
        	// agrega el nuevo usuario detrás del último usuario
        	ultimoUsuario->setAtras(nuevoUsuario);
        	nuevoUsuario->setDelante(ultimoUsuario);
        // Si se desea insertar al frente del usuario existente
    	} else {
        	// agrega el nuevo usuario delante del primer usuario
        	NodoMatriz* primerUsuarioAnterior = auxDepto; // ó auxCompany
            // Establece la relación entre el nuevo usuario y el primer usuario anterior
        	nuevoUsuario->setAtras(primerUsuarioAnterior);
        	primerUsuarioAnterior->setDelante(nuevoUsuario);
            // Establece la relación entre el nuevo usuario y la company
            nuevoUsuario->setIzquierda(primerUsuarioAnterior->getIzquierda());
            primerUsuarioAnterior->getIzquierda()->setDerecha(nuevoUsuario);
    	    // Establece la relación entre el nuevo usuario y el depto
            nuevoUsuario->setArriba(primerUsuarioAnterior->getArriba());
            primerUsuarioAnterior->getArriba()->setAbajo(nuevoUsuario);

            // Si el primer usuario anterior tiene más usuarios a la derecha o abajo
    	    // Se establecen las relaciones con el nuevo usuario a la derecha
    	    if (primerUsuarioAnterior->getDerecha() != nullptr) {
    	        nuevoUsuario->setDerecha(primerUsuarioAnterior->getDerecha());
    	        primerUsuarioAnterior->getDerecha()->setIzquierda(nuevoUsuario);
    	    }
    	    // Se establecen las relaciones con el nuevo usuario abajo
    	    if (primerUsuarioAnterior->getAbajo() != nullptr) {
    	        nuevoUsuario->setAbajo(primerUsuarioAnterior->getAbajo());
    	        primerUsuarioAnterior->getAbajo()->setArriba(nuevoUsuario);
    	    }

        	primerUsuarioAnterior->setAbajo(nullptr);
        	primerUsuarioAnterior->setArriba(nullptr);

            primerUsuarioAnterior->setDerecha(nullptr);
            primerUsuarioAnterior->setIzquierda(nullptr);
    	}
        return;
    }

		// hace la conexión entre el último depto y el usuario
    	auxDepto->setAbajo(nuevoUsuario);
    	nuevoUsuario->setArriba(auxDepto);

    	// hace la conexión entre el último company y el usuario
    	auxCompany->setDerecha(nuevoUsuario);
    	nuevoUsuario->setIzquierda(auxCompany);

}
/*
// verifica si ya existe un nodo en la posición [Depto x Company]
if (auxCompany->getIzquierda() == auxDepto->getAbajo()) {
    // recorre hasta el final de la lista de usuarios en la posición [Depto x Company]
    NodoMatriz* ultimoUsuario = auxCompany->getIzquierda();
    while (ultimoUsuario->getAtras() != nullptr) {
        ultimoUsuario = ultimoUsuario->getAtras();
    }
    // agrega el nuevo usuario detrás del último usuario
    ultimoUsuario->setAtras(nuevoUsuario);
    nuevoUsuario->setDelante(ultimoUsuario);
    return;
}
*/

/*
// recorre hasta el final de la lista de usuarios en la posición [Depto x Company]
        NodoMatriz* ultimoUsuario = auxDepto->getAbajo();
        while (ultimoUsuario->getAtras() != nullptr) {
            ultimoUsuario = ultimoUsuario->getAtras();
        }
        // agrega el nuevo usuario detrás del último usuario
        ultimoUsuario->setAtras(nuevoUsuario);
        nuevoUsuario->setDelante(ultimoUsuario);
        return;
*/
/*
if (auxDepto == auxCompany) {
    char posicion;
    std::cout << "¿Desea insertar al final (f) o al inicio (i) del usuario existente? ";
    std::cin >> posicion;

    if (posicion == 'f') {
        // recorre hasta el final de la lista de usuarios en la posición [Depto x Company]
        NodoMatriz* ultimoUsuario = auxDepto->getAbajo();
        while (ultimoUsuario->getAtras() != nullptr) {
            ultimoUsuario = ultimoUsuario->getAtras();
        }
        // agrega el nuevo usuario detrás del último usuario
        ultimoUsuario->setAtras(nuevoUsuario);
        nuevoUsuario->setDelante(ultimoUsuario);
    } else if (posicion == 'i') {
        // agrega el nuevo usuario delante del primer usuario
        NodoMatriz* primerUsuario = auxDepto->getAbajo();
        nuevoUsuario->setAtras(primerUsuario);
        primerUsuario->setDelante(nuevoUsuario);
        auxDepto->setAbajo(nuevoUsuario);
        nuevoUsuario->setArriba(auxDepto);
    }
    return;
}
*/