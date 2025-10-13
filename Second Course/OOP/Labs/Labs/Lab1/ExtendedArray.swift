class CustomArray {
    private var elements: [Int]
    
    init() {
        self.elements = []
    }
    
    init(elements: [Int]) {
        self.elements = elements
    }
    
    //копирование массива
    func copy() -> CustomArray {
        return CustomArray(elements: self.elements)
    }
    
    //ввод элементов с клавиатуры
    func inputElements() {
        elements.removeAll()
        print("Введите количество элементов: ", terminator: "")
        
        guard let countInput = readLine(), let count = Int(countInput), count > 0 else {
            print("Некорректный ввод количества элементов")
            return
        }
        
        for i in 0..<count {
            print("Введите элемент \(i + 1): ", terminator: "")
            if let input = readLine(), let value = Int(input) {
                elements.append(value)
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
    }
    
    //добавка элемента в конец
    func append(_ element: Int) {
        elements.append(element)
    }
    
    //вставка одного массива в заданную позицию другого
    func insert(_ otherArray: CustomArray, at position: Int) {
        guard position >= 0 && position <= elements.count else {
            print("Ошибка: недопустимая позиция для вставки")
            return
        }
        elements.insert(contentsOf: otherArray.elements, at: position)
    }
    
    //вычисление наибольшего элемента массива
    func maxElement() -> Int? {
        return elements.max()
    }
    
    subscript(index: Int) -> Int {
        get {
            return elements[index]
        }
        set {
            elements[index] = newValue
        }
    }
}

func demonstrateArrayTask() {
    
    //создание и инициализация массива
    let array1 = CustomArray()
    array1.inputElements()
    array1.printElements()
    
    //копирование массива
    let array2 = array1.copy()
    print("Скопированный массив:")
    array2.printElements()
    
    //добавление элемента в конец
    array1.append(11)
    print("После добавления 11:")
    array1.printElements()
    
    //создание второго массива для вставки
    let array3 = CustomArray(elements: [2, 4, 6])
    
    //вставка массива в позицию 2
    array1.insert(array3, at: 2)
    print("После вставки [2,4,6] в позицию 2:")
    array1.printElements()
    
    //максимального элемента
    if let max = array1.maxElement() { //unwrapped тк функция возращает Int?
        print("Наибольший элемент: \(max)")
    }
}
