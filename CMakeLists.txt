cmake_minimum_required(VERSION 3.10)
project(exampleLauncher)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(example_launcher
    example_launcher.cpp
    example_launcher.rc
)

# Link required libraries (Windows specific)
if(WIN32)
    target_link_libraries(example_launcher shell32)
endif()

# Set output directory
set_target_properties(example_launcher PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
