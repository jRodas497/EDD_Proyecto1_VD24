#ifndef ACTIVO_H
#define ACTIVO_H

#include <string>

class Activo {
public:
    Activo(const std::string& nombre, const std::string& descripcion, const std::string& id);
    // getters
    const std::string& getId();
    const std::string& getNombre();
    const std::string& getDescripcion();
    bool getRentado();
    // setters
    void setId(const std::string& id);
    void setNombre(const std::string& nombre);
    void setDescripcion(const std::string& descripcion);
    void setRentado(bool rentado);

private:
    static int nextId;
    std::string id;
    std::string nombre;
    std::string descripcion;
    bool rentado;
};

#endif // ACTIVO_H