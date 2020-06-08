#ifndef PAIR_H
#define PAIR_H
#include <ostream>
template <class T, class Y>
class Pair{

private:
    T key;
    Y value;

public:
    Pair(const T &v1, const Y &v2);
    T getKey() const;
    Y getValue() const;
    void setKey(const T &key);
    void setValue(const Y &value);



    friend std::ostream & operator <<(std::ostream & oss, Pair<T,Y> const & p){
        oss << p.key << ": "<< p.value << std::endl;
    return oss;
    }


};

template<class T, class Y>
Pair<T,Y>::Pair(const T &v1, const Y &v2){
    this->key = v1;
    this->value = v2;
}

template<class T, class Y>
T Pair<T,Y>::getKey() const{
    return this->key;
}

template<class T, class Y>
Y Pair<T,Y>::getValue() const{
    return this->value;
}

template<class T, class Y>
void Pair<T,Y>::setKey(const T &key){
    this->key = key;
}

template<class T, class Y>
void Pair<T,Y>::setValue(const Y &value){
    this->value = value;
}



#endif // PAIR_H
