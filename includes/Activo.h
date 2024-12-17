#ifndef ACTIVO_H
#define ACTIVO_H

#include <string>

class Activo {
public:
    Activo(const std::string& nombre, const std::string& descripcion, const std::string& id, const std::string& usuario, const std::string& diasMax);
    // getters
    const std::string& getId();
    const std::string& getNombre();
    const std::string& getDescripcion();
    const std::string& getDiasMax();
    bool getRentado() const;
    const std::string& getUsuario();
    const std::string& getDiasRenta();
    // setters
    void setId(const std::string& id);
    void setNombre(const std::string& nombre);
    void setDescripcion(const std::string& descripcion);
    void setDiasMax(const std::string& diasMax);
    void setRentado(bool rentado);
    void setUsuario(const std::string& usuario);
    void setDiasRenta(const std::string& diasRenta);

private:
    static int nextId;
    std::string id;
    std::string nombre;
    std::string descripcion;
    std::string diasMax;
    bool rentado;
    std::string usuario;
    std::string diasRenta;
};

#endif // ACTIVO_H