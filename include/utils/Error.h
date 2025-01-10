// ErrorCode.h
#ifndef ERROR__H
#define ERROR__H

#include <fstream>
#include <iostream>
#include <filesystem>
#include <cstdio> // For C++ to use fprintf and stderr

// Global enum definition
enum class errorcode
{
    Success = 0,
    InvalidInput,
    FailedFunction,
    UnknownError
};

/// @brief Function to check if a function has failed
/// @param er the return code of the function  
/// @return If it has failed 
inline bool FAILED(const errorcode &er)
{
    if (er != errorcode::Success)
        return true;
    else
        return false;
}

class Error
{
public:
    static void logError(const std::string &Message);
};

#endif // ERROR_H
