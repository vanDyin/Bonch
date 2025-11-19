// MARK: Задача 3 (вариант 3): Шаблон класса для стэка (throw)

enum StackError: Error {
    case overflow, underflow
}

class Stack<T> {
    private var elements: [T]
    private let maxSize: Int
    
    init(maxSize: Int) {
        self.maxSize = maxSize
        self.elements = []
    }
    
    init(maxSize: Int, elements: [T]) throws {
        self.maxSize = maxSize
        if elements.count > maxSize {
            throw StackError.overflow
        }
        self.elements = elements
    }
    
    //проверка на пустоту
    func isEmpty() -> Bool {
        return elements.isEmpty
    }
    
    //проверка на заполненность
    func isFull() -> Bool {
        return elements.count >= maxSize
    }
    
    //текущее количество элементов
    func size() -> Int {
        return elements.count
    }
    
    //получить размер
    func capacity() -> Int {
        return maxSize
    }
    
    //очистить стэк
    func clear() {
        elements.removeAll()
    }
    
    //вывести стэк
    func printStack() {
        if isEmpty() {
            print("Стэк пуст")
        } else {
            print("Стэк (сверху вниз): \(Array(elements.reversed()))")
        }
        print("Размер: \(size())/\(capacity())")
    }
    
    
    //добавить элемент в стэк
    func add(_ element: T) throws {
        guard !isFull() else {
            throw StackError.overflow
        }
        elements.append(element)
    }
    
    //достать последний элемент стэка (и удалить)
    func removeLast() throws -> T {
        guard !isEmpty() else {
            throw StackError.underflow
        }
        return elements.removeLast()
    }
    
    //достать последний элемент стэка (без удаления)
    func showLast() throws -> T {
        guard !isEmpty() else {
            throw StackError.underflow
        }
        return elements.last!
    }
    
    subscript(index: Int) -> T {
        get {
            return elements[index]
        }
    }
}

func demonstrateStack() {
    print("\n\n\n Задание 3. Тесты")
    
    let stack = Stack<Int>(maxSize: 4)
    
    do {
        for i in 1...5 {
            try stack.add(i * 10)
            print("Добавлен: \(i * 10)")
        }
    } catch StackError.overflow {
        print("Ошибка: стэк переполнен")
    } catch {
        print("Ошибка")
    }
    
    do {
        let lastElement = try stack.showLast()
        print("Верхний элемент: \(lastElement)")
    } catch StackError.underflow {
        print("Ошибка: стэк пуст")
    } catch {
        print("Ошибка")
    }
    
    do {
        while !stack.isEmpty() {
            let element = try stack.removeLast()
            print("\(element) удален ")
        }
    } catch StackError.underflow {
        print("Ошибка: стэк пуст")
    } catch {
        print("Ошибка")
    }
    
    do {
        let element = try stack.removeLast()
        print("\(element) удален ")
    } catch StackError.underflow {
        print("Ошибка: стэк пуст")
    } catch {
        print("Ошибка")
    }
    
    print("\n\n\n")
    
    guard let stringStack = try? Stack<String>(maxSize: 3, elements: ["str1", "str2"]) else {
        print("Не удалось создать стек")
        return
    }
    
    do {
        try stringStack.add("str3")
        stringStack.printStack()
        
        let lastString = try stringStack.showLast()
        print("Первая строка: \(lastString)")
    } catch {
        print("Ошибка")
    }
    
    print("Элемент по индексу 0: \(stringStack[0])")
    print("Элемент по индексу 2: \(stringStack[2])")
    
    stringStack.clear()
    stringStack.printStack()
   
}
