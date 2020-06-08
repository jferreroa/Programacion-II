#include "figure.h"



Figure::Figure(const std::string &type){
            this->type = type;
}

std::string Figure::getType() const{
    return type;
}

void Figure::setType(const std::string &type){
    this->type = type;
}
