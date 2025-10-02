#include "complex.h"

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    try {
        // Создание комплексных чисел
        Complex a(3.0, 4.0);
        Complex b(1.0, -2.0);
        Complex c(0.0, 1.0); // i
        Complex d(2.0, 0.0); // действительное число

        std::cout << "Комплексные числа:" << std::endl;
        std::cout << "a = ";
        a.display();
        std::cout << std::endl;

        std::cout << "b = ";
        b.display();
        std::cout << std::endl;

        std::cout << "c = ";
        c.display();
        std::cout << std::endl;

        std::cout << "d = ";
        d.display();
        std::cout << std::endl << std::endl;

        // Демонстрация операций
        std::cout << "Операции:" << std::endl;
        
        Complex sum = a + b;
        std::cout << "a + b = ";
        sum.display();
        std::cout << std::endl;

        Complex diff = a - b;
        std::cout << "a - b = ";
        diff.display();
        std::cout << std::endl;

        Complex prod = a * b;
        std::cout << "a * b = ";
        prod.display();
        std::cout << std::endl;

        Complex quot = a / b;
        std::cout << "a / b = ";
        quot.display();
        std::cout << std::endl << std::endl;

        // Дополнительные примеры
        std::cout << "Дополнительные примеры:" << std::endl;
        
        Complex prod2 = c * c; // i * i = -1
        std::cout << "i * i = ";
        prod2.display();
        std::cout << std::endl;

        Complex quot2 = a / d; // деление на действительное число
        std::cout << "a / 2 = ";
        quot2.display();
        std::cout << std::endl;

        // Тестирование сеттеров
        std::cout << std::endl << "Тестирование сеттеров:" << std::endl;
        Complex test(1.0, 1.0);
        std::cout << "Исходное: ";
        test.display();
        std::cout << std::endl;
        
        test.setReal(5.0);
        std::cout << "После setReal(5.0): ";
        test.display();
        std::cout << std::endl;
        
        test.setImag(-3.0);
        std::cout << "После setImag(-3.0): ";
        test.display();
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}