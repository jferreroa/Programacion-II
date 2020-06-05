#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <memory>
#include "persona.h"
template<class T>
class Data{
private:
    std::string key;
    T value;
public:
    Data(std::string key, const  T &value){
        this->key = key;
        this->value = value;
    }
    Data(){}
std::string getKey()const {
    return key;
}
    friend std::ostream & operator << (std::ostream & oss, const Data<T> &d){
        oss <<"Key: " << d.key<< std::endl;
        oss <<"Value:{ " << *d.value << "}"<< std::endl;
        return oss;
    }



};

#endif // DATA_H
