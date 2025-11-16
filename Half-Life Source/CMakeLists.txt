cmake_minimum_required(VERSION 3.10)
project(HL1Launcher)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source list — add .rc file only for Windows builds
set(SOURCES
    hl1_launcher.cpp
)

if(WIN32)
    list(APPEND SOURCES hl1_launcher.rc)
endif()

add_executable(hl1_launcher ${SOURCES})

# Windows-only libraries
if(WIN32)
    target_link_libraries(hl1_launcher shell32)
endif()

# Output directory
set_target_properties(hl1_launcher PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)