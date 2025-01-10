#include "Patient.h"


//---------------------------------------------------------------------------------------

Patient::Patient(const std::string &FirstName, const std::string &LastName, const std::string &DOB, const std::string &PhoneNumber,const std::string &MedicalHistory) : _FirstName(FirstName), _LastName(LastName), _DOB(DOB), _PhoneNumber(PhoneNumber),_MedicalHistory(MedicalHistory) {}
//---------------------------------------------------------------------------------------

errorcode Patient::GetFirstName(std::string &oFirstName) const
{
    if (_FirstName.empty()) {Error::logError("_FirstName is NULL");return errorcode::InvalidInput;};
    oFirstName = _FirstName;
    return errorcode::Success;
}
//---------------------------------------------------------------------------------------

errorcode Patient::GetLastName(std::string &oLastName) const
{
    if (_LastName.empty()) {Error::logError("_LastName is NULL");return errorcode::InvalidInput;};
    oLastName = _FirstName;
    return errorcode::Success;
}
//---------------------------------------------------------------------------------------

errorcode Patient::GetDOB(std::string &oDOB) const
{
    if (_DOB.empty()) {Error::logError("_oDOB is NULL");return errorcode::InvalidInput;};
    oDOB = _DOB;
    return errorcode::Success;
}
//---------------------------------------------------------------------------------------
errorcode Patient::GetPhoneNumber(std::string &oPhoneNumber) const
{
    if (_PhoneNumber.empty()) {Error::logError("_oPhoneNumber is NULL");return errorcode::InvalidInput;};
    oPhoneNumber = _PhoneNumber;
    return errorcode::Success;
}
//---------------------------------------------------------------------------------------
 errorcode Patient::SetFirstName(const std::string &iFirstName)
 {
    if (iFirstName.empty()) {Error::logError("iFirstName is NULL");return errorcode::InvalidInput;};
    _FirstName= iFirstName;
    return errorcode::Success;
 }
//---------------------------------------------------------------------------------------
 errorcode Patient::SetLastName(const std::string &iLastName)
 {
    if (iLastName.empty()) {Error::logError("iLastName is NULL");return errorcode::InvalidInput;};
    _LastName= iLastName;
    return errorcode::Success;
 }
//---------------------------------------------------------------------------------------
 errorcode Patient::SetDOB(const std::string &iDOB)
 {
    if (iDOB.empty()) {Error::logError("iDOB is NULL");return errorcode::InvalidInput;};
    _DOB= iDOB;
    return errorcode::Success;
 }
//---------------------------------------------------------------------------------------
 errorcode Patient::SetPhoneNumber(const std::string &iPhoneNumber)
 {
    if (iPhoneNumber.empty()) {Error::logError("iPhoneNumber is NULL");return errorcode::InvalidInput;};
    _PhoneNumber= iPhoneNumber;
    return errorcode::Success;
 }



errorcode Patient::GetMedicalHistory(std::string &oMedicalHistory) const
{
    if (_MedicalHistory.empty()) {Error::logError("_MedicalHistory is NULL");return errorcode::InvalidInput;};
    oMedicalHistory = _MedicalHistory;
    return errorcode::Success;
}
errorcode Patient::SetMedicalHistory(const std::string &iMedicalHistory)
{
    if (_MedicalHistory.empty()) {Error::logError("iMedicalHistory is NULL");return errorcode::InvalidInput;};
    _MedicalHistory= iMedicalHistory;
    return errorcode::Success;
}