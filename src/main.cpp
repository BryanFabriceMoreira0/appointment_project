#include <iostream>
#include "Database.h"
#include "Patient.h"
#include "PatientFactory.h"

int main(){
    std::cout << "Hello, from appointment_project!\n";

    std::string FirstName;
    Database &db = Database::GetInstance();
    db.CreatePatientTable();

    PatientFactory Factory;
    std::shared_ptr<Patient> Bryan = Factory.CreatePatient("Moreira","Bryan","25/07/2000","0766571666","NONE");

    db.InsertPatientData(Bryan);
}
