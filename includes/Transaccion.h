//
// Created by Usuario on 11/12/2024.
//

#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>
#include "Activo.h"

class Transaccion {
public:
    Transaccion();
    Transaccion(Activo* idActivo, std::string nombreUsuario, std::string departamento, std::string empresa, std::string fecha, std::string dias);

    std::string arreglar(std::string id);

    // getters
    std::string getId();
    Activo* getIdActivo();
    std::string getNombreUsuario();
    std::string getDepartamento();
    std::string getEmpresa();
    std::string getFecha();
    std::string getDias();

    // setters
    void setId(std::string id);
    void setIdActivo(Activo* idActivo);
    void setNombreUsuario(std::string nombreUsuario);
    void setDepartamento(std::string departamento);
    void setEmpresa(std::string empresa);
    void setFecha(std::string fecha);
    void setDias(std::string dias);

private:
    std::string id;
    Activo* idActivo;
    std::string nombreUsuario;
    std::string departamento;
    std::string empresa;
    std::string fecha;
    std::string dias;
};



#endif //TRANSACCION_H
