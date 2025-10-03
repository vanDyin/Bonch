#ifndef IMPROVEDARRAY_H
#define IMPROVEDARRAY_H

class ImprovedArray {
private: 
    int* data;
    int size;
    int capacity;

public:
    //Конструкторы
    ImprovedArray();
    ImprovedArray(int cap);
    ImprovedArray(const ImprovedArray& other);

    //Деструктор
    ~ImprovedArray();

    //Методы
    void print();
    void append(int element);
    void input();
    void copy(const ImprovedArray& other);
    void insert(const ImprovedArray& other, int pos);
    int findMax();
};

#endif