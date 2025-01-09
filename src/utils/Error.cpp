#include "Error.h"


/// @brief Log the error into the log file
#include "Error.h"

/// @brief Log the error into the log file
void Error::logError(const std::string &Message)
{
    // Construct the log file path
    std::filesystem::path logFilePath = std::filesystem::current_path().parent_path() / "include" /"utils" / "Error.log";
    
    // Open the log file in append mode
    std::ofstream logFile(logFilePath, std::ios::app);

    // Check if the file is open
    if (!logFile)
    {
        std::cerr << "Error: Could not open log file at: " << logFilePath << std::endl;
        return;
    }

    // Write the error message to the log file
    logFile << Message << std::endl;
}
