cmake_minimum_required(VERSION 3.10)
project(HL1Launcher)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(hl1_launcher
    hl1_launcher.cpp
    hl1_launcher.rc
)

# Link required libraries (Windows specific)
if(WIN32)
    target_link_libraries(hl1_launcher shell32)
endif()

# Set output directory
set_target_properties(hl1_launcher PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)