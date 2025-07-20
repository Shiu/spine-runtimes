cmake_minimum_required(VERSION 3.10)
project(spine-cpp)

include(${CMAKE_CURRENT_LIST_DIR}/../flags.cmake)

option(SPINE_NO_FILE_IO "Disable file I/O operations" OFF)

include_directories(include)
file(GLOB INCLUDES "include/**/*.h")
file(GLOB SOURCES "src/**/*.cpp")

add_library(spine-cpp STATIC ${SOURCES} ${INCLUDES})
target_include_directories(spine-cpp PUBLIC include)

if(SPINE_NO_FILE_IO)
    target_compile_definitions(spine-cpp PRIVATE SPINE_NO_FILE_IO)
endif()

# nostdcpp variant (no C++ standard library)
file(GLOB NOSTDCPP_SOURCES ${SOURCES} "src/nostdlib.cpp")
add_library(spine-cpp-nostdcpp STATIC ${NOSTDCPP_SOURCES} ${INCLUDES})
target_include_directories(spine-cpp-nostdcpp PUBLIC include)

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
    add_executable(headless-test ${CMAKE_CURRENT_SOURCE_DIR}/tests/HeadlessTest.cpp)
    target_link_libraries(headless-test spine-cpp)
    
    if(SPINE_NO_FILE_IO)
        target_compile_definitions(headless-test PRIVATE SPINE_NO_FILE_IO)
    endif()
    
    # nostdcpp test executable (no C++ stdlib)
    add_executable(headless-test-nostdcpp ${CMAKE_CURRENT_SOURCE_DIR}/tests/HeadlessTest.cpp)
    
    if(MSVC)
        # On Windows/MSVC, disable default libraries but keep C runtime
        target_link_libraries(headless-test-nostdcpp spine-cpp-nostdcpp)
        target_link_options(headless-test-nostdcpp PRIVATE /NODEFAULTLIB)
        target_link_libraries(headless-test-nostdcpp msvcrt kernel32)
    else()
        # Unix/Linux: avoid linking libstdc++ automatically
        if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
            target_link_libraries(headless-test-nostdcpp spine-cpp-nostdcpp)
            target_link_options(headless-test-nostdcpp PRIVATE -nostdlib++ -lc)
        else()
            # GCC: use -nodefaultlibs and link minimal libraries including libgcc for operator new/delete
            target_link_options(headless-test-nostdcpp PRIVATE -nodefaultlibs)
            target_link_libraries(headless-test-nostdcpp spine-cpp-nostdcpp -lm -lc -lgcc)
        endif()
    endif()
endif()