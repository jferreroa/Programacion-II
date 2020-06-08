#include <iostream>

#include "DB.h"
int main(){

    try{

        Pair<std::string, std::string>pareja1 ("Nombre", "Julian");
        Pair<std::string, std::string>pareja1_2 ("Apellido", "Santurche");
        Pair<std::string, std::string>pareja1_3 ("Telefono", "32323232");

        Data<std::string,std::string> datos;

        datos.insert(pareja1);
        datos.insert(pareja1_2);
        datos.insert(pareja1_3);

        Data<std::string,std::string> datos2;

        Pair<std::string, std::string>pareja2 ("Nombre", "Alberto");
        Pair<std::string, std::string>pareja2_2 ("Apellido", "Valero");
        Pair<std::string, std::string>pareja2_3 ("Telefono", "12345644");
        datos2.insert(pareja2);
        datos2.insert(pareja2_2);
        datos2.insert(pareja2_3);


        Data<std::string,std::string> datos3;

        Pair<std::string, std::string>pareja3 ("Nombre", "Julian");
        Pair<std::string, std::string>pareja3_2 ("Apellido", "Romeva");
        Pair<std::string, std::string>pareja3_3 ("Telefono", "12345644");
        Pair<std::string, std::string>pareja3_4 ("DNI", "23232334J");
        datos3.insert(pareja3);
        datos3.insert(pareja3_2);
        datos3.insert(pareja3_3);
        datos3.insert(pareja3_4);

        Data<std::string,std::string> datos5;
        Pair<std::string, std::string>pareja5 ("Nombre", "Lucrecia");
        Pair<std::string, std::string>pareja5_2 ("Apellido", "Aveces");
        Pair<std::string, std::string>pareja5_3 ("Correo", "lalucre@gmail.com");
        datos5.insert(pareja5);
        datos5.insert(pareja5_2);
        datos5.insert(pareja5_3);

        DB<std::string,std::string> mydatabase;

        mydatabase.insert(&datos);
        mydatabase.insert(&datos2);
        mydatabase.insert(&datos3);
        mydatabase.insert(&datos5);

        std::cout << "Print: " << std::endl;
        std::cout << mydatabase;

        std::cout << "------------------------PRUEBA FOREACH " << std::endl;
        mydatabase.forEach([](Data<std::string,std::string>*a) -> void {std::cout << *a << std::endl;});

        DB<std::string,std::string> filter;
        filter = mydatabase.filter([](Data<std::string,std::string>*a) -> bool {return a->value("Nombre")=="Julian";});
        std::cout << "-----------------Filer: " << std::endl;
        std::cout << filter << std::endl;

        Data<std::string,std::string> finded;
        finded = *mydatabase.find([](Data<std::string,std::string>*a) -> bool {return a->value("Nombre")=="Julian";});
        std::cout << "-----------------Finded: " << std::endl;
        std::cout << finded << std::endl;

    }catch(std::string a){
        std::cout << a << std::endl;
    }

    return 0;
}
