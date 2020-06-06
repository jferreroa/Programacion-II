#include <iostream>
#include "matriz.h"
#include <random>
int main(){

    try{

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(0,10);


        Matriz m(3, 3), m2(3, 3);

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                m2.set(i, j, distribution(generator));
            }
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                m.set(i, j, distribution(generator));
            }
        }

        Matriz m4(4,4);
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                m4.set(i, j, distribution(generator));
            }
        }

        m.print();
        std::cout << std::endl;
        m2.print();
        std::cout << std::endl;
        m.add(m2);
        m.print();
        std::cout << std::endl;


        Matriz multiplay = m2.multiplyBy(m2);
        multiplay.print();

    }catch(const std::string& a){

        std::cout << a << std::endl;

    }
    return 0;
}
