#include <iostream>
#include "Lista.h"


int main(){
    Lista<int> milista;
    milista.push_back(1);
    milista.push_back(2);
    milista.push_back(0);
    milista.push_back(3);
    milista.push_back(2);
    milista.push_back(5);
    std::cout << "----------FOREACH: " <<std::endl;
    milista.forEach([](int a,int b) -> void {std::cout << 2*a << " "<< b << " ";});
    std::cout << std::endl;
    //std::cout << milista;


    std::cout << "----------FIND: " <<std::endl;
    int finded =  milista.find([](int a, int b) -> bool {return (a%1==0 && b%2 ==0);});
    std::cout << finded << std::endl;

    std::cout << "----------FILTER: " <<std::endl;
    Lista<int> res = milista.filter([](int a, int b) -> bool {return ((a%1==0) && ((b+a)%2 ==0));});
    res.forEach([](int a, int b) -> void {std::cout << a << " " << b << " ";});
    std::cout << std::endl;

    std::cout << "-----MAP" << std::endl;
    Lista<int> miotralista = milista.map([](int a, int b) -> int {return (2*a && b);});
    std::cout << miotralista << " ";
    std::cout << std::endl;






    return 0;
}
