#include <windows.h>
#include <fstream>
#include <string>
#include <iostream>

// Function to check if a file exists
bool fileExists(const std::string& filePath) {
    std::ifstream file(filePath);
    return file.good();
}

// now we get to the good stuff, the main function, the function that will launch hdtf.exe, that function
int main() {

	// Set the path that this executable is in as the working directory to make sure the hdtf.exe is found
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    std::string exePath;
    if (pos != std::string::npos) {
        exePath = std::string(buffer).substr(0, pos);
    }

	//this is only to make sure hdtf.exe exists and is not used to launch the game, STARTUPINFOW is used to launch the game
    else {
        exePath = ".";
    }    std::string hdtfExePath = exePath + "\\hdtf.exe";

    // no hdtf.exe? PANIC!!! SOUND THE FUCKING ALARM!!!! AAHHHHHHHHHHHHH!!!!!!!!
    if (!fileExists(hdtfExePath)) {
        MessageBoxA(NULL, "Error: hdtf.exe not found. Please place this file in the same directory as hdtf.exe. It seems you did not do that.", "HDTF Launcher Error", MB_OK | MB_ICONERROR);
        return 1;
    }

    // the actual running of hdtf.exe
    STARTUPINFOW si = { sizeof(si) };
    PROCESS_INFORMATION pi;

	// Run hdtf.exe with proper launch arguments to start up HDTF
    std::wstring commandLine = L"hdtf.exe -game HDtF";
    BOOL result = CreateProcessW(
        NULL,
        &commandLine[0],
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    );

	// The horror! The absolute horror! IT FAILED TO LAUNCH HDTF.EXE AHHHHHHHHHHHH!!!!!!!!
	// (i don't know why this happened, there's no way to know why it failed to launch either, so it's entirely on your end)
    if (!result) {
        DWORD error = GetLastError();
        std::cerr << "Error: Failed to launch hdtf.exe. Error code: " << error << std::endl;
        system("pause");
        return 1;
    }
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}
