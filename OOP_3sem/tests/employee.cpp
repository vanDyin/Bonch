#include "employee.h"

#include <cstring>

Employee::Employee() {
    Name = new char[strlen("no name" + 1)];
    strcpy(Name, "no name");
    Fam = new char[strlen("no fam") + 1];
    strcpy(Fam, "no fam");
    Dep = new char[strlen("no dep") + 1];
    strcpy(Dep, "no dep");
    Age = 0; 
}


Employee::Employee(char *NName, char *NFam, char *NDep, int NAge) {
    Name = new char[strlen("no name" + 1)];
    strcpy(Name, NName);
    Fam = new char[strlen("no fam") + 1];
    strcpy(Fam, NFam);
    Dep = new char[strlen("no dep") + 1];
    strcpy(Dep, NDep);
    Age = NAge; 
}

