#include <iostream>
#include "ComplexNumber.h"
using namespace std;

int main() {
    ComplexNumber n1(2, 4);
    ComplexNumber n2(5, -5);

    ComplexNumber sum = n1.add(n2);
    cout << "n1 + n2 = ";
    sum.print();

    ComplexNumber substract = n1.substract(n2);
    cout << "n1 - n2 = ";
    substract.print();

    ComplexNumber multiply = n1.multiply(n2);
    cout << "n1 * n2 = ";
    multiply.print();

    ComplexNumber divide = n1.divide(n2);
    cout << "n1 / n2 = ";
    divide.print();

    return 0;
}