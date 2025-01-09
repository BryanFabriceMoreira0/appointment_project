cmake_minimum_required(VERSION 3.10...3.20)
project(appointment_project VERSION 0.1.0 LANGUAGES C CXX)

# Set C++17 as the required standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify include directories for the project using target_include_directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include              # Main include directory
    ${CMAKE_SOURCE_DIR}/include/models       # Header files for models
    ${CMAKE_SOURCE_DIR}/include/controllers  # Header files for controllers
    ${CMAKE_SOURCE_DIR}/include/database     # Header files for database interaction
    ${CMAKE_SOURCE_DIR}/include/utils        # Header files for utility functions
)

# Add source files for the project, including all subdirectories
file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp           # General source files
    ${CMAKE_SOURCE_DIR}/src/models/*.cpp    # Model-related source files
    ${CMAKE_SOURCE_DIR}/src/controllers/*.cpp # Controller-related source files
    ${CMAKE_SOURCE_DIR}/src/database/*.cpp   # Database-related source files
    ${CMAKE_SOURCE_DIR}/src/utils/*.cpp      # Utility source files
)

# Create the executable for the main application
add_executable(${PROJECT_NAME} ${SOURCES})

# Find and link SQLite3
find_package(SQLite3 REQUIRED)
target_link_libraries(${PROJECT_NAME} SQLite::SQLite3)

# Link additional libraries (if necessary)

# Optionally set the C++17 standard flags, although CMake already handles it
target_compile_options(${PROJECT_NAME} PRIVATE -std=c++17)

# Setup packaging and versioning (optional)
include(CPack)
