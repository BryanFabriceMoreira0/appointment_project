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

errorcode Person::GetFirstName(std::string &oFirstName) const
{
    if (_FirstName.empty()) {Error::logError("_FirstName is NULL",__FILE__,__LINE__);return errorcode::InvalidInput;};
    oFirstName = _FirstName;
    return errorcode::Success;
}
//---------------------------------------------------------------------------------------

errorcode Person::GetLastName(std::string &oLastName) const
{
    if (_LastName.empty()) {Error::logError("_LastName is NULL",__FILE__,__LINE__);return errorcode::InvalidInput;};
    oLastName = _FirstName;
    return errorcode::Success;
}
//---------------------------------------------------------------------------------------

errorcode Person::GetDOB(std::string &oDOB) const
{
    if (_DOB.empty()) {Error::logError("_oDOB is NULL",__FILE__,__LINE__);return errorcode::InvalidInput;};
    oDOB = _DOB;
    return errorcode::Success;
}
//---------------------------------------------------------------------------------------
errorcode Person::GetPhoneNumber(std::string &oPhoneNumber) const
{
    if (_PhoneNumber.empty()) {Error::logError("_oPhoneNumber is NULL",__FILE__,__LINE__);return errorcode::InvalidInput;};
    oPhoneNumber = _PhoneNumber;
    return errorcode::Success;
}
//---------------------------------------------------------------------------------------
 errorcode Person::SetFirstName(const std::string &iFirstName)
 {
    if (iFirstName.empty()) {Error::logError("iFirstName is NULL",__FILE__,__LINE__);return errorcode::InvalidInput;};
    _FirstName= iFirstName;
    return errorcode::Success;
 }
//---------------------------------------------------------------------------------------
 errorcode Person::SetLastName(const std::string &iLastName)
 {
    if (iLastName.empty()) {Error::logError("iLastName is NULL",__FILE__,__LINE__);return errorcode::InvalidInput;};
    _LastName= iLastName;
    return errorcode::Success;
 }
//---------------------------------------------------------------------------------------
 errorcode Person::SetDOB(const std::string &iDOB)
 {
    if (iDOB.empty()) {Error::logError("iDOB is NULL",__FILE__,__LINE__);return errorcode::InvalidInput;};
    _DOB= iDOB;
    return errorcode::Success;
 }
//---------------------------------------------------------------------------------------
 errorcode Person::SetPhoneNumber(const std::string &iPhoneNumber)
 {
    if (iPhoneNumber.empty()) {Error::logError("iPhoneNumber is NULL",__FILE__,__LINE__);return errorcode::InvalidInput;};
    _PhoneNumber= iPhoneNumber;
    return errorcode::Success;
 }

