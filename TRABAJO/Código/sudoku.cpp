#include "sudoku.h"

Sudoku::Sudoku()
{
    this->m = 9;
    this->n = 9;
    grid = std::vector<unsigned int>(m*n,0);
}

unsigned int Sudoku::getRows() const{
    return m;
}

unsigned int Sudoku::getCols() const{
    return n;
}

void Sudoku::set(unsigned int row, unsigned int col, float value){
    if(row < m and col < n){
        int index = row * n + col;
        grid[index] = value;
    } else {
        throw std::string{"Error, no puedes hacer eso"};
    }
}

unsigned int Sudoku::get(unsigned int row, unsigned int col) const{
    if(row >= m or col >= n){
        throw std::string{"Error, no puedes hacer eso"};
    }
    int index = row * n + col;
    return grid[index];
}

void Sudoku::print(){
    for(unsigned int i = 0; i < m; i++){
        for(unsigned int j = 0; j < n; j++){
            int index = i*n + j;
            std::cout << grid[index] << "\t";
        }
        std::cout << std::endl;
    }

}

bool Sudoku::posible(unsigned int row, unsigned int col, unsigned int num) const{
    int topX = (int(row/3))*3;
    int topY = (int(col/3))*3;
    for(int i = 0; i< 3; i++){
        for( int j =0; j < 3; j++){
            if(get(topX+i,topY+j) == num){
                return false;
            }
        }
    }
    for(int i =0; i < 9; i++){
        if(get(i,col) == num){
            return false;
        }
    }
    for(int i =0; i < 9; i++){
        if(get(row,i) == num){
            return false;
        }
    }
    return true;
}

bool Sudoku::solve(unsigned int f, unsigned int c){
    c++;
    if(c>8){
        f++;
        c=0;
    }
    if(f>8){
        return true;
    }
    else{
        if(get(f,c)==0){
            for(int v=1;v<=9;v++){
                if(posible(f,c,v)){
                    //std::cout << f << " " << c<< " " << v << " ";
                    set(f,c,v);
                    if(solve(f,c)){
                        return true;
                    }
                    else{
                        set(f,c,0);
                    }
                }
            }
            return false;
        }
        else{
            return solve(f,c);
        }
    }
}

bool Sudoku::solve(){
   return solve(-1,8);
}

