#ifndef COMPLE_H
#define COMPLEX_H

class Complex {
private:
    double real;
    double imag;
    double modulus;
    void updateModulus();

public:
    Complex();
    Complex(double r, double i);
    
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    
    void print() const;
};

#endif

