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

class Error
{
public:
    static void logError(const std::string &Message, const std::string &File, const int Line);
};

#endif // ERROR_H
