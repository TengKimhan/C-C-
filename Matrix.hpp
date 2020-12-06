#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <iostream>
#include<cassert>
#include <iomanip>
#include<cmath>
using namespace std;


class Matrix 
{
        friend ostream& operator<<(ostream &, const Matrix&);
        friend istream& operator>>(istream &, Matrix&);
        friend Matrix operator*(const Matrix&, const Matrix&);
        friend Matrix operator*(const Matrix&, float num);
        friend Matrix operator*(float num, const Matrix&);
    private:
        int rows, columns;
        float **p;
    public: 
        Matrix(int=1, int=1);
        Matrix operator+(const Matrix&) const;
};
#endif // MATRIX_H_INCLUDED