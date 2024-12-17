//
// Created by Usuario on 5/12/2024.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <random>

#include "includes/ListaTransaccion.h"
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

void iniciarDatos() {
    static bool datosCargados = false;
    if (datosCargados) {
        return;
    }
    datosCargados = true;

        // Activos
    Usuario* usuario1 = new Usuario("Elian Estrada", "elian_estrada", "1234");
    Usuario* usuario2 = new Usuario("Juan Perez", "juanito", "4567");
    Usuario* usuario3 = new Usuario("Pedro Rodriguez", "pedrito", "48956");
    Usuario* usuario4 = new Usuario("Maria Fernanda", "mafer", "54312");
    Usuario* usuario5 = new Usuario("Juan Manuel", "juanma", "32897");
    Usuario* usuario6 = new Usuario("Carlos Perez", "casimiro", "721896");
    Usuario* usuario7 = new Usuario("Fernando Mendez", "fuego03", "891346");
    Usuario* usuario8 = new Usuario("Alejandra Guzman", "azurdia", "780145");
    Usuario* usuario9 = new Usuario("Iraldo Martinez", "incrediboy", "201598");
    Usuario* usuario10 = new Usuario("Antonio Lopez", "alcachofa", "20435");

    // ELIAN_ESTRADA
    usuario1->getArbol()->insertar(new Activo("madera", "madera para albañil", randomID(), (usuario1->getUsuario()),"20"));
    usuario1->getArbol()->insertar(new Activo("martillos", "martillos para madera", randomID(), (usuario1->getUsuario()), "10"));
    usuario1->getArbol()->insertar(new Activo("caladora", "caladora para cortar maderas prefabricadas", randomID(), (usuario1->getUsuario()), "15"));
    usuario1->getArbol()->insertar(new Activo("barreno", "barreno para concreto", randomID(), (usuario1->getUsuario()), "5"));

    //CASIMIRO
    usuario6->getArbol()->insertar(new Activo("balanza", "balanza con maximo de 25kg", randomID(), (usuario6->getUsuario()), "15"));
    usuario6->getArbol()->insertar(new Activo("canastas", "canastas para frutas y verduras", randomID(), (usuario6->getUsuario()), "45"));
    usuario6->getArbol()->insertar(new Activo("linternas", "linternas para alumbrar cuartos oscuros", randomID(), (usuario6->getUsuario()), "10"));
    usuario6->getArbol()->insertar(new Activo("cargadores", "cargadores de telefonos tipo c", randomID(), (usuario6->getUsuario()), "5"));
    usuario6->getArbol()->insertar(new Activo("cables", "cables de todo tipo", randomID(), (usuario6->getUsuario()), "10"));
    usuario6->getArbol()->insertar(new Activo("lazos", "lazos para tender ropa", randomID(), (usuario6->getUsuario()), "20"));

    //FUEGO03
    usuario7->getArbol()->insertar(new Activo("termos", "pequeños termos para bebidas calientes", randomID(), (usuario7->getUsuario()), "10"));
    usuario7->getArbol()->insertar(new Activo("maletas", "maletas desde pequeñas a grandes", randomID(), (usuario7->getUsuario()), "15"));
    usuario7->getArbol()->insertar(new Activo("peliculas", "todo tipo de peliculas de accion", randomID(), (usuario7->getUsuario()),"5"));

    //INCREDIBOY
    /*usuario9->getArbol()->insertar(new Activo("casets", "casets con musica de todo tipo", randomID(), (usuario9->getUsuario()), "5"));*/
    usuario9->getArbol()->insertar(new Activo("casest", "casets con musica de todo tipo", randomID(), (usuario9->getUsuario()), "5"));
    usuario9->getArbol()->insertar(new Activo("pantallas", "pantallas para proyección", randomID(), (usuario9->getUsuario()), "10"));
    usuario9->getArbol()->insertar(new Activo("cañonera", "cañonera para proyeccion", randomID(), (usuario9->getUsuario()), "10"));
    usuario9->getArbol()->insertar(new Activo("toldo", "toldo para eventos al exterior", randomID(), (usuario9->getUsuario()), "5"));

    //MAFER
    usuario4->getArbol()->insertar(new Activo("audifonos", "audifonos para grabaciones de estudio", randomID(), (usuario4->getUsuario()), "10"));
    usuario4->getArbol()->insertar(new Activo("microfonos", "microfonos de todo tipo", randomID(), (usuario4->getUsuario()), "8"));
    usuario4->getArbol()->insertar(new Activo("pedestales", "pedestales para microfonos grandes y pequeños", randomID(), (usuario4->getUsuario()), "12"));
    usuario4->getArbol()->insertar(new Activo("atriles", "atriles para colocar ojas con gancho", randomID(), (usuario4->getUsuario()), "14"));

    matriz->insertarUsuario(usuario1, "guatemala", "igss", true);
    matriz->insertarUsuario(usuario2, "jutiapa", "max", true);
    matriz->insertarUsuario(usuario3, "jalapa", "usac", true);
    matriz->insertarUsuario(usuario4, "peten", "cinepolis", true);
    matriz->insertarUsuario(usuario5, "guatemala", "usac", true);
    matriz->insertarUsuario(usuario6, "guatemala", "max", true);
    matriz->insertarUsuario(usuario7, "jutiapa", "cinepolis", true);
    matriz->insertarUsuario(usuario8, "jutiapa", "usac", true);
    matriz->insertarUsuario(usuario9, "jutiapa", "max", true);
    matriz->insertarUsuario(usuario10, "jutiapa", "usac", true);
}

/*
 ===================================================================================================================
 [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[     FUNCIONES DE MENU USUARIO      ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
 ===================================================================================================================
 */

void agregarActivo() {
    std::string nombre, descripcion, diasMax;
    std::string idAlfa = randomID();
    std::cin.ignore();
    std::cout << "\n>> Ingresar Nombre...: ";
    std::getline(std::cin, nombre);
    std::cout << ">> Ingresar Descripcion...: ";
    std::getline(std::cin, descripcion);
    std::cout << ">> Ingresar Dias Maximos de Renta...: ";
    std::getline(std::cin, diasMax);

    std::string usuario = usuarioLogueado->getUsuario()->getUsuario();

    usuarioLogueado->getUsuario()->getArbol()->insertar(new Activo(nombre, descripcion, idAlfa, usuario, diasMax ));
    std::cout << "USUARIO: " << usuarioLogueado->getUsuario()->getUsuario() << std::endl;
    std::cout << "Nombre: " << nombre << " | Descripcion: " << descripcion << " | ID(15): " << idAlfa  << std::endl;
}

void eliminarActivo() {
    std::cin.ignore();
    if (!usuarioLogueado->getUsuario()->getArbol()->raiz) {
        std::cout << "No hay activos para eliminar..." << std::endl;
        return;
    }

    usuarioLogueado->getUsuario()->getArbol()->listarActivosUsuario(usuarioLogueado->getUsuario()->getUsuario());
    std::string id;
    std::cout << ">> Ingresar ID del activo a eliminar: ";
    std::getline(std::cin, id);

    usuarioLogueado->getUsuario()->getArbol()->eliminar(id);
}

void modificarActivo() {
    std::cin.ignore();
    if (!usuarioLogueado->getUsuario()->getArbol()->raiz) {
        std::cout << "No hay activos para eliminar..." << std::endl;
        return;
    }
    usuarioLogueado->getUsuario()->getArbol()->listarActivosUsuario(usuarioLogueado->getUsuario()->getUsuario());

    std::string id, descripcion;
    std::cout << ">> Ingresar ID del activo a modificar: ";
    std::getline(std::cin, id);
    std::cout << ">> Ingresar la nueva descripción: ";
    std::getline(std::cin, descripcion);

    usuarioLogueado->getUsuario()->getArbol()->modificarActivo(id, descripcion);
    std::cout << "Activo modificado! \n" << std::endl;
}

void rentarActivo() {
    std::cin.ignore();
    std::string id;
    std::string dias;
    std::cout << "\n>>>> Rentar Activos Disponibles <<<<";
    matriz->listadoActivos(usuarioLogueado->getUsuario(), true, "");
    std::cout << "\n>> Ingresar ID del activo a rentar: ";
    std::getline(std::cin, id);

    NodoAVL* activoRentado = matriz->listadoActivos(usuarioLogueado->getUsuario(), false, id);

    if (activoRentado != nullptr) {
        std::cout << "Activo seleccionado: " << std::endl;
        std::cout << "\n / ID: " << activoRentado->getActivo()->getId() << std::endl;
        std::cout << "  / Nombre: " << activoRentado->getActivo()->getNombre() << std::endl;
        std::cout << "   / Descripcion: " << activoRentado->getActivo()->getDescripcion() << std::endl;
        std::cout << "    / Dias Maximos de Renta: " << activoRentado->getActivo()->getDiasMax() << std::endl;

        std::cout << " \nIngrese los días por rentar: ";
        std::getline(std::cin, dias);
        activoRentado->getActivo()->setRentado(true);
        activoRentado->getActivo()->setDiasRenta(dias);

        if (std::stoi(dias) <= std::stoi(activoRentado->getActivo()->getDiasMax())) {
            std::cout << "Renta permitida por " << dias << " días." << std::endl;

            std::string departamento = matriz->buscarCabeceraHorizontal(matriz->buscarUsuarioCabeza(usuarioLogueado))->getCabecera();
            std ::string empresa = matriz->buscarCabeceraVertical(matriz->buscarUsuarioCabeza(usuarioLogueado))->getCabecera();
            std::string fecha = activoRentado->getActivo()->getDiasMax();

            transaccion->insertarTransaccion(new Transaccion(activoRentado->getActivo(), usuarioLogueado->getUsuario()->getUsuario(), departamento, empresa, fecha,dias, "Renta"));
            std::cout << "Activo Rentado!" << std::endl;
        } else {
            std::cout << "La cantidad de días rentados excede los días máximos permitidos." << std::endl;
        }
    }
}

void activosRentados() {
    std::cin.ignore();
    std::string id;
    std::cout << ">> Listado de Activos Rentados: \n";
    //transaccion->recorrerLista(usuarioLogueado->getUsuario()->getUsuario());
    if (transaccion->recorrerLista(usuarioLogueado->getUsuario()->getUsuario())) {

        std::cout << "\nIngrese el id del Activo a devolver: " << std::endl;
        std::getline(std::cin, id);

        NodoAVL* activoRentado = matriz->listadoActivos(usuarioLogueado->getUsuario(), false, id);

        if (activoRentado != nullptr) {
            std::cout << "\nActivo Devuelto: " << std::endl;
            std::cout << "\n>> ID = " << activoRentado->getActivo()->getId() << "; Nombre = " << activoRentado->getActivo()->getNombre() << "; Descripcion = " << activoRentado->getActivo()->getDescripcion() << std::endl;

            activoRentado->getActivo()->setRentado(false);
            activoRentado->getActivo()->setDiasRenta("");

            std::string usuario = usuarioLogueado->getUsuario()->getUsuario();
            std::string departamento = matriz->buscarCabeceraHorizontal(matriz->buscarUsuarioCabeza(usuarioLogueado))->getCabecera();
            std::string empresa = matriz->buscarCabeceraVertical(matriz->buscarUsuarioCabeza(usuarioLogueado))->getCabecera();
            std::string fecha = activoRentado->getActivo()->getDiasMax();

            transaccion->insertarTransaccion(new Transaccion(activoRentado->getActivo(), usuario, departamento, empresa, fecha,"", "Devolver"));

            std::cout << "\nActivo devuelto exitosamente..." << std::endl;
            std::cin.ignore();

        } else {
            std::cout << "\nActivo no encontrado..." << std::endl;
            std::cin.ignore();
        }
    } else {
        std::cout << "\nNo hay activos rentados..." << std::endl;
    }
}

void misActivosRentados() {
    std::cout << ">> Listado de Mis Activos Actualmente Rentados: \n";
    if (usuarioLogueado->getUsuario()->getArbol()->raiz) {
        usuarioLogueado->getUsuario()->getArbol()->listarActivosRentados(usuarioLogueado->getUsuario()->getArbol()->raiz);
    } else {
        std::cout << "Ninguno de tus activos están rentados" << std::endl;
    }
}

void menuUsuario(const std::string& user) {
    bool menu = true;
    int opcion;

    while (menu) {
        std::cout << ">> ==================== " << usuarioLogueado->getUsuario()->getNombre() << " ====================" << std::endl;
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
    std::cin.ignore();
    std::string usuario, depto, company;
    std::cout << ">> Ingresar Usuario: ";
    std::getline(std::cin, usuario);
    std::cout << ">> Ingresar Depto:";
    std::getline(std::cin, depto);
    std::cout << ">> Ingresar Company:";
    std::getline(std::cin, company);
    //std::transform(user.begin(), user.end(), user.begin(), ::tolower);

    NodoMatriz* auxiliar = matriz->existeEn(matriz->deptoBuscar(depto), company);
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
        }

    } else {
        std::cout << "\nNo hay usuarios en [" << depto << "x" << company << "]" << std::endl;
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

        NodoMatriz *nodoUsuario = matriz->existeEn(matriz->deptoBuscar(depto), company);

        if (nodoUsuario != nullptr) {
            while (nodoUsuario != nullptr) {
                if ((nodoUsuario->getUsuario()->getUsuario() == usuario) && (nodoUsuario->getUsuario()->getContra() == contra)) {
                    std::cout << "\n>> Bienvenido " << usuario << "!" << std::endl;
                    usuarioLogueado = nodoUsuario;
                    menuUsuario(usuarioLogueado->getUsuario()->getNombre());
                }
                nodoUsuario = nodoUsuario->getAtras();
            }
        } else {
            std::cout << "\n>> Usuario no encontrado en la base de datos..." << std::endl;
            mainMenu();
        }
    }
}

void mainMenu() {
    iniciarDatos();

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
            mainMenu();
    }
}

int main () {
    mainMenu();
    return 0;
}