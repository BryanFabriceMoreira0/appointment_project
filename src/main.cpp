#include <iostream>
#include "Database.h"
#include "Patient.h"

int main(){
    std::cout << "Hello, from appointment_project!\n";

    std::string FirstName;
    Database &db = Database::GetInstance();
    db.CreatePatientTable();
}
