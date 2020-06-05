#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <ostream>
#include<memory>
class Persona{
private:
    std::string nombre;
   std::string nacimiento;
    std::string telefono;
public:
    Persona(std::string nombre,std::string nacimiento, std::string numTel);


    friend std::ostream & operator << (std::ostream & oss, const Persona  &d){
        oss <<"Nombre: " << d.nombre<< std::endl;
        oss <<"Nacimiento: " <<d.nacimiento<< std::endl;
        oss <<"Telefono: " << d.telefono << std::endl;
        return oss;
    }

    std::string getNombre() const;
    void setNombre(const std::string &value);
    std::string getNacimiento() const;
    void setNacimiento(const std::string &value);
    std::string getTelefono() const;
    void setTelefono(const std::string &value);
};

#endif // PERSONA_H
