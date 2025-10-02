#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
    private:
    std::string name;

    public:
    void SetName(const std::string& n);
    std::string GetName() const;
};

#endif

