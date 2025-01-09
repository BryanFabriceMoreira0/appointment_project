#ifndef PATIENT_H
#define PATIENT_H

#include "ErrorCode.h"
#include <string>

/// @brief Abstract base  representing a Person in term of relevant informations
class Person
{
public:
    // Constructors
    Person();
    Person(const std::string &FirstName, const std::string &LastName, const std::string &DOB, const std::string &PhoneNumber);

    // Destructor
    virtual ~Person(); // virtual destructor so that derived class can be handled properly

    // Getters
    ErrorCode GetFirstName(std::string &oFirstName) const;
    ErrorCode GetLastName(std::string &oLastName) const;
    ErrorCode GetDOB(std::string &oDOB) const;
    ErrorCode GetPhoneNumber(std::string &oPhoneNumber) const;

    // Setters
    ErrorCode SetFirstName(const std::string &iFirstName);
    ErrorCode SetLastName(const std::string &iLastName);
    ErrorCode SetDOB(const std::string &iDOB);
    ErrorCode SetPhoneNumber(const std::string &iPhoneNumber);

protected:
    std::string _FirstName;
    std::string _LastName;
    std::string _DOB; // Date of birth
    std::string _PhoneNumber;
};
;

#endif // PATIENT_H