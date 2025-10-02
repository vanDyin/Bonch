#include "Person.h"


void Person::SetName(const std::string& n) {
    name = n;
}

std::string
Person::GetName() const {
    return name;
}

