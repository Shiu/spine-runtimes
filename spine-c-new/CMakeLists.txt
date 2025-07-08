cmake_minimum_required(VERSION 3.10)
project(spine-c-new C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# Include spine-cpp
add_subdirectory(../spine-cpp ${CMAKE_CURRENT_BINARY_DIR}/spine-cpp)

# Collect all source files
file(GLOB SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)
file(GLOB GENERATED_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/generated/*.cpp"
)
list(APPEND SOURCES ${GENERATED_SOURCES})

# Create the library
add_library(spine-c-new STATIC ${SOURCES})

# Include directories
target_include_directories(spine-c-new PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Link with spine-cpp
target_link_libraries(spine-c-new PRIVATE spine-cpp)

# Add spine-cpp include directories
target_include_directories(spine-c-new PRIVATE
    ../spine-cpp/spine-cpp/include
)

# Export compile commands for better IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Create test executable
add_executable(spine-c-test test/test.c)
target_link_libraries(spine-c-test spine-c-new)
target_include_directories(spine-c-test PRIVATE include)