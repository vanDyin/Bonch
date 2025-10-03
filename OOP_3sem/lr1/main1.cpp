#include <iostream>
#include "StringHandler.h"

int main() {
    String str1;
    str1.Insert("Hello World", 0);
    str1.print();
    
    std::cout << "Length: " << str1.Length() << std::endl;
    
    String str2;
    str2.Copy(str1);
    str2.print();
    
    std::cout << "Find 'o' from pos 0: " << str1.Find('o', 0) << std::endl;
    std::cout << "Find last 'l': " << str1.FindLast('l') << std::endl;
    
    String substr = str1.Substr(6, 5);
    substr.print();
    
    str1.Remove(5, 6);
    str1.print();
    
    str1.Insert(" C++", 5);
    str1.print();

    return 0;
}



