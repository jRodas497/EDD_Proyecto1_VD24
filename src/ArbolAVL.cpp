//
// Created by Usuario on 5/12/2024.
//
#include "../includes/ArbolAVL.h"

#include <iostream>
#include <fstream>

ArbolAVL::ArbolAVL() {
    raiz = nullptr;
}
// Iniciar proceso de insercion
void ArbolAVL::insertar(Activo* activo) {
    insertar(activo, raiz); }
// Incersión de forma recursiva
void ArbolAVL::insertar(Activo* activo, NodoAVL*& raiz) {
    if (raiz != nullptr) {

        if (activo->getId() > raiz->getActivo()->getId()) {
            if (raiz->getHijoDer() != nullptr) {
                insertar(activo, raiz->getHijoDer());
                if (facEquilibrio(altoDer(raiz->getHijoDer()), altoIzq(raiz->getHijoIzq())) == 2) {
                    if (activo->getId() > raiz->getHijoDer()->getActivo()->getId()) {
                        raiz = simpleIzq(raiz);
                    } else {
                        raiz = dobleIzq(raiz);
                    }
                }
            } else {
                raiz->setHijoDer(new NodoAVL(activo));
            }
        } else if (activo->getId() < raiz->getActivo()->getId()) {
            if (raiz->getHijoIzq() != nullptr) {
                insertar(activo, raiz->getHijoIzq());
                if (facEquilibrio(altoIzq(raiz->getHijoIzq()), altoDer(raiz->getHijoDer())) == 2) {
                    if (activo->getId() < raiz->getHijoIzq()->getActivo()->getId()) {
                        raiz = simpleDer(raiz);
                    } else {
                        raiz = dobleDer(raiz);
                    }
                }
            } else {
                raiz->setHijoIzq(new NodoAVL(activo));
            }
        }
        int mayor = mayorHijo(altoDer(raiz->getHijoDer()), altoIzq(raiz->getHijoIzq()));
        raiz->setAlto(mayor + 1);
    } else {
        raiz = new NodoAVL(activo);
    }
}

// Iniciar proceso de eliminacion
void ArbolAVL::eliminar(const std::string& id) {
    // Localizar el nodo a eliminar
    NodoAVL* eliminado = buscar(id, raiz);
    if (eliminado != nullptr) {
        std::string idEliminado = eliminado->getActivo()->getId();
        std::string nombre = eliminado->getActivo()->getNombre();
        std::string descripcion = eliminado->getActivo()->getDescripcion();
        std::string diasMax = eliminado->getActivo()->getDiasMax();
        // Suprimir el nodo del árbol
        raiz = eliminar(id, raiz);
        if (raiz != nullptr) {
            std::cout << "\nActivo Suprimido: " << std::endl << " / ID: " << idEliminado << std::endl;
            std::cout << "  / Nombre: " << nombre << std::endl << "   / Descripcion: " << descripcion  << std::endl;
            std::cout << "    / Dias Max: " << diasMax << "\n" << std::endl;
        }
    } else {
        std::cout << "\nEl activo no existe...";
    }
}
// Realiza el proceso de eliminación de forma recursiva
NodoAVL* ArbolAVL::eliminar(const std::string& id, NodoAVL*& raiz) {
    if (raiz != nullptr) {
        if (raiz->getActivo()->getId() == id) {
            if (hoja(raiz)) {
                // Eliminar nodo hoja
                raiz = nullptr;
                return raiz;
            } else if (raiz->getHijoDer() == nullptr && raiz->getHijoIzq() != nullptr) {
                // Eliminar nodo con solo hijo izquierdo
                return raiz->getHijoIzq();
            } else if (raiz->getHijoIzq() == nullptr && raiz->getHijoDer() != nullptr) {
                // Eliminar nodo con solo hijo derecho
                return raiz->getHijoDer();
            } else {
                // Eliminar nodo con dos hijos
                NodoAVL* masDerecha = buscarMasDerecha(raiz->getHijoIzq());
                if (masDerecha != nullptr) {
                    raiz = eliminar(masDerecha->getActivo()->getId(), raiz);
                    NodoAVL* aux = buscar(id, raiz);
                    aux->setActivo(masDerecha->getActivo());
                    if (facEquilibrio(altoIzq(raiz->getHijoIzq()), altoDer(raiz->getHijoDer())) == 2) {
                        // Balancear árbol
                        raiz = simpleDer(raiz);
                    }
                    return raiz;
                }
            }
        } else if (id > raiz->getActivo()->getId()) {
            // Eliminar nodo en subárbol derecho
            raiz->setHijoDer(eliminar(id, raiz->getHijoDer()));
            int mayor = mayorHijo(altoDer(raiz->getHijoDer()), altoIzq(raiz->getHijoIzq()));
            raiz->setAlto(mayor + 1);
            if (facEquilibrio(altoIzq(raiz->getHijoIzq()), altoDer(raiz->getHijoDer())) == 2) {
                // Balancear árbol
                raiz = simpleDer(raiz);
            }
            return raiz;
        } else {
            // Eliminar nodo en subárbol izquierdo
            raiz->setHijoIzq(eliminar(id, raiz->getHijoIzq()));
            int mayor = mayorHijo(altoDer(raiz->getHijoDer()), altoIzq(raiz->getHijoIzq()));
            raiz->setAlto(mayor + 1);
            if (facEquilibrio(altoDer(raiz->getHijoDer()), altoIzq(raiz->getHijoIzq())) == 2) {
                // Balancear árbol
                raiz = simpleIzq(raiz);
            }
            return raiz;
        }
    } else {
        std::cout << "No hay nada que eliminar, Arbol vacio" << std::endl;
    }
    return nullptr;
}

// Recorrer el sub-árbol más a la derecha
NodoAVL* ArbolAVL::buscarMasDerecha(NodoAVL* nodo) {
    NodoAVL* aux = nodo;
    while (aux->getHijoDer() != nullptr) {
        aux = aux->getHijoDer();
    }
    return aux;
}
// Recorrer el sub-árbol más a la izquierda
NodoAVL* ArbolAVL::buscarMasIzquierda(NodoAVL* nodo) {
    NodoAVL* aux = nodo;
    while (aux->getHijoIzq() != nullptr) {
        aux = aux->getHijoIzq();
    }
    return aux;
}

// Buscar un nodo en el árbol para modificar la descripción
bool ArbolAVL::modificarActivo(const std::string& id, const std::string& descripcion) {
    // Localizar el nodo del activo
    NodoAVL* activo = buscar(id, raiz);
    // Si el nodo es encontrado se modifica la descripción
    if (activo != nullptr) {
        // Actualizar la descripción del activo
        activo->getActivo()->setDescripcion(descripcion);
        std::cout << "\nActivo Modificado:" << std::endl << " / ID = " << activo->getActivo()->getId() << std::endl;
        std::cout << "  / Nombre = " << activo->getActivo()->getNombre() << std::endl << "   / Descripción = " << activo->getActivo()->getDescripcion() << "    / Dias Max = " << activo->getActivo()->getDiasMax() <<"\n" << std::endl;
        return true;
    }
    return false;
}

// Buscar un nodo en el árbol | No recursivo
void ArbolAVL::buscar(const std::string& id) {
    NodoAVL* busqueda = buscar(id, raiz);
    if (busqueda != nullptr) {
        std::cout << "El valor [" << id << "] encontrado fue: " << busqueda->getActivo()->getId() << std::endl;
    } else {
        std::cout << "El valor [" << id << "] buscado no existe" << std::endl;
    }
}
// Buscar un nodo en el árbol de forma recursiva
NodoAVL* ArbolAVL::buscar(const std::string& id, NodoAVL* nodo) {
    // Verificar si el nodo actual no es nulo
    if (nodo != nullptr) {
        // Comparar el ID del activo con el ID buscado
        if (nodo->getActivo()->getId() == id) {
            return nodo;
        } else if (id > nodo->getActivo()->getId()) {
            // Buscar en el subárbol derecho
            return buscar(id, nodo->getHijoDer());
        } else {
            // Buscar en el subárbol izquierdo
            return buscar(id, nodo->getHijoIzq());
        }
    } else {
        // Retornar nulo si el nodo no existe
        return nullptr;
    }
}

// Verificar si un nodo es hoja
bool ArbolAVL::hoja(NodoAVL* nodo) {
    // Verificar si el nodo no es nulo
    if (nodo != nullptr) {
        // Retornar verdadero si el nodo no tiene hijos
        return nodo->getHijoDer() == nullptr && nodo->getHijoIzq() == nullptr;
    }
    // Retornar falso si el nodo es nulo
    return false;
}

// Rotación simple a la izquierda
NodoAVL* ArbolAVL::simpleIzq(NodoAVL* nodo) {
    // Guardar el hijo derecho del nodo
    NodoAVL* aux = nodo->getHijoDer();

    // Realizar la rotación
    nodo->setHijoDer(aux->getHijoIzq());
    aux->setHijoIzq(nodo);

    // Actualizar las alturas de los nodos
    nodo->setAlto(mayorHijo(altoDer(nodo->getHijoDer()), altoIzq(nodo->getHijoIzq())) + 1);
    aux->setAlto(mayorHijo(altoDer(aux->getHijoDer()), altoIzq(aux->getHijoIzq())) + 1);

    // Retornar el nuevo nodo raíz
    return aux;
}
// Rotación simple a la derecha
NodoAVL* ArbolAVL::simpleDer(NodoAVL* nodo) {
    // Guardar el hijo izquierdo del nodo
    NodoAVL* aux = nodo->getHijoIzq();

    // Realizar la rotación
    nodo->setHijoIzq(aux->getHijoDer());
    aux->setHijoDer(nodo);

    // Actualizar las alturas de los nodos
    nodo->setAlto(mayorHijo(altoDer(nodo->getHijoDer()), altoIzq(nodo->getHijoIzq())) + 1);
    aux->setAlto(mayorHijo(altoDer(aux->getHijoDer()), altoIzq(aux->getHijoIzq())) + 1);

    // Retornar el nuevo nodo raíz
    return aux;
}
// Rotación doble a la derecha
NodoAVL* ArbolAVL::dobleDer(NodoAVL* nodo) {
    // Realizar una rotación simple a la izquierda en el hijo izquierdo
    nodo->setHijoIzq(simpleIzq(nodo->getHijoIzq()));
    // Realizar una rotación simple a la derecha en el nodo
    return simpleDer(nodo);
}
// Rotación doble a la izquierda
NodoAVL* ArbolAVL::dobleIzq(NodoAVL* nodo) {
    // Realizar una rotación simple a la derecha en el hijo derecho
    nodo->setHijoDer(simpleDer(nodo->getHijoDer()));
    // Realizar una rotación simple a la izquierda en el nodo
    return simpleIzq(nodo);
}

// Obtener la altura del subárbol derecho
bool ArbolAVL::preOrden(bool bandera) {
    if (raiz != nullptr) {
        // Llamar a la función recursiva preOrden con la raíz del árbol
        preOrden(raiz, bandera);
        return true;
    } else {
        return false;
    }
}
// Recorrer el árbol en preorden de forma recursiva
void ArbolAVL::preOrden(NodoAVL* nodo, bool bandera) {
    if (nodo != nullptr) {
        if (bandera) {
            // Si el activo no está rentado (disponible), imprimir sus detalles
            if (!nodo->getActivo()->getRentado()) {
                std::cout << "\n>> ID = " << nodo->getActivo()->getId() << "; Nombre = " << nodo->getActivo()->getNombre() << "; Dias Max = " << nodo->getActivo()->getDiasMax();
            }
        } else {
            // Si el activo está rentado (no disponible), imprimir sus detalles
            if (nodo->getActivo()->getRentado()) {
                std::cout << "\n>> ID = " << nodo->getActivo()->getId() << "; Nombre = " << nodo->getActivo()->getNombre() << "; Dias Max = " << nodo->getActivo()->getDiasMax();
            }
        }
        // Recorrer el subárbol izquierdo
        preOrden(nodo->getHijoIzq(), bandera);
        // Recorrer el subárbol derecho
        preOrden(nodo->getHijoDer(), bandera);
    }
}
// Listar en consola los activos (en general) de un usuario
void ArbolAVL::listarActivosUsuario(const std::string& usuario) {
    listarActivosUsuario(raiz, usuario);
}
void ArbolAVL::listarActivosUsuario(NodoAVL* nodo, const std::string& usuario) {
    if (nodo != nullptr) {
        if (nodo->getActivo()->getUsuario() == usuario) {
            std::cout << "ID: " << nodo->getActivo()->getId() << ", Nombre: " << nodo->getActivo()->getNombre() << ", Descripción: " << nodo->getActivo()->getDescripcion() << std::endl;
        }
        listarActivosUsuario(nodo->getHijoIzq(), usuario);
        listarActivosUsuario(nodo->getHijoDer(), usuario);
    }
}

// Obtener la altura del subárbol derecho
int ArbolAVL::altoDer(NodoAVL* der) {
    if (der != nullptr) {
        return der->getAlto();
    }
    return -1;
}
// Obtener la altura del subárbol izquierdo
int ArbolAVL::altoIzq(NodoAVL* izq) {
    if (izq != nullptr) {
        return izq->getAlto();
    }
    return -1;
}

// Obtener el mayor valor entre dos hijos
int ArbolAVL::mayorHijo(int der, int izq) {
    return (der > izq) ? der : izq;
}

// Calcular el factor de equilibrio entre dos hijos
int ArbolAVL::facEquilibrio(int hijoA, int hijoB) {
    return hijoA - hijoB;
}

// Imprimir los activos de un usuario
void ArbolAVL::activosUsuario(NodoAVL* usuarioActual, std::string usuario) {
    // Crear el encabezado del archivo DOT
    std::string dot = "digraph{ \nrankdir = TB;\n node[shape = box]\n " + usuario + "\n node[shape = circle]; \n";
    // Agregar los activos del usuario al archivo DOT
    dot += activosUsuarioPre(usuarioActual, dot) + "\n}";

    // Abrir el archivo para escribir
    std::ofstream file;
    file.open("../Graficas/activosUsuario.txt");

    // Verificar si el archivo se abrió correctamente
    if (file.is_open()) {
        // Escribir el contenido en el archivo
        file << dot;
        // Cerrar el archivo
        file.close();
    }

    // Generar la imagen PNG usando el archivo DOT
    system("dot -Tpng ../Graficas/activosUsuario.txt -o ../Graficas/activosUsuario.png");
}

std::string ArbolAVL::activosUsuarioPre(NodoAVL* usuarioActual, std::string dot) {
    std::string dot2 = "";
    if (usuarioActual != nullptr && !usuarioActual->getActivo()->getRentado()) {
        // Agregar nodo disponible (color azul)
        dot2 += "\"" + usuarioActual->getActivo()->getId() + "\"" + "[label = <" + usuarioActual->getActivo()->getId() + "<br />" + usuarioActual->getActivo()->getNombre() + "> color = blue];\n";

        // Recorrer el subárbol izquierdo
        if (usuarioActual->getHijoIzq() != nullptr) {
            dot2 += activosUsuarioPre(usuarioActual->getHijoIzq(), dot2) + "\"" + usuarioActual->getActivo()->getId() + "\"" + "->" + "\"" + usuarioActual->getHijoIzq()->getActivo()->getId() + "\"" + ";\n";
        }
        // Recorrer el subárbol derecho
        if (usuarioActual->getHijoDer() != nullptr) {
            dot2 += activosUsuarioPre(usuarioActual->getHijoDer(), dot2) + "\"" + usuarioActual->getActivo()->getId() + "\"" + "->" + "\"" + usuarioActual->getHijoDer()->getActivo()->getId() + "\"" + ";\n";
        }
    } else if (usuarioActual != nullptr && usuarioActual->getActivo()->getRentado()) {
        // Agregar nodo no disponible (color rojo)
        dot2 += "\"" + usuarioActual->getActivo()->getId() + "\"" + "[label = <" + usuarioActual->getActivo()->getId() + "<br />" + usuarioActual->getActivo()->getNombre() + "> color = red];\n";

        // Recorrer el subárbol izquierdo
        if (usuarioActual->getHijoIzq() != nullptr) {
            dot2 += activosUsuarioPre(usuarioActual->getHijoIzq(), dot2) + "\"" + usuarioActual->getActivo()->getId() + "\"" + "->" + "\"" + usuarioActual->getHijoIzq()->getActivo()->getId() + "\"" + ";\n";
        }
        // Recorrer el subárbol derecho
        if (usuarioActual->getHijoDer() != nullptr) {
            dot2 += activosUsuarioPre(usuarioActual->getHijoDer(), dot2) + "\"" + usuarioActual->getActivo()->getId() + "\"" + "->" + "\"" + usuarioActual->getHijoDer()->getActivo()->getId() + "\"" + ";\n";
        }
    }

    return dot2;
}
void ArbolAVL::listarActivosRentados(NodoAVL* nodo) {
    if (nodo != nullptr) {
        listarActivosRentados(nodo->getHijoIzq());
        if (nodo->getActivo()->getRentado()) {
            std::cout << " ID: " << nodo->getActivo()->getId() << " | Nombre: " << nodo->getActivo()->getNombre() << " | Descripción: " << nodo->getActivo()->getDescripcion() << " | Días de Renta: " << nodo->getActivo()->getDiasRenta() << std::endl;
        }
        listarActivosRentados(nodo->getHijoDer());
    }
}