#ifndef PATIENT_H
#define PATIENT_H

#include "Error.h"
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
    errorcode GetFirstName(std::string &oFirstName) const;
    errorcode GetLastName(std::string &oLastName) const;
    errorcode GetDOB(std::string &oDOB) const;
    errorcode GetPhoneNumber(std::string &oPhoneNumber) const;

    // Setters
    errorcode SetFirstName(const std::string &iFirstName);
    errorcode SetLastName(const std::string &iLastName);
    errorcode SetDOB(const std::string &iDOB);
    errorcode SetPhoneNumber(const std::string &iPhoneNumber);

protected:
    std::string _FirstName;
    std::string _LastName;
    std::string _DOB; // Date of birth
    std::string _PhoneNumber;
};
;

#endif // PATIENT_H