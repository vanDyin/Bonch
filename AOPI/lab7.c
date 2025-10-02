#include <stdio.h>      // Для ввода-вывода (printf, scanf)
#include <locale.h>     // Для поддержки локализации (русский язык)
#include <stdlib.h>     // Для работы с памятью и случайными числами (rand, srand)
#include <time.h>       // Для измерения времени (clock, clock_t, CLOCKS_PER_SEC)

/* 
Алгоритм 1: Метод перебора от произвольного числа
Простейший, но наименее эффективный метод
Идея: перебираем все числа от a вниз до 1, пока не найдем общий делитель
*/
long gcd01(long a, long b) {
    long nod = 1L; // Начальное значение НОД (наименьший возможный делитель)
    
    // Перебираем все числа от a до 1
    for (long i = a; i > 0; i--) {
        // Если оба числа делятся на i без остатка
        if (a % i == 0 && b % i == 0) {
            nod = i; // Нашли НОД
            break;   // Прерываем цикл, так как ищем наибольший делитель
        }
    }
    return nod;
}

/*
Алгоритм 2: Метод перебора от минимального числа
Улучшенная версия первого алгоритма
Идея: НОД не может быть больше минимального из двух чисел
*/
long gcd02(long a, long b) {
    long nod = 1L;
    // Находим минимальное из двух чисел
    long min_val = a < b ? a : b;
    
    // Перебираем только до минимального числа
    for (long i = min_val; i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            nod = i;
            break;
        }
    }
    return nod;
}

/*
Алгоритм 3: Метод разложения на делители
Идея: последовательно делим числа на общие простые делители
*/
long gcd03(long a, long b) {
    long nod = 1L;
    
    // Убедимся, что a <= b для удобства
    if (a > b) {
        long tmp = a;
        a = b;
        b = tmp;
    }
    
    // Пока оба числа больше 1
    while (a > 1L && b > 1L) {
        // Ищем делитель для обоих чисел
        for (long i = 2; i <= a; i++) {
            // Если нашли общий делитель
            if (a % i == 0 && b % i == 0) {
                nod *= i; // Умножаем НОД на найденный делитель
                a /= i;   // Делим оба числа
                b /= i;
                break;
            }
            // Если делитель только для a
            if (a % i == 0) {
                a /= i;
                break;
            }
            // Если делитель только для b
            if (b % i == 0) {
                b /= i;
                break;
            }
        }
    }
    return nod;
}

/*
Алгоритм 4: Алгоритм Евклида (рекурсивная реализация)
Математическая основа: НОД(a, b) = НОД(a, b-a) для a <= b
*/
long gcd04(long a, long b) {
    // Базовый случай рекурсии - числа равны
    if (a == b) return a;
    
    // Убедимся, что a <= b
    if (a > b) {
        long tmp = a;
        a = b;
        b = tmp;
    }
    
    // Рекурсивный вызов с новыми параметрами
    return gcd04(a, b - a);
}

/*
Алгоритм 5: Алгоритм Евклида (итерационная реализация)
Та же математическая основа, но без рекурсии
*/
long gcd05(long a, long b) {
    // Пока числа не равны
    while (a != b) {
        // Убедимся, что a <= b
        if (a > b) {
            long tmp = a;
            a = b;
            b = tmp;
        }
        // Заменяем большее число на разность
        b = b - a;
    }
    return a;
}

/*
Алгоритм 6: Бинарный алгоритм (рекурсивный)
Использует свойства:
1. НОД(2a, 2b) = 2*НОД(a, b)
2. НОД(2a, b) = НОД(a, b) для нечетного b
3. НОД(a, b) = НОД(a, b-a) для a <= b
*/
long gcd06(long a, long b) {
    // Базовые случаи рекурсии
    if (a == 0L) return b;
    if (b == 0L) return a;
    if (a == b) return a;
    if (a == 1L || b == 1L) return 1L;
    
    // Оба числа четные
    if (a % 2L == 0L && b % 2L == 0L)
        return 2L * gcd06(a / 2L, b / 2L);
    
    // Только a четное
    if (a % 2L == 0L && b % 2L != 0L)
        return gcd06(a / 2L, b);
    
    // Только b четное
    if (a % 2L != 0L && b % 2L == 0L)
        return gcd06(a, b / 2L);
    
    // Оба нечетные
    if (a < b)
        return gcd06((b - a) / 2L, a);
    else
        return gcd06((a - b) / 2L, b);
}

/*
Алгоритм 7: Бинарный алгоритм (итерационный)
Та же логика, что и в рекурсивной версии, но без рекурсии
*/
long gcd07(long a, long b) {
    long nod = 1L; // Коэффициент для учета общих степеней 2
    long tmp;
    
    // Базовые случаи
    if (a == 0L) return b;
    if (b == 0L) return a;
    if (a == b) return a;
    if (a == 1L || b == 1L) return 1L;
    
    while (a != 0 && b != 0) {
        // Оба четные
        if (a % 2L == 0L && b % 2L == 0L) {
            nod *= 2L; // Увеличиваем коэффициент
            a /= 2L;
            b /= 2L;
            continue;
        }
        
        // Только a четное
        if (a % 2L == 0L && b % 2L != 0L) {
            a /= 2L;
            continue;
        }
        
        // Только b четное
        if (a % 2L != 0L && b % 2L == 0L) {
            b /= 2L;
            continue;
        }
        
        // Оба нечетные
        if (a > b) {
            tmp = a;
            a = b;
            b = tmp;
        }
        tmp = a;
        a = (b - a) / 2L;
        b = tmp;
    }
    
    // Возвращаем НОД с учетом коэффициента
    if (a == 0) return nod * b;
    else return nod * a;
}

/*
Алгоритм 8: Бинарный алгоритм с битовыми операциями
Оптимизированная версия с использованием битовых сдвигов вместо деления
*/
long gcd08(long a, long b) {
    long nod = 1L;
    long tmp;
    
    if (a == 0L) return b;
    if (b == 0L) return a;
    if (a == b) return a;
    if (a == 1L || b == 1L) return 1L;
    
    while (a != 0 && b != 0) {
        // Проверка на четность через битовые операции
        if (((a & 1L) | (b & 1L)) == 0L) {
            nod <<= 1L; // Умножение на 2
            a >>= 1L;   // Деление на 2
            b >>= 1L;
            continue;
        }
        
        if (((a & 1L) == 0L) && (b & 1L)) {
            a >>= 1L;
            continue;
        }
        
        if ((a & 1L) && ((b & 1L) == 0L)) {
            b >>= 1L;
            continue;
        }
        
        if (a > b) {
            tmp = a;
            a = b;
            b = tmp;
        }
        tmp = a;
        a = (b - a) >> 1L;
        b = tmp;
    }
    
    if (a == 0) return nod * b;
    else return nod * a;
}

// Структура для хранения алгоритма и его описания
typedef struct {
    long (*func)(long, long); // Указатель на функцию
    const char *comm;         // Описание алгоритма
} GCDAlgorithm;

// Массив всех алгоритмов для тестирования
GCDAlgorithm algorithms[] = {
    { gcd01, "01 Перебор от произвольного числа" },
    { gcd02, "02 Перебор от минимального числа" },
    { gcd03, "03 С разложением на делители" },
    { gcd04, "04 Алгоритм Евклида рекурсивный" },
    { gcd05, "05 Алгоритм Евклида итерационный" },
    { gcd06, "06 Бинарный алгоритм рекурсивный" },
    { gcd07, "07 Бинарный алгоритм итерационный" },
    { gcd08, "08 Бинарный алгоритм со сдвигом" }
};

// Количество случайных пар чисел для тестирования
const unsigned int RAND_TIMES = 500;
// Количество повторений для каждого теста
const unsigned long REPEAT_TIMES = 10000L;

int main() {
    clock_t the_time;       // Для измерения времени
    double elapsed_time;    // Прошедшее время в секундах
    
    // Устанавливаем локаль для вывода русских букв
    setlocale(LC_ALL, "Russian");
    
    long a, b, c, nod;
    // Инициализация генератора случайных чисел
    srand((unsigned int)time(NULL));
    
    // Массив для накопления времени работы каждого алгоритма
    double times[sizeof(algorithms) / sizeof(GCDAlgorithm)] = { 0.0 };
    
    // Основной цикл тестирования
    for (unsigned int t = 0; t < RAND_TIMES; t++) {
        // Генерируем случайные числа
        c = rand() % 50 + 1; // Общий множитель
        a = (rand() % 1000 + 1) * c;
        b = (rand() % 1000 + 1) * c;
        
        // Тестируем каждый алгоритм
        for (unsigned int alg = 0; alg < sizeof(algorithms) / sizeof(GCDAlgorithm); alg++) {
            the_time = clock(); // Засекаем время
            
            // Многократно выполняем алгоритм для точности измерения
            for (unsigned long m = 0; m < REPEAT_TIMES; m++) {
                nod = algorithms[alg].func(a, b);
            }
            
            // Вычисляем затраченное время
            elapsed_time = (double)(clock() - the_time) / CLOCKS_PER_SEC;
            times[alg] += elapsed_time;
        }
        
        // Выводим результат для текущей пары чисел
        printf("%4u НОД(%7ld, %7ld) = %7ld\n", t + 1, a, b, nod);
    }
    
    // Вывод итоговых результатов
    printf("\nСреднее время для %d пар случайных чисел:\n", RAND_TIMES);
    for (unsigned int alg = 0; alg < sizeof(algorithms) / sizeof(GCDAlgorithm); alg++) {
        printf("%s: %8.4f сек.\n", algorithms[alg].comm, times[alg] / RAND_TIMES);
    }
    
    return 0;
}