#include "persona.h"



std::string Persona::getNombre() const
{
    return nombre;
}

void Persona::setNombre(const std::string &value)
{
    nombre = value;
}

std::string Persona::getNacimiento() const
{
    return nacimiento;
}

void Persona::setNacimiento(const std::string &value)
{
    nacimiento = value;
}

std::string Persona::getTelefono() const
{
    return telefono;
}

void Persona::setTelefono(const std::string &value)
{
    telefono = value;
}

Persona::Persona(std::string nombre1, std::string nacimiento1, std::string numTel)
{
    this->nombre = nombre1;
    this->nacimiento = nacimiento1;
    this->telefono = numTel;
}
