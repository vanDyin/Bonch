#include "Complex.h"
#include <cmath>
#include <iostream>

Complex::Complex(){
    real = 0;
    imag = 0; 
    modulus = 0; 
}

Complex::Complex(double r, double i){
    real = r;
    imag = i; 
    updateModulus();
}

void Complex::updateModulus() {
    modulus = sqrt(real * real + imag * imag);
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    double r = real * other.real - imag * other.imag;
    double i = real * other.imag + imag * other.real;
    return Complex(r, i);
}

Complex Complex::operator/(const Complex& other) const {
    double a = other.real * other.real + other.imag * other.imag;

    if (a == 0) {
        return Complex(0, 0);
    }
    double r = (real * other.real + imag * other.imag) / a;
    double i = (imag * other.real - real * other.imag) / a;
    return Complex(r, i);
}

void Complex::print() const {
    if (imag >= 0) {
        std::cout << real << " + " << imag << "i (modulus: " << modulus << ")" << std::endl;
    } else {
        std::cout << real << " - " << -imag << "i (modulus: " << modulus << ")" << std::endl;
    }
}