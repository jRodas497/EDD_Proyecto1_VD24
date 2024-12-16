//
// Created by Usuario on 11/12/2024.
//
#include "../includes/ListaTransaccion.h"
#include <iostream>
#include <fstream>

// Constructor
ListaTransaccion::ListaTransaccion() : ini(nullptr), fin(nullptr) {}

// Verifica si la lista está vacía
void ListaTransaccion::insertarTransaccion(Transaccion* transaccion) {
    NodoTransaccion* elemento = new NodoTransaccion(transaccion);

    if (!estaVacia()) {
        NodoTransaccion* aux = ini;

        if (aux == ini && aux == fin) {
            if (elemento->getTransaccion()->getId() > aux->getTransaccion()->getId()) {
                insertarAlFinal(elemento);
            } else if (elemento->getTransaccion()->getId() < aux->getTransaccion()->getId()) {
                insertarAlFrente(elemento);
            }
        } else {
            while (aux != fin) {
                if (elemento->getTransaccion()->getId() > aux->getTransaccion()->getId() &&
                    elemento->getTransaccion()->getId() < aux->getSig()->getTransaccion()->getId()) {
                    insertarAlMedio(elemento, aux->getSig());
                    return;
                    } else if (elemento->getTransaccion()->getId() < aux->getTransaccion()->getId()) {
                        insertarAlFrente(elemento);
                        return;
                    }
                aux = aux->getSig();
            }
            insertarAlFinal(elemento);
        }
    } else {
        ini = fin = elemento;
        ini->setSig(ini);
        ini->setAnt(ini);
    }
}

// Método para insertar al final
void ListaTransaccion::insertarAlFinal(NodoTransaccion* elemento) {
    if (estaVacia()) {
        ini = fin = elemento;
        ini->setSig(ini);
        ini->setAnt(ini);
    } else {
        elemento->setAnt(fin);
        elemento->setSig(ini);
        fin->setSig(elemento);
        ini->setAnt(elemento);
        fin = elemento;
    }
}

// Método para insertar al frente
void ListaTransaccion::insertarAlFrente(NodoTransaccion* elemento) {
    if (estaVacia()) {
        ini = fin = elemento;
        ini->setSig(ini);
        ini->setAnt(ini);
    } else {
        elemento->setSig(ini);
        elemento->setAnt(fin);
        ini->setAnt(elemento);
        fin->setSig(elemento);
        ini = elemento;
    }
}
// Método para insertar al medio
void ListaTransaccion::insertarAlMedio(NodoTransaccion* elemento, NodoTransaccion* transaccionSiguiente) {
    if (transaccionSiguiente == ini) {
        insertarAlFrente(elemento);
    } else if (transaccionSiguiente == nullptr) {
        insertarAlFinal(elemento);
    } else {
        NodoTransaccion* anterior = transaccionSiguiente->getAnt();
        anterior->setSig(elemento);
        elemento->setAnt(anterior);
        elemento->setSig(transaccionSiguiente);
        transaccionSiguiente->setAnt(elemento);
    }
}
// Metodo para verificar si la lista esta vacia
bool ListaTransaccion::recorrerLista(string usuario) {
    if (!estaVacia()) {
        NodoTransaccion* aux = ini;
        do {
            //if (aux->getTransaccion()->getNombreUsuario() == usuario && !aux->getTransaccion()->getIdActivo()->getRentado()) {
            std::cout << "Usuario: " << aux->getTransaccion()->getNombreUsuario() <<  std::endl;
            if (aux->getTransaccion()->getNombreUsuario() == usuario && aux->getTransaccion()->getIdActivo()->getRentado()) {
                std::cout << " >>ID = " << aux->getTransaccion()->getIdActivo()->getId() << "; Nombre = " << aux->getTransaccion()->getIdActivo()->getNombre() << "; Tiempo de Renta = " << aux->getTransaccion()->getDias() << std::endl;
            }
            aux = aux->getSig();
        } while (aux != ini);
    } else {
        std::cout << "No hay transacciones disponibles..." << std::endl;
        return false;
    }
    return true;
}

bool ListaTransaccion::estaVacia() const {
    return ini == nullptr;
}

void ListaTransaccion::reporteActivosRentadosUsuario(string usuario) {
    string dot = "digraph{ \nrankdir = LR;\n node[shape = box]; \n";
    dot = reporteActivosRentadosUsuario(dot, usuario);
    dot += "}";

    ofstream file;
    file.open("../Graficas/activosRentados.txt");

    if (file.is_open()) {
        file << dot;
        file.close();
    }

    system("dot -Tpng ../Graficas/activosRentados.txt -o ../Graficas/activosRentados.png");
}

string ListaTransaccion::reporteActivosRentadosUsuario(string dot, string usuario) {
    int contador = 0;
    if (!estaVacia()) {
        NodoTransaccion* aux = ini;
        // Primera pasada para crear los nodos
        do {
            if (aux->getTransaccion()->getNombreUsuario() == usuario && aux->getTransaccion()->getDias() != "") {
                contador++;
                dot += "activo" + to_string(contador) + "[label = <" + aux->getTransaccion()->getIdActivo()->getId() + " <br /> " + aux->getTransaccion()->getIdActivo()->getNombre() + ">]\n";
            }
            aux = aux->getSig();
        } while (aux != ini);
        // Reiniciar aux para la segunda pasada
        aux = ini;
        int contador2 = 0;
        // Segunda pasada para crear las conexiones
        do {
            if (aux->getTransaccion()->getNombreUsuario() == usuario && aux->getTransaccion()->getDias() != "" && contador2 < contador - 1) {
                contador2++;
                dot += "activo" + to_string(contador2) + "->activo" + to_string(contador2 + 1) + "\n";
            }
            aux = aux->getSig();
        } while (aux != ini);
        dot += usuario + "\n";
    } else {
        dot += "vacio;\n" + usuario + "\n";
    }
    return dot;
}

void ListaTransaccion::reporteTransacciones() {
    std::string dot = "digraph{ \nrankdir = LR;\n node[shape = box, color = red]; \n";
    if (!estaVacia()) {
        NodoTransaccion* aux = ini;
        do {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" +
                   (aux->getTransaccion()->getDias() != "" ? "RENTADO\n" : "DEVUELTO\n") +
                   aux->getTransaccion()->getIdActivo()->getNombre() + "\n" +
                   aux->getTransaccion()->getNombreUsuario() + "\"->\n";
            aux = aux->getSig();
        } while (aux != ini);

        // Eliminar la última flecha
        dot = dot.substr(0, dot.size() - 3);
    }
    dot += ";\n}";
    std::ofstream file;
    file.open("../Graficas/reporteTransaccionesOriginal.txt");

    if (file.is_open()) {
        file << dot;
        file.close();
    }
    system("dot -Tpng ../Graficas/reporteTransaccionesOriginal.txt -o ../Graficas/reporteTransaccionesOriginal.png");
}

void ListaTransaccion::reporteTransaccionesAscendente() {
    string dot = "digraph{ \nrankdir = LR;\n node[shape = box, color = red]; \n";
    NodoTransaccion* aux = ini;
    do {
        if (aux->getTransaccion()->getDias() != "") {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" + "RENTADO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"->\n";
        } else {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" + "DEVUELTO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"->\n";
        }
        aux = aux->getSig();
    } while (aux != ini);
    if (ini != fin) {
        if (ini->getTransaccion()->getDias() != "") {
            dot += "\"" + ini->getTransaccion()->getId() + "\n" + "RENTADO\n" + ini->getTransaccion()->getIdActivo()->getNombre() + "\n" + ini->getTransaccion()->getNombreUsuario() + "\"->\n";
        } else {
            dot += "\"" + ini->getTransaccion()->getId() + "\n" + "DEVUELTO\n" + ini->getTransaccion()->getIdActivo()->getNombre() + "\n" + ini->getTransaccion()->getNombreUsuario() + "\"->\n";
        }
    }
    aux = fin;
    do {
        if (aux->getTransaccion()->getDias() != "") {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" + "RENTADO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"->\n";
        } else {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" + "DEVUELTO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"->\n";
        }
        aux = aux->getAnt();
    } while (aux->getAnt() != fin);
    if (aux->getTransaccion()->getDias() != "") {
        dot += "\"" + aux->getTransaccion()->getId() + "\n" + "RENTADO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"";
    } else {
        dot += "\"" + aux->getTransaccion()->getId() + "\n" + "DEVUELTO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"";
    }
    dot += ";\n}";
    ofstream file;
    file.open("../Graficas/reporteTransaccionesAscendente.txt");
    if (file.is_open()) {
        file << dot;
        file.close();
    }
    system("dot -Tpng ../Graficas/reporteTransaccionesAscendente.txt -o ../Graficas/reporteTransaccionesAscendente.png");
}

void ListaTransaccion::reporteTransaccionesDescendente() {
    string dot = "digraph{ \nrankdir = LR;\n node[shape = box, color = red]; \n";
    NodoTransaccion* aux = fin;
    do {
        if (aux->getTransaccion()->getDias() != "") {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" + "RENTADO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"->\n";
        } else {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" + "DEVUELTO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"->\n";
        }
        aux = aux->getAnt();
    } while (aux != fin);
    if (ini != fin) {
        if (fin->getTransaccion()->getDias() != "") {
            dot += "\"" + fin->getTransaccion()->getId() + "\n" + "RENTADO\n" + fin->getTransaccion()->getIdActivo()->getNombre() + "\n" + fin->getTransaccion()->getNombreUsuario() + "\"->\n";
        } else {
            dot += "\"" + fin->getTransaccion()->getId() + "\n" + "DEVUELTO\n" + fin->getTransaccion()->getIdActivo()->getNombre() + "\n" + fin->getTransaccion()->getNombreUsuario() + "\"->\n";
        }
    }
    aux = ini;
    do {
        if (aux->getTransaccion()->getDias() != "") {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" + "RENTADO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"->\n";
        } else {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" + "DEVUELTO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"->\n";
        }
        aux = aux->getSig();
    } while (aux->getSig() != ini);

    if (aux->getTransaccion()->getDias() != "") {
        dot += "\"" + aux->getTransaccion()->getId() + "\n" + "RENTADO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"";
    } else {
        dot += "\"" + aux->getTransaccion()->getId() + "\n" + "DEVUELTO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"";
    }
    dot += ";\n}";
    ofstream file;
    file.open("../Graficas/reporteTransaccionesDescendente.txt");

    if (file.is_open()) {
        file << dot;
        file.close();
    }
    system("dot -Tpng ../Graficas/reporteTransaccionesDescendente.txt -o ../Graficas/reporteTransaccionesDescendente.png");
}

/*

void ListaTransaccion::reporteTransaccionesAscendente() {
    string dot = "digraph{ \nrankdir = LR;\n node[shape = box, color = red]; \n";
    if (!estaVacia()) {
        NodoTransaccion* aux = ini;
        // Primera pasada para crear los nodos y conexiones en orden ascendente
        do {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" +
                   (aux->getTransaccion()->getDias() != "" ? "RENTADO\n" : "DEVUELTO\n") +
                   aux->getTransaccion()->getIdActivo()->getNombre() + "\n" +
                   aux->getTransaccion()->getNombreUsuario() + "\"->\n";
            aux = aux->getSig();
        } while (aux != ini);

        // Eliminar la última flecha
        dot = dot.substr(0, dot.size() - 3);
    }
    dot += ";\n}";
    ofstream file;
    file.open("../Graficas/reporteTransaccionesAscendente.txt");

    if (file.is_open()) {
        file << dot;
        file.close();
    }
    system("dot -Tpng ../Graficas/reporteTransaccionesAscendente.txt -o ../Graficas/reporteTransaccionesAscendente.png");
}

void ListaTransaccion::reporteTransaccionesDescendente() {
    string dot = "digraph{ \nrankdir = LR;\n node[shape = box, color = red]; \n";

    if (!estaVacia()) {
        NodoTransaccion* aux = fin;

        // Crear nodos y conexiones en orden descendente
        do {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" +
                   (aux->getTransaccion()->getDias() != "" ? "RENTADO\n" : "DEVUELTO\n") +
                   aux->getTransaccion()->getIdActivo()->getNombre() + "\n" +
                   aux->getTransaccion()->getNombreUsuario() + "\"->\n";
            aux = aux->getAnt();
        } while (aux != fin);

        // Eliminar la última flecha
        dot = dot.substr(0, dot.size() - 3);
    }

    dot += ";\n}";

    ofstream file;
    file.open("../Graficas/reporteTransaccionesDescendente.txt");

    if (file.is_open()) {
        file << dot;
        file.close();
    }

    system("dot -Tpng ../Graficas/reporteTransaccionesDescendente.txt -o ../Graficas/reporteTransaccionesDescendente.png");
}
 */