#include <iostream>
#include "ImprovedArray.h"
using namespace std;

int main() {
    ImprovedArray array(5);

    array.append(10);
    array.append(20);
    array.append(30);
    array.print();

    ImprovedArray array1(3);
    array1.input();
    array1.print();

    ImprovedArray array2(2);
    array2.append(100);
    array2.append(200);
    array2.append(300);
    array2.print();

    ImprovedArray copy(array);
    copy.print();
    cout << "Copy" << endl;
    array.print();
    copy.print();
    cout << &array << "\n" << &copy << endl;

    array.insert(array2, 1);
    array.print();
    cout << "Max: " << array.findMax() << endl;

    cout << "\nCompleted" << endl;

    return 0;
};