#include "String.h"
#include <cstring>
#include <algorithm>

// Конструктор по умолчанию
String::String() : ptr(nullptr) {}

// Конструктор из C-строки
String::String(const char* str) {
    if (str) {
        ptr = new char[strlen(str) + 1];
        strcpy(ptr, str);
    } else {
        ptr = nullptr;
    }
}

// Деструктор
String::~String() {
    delete[] ptr;
}

// Длина строки
int String::Length() const {
    return ptr ? strlen(ptr) : 0;
}

// Копирование строки
void String::Copy(const String& str) {
    delete[] ptr;
    if (str.ptr) {
        ptr = new char[strlen(str.ptr) + 1];
        strcpy(ptr, str.ptr);
    } else {
        ptr = nullptr;
    }
}

// Поиск символа с позиции start
int String::Find(char ch, int start) const {
    if (!ptr || start < 0 || start >= Length()) {
        return -1;
    }

    for (int i = start; ptr[i] != '\0'; i++) {
        if (ptr[i] == ch) {
            return i;
        }
    }
    return -1;
}

// Поиск последнего вхождения символа
int String::FindLast(char ch) const {
    if (!ptr) return -1;

    for (int i = Length() - 1; i >= 0; i--) {
        if (ptr[i] == ch) {
            return i;
        }
    }
    return -1;
}

// Выделение подстроки
String String::Substr(int index, int count) const {
    if (!ptr || index < 0 || index >= Length() || count <= 0) {
        return String();
    }

    int actualCount = std::min(count, Length() - index);
    char* sub = new char[actualCount + 1];
    
    strncpy(sub, ptr + index, actualCount);
    sub[actualCount] = '\0';

    String result(sub);
    delete[] sub;
    return result;
}

// Удаление подстроки
void String::Remove(int index, int count) {
    if (!ptr || index < 0 || index >= Length() || count <= 0) 
        return;

    int len = Length();
    int actualCount = std::min(count, len - index);

    for (int i = index; i <= len - actualCount; i++) {
        ptr[i] = ptr[i + actualCount];
    }

    char* newPtr = new char[len - actualCount + 1];
    strcpy(newPtr, ptr);
    delete[] ptr;
    ptr = newPtr;
}

// Вставка C-строки
void String::Insert(const char* s, int index) {
    if (!s) return;
    
    int len = Length();
    int sLen = strlen(s);
    
    index = std::max(0, std::min(index, len));
    
    char* newData = new char[len + sLen + 1];
    
    // Копируем начало
    if (index > 0) {
        strncpy(newData, ptr, index);
    }
    newData[index] = '\0';
    
    // Вставляем новую строку
    strcat(newData, s);
    
    // Копируем оставшуюся часть
    if (index < len) {
        strcat(newData, ptr + index);
    }
    
    delete[] ptr;
    ptr = newData;
}

// Вывод на экран
void String::print() const {
    if (ptr) {
        std::cout << ptr;
    }
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const String& str) {
    if (str.ptr) {
        os << str.ptr;
    }
    return os;
}