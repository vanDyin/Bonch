#include "complex.h"

void Complex::calculateModulus() {
    modulus = std::sqrt(real * real + imag * imag);
}

Complex::Complex(double r, double i) : real(r), imag(i) {
    calculateModulus();
}

double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}

double Complex::getModulus() const {
    return modulus;
}

void Complex::setReal(double r) {
    real = r;
    calculateModulus();
}

void Complex::setImag(double i) {
    imag = i;
    calculateModulus();
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    double newReal = real * other.real - imag * other.imag;
    double newImag = real * other.imag + imag * other.real;
    return Complex(newReal, newImag);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imag * other.imag;
    if (denominator == 0) {
        throw std::runtime_error("Division by zero");
    }
    
    double newReal = (real * other.real + imag * other.imag) / denominator;
    double newImag = (imag * other.real - real * other.imag) / denominator;
    return Complex(newReal, newImag);
}

void Complex::display() const {
    if (imag >= 0) {
        std::cout << real << " + " << imag << "i";
    } else {
        std::cout << real << " - " << -imag << "i";
    }
    std::cout << " (modulus: " << modulus << ")";
}