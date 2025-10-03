#include <iostream>
#include "Complex.h"

int main() {
    Complex c1(3, 4);
    Complex c2(1, -2);
    
    std::cout << "c1 = ";
    c1.print();
    std::cout << "c2 = ";
    c2.print();
    
    Complex sum = c1 + c2;
    std::cout << "c1 + c2 = ";
    sum.print();
    
    Complex diff = c1 - c2;
    std::cout << "c1 - c2 = ";
    diff.print();
    
    Complex mult = c1 * c2;
    std::cout << "c1 * c2 = ";
    mult.print();
    
    Complex div = c1 / c2;
    std::cout << "c1 / c2 = ";
    div.print();
    
    return 0;
}