import Foundation
// MARK: Задача 1: Шаблон класса CustomArray (Generic)
class Pattern<T: FloatingPoint> {
    private var real: T
    private var image: T
    
    //инициализаторы
    init(real: T = 0, image: T = 0) {
        self.real = real
        self.image = image
    }
    
    //сложение
    func add(_ other: Pattern<T>) -> Pattern<T> {
        return Pattern<T>(real: self.real + other.real,
                      image: self.image + other.image)
    }
    
    //вычитание
    func subtract(_ other: Pattern<T>) -> Pattern<T> {
        return Pattern<T>(real: self.real - other.real,
                      image: self.image - other.image)
    }
    
    //умножение
    func multiply(_ other: Pattern<T>) -> Pattern<T> {
        let newReal = self.real * other.real - self.image * other.image
        let newimage = self.real * other.image + self.image * other.real
        return Pattern<T>(real: newReal, image: newimage)
    }
    
    //деление
    func divide(_ other: Pattern<T>) -> Pattern<T>? {
        let denominator = other.real * other.real + other.image * other.image
        guard denominator != 0 else {
            print("Ошибка: деление на ноль")
            return nil
        }
        
        let newReal = (self.real * other.real + self.image * other.image) / denominator
        let newimage = (self.image * other.real - self.real * other.image) / denominator
        return Pattern<T>(real: newReal, image: newimage)
    }
    
    //вывод комплексного числа
    func printPattern() {
        if image > 0 {
            print("\(real) + \(image)i")
        } else if  image < 0{
            print("\(real) - \(-image)i")
        } else {
            print("\(real)")
        }
    }
}

func demonstratePattern() {
    
    //Float
    
    let floatComplex1 = Pattern<Float>(real: 1.2, image: 2.6)
    let floatComplex2 = Pattern<Float>(real: 2.4, image: 5.2)
    
    print("Число 1: ", terminator: "")
    floatComplex1.printPattern()
    
    print("Число 2: ", terminator: "")
    floatComplex2.printPattern()
    
    print("\nСложение:")
    floatComplex1.add(floatComplex2).printPattern()
    
    //вычитание
    print("\nВычитание:")
    floatComplex1.subtract(floatComplex2).printPattern()
    
    //умножение
    print("\nУмножение:")
    floatComplex1.multiply(floatComplex2).printPattern()
    
    //деление (unwrapped)
    print("\nДеление:")
    if let divide = floatComplex1.divide(floatComplex2) {
        divide.printPattern()
    }
    
    //Double
    
    print("\n\n\n")
    
    let doubleComplex1 = Pattern<Double>(real: 1.2, image: 2.6)
    let doubleComplex2 = Pattern<Double>(real: 2.4, image: 5.2)
    
    print("Число 1: ", terminator: "")
    doubleComplex1.printPattern()
    
    print("Число 2: ", terminator: "")
    doubleComplex2.printPattern()
    
    print("\nСложение:")
    doubleComplex1.add(doubleComplex2).printPattern()
    
    //вычитание
    print("\nВычитание:")
    doubleComplex1.subtract(doubleComplex2).printPattern()
    
    //умножение
    print("\nУмножение:")
    doubleComplex1.multiply(doubleComplex2).printPattern()
    
    //деление (unwrapped)
    print("\nДеление:")
    if let divide = doubleComplex1.divide(doubleComplex2) {
        divide.printPattern()
    }
}
