// Four classes in one file are specially made, I know that you shouldn't do that.

class COne {
    private var _d: Double
    private var _s: String
    
    var d: Double {
        get { return _d }
        set { _d = newValue }
    }
    
    var s: String {
        get { return _s }
        set { _s = newValue }
    }
    
    //по умолчанию
    init() {
        self._d = 0.0
        self._s = ""
    }
    
    //с параметрами
    init(d: Double, s: String) {
        self._d = d
        self._s = s
    }
    
    //копирования
    init(other: COne) {
        self._d = other._d
        self._s = other._s
    }
    
    //глубокое копирование
    func copy() -> COne {
        return COne(other: self)
    }
    
    //метод print
    func printData() {
        print("COne: d = \(_d), s = \"\(_s)\"")
    }
}

class CTwo {
    private var _d: Double
    private var _p: COne?
        
        var d: Double {
            get { return _d }
            set { _d = newValue }
        }
        
        var p: COne? {
            get {
                return _p?.copy()
            }
            set {
                _p = newValue?.copy()
            }
        }
    //по умолчанию
    init() {
        self._d = 0.0
        self._p = nil
    }
    
    //с параметрами
    init(d: Double, p: COne?) {
        self._d = d
        self._p = p?.copy()
    }
    
    //копирования
    init(other: CTwo) {
        self._d = other._d
        self._p = other._p?.copy()
    }
    
    //глубокое копирование
    func copy() -> CTwo {
        return CTwo(other: self)
    }
    
    //метод print
    func printData() {
        print("CTwo: d = \(d)")
        if let p = _p {
            print("Содержит COne:")
            p.printData()
        } else {
            print("COne: nil")
        }
    }
}

class CThree: CTwo {
    private var _thirdField: String
    
    var additionalField: String {
        get { return _thirdField }
        set { _thirdField = newValue }
    }
    
    //по умолчанию
    override init() {
        self._thirdField = ""
        super.init()
    }
    
    //с параметрами
    init(d: Double, p: COne?, thirdField: String) {
        self._thirdField = thirdField
        super.init(d: d, p: p)
    }
    
    //копирования
    init(other: CThree) {
        self._thirdField = other._thirdField
        super.init(other: other)
    }
    
    override func printData() {
        print("CThree: d = \(d), thirdField = \(_thirdField)")
        if let p = p {
            print("Содержит COne:")
            p.printData()
        } else {
            print("COne: nil")
        }
    }
    
    override func copy() -> CThree {
        return CThree(other: self)
    }
}

class CFour: CThree {
    private var _fourthField: Int
    
    var fourthField: Int {
        get { return _fourthField }
        set { _fourthField = newValue }
    }
    
    //по умлочанию
    override init() {
        self._fourthField = 0
        super.init()
    }
    
    //с параметрами
    init(d: Double, p: COne?, thirdField: String, fourthField: Int) {
        self._fourthField = fourthField
        super.init(d: d, p: p, thirdField: thirdField)
    }
    
    //копирования
    init(other: CFour) {
        self._fourthField = other._fourthField
        super.init(other: other)
    }
    
    override func printData() {
        print("CFour: d = \(d), additionalField = \(additionalField), fourthField = \(_fourthField)")
        if let p = p {
            print("Содержит COne:")
            p.printData()
        } else {
            print("COne: nil")
        }
    }
    
    override func copy() -> CFour {
        return CFour(other: self)
    }
}

//глобальный вывод
func printAll(objects: [CTwo], n: Int) {
    print("\nВсе объекты")
    for (index, object) in objects.prefix(n).enumerated() {
        print("Объект \(index + 1):")
        object.printData()
    }
}

func demonstrateClassesTask() {
    
    let one = COne()
    one.d = 1.0
    one.s = "cone"
    one.printData()
    
    print("\n")
    
    let two = CTwo(d: 2.0, p: one)
    two.printData()
    print("two.d = \(two.d)")
    
    print("\n")
    
    let modifiedOne = COne(d: 11.0, s: "m.cone")
    two.p = modifiedOne
    two.printData()
    
    print("\n")
    
    if let fillCOne = two.p { //unwrapped
        fillCOne.printData()
        
        fillCOne.d = 111
        fillCOne.s = "Changed"
        print("После изменения fillCOne:")
        fillCOne.printData()
        print("two.p (исходный):")
        two.p?.printData() //исходный объект не изменился
    }
    print("Here")
    two.p? = COne(d: 12.0, s: "a")
    two.p?.printData()
    
    print("\n")
    
    let copyOne = COne(other: one)
    copyOne.printData()
    
    print("\n")
    
    let three = CThree(d: 3.0, p: copyOne, thirdField: "third field")
    three.d = 4.0
    
    
    three.printData()
    
    print("\n")
    
    let four = CFour(d: 4.0, p: copyOne, thirdField: "fourth field 1", fourthField: 4)
    four.printData()
    
    print("\n")
    
    let objects: [CTwo] = [two, three, four]
    printAll(objects: objects, n: objects.count)
}


