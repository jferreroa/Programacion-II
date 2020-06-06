#include "matriz.h"
#include <iostream>

Matriz::Matriz(unsigned int m, unsigned int n){
    this->m = m;
    this->n = n;
    matriz = std::vector<float>(m*n, 0);
}

unsigned int Matriz::getRows() const{
    return m;
}

unsigned int Matriz::getCols() const{
    return n;
}

void Matriz::set(unsigned int row, unsigned int col, float value){
    if(row < m and col < n){
        int index = row * n + col;
        matriz[index] = value;
    } else {
        throw std::string{"Error, no puedes hacer eso"};
    }
}

float Matriz::get(unsigned int row, unsigned int col) const{
    if(row >= m or col >= n){
        throw std::string{"Error, no puedes hacer eso"};
    }
    int index = row * n + col;
    return matriz[index];
}

float Matriz::atPos(unsigned int num) const
{
    return matriz.at(num);
}

void Matriz::print() const
{
    for(unsigned int i = 0; i < m; i++){
        for(unsigned int j = 0; j < n; j++){
            int index = i*n + j;
            std::cout << matriz[index] << "\t";
        }
        std::cout << std::endl;
    }
}

void Matriz::add(const Matriz &a){
    if(this->m != a.getRows() || this->n != a.getCols()){
        throw std::string{"Error, no puedes hacer eso"};
    }
    for(unsigned int i  =0; i<matriz.size(); i++){
        matriz[i] = matriz[i] + a.atPos(i);
    }
}

Matriz Matriz::multiplyBy(const Matriz &a){
    if(this->n != a.getRows()){
        throw std::string{"Error, no puedes hacer eso"};
    }
    Matriz result(m,a.getCols());
    for (unsigned int i = 0; i < this->getRows(); i++ ){
        for (unsigned int k = 0; k < a.getCols(); k++){
            float suma = 0;
            for (unsigned int j = 0; j < a.getRows(); j++){
                suma += this->get(i, j) * a.get(j, k);
            }
            result.set(i, k, suma);
        }
    }
    return result;
}
