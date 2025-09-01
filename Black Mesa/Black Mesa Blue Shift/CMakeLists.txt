cmake_minimum_required(VERSION 3.10)
project(BMSLauncher)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(bms_launcher
    bms_launcher.cpp
    bms_launcher.rc
)

# Link required libraries (Windows specific)
if(WIN32)
    target_link_libraries(bms_launcher shell32)
endif()

# Set output directory
set_target_properties(bms_launcher PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)