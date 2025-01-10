#ifndef PATIENT_H
#define PATIENT_H
#include "Error.h"
/// @brief  class representing a Patient
class Patient 
{
public:
    //  Constructors
    Patient(const std::string &FirstName, const std::string &LastName, const std::string &DOB, const std::string &PhoneNumber, const std::string &MedicalHistory);

    //  Destructor
    ~Patient() {};

    // // Getters
    errorcode GetFirstName(std::string &oFirstName) const;
    errorcode GetLastName(std::string &oLastName) const;
    errorcode GetDOB(std::string &oDOB) const;
    errorcode GetPhoneNumber(std::string &oPhoneNumber) const;
    errorcode GetMedicalHistory(std::string &oMedicalHistory) const;

    // Setters
    errorcode SetFirstName(const std::string &iFirstName);
    errorcode SetLastName(const std::string &iLastName);
    errorcode SetDOB(const std::string &iDOB);
    errorcode SetPhoneNumber(const std::string &iPhoneNumber);
    errorcode SetMedicalHistory(const std::string &iMedicalHistory);

private:
    std::string _FirstName;
    std::string _LastName;
    std::string _DOB; // Date of birth
    std::string _PhoneNumber;
    std::string _MedicalHistory;
};

#endif // PATIENT_H