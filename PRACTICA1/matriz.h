#ifndef MATRIZ_H
#define MATRIZ_H
#include <vector>

class Matriz{
private:
    unsigned int m, n;
    std::vector<float> matriz;
public:

    Matriz(unsigned int m, unsigned int n);

        unsigned int getRows() const;
        unsigned int getCols() const;

        void set(unsigned int row, unsigned int col, float value);
        float get(unsigned int row, unsigned int col) const;
        float atPos(unsigned int num) const ;

        void print() const;

        void add(const Matriz &a);
        Matriz multiplyBy(const Matriz &a);

};

#endif // MATRIZ_H
