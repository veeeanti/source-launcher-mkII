cmake_minimum_required(VERSION 3.16)

project(PostalIIILauncher VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_GUI "Build as Windows GUI application (no console)" OFF)

set(SOURCE_FILES
    p3_launcher.cpp
)

set(RESOURCE_FILES
    p3_launcher.rc
    icon.ico
)

if(BUILD_GUI)
    add_executable(p3_launcher WIN32 ${SOURCE_FILES} ${RESOURCE_FILES})
else()
    add_executable(p3_launcher ${SOURCE_FILES} ${RESOURCE_FILES})
endif()

target_include_directories(p3_launcher PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(MSVC)
    target_compile_options(p3_launcher PRIVATE /W4 /permissive-)
else()
    target_compile_options(p3_launcher PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(WIN32)
    # Link common Windows libraries
    target_link_libraries(p3_launcher PRIVATE user32 gdi32 shell32)
endif()

set_target_properties(p3_launcher PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

install(TARGETS p3_launcher RUNTIME DESTINATION bin)
