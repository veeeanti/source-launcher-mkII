# Target a Windows system from Linux
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# Compilers (provided by Arch Linux's mingw-w64-gcc package)
set(CMAKE_C_COMPILER   x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)

# Root path containing MinGW libraries and headers
set(CMAKE_FIND_ROOT_PATH /usr/x86_64-w64-mingw32)

# Ensure CMake searches the MinGW root for headers + libs,
# but looks normally for programs
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# Enable windres for .rc resource files automatically
set(CMAKE_RC_COMPILER x86_64-w64-mingw32-windres)

# Optional: force static linking if you want a portable EXE
# set(CMAKE_EXE_LINKER_FLAGS "-static")
