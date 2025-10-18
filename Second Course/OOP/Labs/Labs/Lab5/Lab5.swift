// MARK: Задача 1: Шаблон класса CustomArray (Generic)

class Pattern<T: Comparable> {
    var elements: [T] {
        didSet {
            capacity = elements.count
        }
    }
    private var capacity: Int = 0
    
    init() {
        self.elements = []
        self.capacity = 0
    }
    
    init(elements: [T]) {
        self.elements = elements
        self.capacity = elements.count
    }
    
    //копирование массива
    func copy() -> Pattern<T> {
        return Pattern<T>(elements: self.elements)
    }
    
    //ввод элементов с клавиатуры
    func inputElements() {
        print("Введите количество элементов: ", terminator: "")
        
        guard let countInput = readLine(), let count = Int(countInput), count > 0 else {
            print("Некорректный ввод количества элементов")
            return
        }
        
        capacity = count
        elements.removeAll()
        
        for i in 0..<count {
            print("Введите элемент \(i + 1): ", terminator: "")
            if let input = readLine() {
                elements.append(input as! T)
            } else {
                print("Некорректный ввод числа")
            }
        }
    }
    
    //вывод элементов на экран
    func printElements() {
        if elements.isEmpty {
            print("Массив пуст")
        } else {
            print("Элементы массива: \(elements)")
        }
        print(getCapacity())
    }
    
    //добавка элемента в конец
    func append(_ element: T) {
        elements.append(element)
    }
    
    //вставка одного массива в заданную позицию другого
    func insert(_ otherArray: Pattern<T>, at position: Int) {
        guard position >= 0 && position <= elements.count else {
            print("Ошибка: недопустимая позиция для вставки")
            return
        }
        elements.insert(contentsOf: otherArray.elements, at: position)
    }
    
    //вычисление наибольшего элемента массива
    func maxElement() -> T? {
        return elements.max()
    }
    
    //получение вместимости
    func getCapacity() -> String {
        return "Количество элементов: \(capacity)"
    }
    
    subscript(index: Int) -> T {
        get {
            return elements[index]
        }
        set {
            elements[index] = newValue
        }
    }
}

// MARK: Задача 3 (вариант 3): Шаблон класса для стэка (throw)

enum StackError: Error {
    case overflow, underflow
}

class Stack<T> {
    private var elements: [T]
    private let fixSize: Int
    
    init() {
        self.elements = []
        self.fixSize = 5
    }
    
    init(fixSize: Int, elements: [T]) throws {
        self.fixSize = fixSize
        if elements.count > fixSize {
            throw StackError.overflow
        }
        self.elements = elements
    }
    
    //проверка на пустоту
    var isEmpty: Bool {
        return elements.isEmpty
    }
    
    //проверка на заполненность
    var isFull: Bool {
        return elements.count >= fixSize
    }
    
    //текущее количество элементов
    var size: Int {
        return elements.count
    }
    
    //получить размер
    var capacity: Int {
        return fixSize
    }
    
    //очистить стэк
    func clear() {
        elements.removeAll()
    }
    
    //вывести стэк
    func printStack() {
        if isEmpty {
            print("Стэк пуст")
        } else {
            print("Стэк (сверху вниз): \(elements.reversed())")
        }
        print("Размер: \(size)/\(capacity)")
    }
    
    
    //добавить элемент в стэк
    func append(_ element: T) throws {
        guard !isFull else {
            throw StackError.overflow
        }
        elements.append(element)
    }
    
    //достать последний элемент стэка (и удалить)
    func removeLast() throws -> T {
        guard !isEmpty else {
            throw StackError.underflow
        }
        return elements.removeLast()
    }
    
    //достать последний элемент стэка (без удаления)
    func showLast() throws -> T {
        guard !isEmpty else {
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

func demonstrateClassesPattern() {
    
    let intArray = Pattern<Int>()
    intArray.inputElements()
    intArray.printElements()
}
