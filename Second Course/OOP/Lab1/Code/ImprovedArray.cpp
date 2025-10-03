#include <iostream>
#include "ImprovedArray.h"
using namespace std;

//Конструкторы
ImprovedArray::ImprovedArray() {
    data = nullptr;
    size = 0;
    capacity = 0;
    cout << "Empty array has been created\n" << endl;
}

ImprovedArray::ImprovedArray(int cap) {
    capacity = cap;
    size = 0;
    data = new int[capacity];
    cout << "\nArray with capacity of " << capacity << " elements has been created\n" << endl;
}

ImprovedArray::ImprovedArray(const ImprovedArray& other) {
    capacity = other.capacity;
    size = other.size;
    data = other.data;
    cout << "Array copy was created" << endl;
}

//Деструктор
ImprovedArray::~ImprovedArray() {
    delete[] data;
    cout << "Array was deleted" << endl;
}

//Методы
void ImprovedArray::print() {
    cout << "Array [" << size << "/" << capacity << "]: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void ImprovedArray::append(int element) {
    if (size < capacity) {
        data[size] = element;
        size++;
        cout << "New element " << element << " was added" << endl;
    } else {
        cout << "Error: array is full\n" << endl;
    }
}

void ImprovedArray::input() {
    cout << "How many element do you want to adds? (maximum: " << capacity << "): ";
    int count;
    cin >> count;

    if (count > capacity - size) {
        cout << "Error: Too many elements, total: " << capacity-size << endl;
        return;
    }

    cout << "Enter " << count << " integers: ";
    for (int i = 0; i < count ; i++) {
        int element; 
        cin >> element;
        append(element);
    }
}

void ImprovedArray::copy(const ImprovedArray& other) {
    delete[] data;

    capacity = other.capacity;
    size = other.size;
    data = new int[capacity];

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    cout << "Array was copied" << endl;
}

void ImprovedArray::insert(const ImprovedArray& other, int pos) {
    if (pos < 0 || pos > size) {
        cout << "Error: uncorrected value" << endl;
        return;
    }

    if (size + other.size > capacity) {
        cout << "Not enough space" << endl;
        return;
    }

    for (int i = size - 1; i >= pos; i--) {
        data[i + other.size] = data [i];
    }

    for (int i = 0; i < other.size; i++) {
        data[i + pos] = other.data[i];
    }

    size += other.size;
    cout << "Array has been inserted" << endl;
}

int ImprovedArray::findMax() {
    if (size == 0) {
        cout << "Array is Empty" << endl;
    }

    int max = data[0];
    for (int i = 0; i < size; i++) {
        if (max < data[i]) {
            max = data[i];
        }
    }

    return max;
}