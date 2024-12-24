cmake_minimum_required(VERSION 3.10)
project(option_pricer)

# Set the C++ standard and compile options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall")

# Include headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Collect all source files
# Adjust these glob patterns as your project structure changes.
file(GLOB_RECURSE SRC_FILES 
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/models/*/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/models/*/*/*.cpp"
)

# Create the executable target
add_executable(option_pricer ${SRC_FILES})
