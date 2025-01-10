#ifndef PATIENTFACTORY_H
#define PATIENTFACTORY_H
#include "Patient.h"

/// @brief 
class PatientFactory 
{
public:
    // Constructor
    PatientFactory(){};
    // Destructor
    ~PatientFactory(){};
    std::shared_ptr<Patient> CreatePatient(const std::string &FirstName, const std::string &LastName, const std::string &DOB, const std::string &PhoneNumber, const std::string &MedicalHistory);

};
;

#endif // PATIENTFACTORY_H