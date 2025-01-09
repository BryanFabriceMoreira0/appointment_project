#ifndef DATABASE_H
#define DATABASE_H
#include <memory>
#include <sqlite3.h>


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
};

#endif // DATABASE_H