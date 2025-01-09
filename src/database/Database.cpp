#include "Database.h"
#include <cstdio> // For C++ to use fprintf and stderr

// Private constructor to use the singleton pattern and ensure only one connection
// to be reused. Opens the connection to the database.
Database::Database()
{
    int rc = sqlite3_open("Database.db", &_db); // Initialize _db
    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(_db));
        // You could choose to throw an exception or handle it differently if needed.
        throw std::runtime_error("Failed to open database");
    }
    else
        fprintf(stderr, "Opened database successfully\n");
}

Database::~Database()
{
    if (_db)
        sqlite3_close(_db);
}

/// @brief Get the instance of the database (singleton pattern)
Database &Database::GetInstance()
{
    static Database instance; // This will ensure only one instance of Database
    return instance;
}
