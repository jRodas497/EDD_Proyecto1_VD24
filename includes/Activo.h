#ifndef ACTIVO_H
#define ACTIVO_H

#include <string>

class Activo {
public:
    Activo(const std::string& nombre, const std::string& descripcion, const std::string& idAlfa);
    // getters
    int getId() const;
    const std::string& getIdAlfa() const;
    const std::string& getNombre() const;
    const std::string& getDescripcion() const;
    bool isRentado() const;
    bool isEliminado() const;
    // setters
    void setIdAlfa(const std::string& idAlfa);
    void setNombre(const std::string& nombre);
    void setDescripcion(const std::string& descripcion);
    void setRentado(bool rentado);
    void setEliminado(bool eliminado);

private:
    static int nextId;
    int id;
    std::string idAlfa;
    std::string nombre;
    std::string descripcion;
    bool rentado;
    bool eliminado;
};

#endif // ACTIVO_H