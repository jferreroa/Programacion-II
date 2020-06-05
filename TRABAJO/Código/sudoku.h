#ifndef SUDOKU_H
#define SUDOKU_H
#include <vector>
#include <iostream>
#include <string>
#include <ostream>

class Sudoku{
private:
    std::vector<unsigned int> grid;
    unsigned int m,n;
public:
    Sudoku();
     unsigned int getRows() const;
     unsigned int getCols() const;
     void set(unsigned int row, unsigned int col, float value);
     unsigned int get(unsigned int row, unsigned int col) const;
     void print();
     bool posible(unsigned int row, unsigned int col, unsigned int num) const;
     bool solve(unsigned int f, unsigned int  c);
     bool solve();





};

#endif // SUDOKU_H
