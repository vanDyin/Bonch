#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
private:
    char* ptr;

public:
    // Конструкторы
    String();
    String(const char* str);
    
    // Деструктор
    ~String();
    
    // Методы
    int Length() const;
    void Copy(const String& str);
    int Find(char ch, int start = 0) const;
    int FindLast(char ch) const;
    String Substr(int index, int count) const;
    void Remove(int index, int count);
    void Insert(const char* s, int index);
    void print() const;
    
    // Дружественные функции
    friend std::ostream& operator<<(std::ostream& os, const String& str);
};

#endif // STRING_H