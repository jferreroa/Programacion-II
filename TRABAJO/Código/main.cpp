#include <iostream>
#include <fstream>
#include <string>
#include "sudoku.h"
#include <vector>

Sudoku lectura(const std::string &a){
    Sudoku ref;
    std::vector<int> elementos;
    std::ifstream archivo(a,std::ios::in);
    if(archivo.fail()) throw std::string{"No se pudo abrir el archivo \n"};
    std::cout << std::endl;
    std::cout << "RECOGIENDO DATOS...  \n";
    std::cout << std::endl;
    for(std::string fila; getline(archivo,fila);){
         std::cout << "--> " << fila << " <--" << std::endl;

        for(char elem : fila){
            if(elem != ' '){
                if(elem == '-'){
                    elementos.push_back(0);
                }else{
                    elementos.push_back(elem-'0');
                }
            }
        }
    }
    std::cout << std::endl;
    std::cout << "PROCESANDO DATOS...  \n";
    int cont = 0;
    for(int k = 0; k <9 ; k++){
        for(int o = 0; o<9; o++){

            ref.set(k,o,elementos.at(0+cont));
            cont++;
        }
    }
    archivo.close();
    return ref;
}
int main(){
    try {








        std::string ruta;
        std::cout  << "Ruta de acceso al aechivo:  " << std::endl;
        getline(std::cin,ruta);
        //std::cin >> ruta;
        Sudoku s2 = lectura(ruta);
        std::cout << std::endl;
        s2.print();
        std::cout << "--------------\n";
        s2.solve();
        std::cout << "--------------\n";
        std::cout << "---SOLUCION---" << std::endl;
        std::cout << std::endl;
        s2.print();


    }catch(std::string a ){
        std::cout << a;
    }

    return 0;
}
