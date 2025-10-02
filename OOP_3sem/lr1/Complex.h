#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>
#include <stdexcept>

class Complex {
private:
    double real;      // Действительная часть
    double imag;      // Мнимая часть
    double modulus;   // Модуль комплексного числа

    void calculateModulus(); // Вспомогательный метод для пересчета модуля

public:
    // Конструкторы
    Complex(double r = 0.0, double i = 0.0);

    // Геттеры
    double getReal() const;
    double getImag() const;
    double getModulus() const;

    // Сеттеры
    void setReal(double r);
    void setImag(double i);

    // Операции
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    // Вывод на экран
    void display() const;
};

#endif
