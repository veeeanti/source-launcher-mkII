#include <windows.h>
#include <fstream>
#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

// Function to check if a file exists
bool fileExists(const std::string& filePath) {
    std::ifstream file(filePath);
    return file.good();
}

int main() {

	
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    std::string exePath;
    if (pos != std::string::npos) {
        exePath = std::string(buffer).substr(0, pos);
    }

	
    else {
        exePath = ".";
    }    std::string p3ExePath = exePath + "\\p3.exe";

   
    if (!fileExists(p3ExePath)) {
        MessageBoxA(NULL, "Error: p3.exe not found.", "P3 Launcher Error", MB_OK | MB_ICONERROR);
        return 1;
    }


    STARTUPINFOW si = { sizeof(si) };
    PROCESS_INFORMATION pi;

	 /* yes i know the game param should be p3, but after installing ultrapatch and postal iii
     and running the game, it refuses to live. however, changing the folder name and also the game param tooo~ */
    std::wstring commandLine = L"p3.exe -game postal3 -norussian -language english";
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



    if (!result) {
        DWORD error = GetLastError();
        std::cerr << "Error: Failed to launch p3.exe. Error code: " << error << std::endl;
        system("pause");
        return 1;
    }
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}
