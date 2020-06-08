#ifndef LISTA_H
#define LISTA_H
#include <vector>
#include <functional>
#include <ostream>
template <class T>
class Lista{

private:
    std::vector <T> miLista;
public:
    std::vector <T> getLista() const{
        return miLista;
    }
    void push_back(const T &a){
        miLista.push_back(a);
    }

    void forEach(const std::function <void(T,int)> &op) const {
        for (unsigned int i = 0; i<miLista.size(); i++){
            (op(miLista.at(i), i));
        }
    }

    T find(const std::function<bool(T, int)> &op){
        for(unsigned int i=0; i<miLista.size(); i++){
            if(op(miLista.at(i), i)){
                return(miLista.at(i));
            }
        }
        throw std::string {"NO ENCONTRADO"};
    }



    Lista<T> filter(const std::function <bool(T, int)> &op){
        Lista<T> result;
        for(unsigned int i=0; i<miLista.size(); i++){
            if(op(miLista.at(i), i)){
                result.push_back(miLista.at(i));
            }
        }
        return result;
    }


    Lista<T> map(const std::function <T(T,int)> &op){
        Lista<T> result;
        for(unsigned int i=0; i<miLista.size(); i++){
            result.push_back(op(miLista.at(i), i));
        }
        return result;
    }

    friend std::ostream & operator <<(std::ostream & oss, const Lista<T> &datos){
        for(auto elem: datos.getLista()){
            oss << elem << " ";
        }
        return oss;
    }

    Lista(){};


};

#endif // LISTA_H
