cmake_minimum_required(VERSION 3.10)
project(spine-cpp)

include(${CMAKE_CURRENT_LIST_DIR}/../flags.cmake)

option(SPINE_NO_FILE_IO "Disable file I/O operations" OFF)

include_directories(include)
file(GLOB INCLUDES "include/**/*.h")
file(GLOB ALL_SOURCES "src/**/*.cpp")

# Exclude nostdcpp.cpp from regular build
list(FILTER ALL_SOURCES EXCLUDE REGEX "src/nostdcpp\\.cpp$")
set(SOURCES ${ALL_SOURCES})

add_library(spine-cpp STATIC ${SOURCES} ${INCLUDES})
target_include_directories(spine-cpp PUBLIC include)

if(SPINE_NO_FILE_IO)
    target_compile_definitions(spine-cpp PRIVATE SPINE_NO_FILE_IO)
endif()

# nostdcpp variant (no C++ standard library)
set(NOSTDCPP_SOURCES ${SOURCES} "src/nostdcpp.cpp")
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

    # Configure nostdcpp linking for different platforms
    add_executable(headless-test-nostdcpp ${CMAKE_CURRENT_SOURCE_DIR}/tests/HeadlessTest.cpp)
    target_link_libraries(headless-test-nostdcpp spine-cpp-nostdcpp)

    if(MSVC)
        target_link_options(headless-test-nostdcpp PRIVATE /NODEFAULTLIB)
        target_link_libraries(headless-test-nostdcpp msvcrt kernel32)
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_link_options(headless-test-nostdcpp PRIVATE -nostdlib++ -lc)
    else()
        target_link_options(headless-test-nostdcpp PRIVATE -nodefaultlibs)
        target_link_libraries(headless-test-nostdcpp -lm -lc -lgcc)
    endif()

    # Static variants (Linux only)
    if(UNIX AND NOT APPLE)
        add_executable(headless-test-static ${CMAKE_CURRENT_SOURCE_DIR}/tests/HeadlessTest.cpp)
        target_link_libraries(headless-test-static spine-cpp)
        target_link_options(headless-test-static PRIVATE -static)

        add_executable(headless-test-nostdcpp-static ${CMAKE_CURRENT_SOURCE_DIR}/tests/HeadlessTest.cpp)
        target_link_libraries(headless-test-nostdcpp-static spine-cpp-nostdcpp)
        target_link_options(headless-test-nostdcpp-static PRIVATE -static -static-libgcc -Wl,--exclude-libs,libstdc++.a)
        target_link_libraries(headless-test-nostdcpp-static -lm -lc)

        if(SPINE_NO_FILE_IO)
            target_compile_definitions(headless-test-static PRIVATE SPINE_NO_FILE_IO)
            target_compile_definitions(headless-test-nostdcpp-static PRIVATE SPINE_NO_FILE_IO)
        endif()
    endif()
endif()