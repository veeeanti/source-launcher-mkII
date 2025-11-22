cmake_minimum_required(VERSION 3.10)
project(HL2Launcher)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(hl2_launcher
    hl2_launcher.cpp
    hl2_launcher.rc
)

# Link required libraries (Windows specific)
if(WIN32)
    target_link_libraries(hl2_launcher shell32)
endif()

# Set output directory
set_target_properties(hl2_launcher PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)