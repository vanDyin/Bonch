#include "ComplexNumber.h"
#include <iostream>
using namespace std;

ComplexNumber::ComplexNumber() {
    real = 0.0;
    image = 0.0;
}

ComplexNumber::ComplexNumber(double r, double i) {
    real = r;
    image = i;
}

ComplexNumber ComplexNumber::add(const ComplexNumber& other) const {
    double r = real + other.real;
    double i = image + other.image;
    return ComplexNumber(r, i);
}

ComplexNumber ComplexNumber::substract(const ComplexNumber& other) const {
    double r = real - other.real;
    double i = image - other.image;
    return ComplexNumber(r, i);
}

ComplexNumber ComplexNumber::multiply(const ComplexNumber& other) const {
    double r = real * other.real - image * other.image;
    double i = real * other.image + image * other.real;
    return ComplexNumber(r, i);
}

ComplexNumber ComplexNumber::divide(const ComplexNumber& other) const {
    double denominator = other.real * other.real + other.image * other.image;

    if (denominator == 0) {
        return ComplexNumber(0, 0);
    }

    double r = (real * other.real + image * other.image) / denominator;
    double i = (image * other.real - real * other.image) / denominator;
    return ComplexNumber(r, i);
}

void ComplexNumber::print() {
    cout << real << (image >= 0 ? " + " : " - ") << abs(image) << "i" << endl;
}
