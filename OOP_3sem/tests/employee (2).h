#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include <iostream>

class Employee {

public:
    Employee(char *NName, char *NFam, char *NDep, int NAge);
    Employee();
    virtual ~Employee();
    virtual void print();

    void SetName( char *NName);
    void SetAge( int NAge);
    void SetDep( char *NDep):
    void SetFam( char *NFam):
    
    int GetAge();
    char *GetDep(char *NDep);
    char *GetFam(char *NFam):
    char *GetName(char *NName);

    friend std::istream& operator >> (std::istream&,Employee&);
    friend std::ostream& operator << (std::ostream&,Employee&);

protected:
    int Age;
    char *Dep;
    char *Name;
    char *Fam;
};

#endif
