//
// Created by Usuario on 5/12/2024.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <random>
#include "includes/Activo.h"
#include "includes/GestorDatos.h"

GestorDatos gestorDatos;

std::string randomID(size_t length) {
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    std::string randomID;
    for (size_t i = 0; i < length; ++i) {
        randomID += characters[distribution(generator)];
    }
    return randomID;
}

void agregarActivo() {
    std::string nombre, descripcion;
    std::string idAlfa = randomID(15);

    std::cout << ">> %%%%%%%%%%%%%%%%%%%% Agregar Activo %%%%%%%%%%%%%%%%%%%%" << std::endl;
    std::cout << ">> Ingresar Nombre...: ";
    std::cin >> nombre;
    std::cout << ">> Ingresar Descripción...: ";
    std::cin >> descripcion;

    gestorDatos.agregarActivo(nombre, descripcion, idAlfa);
    std::cout << "Nombre: " << nombre << " | Descripcion: " << descripcion << " | ID(15): " << idAlfa << std::endl;
}

void mostrarActivos() {
    gestorDatos.mostrarActivos();
}

void eliminarActivo() {
    mostrarActivos();

    int id;
    std::cout << ">> Ingresar ID del activo a eliminar: ";
    std::cin >> id;

    gestorDatos.eliminarActivo(id);
}

void mainMenu(const std::string& user) {
    bool menu = true;
    int opcion;

    while (menu) {
        std::cout << "\n>> ==================== " << user << " ====================" << std::endl;
        std::cout << ">> %%%%%%%%%%%%%%%%%%%% 1. Agregar Activo       %%%%%%%%%%%%%%%" << std::endl;
        std::cout << ">> %%%%%%%%%%%%%%%%%%%% 2. Eliminar Activo      %%%%%%%%%%%%%%%" << std::endl;
        std::cout << ">> %%%%%%%%%%%%%%%%%%%% 3. Modificar Activo     %%%%%%%%%%%%%%%" << std::endl;
        std::cout << ">> %%%%%%%%%%%%%%%%%%%% 4. Rentar Activo        %%%%%%%%%%%%%%%" << std::endl;
        std::cout << ">> %%%%%%%%%%%%%%%%%%%% 5. Activos Rentados     %%%%%%%%%%%%%%%" << std::endl;
        std::cout << ">> %%%%%%%%%%%%%%%%%%%% 6. Mis Activos Rentados %%%%%%%%%%%%%%%" << std::endl;
        std::cout << ">> %%%%%%%%%%%%%%%%%%%% 7. Cerrar Sesion        %%%%%%%%%%%%%%%\n" << std::endl;
        std::cout << ">> Ingresar Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                agregarActivo();
                break;
            case 2:
                eliminarActivo();
                break;
            case 3:
                // Modify asset logic
                    break;
            case 4:
                // Rent asset logic
                    break;
            case 5:
                // View rented assets logic
                    break;
            case 6:
                // View my rented assets logic
                    break;
            default:
                menu = false;
                std::cout << "Adios " << user << " nos vemos!" << std::endl;
        }
    }
}

void login() {
    std::string usuario, pass, depto, company;

    std::cout << ">> %%%%%%%%%%%%%%%%%%%%%%%%%%% Renta de Activos %%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
    std::cout << ">> %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Login %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n" << std::endl;

    std::cout << ">> Ingresar Usuario... " << std::endl;
    std::cin >> usuario;

    std::cout << ">> Ingresar Password... " << std::endl;;
    std::cin >> pass;

    std::cout << ">> Ingresar Departamento... " << std::endl;;
    std::cin >> depto;
    std::transform(depto.begin(), depto.end(), depto.begin(), ::tolower);

    std::cout << ">> Ingresar Company... " << std::endl;;
    std::cin >> company;
    std::transform(company.begin(), company.end(), company.begin(), ::tolower);


    /*
     lógica de login
     */
    mainMenu(usuario);
}

int main () {
    bool log = true;
    int opcion = 0;

    while (log) {
        std::cout << ">> 1. Login" << std::endl;
        std::cout << ">> 2. Salir" << std::endl;
        std::cin >> opcion;
        switch (opcion) {
            case 1:
                login();
                break;
            default:
                log = false;
                break;
        }
    }
    return 0;
}