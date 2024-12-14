//
// Created by Usuario on 5/12/2024.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <random>

#include "ListaTransaccion.h"
#include "includes/Activo.h"
#include "includes/Usuario.h"
#include "includes/Matriz.h"

// Inicializar datos
NodoMatriz* usuarioLogueado = nullptr;

Matriz* matriz = new Matriz();
ListaTransaccion* transaccion = new ListaTransaccion();

void mainMenu();
void menuAdmin();
void menuUser();

bool obtenerOpcion(int& opcion) {
    std::cin >> opcion;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Por favor ingrese un numero valido." << std::endl;
        return false;
    }
    return true;
}

std::string randomID() {
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    std::string randomID;
    for (size_t i = 0; i < 15; ++i) {
        randomID += characters[distribution(generator)];
    }
    return randomID;
}

/*
 ===================================================================================================================
 [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[     FUNCIONES DE MENU USUARIO      ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
 ===================================================================================================================
 */

void agregarActivo() {
    std::string nombre, descripcion;
    std::string idAlfa = randomID();

    std::cout << "\n>> Ingresar Nombre...: ";
    std::cin >> nombre;
    std::cout << ">> Ingresar Descripcion...: ";
    std::cin >> descripcion;

    //Activo* nuevoActivo = new Activo(nombre, descripcion, idAlfa);
    //arbolActivos.insertar(nuevoActivo);
    std::cout << "Nombre: " << nombre << " | Descripcion: " << descripcion << " | ID(15): " << idAlfa  << std::endl;
}

void eliminarActivo() {
    int id;
    std::cout << ">> Ingresar ID del activo a eliminar: ";
    if (!obtenerOpcion(id)) return;

    //arbolActivos.eliminar(id);
}

void modificarActivo() {
    int id;
    std::cout << ">> Ingresar ID del activo a modificar: ";
    if (!obtenerOpcion(id)) return;

    //arbolActivos.modificar(id);
}

void rentarActivo() {
    int id;
    std::cout << ">> Ingresar ID del activo a rentar: ";
    if (!obtenerOpcion(id)) return;

    //arbolActivos.rentar(id);
}

void activosRentados() {
    std::cout << ">> Listado de Activos Rentados: \n";
    //arbolActivos.activosRentados();
}

void misActivosRentados() {
    std::cout << ">> Listado de Mis Activos Rentados: \n";
    //arbolActivos.misActivosRentados();
}

void menuUsuario(const std::string& user) {
    bool menu = true;
    int opcion;

    while (menu) {
        std::cout << ">> ==================== " << user << " ====================" << std::endl;
        std::cout << ">> ### [1]. Agregar Activo" << std::endl;
        std::cout << ">> ### [2]. Eliminar Activo" << std::endl;
        std::cout << ">> ### [3]. Modificar Activo" << std::endl;
        std::cout << ">> ### [4]. Rentar Activo" << std::endl;
        std::cout << ">> ### [5]. Activos Rentados" << std::endl;
        std::cout << ">> ### [6]. Mis Activos Rentados" << std::endl;
        std::cout << ">> ### [7]. Cerrar Sesion\n" << std::endl;
        std::cout << ">> Ingresar Opcion: ";
        if (!obtenerOpcion(opcion)) continue;

        switch (opcion) {
            case 1:
                agregarActivo();
                break;
            case 2:
                eliminarActivo();
                break;
            case 3:
                modificarActivo();
                break;
            case 4:
                rentarActivo();
                break;
            case 5:
                activosRentados();
                break;
            case 6:
                misActivosRentados();
                break;
            case 7:
                std::cout << "Adios " << user << " nos vemos!" << std::endl;
                menu = false;
                break;
            default:
                std::cout << "\nPor favor escoja una de las opciones disponibles...\n";
        }
    }
}

/*
 ===================================================================================================================
 [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[      FUNCIONES DE MENU ADMINISTRADOR      ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
 ===================================================================================================================
 */
void registrarUsuario() {
    char opcion;
    std::cin.ignore();

    std::string nombre, usuario, contra, depto, company;
    std::cout << "\n>> Ingresar Nombre...: ";
    std::getline(std::cin, nombre);
    std::cout << ">> Ingresar Usuario...: ";
    std::getline(std::cin, usuario);
    std::cout << ">> Ingresar Password...: ";
    std::getline(std::cin, contra);
    std::cout << ">> Ingresar Departamento...: ";
    std::getline(std::cin, depto);
    std::transform(depto.begin(), depto.end(), depto.begin(), ::tolower);
    std::cout << ">> Ingresar Company...: ";
    std::getline(std::cin, company);
    std::transform(company.begin(), company.end(), company.begin(), ::tolower);

    std::cout << ">> Desea Agregar al Usuario al Final o al Inicio de la Lista de Usuarios? ";
    std::cout << "[f]/[i]" << std::endl;
    std::cin >> opcion;

    if (opcion == 'f') {
        matriz->insertarUsuario(new Usuario(nombre, usuario, contra), depto, company, true);
        std::cout << "\nNombre: " << nombre << " | Usuario: " << usuario << " | Password: " << contra << " | Depto: " << depto << " | Company: " << company << "\n" << std::endl;
    } else if (opcion == 'i') {
        matriz->insertarUsuario(new Usuario(nombre, usuario, contra), depto, company, false);
        std::cout << "\nNombre: " << nombre << " | Usuario: " << usuario << " | Password: " << contra << " | Depto: " << depto << " | Company: " << company << "\n" << std::endl;
    } else {
        std::cout << "Por favor ingrese una opcion valida..." << std::endl;
    }

}

void reporteMatrizDispersa() {
    matriz -> reporteMatrizDispersa();
    std::cout << "\n>> Reporte de la Matriz Dispersa [Departamentos x Company] generado! \n";
}

void reporteActivosDisponiblesDepto() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string depto;
    std::cout << "\n>> Ingresar Departamento: ";
    std::getline(std::cin, depto);
    std::transform(depto.begin(), depto.end(), depto.begin(), ::tolower);

    matriz->reporteActivosDepto(depto);

    std::cout << ">> Reporte de Activos Disponibles de la Company generado!\n";
}

void reporteActivosDisponiblesEmpresa() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string company;
    std::cout << "\n>> Ingresar Company: ";
    std::getline(std::cin, company);
    std::transform(company.begin(), company.end(), company.begin(), ::tolower);

    matriz->reporteActivosCompany(company);

    std::cout << ">> Reporte de Activos Disponibles de la Company generado! \n";
}

void reporteTransacciones() {
    std::cout << "\n>> Reporte de Transacciones generado!\n";

    transaccion->reporteTransacciones();

}

void reporteActivosUsuario() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string usuario, depto, company;
    std::cout << ">> Ingresar Usuario: ";
    std::getline(std::cin, usuario);
    std::cout << ">> Ingresar Depto:";
    std::getline(std::cin, depto);
    std::cout << ">> Ingresar Company:";
    std::getline(std::cin, company);
    //std::transform(user.begin(), user.end(), user.begin(), ::tolower);

    NodoMatriz* auxiliar = matriz->existeEn(matriz->companyBuscar(company), depto);
    if (auxiliar != nullptr) {
        do {
            if (auxiliar->getUsuario()->getUsuario() == usuario) {
                auxiliar->getUsuario()->getArbol()->activosUsuario(auxiliar->getUsuario()->getArbol()->raiz, usuario);
                break;
            }
            auxiliar = auxiliar->getAtras();
        } while (auxiliar != nullptr);

        if (auxiliar == nullptr) {
            std::cout << "\nEl nombre del usuario está incorrecto..." << std::endl;
            std::cin.ignore();
        }
    } else {
        std::cout << "\nEl usuario no existe..." << std::endl;
        std::cin.ignore();
    }
    std::cout << ">> Reporte de Activos de Usuario generado!\n";
}

void activosRentadosUsuario() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string usuario;
    std::cout << "\n>> Ingresar Usuario: ";
    std::getline(std::cin, usuario);

    transaccion->reporteActivosRentadosUsuario(usuario);
    std::cout << ">> Reporte de Activos Rentados por Usuario generado!\n";
}

void ordenarTransacciones() {
    char orden;
    std::cout << "\n>> Ordenar Transacciones de forma Ascendente o Descendente? [a][d]" << std::endl;
    std::cin >> orden;
    if (orden == 'a') {
        std::cout << " Orden de Transacciones Ascendente hecho! " << std::endl;
        transaccion->reporteTransaccionesAscendente();
    } else if (orden == 'd') {
        std::cout << " Orden de Transacciones Descendente hecho! " << std::endl;
        transaccion->reporteTransaccionesDescendente();
    } else {
        std::cout << "Por favor ingrese una opcion valida..." << std::endl;
    }
}

void menuAdmin() {
    bool menu = true;
    int opcion;

    while (menu) {
        std::cout << ">> ====================   SEA BIENVENIDO ADMIN   ====================" << std::endl;
        std::cout <<   ">> %%% [1]. Registrar Usuario  " << std::endl;
        std::cout <<   ">> %%% [2]. Reporte (Graphviz) Matriz Dispersa  " << std::endl;
        std::cout <<   ">> %%% [3]. Reporte (Graphviz) Activos Disponibles de un Departamento  " << std::endl;
        std::cout <<   ">> %%% [4]. Reporte (Graphviz) Activos Disponibles de una Company  " << std::endl;
        std::cout <<   ">> %%% [5]. Reporte (Graphviz) Transacciones  " << std::endl;
        std::cout <<   ">> %%% [6]. Reporte Activos de un Usuario  " << std::endl;
        std::cout <<   ">> %%% [7]. Activos Rentados por un Usuario  " << std::endl; //Todos los activos que un usuario
        //tenga en su posesión actualmente (activos que el haya rentado)
        std::cout <<   ">> %%% [8]. Ordenar Transacciones  " << std::endl; //Por medio del ID alfabético de los activos
        std::cout <<   ">> %%% [9]. Cerrar Sesion  " << std::endl;
        std::cout << ">> Ingresar Opcion: ";
        if (!obtenerOpcion(opcion)) continue;

        switch (opcion) {
            case 1:
                registrarUsuario();
                break;
            case 2:
                reporteMatrizDispersa();
                break;
            case 3:
                reporteActivosDisponiblesDepto();
                break;
            case 4:
                reporteActivosDisponiblesEmpresa();
                break;
            case 5:
                reporteTransacciones();
                break;
            case 6:
                reporteActivosUsuario(); // Activos en general
                break;
            case 7:
                activosRentadosUsuario(); // Activos rentados para un usuario
                break;
            case 8:
                ordenarTransacciones();
                break;
            case 9:
                std::cout << "\nAdios estimado Administrador!" << std::endl;
                menu = false;
                break;
            default:
                std::cout << "\nPor favor escoja una de las opciones disponibles...\n";
        }
    }
}

void login() {
    std::string usuario, contra, depto, company;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    std::cout << "\n>> %%%%%%%%%%%%%%%%%%%%%%%%%%% Renta de Activos %%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
    std::cout <<   ">> %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Login %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n" << std::endl;

    std::cout << ">> Ingresar Usuario... " << std::endl;
    std::getline(std::cin, usuario);
    //std::transform(usuario.begin(), usuario.end(), usuario.begin(), ::tolower);

    std::cout << ">> Ingresar Password... " << std::endl;;
    std::getline(std::cin, contra);
    //std::transform(contra.begin(), contra.end(), contra.begin(), ::tolower);

    if (usuario == "admin" && contra == "admin") {
        menuAdmin();
    } else {

        std::cout << ">> Ingresar Departamento... " << std::endl;;
        std::getline(std::cin, depto);
        //volver en minus para no tener Guatemala/guatemala/GUATEMALA/gUaTeMaLa
        std::transform(depto.begin(), depto.end(), depto.begin(), ::tolower);

        std::cout << ">> Ingresar Company... " << std::endl;;
        std::getline(std::cin, company);
        //volver en minus para no tener IGSS/igss/Igss/iGsS
        std::transform(company.begin(), company.end(), company.begin(), ::tolower);

        NodoMatriz* nodoUsuario = matriz->existeEn(matriz->deptoBuscar(depto), company);

        if (nodoUsuario != nullptr) {
            do {
                if ((nodoUsuario->getUsuario()->getUsuario() == usuario) && (nodoUsuario->getUsuario()->getContra() == contra)) {
                    std::cout << "\n>> Bienvenido " << usuario << "!" << std::endl;
                    usuarioLogueado = nodoUsuario;
                    menuUsuario(usuarioLogueado->getUsuario()->getNombre());
                }
                nodoUsuario = nodoUsuario->getAtras();
            } while (nodoUsuario != nullptr);
        } else {
            std::cout << "\n>> Usuario no encontrado en la base de datos..." << std::endl;
            mainMenu();
        }
    }
}

void mainMenu() {
    // Activos
    Usuario* u1 = new Usuario("Pedro Perez", "pperez", "peres");
    Usuario* u2 = new Usuario("Juan Camanei", "juancho", "1111");
    Usuario* u3 = new Usuario("Tziquin Pashut", "tutsi", "tutsi");
    Usuario* u4 = new Usuario("Juan Rodas", "jrodas", "1234");

    u1->getArbol()->insertar(new Activo("Activo 1", "Descripcion 1", randomID()));
    u1->getArbol()->insertar(new Activo("Activo 2", "Descripcion 2", randomID()));
    u1->getArbol()->insertar(new Activo("Activo 3", "Descripcion 3", randomID()));
    u1->getArbol()->insertar(new Activo("Activo 4", "Descripcion 4", randomID()));
    u1->getArbol()->insertar(new Activo("Deportes", "Descripcion Deportiva", randomID()));
    u1->getArbol()->insertar(new Activo("Activo 5", "Descripcion 5", randomID()));
    u1->getArbol()->insertar(new Activo("Activo 6", "Descripcion 6", randomID()));
    u1->getArbol()->insertar(new Activo("Activo 7", "Descripcion 7", randomID()));

    u2->getArbol()->insertar(new Activo("Activo 8", "Descripcion 5", randomID()));
    u2->getArbol()->insertar(new Activo("Activo 9", "Descripcion 6", randomID()));

    u3->getArbol()->insertar(new Activo("Activo 10", "Descripcion 7", randomID()));
    u3->getArbol()->insertar(new Activo("Activo 11", "Descripcion 8", randomID()));
    u3->getArbol()->insertar(new Activo("Activo 12", "Descripcion 9", randomID()));
    u3->getArbol()->insertar(new Activo("Activo 13", "Descripcion 10", randomID()));

    u4->getArbol()->insertar(new Activo("Activo 14", "Descripcion 11", randomID()));
    u4->getArbol()->insertar(new Activo("Activo 15", "Descripcion 12", randomID()));
    u4->getArbol()->insertar(new Activo("Activo 16", "Descripcion 13", randomID()));

    // Usuarios con el mismo departamento y empresa
    matriz->insertarUsuario(u1, "guatemala", "usac", true);
    matriz->insertarUsuario(u2, "guatemala", "usac", true);
    matriz->insertarUsuario(u3, "guatemala", "usac", false);
    matriz->insertarUsuario(u4, "guatemala", "usac", false);

                //matriz->listarUsuarios("guatemala", "usac");
    matriz->insertarUsuario(new Usuario("Frank Miller", "fmiller", "pass6"), "santa rosa", "twitch", true);
    matriz->insertarUsuario(new Usuario("Grace Lee", "glee", "pass7"), "santa rosa", "twitch", false);
    matriz->insertarUsuario(new Usuario("Eva Davis", "rocinante", "pass5"), "santa rosa", "twitch", false);
                //matriz->listarUsuarios("santa rosa", "twitch");
    matriz->insertarUsuario(new Usuario("Marco Tulio", "mt", "pass"), "santa rosa", "usac", false);
                //matriz->listarUsuarios("santa rosa", "usac");
    matriz->insertarUsuario(new Usuario("Juan Carlos", "carlos", "pass"), "guatemala", "twitch", false);
                //matriz->listarUsuarios("guatemala", "twitch");
    matriz->insertarUsuario(new Usuario("Rui Valdez","rvaldez17","fnoque"), "jutiapa", "irtra", false);
    matriz->insertarUsuario(new Usuario("Angel Escobar","gelitras","irtra"), "jrb", "vcorp", true);
    matriz->insertarUsuario(new Usuario("Juan Perez", "jperez", "pass"), "santa rosa", "irtra", false);
                //matriz->listarUsuarios("santa rosa", "irtra");
    matriz->insertarUsuario(new Usuario("Kevincito Kevincito","andresito","emy"), "peten", "bigmc", true);
    matriz->insertarUsuario(new Usuario("Alice Smith", "asmith", "pass1"), "san marcos", "bigmc", true);
    matriz->insertarUsuario(new Usuario("Bob Johnson", "bjohnson", "pass2"), "quetzaltenango", "bigmc", true);
    matriz->insertarUsuario(new Usuario("Charlie Brown", "cbrown", "pass3"), "quiche", "bigmc", true);
    matriz->insertarUsuario(new Usuario("David Wilson", "dwilson", "pass4"), "jalapa", "bigmc", true);
    matriz->insertarUsuario(new Usuario("Jack Clark", "jclark", "pass10"), "chimaltenango", "bigmc", true);
    // Usuarios con el mismo departamento pero diferente empresa al final
    matriz->insertarUsuario(new Usuario("Hannah White", "hwhite", "pass8"), "baja verapaz", "bigmc", false);
    matriz->insertarUsuario(new Usuario("Ian Harris", "iharris", "pass9"), "baja verapaz", "bigmc", false);
                //matriz->listarUsuariosPorDepto("baja verapaz");
    // Usuarios con el mismo empresa pero diferente departamento al final
    matriz->insertarUsuario(new Usuario("Ericka Brown", "ebrown", "pass11"), "escuintla", "bigmc", true);
    matriz->insertarUsuario(new Usuario("Fernando Perez", "fperez", "pass12"), "huehuetenango", "bigmc", true);
    matriz->insertarUsuario(new Usuario("Gloria Smith", "gsmith", "pass13"), "retalhuleu", "bigmc", false);
            //matriz->listarUsuariosPorCompany("company11");

    int opcion = 0;

    std::cout << "\n>> [1]. Login [ADMIN]/[USUARIO]" << std::endl;
    std::cout << ">> [2]. Salir del Programa" << std::endl;
    if (!obtenerOpcion(opcion)) {
        mainMenu();
    }

    switch (opcion) {
        case 1:
            login();
            mainMenu();
            break;
        case 2:
            std::cout << "\n>> Esperamos que vuelva pronto!!!" << std::endl;
            system(0);
            break;
        default:
            std::cout << "\nPor favor escoja una de las opciones disponibles...\n";
    }
}

int main () {
    mainMenu();
    return 0;
}