#ifndef LISTA_H
#define LISTA_H
#include "Data.h"
#include<persona.h>
#include <vector>
class Lista{
private:
    std::vector<std::shared_ptr<Data<std::shared_ptr<Persona>>>> vec;
public:
    Lista(){};
    void add(Data<std::shared_ptr<Persona>> u){
        std::shared_ptr<Data<std::shared_ptr<Persona>>> j(std::make_shared<Data<std::shared_ptr<Persona>>>(u));
        vec.push_back(j);
    }
    friend std::ostream & operator << (std::ostream & oss,const  Lista &d){
        for(auto const &elem: d.vec){
            oss << *elem;
        }
        return oss;
    }

    void eliminar(const std::string &clave){
        for(unsigned int i = 0; i < vec.size();i++){
            if((vec.at(i)->getKey()) == clave){
                vec.erase(vec.begin() + i);
                std::cout << "Se ha eliminado a la persona de la lista\n";
                std::cout << std::endl;
            }
        }
    }

    std::shared_ptr<Data<std::shared_ptr<Persona>>> buscarPorClave(const std::string &clave){
        for(unsigned int i = 0; i < vec.size();i++){
            if((vec.at(i)->getKey()) == clave){
                return vec.at(i);

            }
        }

        return nullptr;
    }

    //unir listas
    void push(std::shared_ptr<Data<std::shared_ptr<Persona>>> j){
        vec.push_back(j);
    }
    int sizeL()const {
        return vec.size();
    }
    std::shared_ptr<Data<std::shared_ptr<Persona>>> pos(int num)const{
        return  vec.at(num);
    }
    Lista unirListas(const Lista &a){
        Lista res;
        for(unsigned int i = 0; i < vec.size();i++){
                res.push(vec.at(i));
            }
        for(int i = 0; i < a.sizeL();i++){
            res.push(a.pos(i));
        }
        return res;
    }
};

#endif // LISTA_H
