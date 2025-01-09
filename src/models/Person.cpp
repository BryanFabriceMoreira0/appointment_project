#include "Person.h"

Person::Person()
{
}
//---------------------------------------------------------------------------------------

Person::~Person()
{
}
//---------------------------------------------------------------------------------------

Person::Person(const std::string &FirstName, const std::string &LastName, const std::string &DOB, const std::string &PhoneNumber) : _FirstName(FirstName), _LastName(LastName), _DOB(DOB), _PhoneNumber(PhoneNumber) {}
//---------------------------------------------------------------------------------------

ErrorCode Person::GetFirstName(std::string &oFirstName) const
{
    if (_FirstName.empty()) {logError("_FirstName is NULL");return ErrorCode::InvalidInput;};
    oFirstName = _FirstName;
    return ErrorCode::Success;
}
//---------------------------------------------------------------------------------------

ErrorCode Person::GetLastName(std::string &oLastName) const
{
    if (_LastName.empty()) {logError("_LastName is NULL");return ErrorCode::InvalidInput;};
    oLastName = _FirstName;
    return ErrorCode::Success;
}
//---------------------------------------------------------------------------------------

ErrorCode Person::GetDOB(std::string &oDOB) const
{
    if (_DOB.empty()) {logError("_oDOB is NULL");return ErrorCode::InvalidInput;};
    oDOB = _DOB;
    return ErrorCode::Success;
}
//---------------------------------------------------------------------------------------
ErrorCode Person::GetPhoneNumber(std::string &oPhoneNumber) const
{
    if (_PhoneNumber.empty()) {logError("_oPhoneNumber is NULL");return ErrorCode::InvalidInput;};
    oPhoneNumber = _PhoneNumber;
    return ErrorCode::Success;
}
//---------------------------------------------------------------------------------------
 ErrorCode Person::SetFirstName(const std::string &iFirstName)
 {
    if (iFirstName.empty()) {logError("iFirstName is NULL");return ErrorCode::InvalidInput;};
    _FirstName= iFirstName;
    return ErrorCode::Success;
 }
//---------------------------------------------------------------------------------------
 ErrorCode Person::SetLastName(const std::string &iLastName)
 {
    if (iLastName.empty()) {logError("iLastName is NULL");return ErrorCode::InvalidInput;};
    _LastName= iLastName;
    return ErrorCode::Success;
 }
//---------------------------------------------------------------------------------------
 ErrorCode Person::SetDOB(const std::string &iDOB)
 {
    if (iDOB.empty()) {logError("iDOB is NULL");return ErrorCode::InvalidInput;};
    _DOB= iDOB;
    return ErrorCode::Success;
 }
//---------------------------------------------------------------------------------------
 ErrorCode Person::SetPhoneNumber(const std::string &iPhoneNumber)
 {
    if (iPhoneNumber.empty()) {logError("iPhoneNumber is NULL");return ErrorCode::InvalidInput;};
    _PhoneNumber= iPhoneNumber;
    return ErrorCode::Success;
 }

