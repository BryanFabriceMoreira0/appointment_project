#include "Database.h"
#include <iostream>
#include <filesystem>
#include <cstdio> // For C++ to use fprintf and stderr

/// @brief ///Method to get he right path to create the database
/// @return the absolute path to the database file
std::string Database::getDatabasePath()
{
    std::filesystem::path dbPath = std::filesystem::current_path().parent_path() / "data" / "Database.db";
    return dbPath.string();
}

//----------------------------------------------------------------------------------------------------

/// @brief Private constructor to use the singleton pattern and ensure only one connection
// to be reused. Opens the connection to the database.
Database::Database()
{
    std::string dbpath = getDatabasePath();
    int rc = sqlite3_open(dbpath.c_str(), &_db); // Initialize _db
    if (rc)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(_db) << std::endl;
        sqlite3_close(_db); // Clean up even if opening fails
        throw std::runtime_error("Failed to open database");
    }
}
//----------------------------------------------------------------------------------------------------

Database::~Database()
{
    if (_db)
        sqlite3_close(_db);
}

//----------------------------------------------------------------------------------------------------

/// @brief Get the instance of the database (singleton pattern)
///@return The instance (static so one instance for the whole class)
Database &Database::GetInstance()
{
    static Database instance; // This will ensure only one instance of Database for the whole class
    return instance;
}

/// @brief Create the patients table
///@return The return code
//----------------------------------------------------------------------------------------------------
errorcode Database ::CreatePatientTable()
{
    std::string createTableSQL = "CREATE TABLE IF NOT EXISTS Patients (\
        id INTEGER PRIMARY KEY, \
        firstname TEXT NOT NULL, \
        lastname TEXT NOT NULL, \
        dob TEXT NOT NULL, \
        phonenumber TEXT NOT NULL UNIQUE, \
        medicalhistory TEXT );";

    int rc = sqlite3_exec(_db, createTableSQL.c_str(), NULL, NULL, NULL);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Error creating table: " << sqlite3_errmsg(_db) << std::endl;
    }
    else
    {
        std::cout << "Table 'Patients' created successfully." << std::endl;
    }

    return errorcode::Success;
}
//----------------------------------------------------------------------------------------------------
// Insert the data of a single patient to the database
errorcode Database::InsertPatientData(std::shared_ptr<Patient> spPerson)
{
    errorcode ec;

    if (!spPerson)
    {
        Error::logError("spPerson is NULL");
        return errorcode::InvalidInput;
    };

    std::string createPatientSQL = "INSERT INTO patients (firstname, lastname, dob, phonenumber, medicalhistory) VALUES (?, ?, ?, ?, ?);";

    sqlite3_stmt *stmt;
    char *errorMessage;
    int size = sizeof(createPatientSQL.c_str());
    int rc = sqlite3_prepare_v2(_db, createPatientSQL.c_str(), -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(_db) << std::endl;
        Error::logError("sqlite3_prepare_v2 FAILED");
        return errorcode::FailedFunction;
    }

    // Bind the values for the first insert:
    //
    std::string FirstName;
    ec = spPerson->GetFirstName(FirstName);
    if (FAILED(ec))
    {
        Error::logError("GetFirstName FAILED ");
        return ec;
    }

    rc = sqlite3_bind_text(stmt, 1, FirstName.c_str(), -1, NULL);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Error binding : " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        Error::logError("sqlite3_bind_text FAILED");
        return errorcode::FailedFunction;
    }

    std::string LastName;
    ec = spPerson->GetLastName(LastName);
    if (FAILED(ec))
    {
        Error::logError("GetLastName FAILED ");
        return ec;
    }

    sqlite3_bind_text(stmt, 2, LastName.c_str(), -1, NULL);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Error binding : " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        Error::logError("sqlite3_bind_text FAILED");
        return errorcode::FailedFunction;
    }

    std::string DOB;
    ec = spPerson->GetDOB(DOB);
    if (FAILED(ec))
    {
        Error::logError("GetDOB FAILED ");
        return ec;
    }

    sqlite3_bind_text(stmt, 3, DOB.c_str(), -1, NULL);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Error binding : " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        Error::logError("sqlite3_bind_text FAILED");
        return errorcode::FailedFunction;
    }

    std::string PhoneNumber;
    ec = spPerson->GetPhoneNumber(PhoneNumber);
    if (FAILED(ec))
    {
        Error::logError("GetPhoneNumber FAILED ");
        return ec;
    }

    sqlite3_bind_text(stmt, 4, PhoneNumber.c_str(), -1, NULL);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Error binding : " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        Error::logError("sqlite3_bind_text FAILED");
        return errorcode::FailedFunction;
    }

    std::string MedicalHistory;
    ec = spPerson->GetMedicalHistory(MedicalHistory);
    if (FAILED(ec))
    {
        Error::logError("GetMedicalHistory FAILED ");
        return ec;
    }

    sqlite3_bind_text(stmt, 5, MedicalHistory.c_str(), -1, NULL);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Error binding : " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        Error::logError("sqlite3_bind_text FAILED");
        return errorcode::FailedFunction;
    }

    // Insert
    sqlite3_step(stmt);

    // Finalize
    sqlite3_finalize(stmt);

    // Close
    sqlite3_close(_db);

    return errorcode::Success;
}