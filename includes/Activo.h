#ifndef ACTIVO_H
#define ACTIVO_H

#include <string>

class Activo {
public:
    Activo(int id, const std::string& nombre, const std::string& descripcion, const std::string& idAlfa);
    int getId() const;
    const std::string& getIdAlfa() const;
    const std::string& getName() const;
    const std::string& getDescription() const;
    void setName(const std::string& nombre);
    void setDescription(const std::string& descripcion);
    void setIdAlfa(const std::string& idAlfa);
    bool isRented() const;
    void setRented(bool rentado);
    bool isDeleted() const;
    void setDeleted(bool eliminado);

private:
    int id;
    std::string idAlfa;
    std::string nombre;
    std::string descripcion;
    bool rentado;
    bool eliminado;
};

#endif // ACTIVO_H