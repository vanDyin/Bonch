#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

class ComplexNumber {
private: 
    double real;
    double image;

public: 
    ComplexNumber();
    ComplexNumber(double r, double i);

    ComplexNumber add(const ComplexNumber& other) const;
    ComplexNumber substract(const ComplexNumber& other) const;
    ComplexNumber multiply(const ComplexNumber& other) const;
    ComplexNumber divide(const ComplexNumber& other) const;

    void print();
};


#endif