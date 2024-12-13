//
// Created by Usuario on 5/12/2024.
//
#include <iostream>
#include <string>
#include <fstream>

#include "../includes/Matriz.h"

// Inicializar la matriz dispersa
Matriz::Matriz()
    { inicial = new NodoMatriz("(0,0)"); }

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
NodoMatriz* Matriz::deptoUltimo() {
    NodoMatriz* aux = inicial;

    while (aux->getDerecha()) {
        aux = aux->getDerecha();
    }

    return aux;
}
// Cabecera company más abajo
NodoMatriz* Matriz::companyUltimo() {
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
// Comprueba si hay un usuario en la posición [Depto x Company]
NodoMatriz *Matriz::existeEn(NodoMatriz *cabezaDepto, const std::string &company) {
    NodoMatriz* auxDepto = cabezaDepto;

    if (auxDepto != nullptr) {
        while (auxDepto->getAbajo() != nullptr) {

            if (company == buscarCabeceraVertical(auxDepto->getAbajo())->getCabecera()) {
                return auxDepto->getAbajo();
            }

            auxDepto = auxDepto->getAbajo();
        }
    }

    return nullptr;
}
// Busca el nodo de la cabecera vertical de un usuario (Company)
NodoMatriz *Matriz::buscarCabeceraVertical(NodoMatriz *nodoUser) {
    NodoMatriz* aux = nodoUser;

    while (aux->getDelante()) {
        aux = aux->getDelante();
    }

    while (aux->getIzquierda()) {
        aux = aux->getIzquierda();
    }

    return aux;
}
// Busca el nodo de la cabecera horizontal de un usuario (Depto)
NodoMatriz *Matriz::buscarCabeceraHorizontal(NodoMatriz *nodoUser) {
    NodoMatriz* aux = nodoUser;

    while (aux->getDelante()) {
        aux = aux->getDelante();
    }

    while (aux->getArriba()) {
        aux = aux->getArriba();
    }

    return aux;
}
// Inserta un nuevo usuario en la matriz
void Matriz::insertarUsuario(Usuario* usuarioNuevo, const std::string& depto, const std::string& company, bool insertarAtras) {
    // Devuelve el nodo del depto y la company si ya existen, si no, devuelve nullptr
    NodoMatriz* deptoNodo = deptoBuscar(depto);
    NodoMatriz* companyNodo = companyBuscar(company);

    if (deptoNodo == nullptr || companyNodo == nullptr) {
        // Caso 1: Si no existe el depto ni la company, se crean
        if (deptoNodo == nullptr && companyNodo == nullptr) {
            deptoNodo = insertarCabHorizontal(depto);
            companyNodo = insertarCabVertical(company);
            insertarFinal(usuarioNuevo, deptoNodo, companyNodo, false);
        }
        // Caso 2: Si no existe el depto pero si la company(de ultimo)
        else if ( (deptoNodo == nullptr) && (companyNodo == companyUltimo()) && (deptoNodo != deptoUltimo()) ) {
            deptoNodo = insertarCabHorizontal(depto);

            insertarFinal(usuarioNuevo, deptoNodo, companyNodo, false);
        }
        // Caso3: Si existe el depto (de ultimo) pero no la company
        else if ((deptoNodo == deptoUltimo()) && (companyNodo == nullptr)) {
            companyNodo = insertarCabVertical(company);

            insertarFinal(usuarioNuevo, deptoNodo, companyNodo, false);
        }
        // Caso 4: Si ya existen ambos (depto y company) al final se inserta el usuario detras/adelante del(los) usuario/s existente/s
        else if (deptoNodo == deptoUltimo() && companyNodo == companyUltimo()) {
            insertarFinal(usuarioNuevo, deptoNodo, companyNodo, insertarAtras);
        }
        // caso 5: Company en medio y depto al final
        else if (companyNodo != companyUltimo() && deptoNodo == deptoUltimo()) {
            NodoMatriz* nuevoUsuario = new NodoMatriz(usuarioNuevo);
            deptoCompanyMid(deptoNodo, companyNodo, nuevoUsuario);
        }
        // caso 5.1: company en medio y depto no existe
        else if (companyNodo != companyUltimo() && deptoNodo == nullptr) {
            NodoMatriz* nuevoUsuario = new NodoMatriz(usuarioNuevo);
            deptoNodo = insertarCabHorizontal(depto);
            deptoCompanyMid(deptoNodo, companyNodo, nuevoUsuario);
        }
        // caso 6: Depto en medio y company al final
        else if (deptoNodo != deptoUltimo() && companyNodo == companyUltimo()) {
            NodoMatriz* nuevoUsuario = new NodoMatriz(usuarioNuevo);
            deptoCompanyMid(deptoNodo, companyNodo, nuevoUsuario);
        }
        // caso 6.1: Depto en medio y company no existe
        else if (deptoNodo != deptoUltimo() && companyNodo == nullptr) {
            NodoMatriz* nuevoUsuario = new NodoMatriz(usuarioNuevo);
            companyNodo = insertarCabVertical(company);
            deptoCompanyMid(deptoNodo, companyNodo, nuevoUsuario);
        }
        // caso 7: Depto y company en medio
        else if (deptoNodo !=deptoUltimo() && companyNodo != companyUltimo()) {
            NodoMatriz* nuevoUsuario = new NodoMatriz(usuarioNuevo);
            deptoCompanyMid(deptoNodo, companyNodo, nuevoUsuario);
        }
    }     else if (deptoNodo != nullptr && companyNodo != nullptr)  {
        // Caso 8: Si ya existen ambas cabeceras
        NodoMatriz* nuevoUsuario = new NodoMatriz(usuarioNuevo);
        deptoCompanyMid(deptoNodo, companyNodo, nuevoUsuario);
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
        	NodoMatriz* primerUsuario = auxDepto; // ó auxCompany
            NodoMatriz* usuarioActual = auxDepto; // ó auxCompany

        	while (primerUsuario->getAtras()) {
            	primerUsuario = primerUsuario->getAtras();
        	}
        	// agrega el nuevo usuario detrás del último usuario
        	primerUsuario->setAtras(nuevoUsuario);
        	nuevoUsuario->setDelante(primerUsuario);
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

    	    NodoMatriz* usuarioActual = auxDepto; // ó auxCompany
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
// Company en medio y depto al final
void Matriz::companyMidDeptoFin(NodoMatriz* deptoNodo, NodoMatriz* companyNodo, NodoMatriz* nuevoUsuario) {
        NodoMatriz* auxCompany = companyNodo;
        while (auxCompany->getDerecha()) {
            auxCompany = auxCompany->getDerecha();
        }
        // relación de izquierda
        auxCompany->setDerecha(nuevoUsuario);
        nuevoUsuario->setIzquierda(auxCompany);
        // relación de abajo
        // Se asigna la busqueda desde el nodo de abajo de la cabecera de company
        NodoMatriz* tempCompany = companyNodo->getAbajo();
        // Se recorre la lista de company hacía abajo
        while (tempCompany != nullptr) {
            NodoMatriz* tempUsuario = tempCompany->getDerecha();
            // Se recorre la lista de usuarios de la company
            while (tempUsuario != nullptr) {
                // Se ve si la cabecera de tempUsuario es igual a la cabecera que se busca de depto
                if (buscarCabeceraHorizontal(tempUsuario)->getCabecera() == deptoNodo->getCabecera()) {
                    nuevoUsuario->setAbajo(tempUsuario);
                    tempUsuario->setArriba(nuevoUsuario);
                    break;
                }
                tempUsuario = tempUsuario->getDerecha();
            }
            tempCompany = tempCompany->getAbajo();
        }
        // relación de arriba
        tempCompany = companyNodo->getArriba();
        // Se recorre la lista de company hacía arriba
        while (tempCompany != nullptr) {
            NodoMatriz* tempUsuario = tempCompany->getDerecha();
            // Se recorre la lista de usuarios de la company
            while (tempUsuario != nullptr) {
                // Se ve si la cabecera de tempUsuario es igual a la cabecera que se busca de depto
                if (buscarCabeceraHorizontal(tempUsuario)->getCabecera() == deptoNodo->getCabecera()) {
                    nuevoUsuario->setArriba(tempUsuario);
                    tempUsuario->setAbajo(nuevoUsuario);
                    break;
                }
                tempUsuario = tempUsuario->getDerecha();

            }
            tempCompany = tempCompany->getArriba();
        }
}
// Depto en medio y company al final
void Matriz::deptoMidCompanyFin(NodoMatriz* deptoNodo, NodoMatriz* companyNodo, NodoMatriz* nuevoUsuario) {
    NodoMatriz* auxDepto = deptoNodo;
    while (auxDepto->getAbajo()) {
        auxDepto = auxDepto->getAbajo();
    }
    // relación de arriba
    auxDepto->setAbajo(nuevoUsuario);
    nuevoUsuario->setArriba(auxDepto);

    // relación de derecha
    // Se asigna la busqueda desde el nodo de la derecha de la cabecera de depto
    NodoMatriz* tempDepto = deptoNodo->getDerecha();
    // Se recorre la lista de depto hacía la derecha
    while (tempDepto != nullptr) {
        NodoMatriz* tempUsuario = tempDepto->getAbajo();
        // Se recorre la lista de usuarios de los depto's
        while (tempUsuario != nullptr) {
            // Se ve si la cabecera de tempUsuario es igual a la cabecera que se busca de company
            if (buscarCabeceraVertical(tempUsuario)->getCabecera() == companyNodo->getCabecera()) {
                nuevoUsuario->setDerecha(tempUsuario);
                tempUsuario->setIzquierda(nuevoUsuario);
                break;
            }
            tempUsuario = tempUsuario->getAbajo();
        }
        tempDepto = tempDepto->getDerecha();
    }

    // relación de izquierda
    // Se asigna la busqueda desde el nodo de la izquierda de la cabecera de depto
    tempDepto = deptoNodo->getIzquierda();
    // Se recorre la lista de depto hacía la izquierda
    while (tempDepto != nullptr) {
        NodoMatriz* tempUsuario = tempDepto->getAbajo();
        // Se recorre la lista de usuarios de los depto's
        while (tempUsuario != nullptr) {
            // Se ve si la cabecera de tempUsuario es igual a la cabecera que se busca de company
            if (buscarCabeceraVertical(tempUsuario)->getCabecera() == companyNodo->getCabecera()) {
                nuevoUsuario->setIzquierda(tempUsuario);
                tempUsuario->setDerecha(nuevoUsuario);
                break;
            }
            tempUsuario = tempUsuario->getAbajo();
        }
        tempDepto = tempDepto->getIzquierda();
    }
}
// Insertar un usuario con depto y company en medio
void Matriz::deptoCompanyMid(NodoMatriz* deptoNodo, NodoMatriz* companyNodo, NodoMatriz* nuevoUsuario) {
    // relación de arriba
    NodoMatriz* tempCompany = companyNodo->getArriba();
    // se verifica si la company tiene nodos arriba
    if (tempCompany == inicial) {
        nuevoUsuario->setArriba(deptoNodo);
        deptoNodo->setAbajo(nuevoUsuario);
    } else if (tempCompany != nullptr) {
        // se recorre la lista de company hacía arriba
        while (tempCompany != nullptr) {
            NodoMatriz* tempUsuario = tempCompany->getDerecha();
            // Se recorre la lista de usuarios de la company
            while (tempUsuario != nullptr) {
                // Se ve si la cabecera de tempUsuario es igual a la cabecera que se busca de depto
                if (buscarCabeceraHorizontal(tempUsuario)->getCabecera() == deptoNodo->getCabecera()) {
                    nuevoUsuario->setArriba(tempUsuario);
                    tempUsuario->setAbajo(nuevoUsuario);
                    tempUsuario = nullptr;
                }
                if (tempUsuario != nullptr) {
                    tempUsuario = tempUsuario->getDerecha();
                } else {
                    tempCompany = nullptr;
                    break;
                }
            }
            if (tempCompany != nullptr) {
                tempCompany = tempCompany->getArriba();
            } else {
                break;
            }
        }
    }

    // relación de abajo
    // Se asigna la busqueda desde el nodo de abajo de la cabecera de company
    tempCompany = companyNodo->getAbajo();
    // se verifica si la company tiene nodos abajo
    if (tempCompany != nullptr) {
        // Se recorre la lista de company hacía abajo
        while (tempCompany != nullptr) {
            NodoMatriz* tempUsuario = tempCompany->getDerecha();
            // Se recorre la lista de usuarios de la company
            while (tempUsuario != nullptr) {
                // Se ve si la cabecera de tempUsuario es igual a la cabecera que se busca de depto
                if (buscarCabeceraHorizontal(tempUsuario)->getCabecera() == deptoNodo->getCabecera()) {
                    nuevoUsuario->setAbajo(tempUsuario);
                    tempUsuario->setArriba(nuevoUsuario);
                    tempUsuario = nullptr;
                }
                if (tempUsuario != nullptr) {
                    tempUsuario = tempUsuario->getDerecha();
                } else {
                    tempCompany = nullptr;
                    break;
                }
            }
            if (tempCompany != nullptr) {
                tempCompany = tempCompany->getAbajo();
            } else {
                break;
            }
        }
    }

    // relación de derecha
    // Se asigna la busqueda desde el nodo de la derecha de la cabecera de depto
    NodoMatriz* tempDepto = deptoNodo->getDerecha();
    // Se recorre la lista de depto hacía la derecha
    while (tempDepto != nullptr) {
        NodoMatriz* tempUsuario = tempDepto->getAbajo();
        // Se recorre la lista de usuarios de los depto's
        while (tempUsuario != nullptr) {
            // Se ve si la cabecera de tempUsuario es igual a la cabecera que se busca de company
            if (buscarCabeceraVertical(tempUsuario)->getCabecera() == companyNodo->getCabecera()) {
                nuevoUsuario->setDerecha(tempUsuario);
                tempUsuario->setIzquierda(nuevoUsuario);
                tempUsuario = nullptr;
            }
            if (tempUsuario != nullptr) {
                tempUsuario = tempUsuario->getAbajo();
            } else {
                tempDepto = nullptr;
                break;
            }
        }
        if (tempDepto != nullptr) {
            tempDepto = tempDepto->getDerecha();
        } else {
            break;
        }
    }

    // relación de izquierda
    // Se asigna la busqueda desde el nodo de la izquierda de la cabecera de depto
    tempDepto = deptoNodo->getIzquierda();
    // Se recorre la lista de depto hacía la izquierda
    if (tempDepto == inicial) {
        nuevoUsuario->setIzquierda(companyNodo);
        companyNodo->setDerecha(nuevoUsuario);
    } else if (tempDepto != nullptr) {
        while (tempDepto != nullptr) {
            NodoMatriz* tempUsuario = tempDepto->getAbajo();
            // Se recorre la lista de usuarios de los depto's
            while (tempUsuario != nullptr) {
                // Se ve si la cabecera de tempUsuario es igual a la cabecera que se busca de company
                if (buscarCabeceraVertical(tempUsuario)->getCabecera() == companyNodo->getCabecera()) {
                    nuevoUsuario->setIzquierda(tempUsuario);
                    tempUsuario->setDerecha(nuevoUsuario);
                    tempUsuario = nullptr;
                }
                if (tempUsuario != nullptr) {
                    tempUsuario = tempUsuario->getAbajo();
                } else {
                    tempDepto = nullptr;
                    break;
                }
            }
            if (tempDepto != nullptr) {
                tempDepto = tempDepto->getIzquierda();
            } else {
                break;
            }
        }
    }
}
/*
 ===================================================================================================================
 [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[      FUNCIONES DE REPORTE      ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
 ===================================================================================================================
 */
// Reporte de Matriz Dispersa
void Matriz::reporteMatrizDispersa() {
    NodoMatriz* aux = inicial;
    NodoMatriz* aux2 = nullptr;

    std::string dot = "";
    dot += "digraph G{\n";
    dot += "{node[shape = box, group = a];\n";

    // recorrer cabeceras company / verticales
    while (aux != nullptr) {
        dot += "\"" + aux->getCabecera() + "\" -> ";

        aux2 = aux;
        aux = aux->getAbajo();
    }
    aux = aux2->getArriba();
    while (aux != nullptr) {
        if (aux != inicial) {
            dot += "\"" + aux->getCabecera() + "\" -> ";
        } else {
            dot += "\"" + aux->getCabecera() + "\"\n}";
            break;
        }
        aux = aux->getArriba();
    }

    dot += "\n{";
    dot += "\nrank=same;";
    dot += "\nnode[shape = box, group = true];\n";


    // recorriendo cabeceras depto / horizontales
    aux = inicial;
    while (aux != nullptr) {
        dot += "\"" + aux->getCabecera() + "\" -> ";

        aux2 = aux;
        aux = aux->getDerecha();
    }

    aux = aux2->getIzquierda();

    while (aux != nullptr) {
        if (aux != inicial) {
            dot += "\"" + aux->getCabecera() + "\" -> ";
        } else {
            dot += "\"" + aux->getCabecera() + "\"\n}";
            break;
        }
        aux = aux->getIzquierda();
    }
    dot += "\nnode[shape = box, group = true];\n";


    // recorrer las filas de la matriz
    NodoMatriz* aux3 = inicial->getAbajo();
    aux3 = inicial->getAbajo();
    aux = aux3;
    while (aux != nullptr) {
        if (aux->getAbajo() != nullptr) {
            dot += "{rank=same;";
        } else {
            dot += "{rank=max;";
        }
        while (aux != nullptr) {
            if (aux->getUsuario() != nullptr) {
                dot += "\"" + aux->getUsuario()->getUsuario() + "\" ->";
            } else {
                dot += "\"" + aux->getCabecera() + "\" ->";
            }
            aux2 = aux;
            aux = aux->getDerecha();
        }
        aux = aux2->getIzquierda();
        while (aux != nullptr) {
            if (aux != aux3) {
                if (aux->getUsuario() != nullptr) {
                    dot += "\"" + aux->getUsuario()->getUsuario() + "\" ->";
                } else {
                    dot += "\"" + aux->getCabecera() + "\" ->";
                }
            } else {
                dot += "\"" + aux->getCabecera() + "\"}\n";
                break;
            }
            aux = aux->getIzquierda();
        }
        aux = aux->getAbajo();
        aux3 = aux3->getAbajo();
    }


    // recorrer columnas de la matriz
    aux3 = inicial->getDerecha();
    aux = aux3;
    while (aux != nullptr) {
        while (aux != nullptr) {
            if (aux->getUsuario() != nullptr) {
                dot += "\"" + aux->getUsuario()->getUsuario() + "\" ->";
            } else {
                dot += "\"" + aux->getCabecera() + "\" ->";
            }
            aux2 = aux;
            aux = aux->getAbajo();
        }
        aux = aux2->getArriba();
        while (aux != nullptr) {
            if (aux != aux3) {
                if (aux->getUsuario() != nullptr) {
                    dot += "\"" + aux->getUsuario()->getUsuario() + "\" ->";
                } else {
                    dot += "\"" + aux->getCabecera() + "\" ->";
                }
            } else {
                dot += "\"" + aux->getCabecera() + "\"\n";
                break;
            }
            aux = aux->getArriba();
        }
        aux = aux->getDerecha();
        aux3 = aux3->getDerecha();
    }

    dot += "\n}";

    std::ofstream file;
    file.open("../Graficas/reporteMatrizDispersa.txt");

    if (file.is_open()) {
        file << dot;
        file.close();
    }
    system("dot -Tpng ../Graficas/reporteMatrizDispersa.txt -o ../Graficas/reporteMatrizDispersa.png");

}
// Reporte de Activos de un Depto
void Matriz::reporteActivosDepto(const std::string& depto) {
    std::string dot = "digraph{ \nrankdir = TB;\nnode[shape = box, color = red]\n" + depto + "\n";
    NodoMatriz* deptoNodo = deptoBuscar(depto);
    if (deptoNodo == nullptr) {
        std::cout << "Departamento no encontrado." << std::endl;
        return;
    }
    NodoMatriz* aux = deptoNodo->getAbajo();
    NodoMatriz* aux2;
    while (aux != nullptr) {
        aux2 = aux;
        while (aux2 != nullptr) {
            dot += "node[shape = box];\n " + aux2->getUsuario()->getUsuario() + ";\n node[shape = circle]; \n";
            dot += aux2->getUsuario()->getArbol()->activosUsuarioPre(aux2->getUsuario()->getArbol()->raiz, dot);
            aux2 = aux2->getAtras();
        }
        aux = aux->getAbajo();
    }
    dot += "\n}";

    std::ofstream file;
    file.open("../Graficas/reporteActivosDepto.txt");
    if (file.is_open()) {
        file << dot;
        file.close();
    }

    system("dot -Tpng ../Graficas/reporteActivosDepto.txt -o ../Graficas/reporteActivosDepto.png");
}
// Reporte de Activos de una Company
void Matriz::reporteActivosCompany(const std::string& empresa) {
    std::string dot = "digraph{ \nrankdir = TB;\nnode[shape = box, color = red]\n" + empresa + "\n";
    NodoMatriz* nodoEmpresa = companyBuscar(empresa);
    if (nodoEmpresa == nullptr) {
        std::cout << "Company no encontrada." << std::endl;
        return;
    }
    NodoMatriz* aux = nodoEmpresa->getDerecha();
    NodoMatriz* aux2;
    while (aux != nullptr) {
        aux2 = aux;
        while (aux2 != nullptr) {
            dot += "node[shape = box];\n " + aux2->getUsuario()->getUsuario() + ";\n node[shape = circle]; \n";
            dot += aux2->getUsuario()->getArbol()->activosUsuarioPre(aux2->getUsuario()->getArbol()->raiz, dot);
            aux2 = aux2->getAtras();
        }
        aux = aux->getDerecha();
    }
    dot += "\n}";

    std::ofstream file;
    file.open("../Graficas/reporteActivosCompany.txt");
    if (file.is_open()) {
        file << dot;
        file.close();
    }

    system("dot -Tpng ../Graficas/reporteActivosCompany.txt -o ../Graficas/reporteActivosCompany.png");
}

// Lista los usuarios de un depto y una company
void Matriz::listarUsuarios(const std::string& depto, const std::string& company) {
    NodoMatriz* deptoNodo = deptoBuscar(depto);
    if (deptoNodo == nullptr) {
        std::cout << "Departamento no encontrado." << std::endl;
        return;
    }

    NodoMatriz* companyNodo = existeEn(deptoNodo, company);
    if (companyNodo == nullptr) {
        std::cout << "Compañía no encontrada en el departamento especificado." << std::endl;
        return;
    }

    NodoMatriz* usuarioNodo = companyNodo;
    while (usuarioNodo != nullptr) {
        std::cout << "Usuario: " << usuarioNodo->getUsuario()->getUsuario() << std::endl;
        usuarioNodo = usuarioNodo->getAtras();
    }
}
// Lista los usuarios de una compañía
void Matriz::listarUsuariosPorCompany(const std::string& company) {
    NodoMatriz* companyNodo = companyBuscar(company);
    if (companyNodo == nullptr) {
        std::cout << "Compañía no encontrada." << std::endl;
        return;
    }
    std::cout << "Usuarios de: " << company << std::endl;
    NodoMatriz* usuariosNodo = companyNodo->getDerecha();
    while (usuariosNodo != nullptr) {
        std::cout << "Departamento: " << buscarCabeceraHorizontal(usuariosNodo)->getCabecera() << std::endl;
        NodoMatriz* usuarioNodo = usuariosNodo;
        while (usuarioNodo != nullptr) {
            std::cout << "Usuario: " << usuarioNodo->getUsuario()->getUsuario() << std::endl;
            usuarioNodo = usuarioNodo->getAtras();
        }
        usuariosNodo = usuariosNodo->getDerecha();
    }
}
// Lista los usuarios de un departamento
void Matriz::listarUsuariosPorDepto(const std::string& depto) {
    NodoMatriz* deptoNodo = deptoBuscar(depto);
    if (deptoNodo == nullptr) {
        std::cout << "Departamento no encontrado." << std::endl;
        return;
    }

    std::cout << "Usuarios de: " << depto << std::endl;
    NodoMatriz* usuariosNodo = deptoNodo->getAbajo();
    while (usuariosNodo != nullptr) {
        std::cout << "Compañía: " << buscarCabeceraVertical(usuariosNodo)->getCabecera() << std::endl;
        NodoMatriz* usuarioNodo = usuariosNodo;
        while (usuarioNodo != nullptr) {
            std::cout << "Usuario: " << usuarioNodo->getUsuario()->getUsuario() << std::endl;
            usuarioNodo = usuarioNodo->getAtras();
        }
        usuariosNodo = usuariosNodo->getAbajo();
    }
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