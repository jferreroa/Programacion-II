#ifndef DB_H
#define DB_H
#include "data.h"
#include <functional>
#include <iostream>
#include "pair.h"
template <class T, class Y>
class DB{

private:
    std::vector<Data<T,Y>*> database;

public:
   std::vector<Data<T,Y>*> getLista(){
        return this->database;
    }

    void insert(Data<T,Y> *v){
        database.push_back(v);
    }


    Data<T,Y>* find(const std::function<bool(Data<T,Y>*)> &op){
        for(auto elem: database){
            if(op(elem)) return elem;
        }
        throw  std::string{"Not found"};
    }
    DB<T,Y> filter(const std::function<bool(Data<T,Y>*)> &op) const{
        DB<T,Y> res;
        for(auto elem: database){
            if(op(elem)) res.insert(elem);
        }
        return res;
    }

    void forEach(const std::function<void(Data<T,Y>*)> &op) const{
        for (auto elem: database){
            op(elem);
        }
    }


    friend std::ostream & operator <<(std::ostream & oss,  DB<T,Y> datos){
        for(auto elem: datos.getLista()){
            oss << *elem << "\n";
        }
        return oss;
    }




};

#endif // DB_H
