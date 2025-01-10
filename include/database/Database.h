#ifndef DATABASE_H
#define DATABASE_H
#include <memory>
#include <sqlite3.h>
#include "Error.h"
#include "Patient.h"

// Wrapper classs to handle sqlite database connetion using singleton pattern
class Database
{

private:
    Database(); // Private constructor to use the singleton pattern
    ~Database();
    static std::string getDatabasePath();

    sqlite3 *_db; //

public:
    static Database &GetInstance();

    errorcode CreatePatientTable();
    errorcode InsertPatientData(std::shared_ptr<Patient> spPerson);
};

#endif // DATABASE_H