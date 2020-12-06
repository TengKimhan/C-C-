#include "Matrix.hpp"
#include <iostream>
using namespace std;

int main() {
   
    Matrix A, B;
    cout << "Enter the A matrix" << endl;
    cin >> A;
    cout << "Enter the B matrix" << endl;
    cin >> B; 
    
    cout << "(A * b): A * 2" << endl;
    cout << A * 2 << endl;

    cout << "(a * B): 3 * B" << endl;
    cout << 3 * B << endl;
    
    cout << "The two matrices multiplication" << endl;
    cout << A * B << endl;
    
    cout << "The two matrices addition" << endl;
    cout << A + B << endl;
   
    return 0;
}