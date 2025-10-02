#include "String.h"

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Создаём строку
    String s = "Hello, World!";
    
    // Тестируем методы
    std::cout << "Длина: " << s.Length() << std::endl;
    
    // Поиск символов
    std::cout << "Первая 'o': " << s.Find('o') << std::endl;
    std::cout << "Последняя 'o': " << s.FindLast('o') << std::endl;
    
    // Подстрока
    String sub = s.Substr(7, 5);
    std::cout << "Подстрока: " << sub << std::endl;
    
    // Удаление
    s.Remove(5, 2);
    std::cout << "После удаления: " << s << std::endl;
    
    // Вставка
    s.Insert(" C++", 5);
    std::cout << "После вставки: " << s << std::endl;
    
    return 0;
}