#include "PatientFactory.h"

std::shared_ptr<Patient> PatientFactory::CreatePatient(const std::string &FirstName, const std::string &LastName, const std::string &DOB, const std::string &PhoneNumber, const std::string &MedicalHistory)
{
    return std::make_shared<Patient>(FirstName,LastName,DOB,PhoneNumber,MedicalHistory);
}
