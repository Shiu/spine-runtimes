# Create DebugPrinter executable
add_executable(DebugPrinter ${CMAKE_CURRENT_SOURCE_DIR}/src/DebugPrinter.cpp)
target_link_libraries(DebugPrinter spine-cpp)
target_compile_features(DebugPrinter PRIVATE cxx_std_11)