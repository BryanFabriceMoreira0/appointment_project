#include <iostream>
#include "Database.h"
#include "Person.h"

int main(){
    std::cout << "Hello, from appointment_project!\n";

    Person Bryan;
    std::string FirstName;
    Bryan.GetFirstName(FirstName);
    Database &db = Database::GetInstance();
}
