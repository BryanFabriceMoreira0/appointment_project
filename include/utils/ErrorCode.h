// ErrorCode.h
#ifndef ERROR_CODE_H
#define ERROR_CODE_H

#include <fstream>
#include <iostream>
#include <filesystem>
#include <cstdio> // For C++ to use fprintf and stderr

// Global enum definition
enum class ErrorCode {
    Success = 0,
    InvalidInput,
    FailedFunction,
    UnknownError
};

std::string GetLogFilePath()
{
    std::filesystem::path LogFilePath = std::filesystem::current_path().parent_path() / "utils" / "Error.log";
    return LogFilePath.string();
}

void logError(const std::string& message) {

    //Get the right path 
    std::string LogFilePath=GetLogFilePath();
    // Open the log file in append mode
    std::ofstream logFile(LogFilePath.c_str(), std::ios::app);

    // Check if the file is open
    if (!logFile) {
        std::cerr << "Error: Could not open log file!" << std::endl;
        return;
    }

    // Write the error message to the log file
    logFile << message << std::endl;

    // Close the file
    logFile.close();
}
#endif // ERROR_CODE_H
