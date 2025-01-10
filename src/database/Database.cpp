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
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(_db));
        // You could choose to throw an exception or handle it differently if needed.
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

    std::string createTableSQL = "CREATE TABLE Patients (\
    id INTEGER PRIMARY KEY, \
    firstname TEXT NOT NULL, \
    lastname TEXT NOT NULL, \
    dob TEXT NOT NULL, \
    phonenumber TEXT NOT NULL UNIQUE, \
    medicalhistory TEXT \
);";

    char *errorMessage;
    int rc = sqlite3_exec(_db, createTableSQL.c_str(), nullptr, nullptr, &errorMessage);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Error creating table: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        Error::logError("CreatePatientTable FAILED");
        return errorcode::FailedFunction;
    }
    else
        std::cout << "Table created successfully!" << std::endl;

    return errorcode::Success;
}
//----------------------------------------------------------------------------------------------------
errorcode Database::InsertPatientData(std::shared_ptr<Patient> spPerson)
{

    return errorcode::Success;
}