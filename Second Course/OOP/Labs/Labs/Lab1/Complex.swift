class Complex {
    private var real: Double
    private var image: Double
    
    //инициализаторы
    init(real: Double = 0, image: Double = 0) {
        self.real = real
        self.image = image
    }
    
    //сложение
    func add(_ other: Complex) -> Complex {
        return Complex(real: self.real + other.real,
                      image: self.image + other.image)
    }
    
    //вычитание
    func subtract(_ other: Complex) -> Complex {
        return Complex(real: self.real - other.real,
                      image: self.image - other.image)
    }
    
    //умножение
    func multiply(_ other: Complex) -> Complex {
        let newReal = self.real * other.real - self.image * other.image
        let newimage = self.real * other.image + self.image * other.real
        return Complex(real: newReal, image: newimage)
    }
    
    //деление
    func divide(_ other: Complex) -> Complex? {
        let denominator = other.real * other.real + other.image * other.image
        guard denominator != 0 else {
            print("Ошибка: деление на ноль")
            return nil
        }
        
        let newReal = (self.real * other.real + self.image * other.image) / denominator
        let newimage = (self.image * other.real - self.real * other.image) / denominator
        return Complex(real: newReal, image: newimage)
    }
    
    //вывод комплексного числа
    func printComplex() {
        if image > 0 {
            print("\(real) + \(image)i")
        } else {
            print("\(real) - \(-image)i")
        }
    }
}

func demonstrateComplexTask() {
    
    //создание комплексных чисел
    let num1 = Complex(real: 3, image: 2)
    let num2 = Complex(real: 1, image: 4)
    let num3 = Complex(real: 5, image: -3)
    
    print("Число 1: ", terminator: "")
    num1.printComplex()
    
    print("Число 2: ", terminator: "")
    num2.printComplex()
    
    print("Число 3: ", terminator: "")
    num3.printComplex()
    
    //сложение
    print("\nСложение:")
    print("(3 + 2i) + (1 + 4i) = ", terminator: "")
    num1.add(num2).printComplex()
    
    //вычитание
    print("\nВычитание:")
    print("(3 + 2i) - (1 + 4i) = ", terminator: "")
    num1.subtract(num2).printComplex()
    
    //умножение
    print("\nУмножение:")
    print("(3 + 2i) * (1 + 4i) = ", terminator: "")
    num1.multiply(num2).printComplex()
    
    //деление (unwrapped)
    print("\nДеление:")
    if let divide = num1.divide(num2) {
        print("(3 + 2i) / (1 + 4i) = ", terminator: "")
        divide.printComplex()
    }
}
