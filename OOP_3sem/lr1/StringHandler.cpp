#include "StringHandler.h"
#include <cstring>
#include <iostream>

String::String() : data(nullptr) {}

String::String(const char* str) {
    if (str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    } else {
        data = nullptr;
    }
}

String::String(const String& other) {
    if (other.data) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    } else {
        data = nullptr;
    }
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] data;
        if (other.data) {
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        } else {
            data = nullptr;
        }
    }
    return *this;
}

String::~String() {
    delete[] data;
}

int String::Length() const {
    return data ? strlen(data) : 0;
}

void String::Copy(const String str) {
    delete[] data;
    if (str.data) {
        data = new char[strlen(str.data) + 1];
        strcpy(data, str.data);
    } else {
        data = nullptr;
    }
}

int String::Find(char ch, int start) const {
    if (!data || start < 0 || start >= Length()) return -1;
    
    for (int i = start; data[i] != '\0'; i++) {
        if (data[i] == ch) {
            return i;
        }
    }
    return -1;
}

int String::FindLast(char ch) const {
    if (!data) return -1;
    
    int lastPos = -1;
    for (int i = 0; data[i] != '\0'; i++) {
        if (data[i] == ch) {
            lastPos = i;
        }
    }
    return lastPos;
}

String String::Substr(int index, int count) const {
    if (!data || index < 0 || index >= Length() || count <= 0) {
        return String();
    }
    
    int actualCount = count;
    if (index + count > Length()) {
        actualCount = Length() - index;
    }
    
    char* temp = new char[actualCount + 1];
    for (int i = 0; i < actualCount; i++) {
        temp[i] = data[index + i];
    }
    temp[actualCount] = '\0';
    
    String result(temp);
    delete[] temp;
    return result;
}

void String::Remove(int index, int count) {
    if (!data || index < 0 || index >= Length() || count <= 0) return;
    
    int len = Length();
    int actualCount = count;
    if (index + count > len) {
        actualCount = len - index;
    }
    
    int newLen = len - actualCount;
    char* newData = new char[newLen + 1];
    
    for (int i = 0; i < index; i++) {
        newData[i] = data[i];
    }
    
    for (int i = index; i < newLen; i++) {
        newData[i] = data[i + actualCount];
    }
    newData[newLen] = '\0';
    
    delete[] data;
    data = newData;
}

void String::Insert(char* s, int index) {
    if (!s || index < 0) return;
    
    int len = Length();
    int insertLen = strlen(s);
    
    if (index > len) index = len;
    
    int newLen = len + insertLen;
    char* newData = new char[newLen + 1];
    
    for (int i = 0; i < index; i++) {
        newData[i] = data[i];
    }
    
    for (int i = 0; i < insertLen; i++) {
        newData[index + i] = s[i];
    }
    
    for (int i = index; i < len; i++) {
        newData[insertLen + i] = data[i];
    }
    newData[newLen] = '\0';
    
    delete[] data;
    data = newData;
}

void String::print() const {
    if (data) {
        std::cout << data << std::endl;
    } else {
        std::cout << "(empty)" << std::endl;
    }
}