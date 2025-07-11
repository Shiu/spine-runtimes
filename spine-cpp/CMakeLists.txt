cmake_minimum_required(VERSION 3.10)
project(spine-cpp)

include(${CMAKE_CURRENT_LIST_DIR}/../flags.cmake)

include_directories(include)
file(GLOB INCLUDES "include/**/*.h")
file(GLOB SOURCES "src/**/*.cpp")

add_library(spine-cpp STATIC ${SOURCES} ${INCLUDES})
target_include_directories(spine-cpp PUBLIC include)

# Install target
install(TARGETS spine-cpp EXPORT spine-cpp_TARGETS DESTINATION dist/lib)
install(FILES ${INCLUDES} DESTINATION dist/include)

# Export target
export(
	EXPORT spine-cpp_TARGETS
	FILE ${CMAKE_CURRENT_BINARY_DIR}/spine-cppTargets.cmake
	NAMESPACE "Spine::")

# Optional tests
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    add_executable(debug-printer ${CMAKE_CURRENT_SOURCE_DIR}/tests/DebugPrinter.cpp)
    target_link_libraries(debug-printer spine-cpp)
endif()