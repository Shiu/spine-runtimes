cmake_minimum_required(VERSION 3.10)
project(spine-glfw)

include(FetchContent)
# Set GLFW options before fetching
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL " " FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL " " FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL " " FORCE)
set(GLFW_INSTALL OFF CACHE BOOL " " FORCE)

# Fetch GLFW
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG latest
        GIT_SHALLOW 1
)
FetchContent_MakeAvailable(glfw)

# Set glbinding options before fetching
set(OPTION_BUILD_DOCS OFF CACHE BOOL " " FORCE)
set(OPTION_BUILD_EXAMPLES OFF CACHE BOOL " " FORCE)
set(OPTION_BUILD_TESTS OFF CACHE BOOL " " FORCE)
set(OPTION_BUILD_TOOLS OFF CACHE BOOL " " FORCE)
set(OPTION_BUILD_WITH_BOOST_THREAD OFF CACHE BOOL " " FORCE)
set(OPTION_BUILD_GPU_TESTS OFF CACHE BOOL " " FORCE)
set(OPTION_BUILD_PYTHON_BINDINGS OFF CACHE BOOL " " FORCE)
set(OPTION_SELF_CONTAINED OFF CACHE BOOL " " FORCE)

# Fetch glbinding
FetchContent_Declare(
        glbinding
        GIT_REPOSITORY https://github.com/cginternals/glbinding.git
        GIT_TAG master
        GIT_SHALLOW 1
)
FetchContent_MakeAvailable(glbinding)

include_directories(${glbinding_SOURCE_DIR}/include)
include_directories(src)

# Find local OpenGL lib
find_package(OpenGL REQUIRED)

# Default flags
include(${CMAKE_SOURCE_DIR}/../flags.cmake)

# Add spine-c (which includes spine-cpp)
add_subdirectory(${CMAKE_SOURCE_DIR}/../spine-c ${CMAKE_BINARY_DIR}/spine-c-build)

# spine-glfw library
add_library(spine-glfw STATIC src/spine-glfw.cpp src/spine-glfw.h src/stb_image.h)
target_link_libraries(spine-glfw PRIVATE glbinding::glbinding)
target_link_libraries(spine-glfw LINK_PUBLIC spine-c)

# Example
add_executable(spine-glfw-example example/main.cpp)
target_link_libraries(spine-glfw-example PRIVATE glfw)
target_link_libraries(spine-glfw-example PRIVATE OpenGL::GL)
target_link_libraries(spine-glfw-example LINK_PUBLIC spine-glfw)
target_link_libraries(spine-glfw-example PRIVATE glbinding::glbinding)
set_property(TARGET spine-glfw-example PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/spine-glfw")

# spine-c Example
add_executable(spine-glfw-example-c example/main-c.cpp)
target_link_libraries(spine-glfw-example-c PRIVATE glfw)
target_link_libraries(spine-glfw-example-c PRIVATE OpenGL::GL)
target_link_libraries(spine-glfw-example-c LINK_PUBLIC spine-glfw)
target_link_libraries(spine-glfw-example-c PRIVATE glbinding::glbinding)
set_property(TARGET spine-glfw-example-c PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/spine-glfw")


# Physics example
add_executable(spine-glfw-physics example/physics.cpp)
target_link_libraries(spine-glfw-physics PRIVATE glfw)
target_link_libraries(spine-glfw-physics PRIVATE OpenGL::GL)
target_link_libraries(spine-glfw-physics LINK_PUBLIC spine-glfw)
target_link_libraries(spine-glfw-physics PRIVATE glbinding::glbinding)
set_property(TARGET spine-glfw-physics PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/spine-glfw")

# IK Following example
add_executable(spine-glfw-ik-following example/ik-following.cpp)
target_link_libraries(spine-glfw-ik-following PRIVATE glfw)
target_link_libraries(spine-glfw-ik-following PRIVATE OpenGL::GL)
target_link_libraries(spine-glfw-ik-following LINK_PUBLIC spine-glfw)
target_link_libraries(spine-glfw-ik-following PRIVATE glbinding::glbinding)
set_property(TARGET spine-glfw-ik-following PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/spine-glfw")

# copy data to build directory
add_custom_command(TARGET spine-glfw-example PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_LIST_DIR}/data $<TARGET_FILE_DIR:spine-glfw-example>/data)

add_custom_command(TARGET spine-glfw-physics PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_LIST_DIR}/data $<TARGET_FILE_DIR:spine-glfw-physics>/data)

add_custom_command(TARGET spine-glfw-ik-following PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_LIST_DIR}/data $<TARGET_FILE_DIR:spine-glfw-ik-following>/data)
