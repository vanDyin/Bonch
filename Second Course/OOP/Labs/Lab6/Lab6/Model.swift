import Foundation
import Observation

@Observable
class Model {
    var strLeft: String
    var strRight: String
    
    init() {
        self.strLeft = ""
        self.strRight = ""
    }
    
    func clearLeft() {
        strLeft = ""
    }
    
    func clearRight() {
        strRight = ""
    }
    
    func clearAll() {
        clearLeft()
        clearRight()
    }
    
    func swap() {
        (strLeft, strRight) = (strRight, strLeft)
    }
    
    func copyLeftToRight() {
        strRight = strLeft
    }
    
    func copyRightToLeft() {
        strLeft = strRight
    }
}
