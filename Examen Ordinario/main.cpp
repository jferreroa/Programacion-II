#include <iostream>
#include "persona.h"
#include "Data.h"
#include <vector>
#include "Lista.h"

int main(){
    //creacion de personas
    std::shared_ptr<Persona> a (std::make_shared<Persona>("Paco","1900","618932800"));
    std::shared_ptr<Persona> b (std::make_shared<Persona>("Antonio","2000","242234098"));
    //std::cout << *a;

    //creacion de parejas
    Data<std::shared_ptr<Persona>> key1("1131",a);
    std::cout << "KEY 1: \n";
    std::cout << key1 << std::endl;
    Data<std::shared_ptr<Persona>> key2("23421",b);
    std::cout << "KEY 2: \n";
    std::cout << key2 << std::endl;

    //vector
    std::cout << "-------UNIR LISTAS: \n";
    Lista vec4;
    vec4.add(key1);
    Lista vec2;
    vec2.add(key2);
    Lista vec3 = vec4.unirListas(vec2);
    std::cout << vec3;
    std::cout << "MENU: \n";
    std::cout << std::endl;
    Lista vec;
    std::cout << " -------------" << std::endl;
    int numero = 9;
    while(numero != 0){
        std::cout << "1. Anadir una persona \n";
        std::cout << "2. Mostrar el listado \n";
        std::cout << "3. Buscar una persona por clave \n";
        std::cout << "4. Borrar una persona por clave \n";
        std::cout << "0. Salir \n";
        std::cin >> numero;
        if(numero == 1){
            std::cout << "INTRODUCE NOMBRE, NACIMIENTO, TELEFONO Y NUMERO CLAVE: \n";
            std::string a,b,c,d;
            std::cin>>a;
            std::cin>>b;
            std::cin>>c;
            std::cin>>d;
            std::shared_ptr<Persona> persona (std::make_shared<Persona>(a,b,c));
            Data<std::shared_ptr<Persona>> key1(d,persona);
            vec.add(key1);
        }else if(numero == 2){
            std::cout << vec;
        }else if(numero == 3){
            std::cout << "INTRODUCE CLAVE DE LA PERSONA QUE QUIERAS BUSCAR: \n";
            std::string a;
            std::cin>> a;
            std::shared_ptr<Data<std::shared_ptr<Persona>>> P = vec.buscarPorClave(a);
            std::cout << *P<< std::endl;
            std::cout << std::endl;
        }else if(numero == 4){
            std::cout << "INTRODUCE CLAVE DE LA PERSONA QUE QUIERAS ELIMINAR: \n";
            std::string a;
            std::cin>> a;
            vec.eliminar(a);
        }
    }
    return 0;
}
