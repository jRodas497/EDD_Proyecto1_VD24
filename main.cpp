//
// Created by Usuario on 5/12/2024.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <random>
#include "includes/Activo.h"
#include "includes/AVL.h"

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
 [[[[[[[[[      FUNCIONES DE MENU USUARIO      ]]]]]]]]]
 */

void agregarActivo() {
    std::string nombre, descripcion;
    std::string idAlfa = randomID();

    std::cout << "\n>> Ingresar Nombre...: ";
    std::cin >> nombre;
    std::cout << ">> Ingresar Descripcion...: ";
    std::cin >> descripcion;

    Activo* nuevoActivo = new Activo(nombre, descripcion, idAlfa);
    //arbolActivos.insertar(nuevoActivo);
    std::cout << "Nombre: " << nombre << " | Descripcion: " << descripcion << " | ID(15): " << idAlfa << "\n" << std::endl;
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
        std::cout << "\n>> ==================== " << user << " ====================" << std::endl;
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
            default:
                std::cout << "\nPor favor escoja una de las opciones disponibles...\n";
        }
    }
}

/*
 [[[[[[[[[      FUNCIONES DE MENU ADMINISTRADOR      ]]]]]]]]]
 */
void registrarUsuario() {
    std::string nombre, usuario, contra;
    std::cout << "\n>> Ingresar Nombre...: ";
    std::cin >> nombre;
    std::cout << ">> Ingresar Usuario...: ";
    std::cin >> usuario;
    std::cout << ">> Ingresar Password...: ";
    std::cin >> contra;

    //Usuario* nuevoUsuario = new Usuario(nombre, usuario, contra);
    //arbolUsuarios.insertar(nuevoUsuario);
    std::cout << "\nNombre: " << nombre << " | Usuario: " << usuario << " | Password: " << contra << std::endl;
}

void reporteMatrizDispersa() {
    //matrizDispersa.reporte();
    std::cout << "\n>> Reporte de la Matriz Dispersa [Departamentos x Empresas] generado! \n";
}

void reporteActivosDisponiblesDepto() {
    std::string depto;
    std::cout << "\n>> Ingresar Departamento: ";
    std::cin >> depto;
    std::transform(depto.begin(), depto.end(), depto.begin(), ::tolower);
    //matrizDispersa.reporteActivosDisponiblesDepto(depto);
    std::cout << ">> Reporte de Activos Disponibles de la Empresa generado!\n";
}

void reporteActivosDisponiblesEmpresa() {
    std::string company;
    std::cout << "\n>> Ingresar Empresa: ";
    std::cin >> company;
    std::transform(company.begin(), company.end(), company.begin(), ::tolower);
    //matrizDispersa.reporteActivosDisponiblesEmpresa(company);
    std::cout << ">> Reporte de Activos Disponibles de la Empresa generado! \n";
}

void reporteTransacciones() {
    //arbolTransacciones.imprimirEnOrden();
    std::cout << "\n>> Reporte de Transacciones generado!\n";
}

void reporteActivosUsuario() {
    std::string user;
    std::cout << "\n>> Ingresar Usuario: ";
    std::cin >> user;
    std::transform(user.begin(), user.end(), user.begin(), ::tolower);

    //arbolUsuarios.reporteActivosUsuario(user);
    std::cout << ">> Reporte de Activos de Usuario generado!\n";
}

void activosRentadosUsuario() {
    std::string user;
    std::cout << "\n>> Ingresar Usuario: ";
    std::cin >> user;
    std::transform(user.begin(), user.end(), user.begin(), ::tolower);

    //arbolUsuarios.activosRentadosUsuario(user);
    std::cout << ">> Reporte de Activos Rentados por Usuario generado!\n";
}

void ordenarTransacciones() {
    char orden;
    std::cout << "\n>> Ordenar Transacciones de forma Ascendente o Descendente? [a][d]" << std::endl;
    std::cin >> orden;
    if (orden == 'a') {
        std::cout << " Orden de Transacciones Ascendente hecho! " << std::endl;
    } else if (orden == 'd') {
        std::cout << " Orden de Transacciones Descendente hecho! " << std::endl;
    } else {
        std::cout << "Por favor ingrese una opcion valida..." << std::endl;
    }
}

void menuAdmin() {
    bool menu = true;
    int opcion;

    while (menu) {
        std::cout << "\n>> ====================   SEA BIENVENIDO ADMIN   ====================" << std::endl;
        std::cout <<   ">> %%% [1]. Registrar Usuario  " << std::endl;
        std::cout <<   ">> %%% [2]. Reporte (Graphviz) Matriz Dispersa  " << std::endl;
        std::cout <<   ">> %%% [3]. Reporte (Graphviz) Activos Disponibles de un Departamento  " << std::endl;
        std::cout <<   ">> %%% [4]. Reporte (Graphviz) Activos Disponibles de una Empresa  " << std::endl;
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
                reporteActivosUsuario();
                break;
            case 7:
                activosRentadosUsuario();
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

    std::cout << "\n>> %%%%%%%%%%%%%%%%%%%%%%%%%%% Renta de Activos %%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
    std::cout <<   ">> %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Login %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n" << std::endl;

    std::cout << ">> Ingresar Usuario... " << std::endl;
    std::cin >> usuario;
    std::transform(usuario.begin(), usuario.end(), usuario.begin(), ::tolower);

    std::cout << "\n>> Ingresar Password... " << std::endl;;
    std::cin >> contra;
    std::transform(contra.begin(), contra.end(), contra.begin(), ::tolower);

    if (usuario == "admin" && contra == "admin") {
        menuAdmin();
    } else {
        std::cout << "\n>> Ingresar Departamento... " << std::endl;;
        std::cin >> depto;
        //volver en minus para no tener Guatemala/guatemala/GUATEMALA/gUaTeMaLa
        std::transform(depto.begin(), depto.end(), depto.begin(), ::tolower);

        std::cout << "\n>> Ingresar Company... " << std::endl;;
        std::cin >> company;
        //volver en minus para no tener IGSS/igss/Igss/iGsS
        std::transform(company.begin(), company.end(), company.begin(), ::tolower);




        //comprobación de si el usuario existe en la base de datos con if
        menuUsuario(usuario);




    }
}

int main () {
    int opcion = 0;

    std::cout << "\n>> [1]. Login [ADMIN]/[USUARIO]" << std::endl;
    std::cout << ">> [2]. Salir del Programa" << std::endl;
    if (!obtenerOpcion(opcion)) {
        main();
    }

    switch (opcion) {
        case 1:
            login();
            main();
        case 2:
            std::cout << "\n>> Esperamos que vuelva pronto!!!" << std::endl;
            system(0);
        default:
            std::cout << "\nPor favor escoja una de las opciones disponibles...\n";
    }
    return 0;
}