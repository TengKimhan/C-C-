#include "Matrix.hpp"

//for cout operation
ostream &operator<<( ostream &coout, const Matrix& n ) 
{
    for(int i=0; i<n.rows; i++) 
    {
        for(int j=0; j<n.columns; j++)
            {
                coout << setw(14) << n.p[i][j];
            }
        coout << endl;
    }
    return coout;
}

// for cin operation
istream &operator>>( istream  &ciin, Matrix &n ) 
{
    delete [] n.p;
    cout<<"Enter the number of Rows and Columns: ";
    ciin>>n.rows>>n.columns;
    n.p = new float *[n.rows];
    for(int i=0; i<n.rows; i++) {
        n.p[i] = new float[n.columns];
    }
    cout << "Enter the " << n.rows << " rows of the matrix:" << endl;

    for(int i=0; i<n.rows; i++) 
    {
        cout << "Enter the " << n.columns << " elements of row number " << i+1 << ": ";
        for(int j=0; j<n.columns; j++)
            {
                ciin >> n.p[i][j];
            }
    }
    return ciin;
}

// for additional operation
Matrix Matrix::operator+(const Matrix& n) const 
{
    int i, j;
    Matrix tempMatrix(n.rows, n.columns);

    for(i=0; i<n.rows; i++) 
    {
        for(j=0; j<n.columns; j++) 
        {
            tempMatrix.p[i][j] = p[i][j] + n.p[i][j];
        }
    }
    return tempMatrix;
};

// multiple operation
Matrix operator*(const Matrix& A, const Matrix& B) 
{
    float sum;
    int i, j, k, n, m, l;
    n = A.rows;
    m = A.columns;
    l = B.columns;
    Matrix tempMatrix(n, l);
    
    for(i=0; i<n; i++) 
    {
        for(j=0; j<l; j++) 
        {
            sum = 0;
            for(k=0; k<m ; k++)
            {
                sum = sum + A.p[i][k] * B.p[k][j];
            }
            tempMatrix.p[i][j] = sum;
        }
    }
    return tempMatrix;
}

// right mult
Matrix operator*(const Matrix& A, float num)
{
    Matrix tempMatrix(A.rows, A.columns);

    for(int i=0;i<A.rows;i++)
    {
        for(int j=0;j<A.columns;j++)
        {
            tempMatrix.p[i][j] = A.p[i][j] * num;
        }
    }
    return tempMatrix;
}

//left mult
Matrix operator*(float num, const Matrix& B)
{
    Matrix tempMatrix(B.rows, B.columns);
    for(int i=0;i<B.rows;i++)
    {
        for(int j=0;j<B.columns;j++)
        {
            tempMatrix.p[i][j] = B.p[i][j] * num;
        }
    }
    return tempMatrix;
}

Matrix::Matrix(int r, int c) 
{
    int i, j;
    rows = r;
    columns = c;

    p = new float *[rows];
    assert(p != NULL);
    for(i=0; i<rows; i++) 
    {
        p[i] = new float[columns];
        assert(p[i] != NULL);
    }

    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            p[i][j] = 0;
        }
    }
}
