#ifndef DATA_H
#define DATA_H
#include "pair.h"
#include <vector>
template <class T, class Y>
class Data{
    private:
    std::vector <Pair<T,Y>> datos;

    public:
    void insert (const Pair<T,Y> &p);
    Y value (const T &key) const;
    Data();



    friend std::ostream & operator << (std::ostream & oss, const Data<T,Y> &v){
        for(auto elem: v.datos){
            oss << elem;

        }
        oss << std::endl;

        return oss;
    }

};

template <class T, class Y>
Data<T,Y>::Data(){}


template <class T, class Y>
void Data<T,Y>::insert(const Pair<T,Y> &p){
    /*for (auto elem: datos){
        if (elem.getKey() == p.getKey()){
            throw std::string {"No se pueden repetir claves"};
        }
    }*/
    datos.push_back(p);
}

template <class T, class Y>
Y Data<T,Y>::value(const T &key)const {
    for(auto elem: datos){
        if(elem.getKey() == key){
            return elem.getValue();
        }
    }
    throw std::string {"Key not found"};
}

#endif // DATA_H
