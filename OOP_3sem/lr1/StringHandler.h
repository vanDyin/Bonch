#ifndef STRINGHANDLER_H
#define STRINGHANDLER_H

class String {
private:
    char* data;

public:
    String();
    String(const char* str);
    String(const String& other);
    String& operator=(const String& other);
    ~String();

    int Length() const;
    void Copy(const String str);
    int Find(char ch, int start) const;
    int FindLast(char ch) const;
    String Substr(int index, int count) const;
    void Remove(int index, int count);
    void Insert(char* s, int index);
    void print() const;
};

#endif