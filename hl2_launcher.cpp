#include <windows.h>
#include <fstream>
#include <string>
#include <iostream>

// Function to check if a file exists, only used to check if hl2.exe exists in the folder 
bool fileExists(const std::string& filePath) {
    std::ifstream file(filePath);
    return file.good();
}

// now we get to the good stuff, the main function, the function that will launch hl2.exe, that function
int main() {

	// Set the path that this executable is in as the working directory to make sure the hl2.exe is found
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    std::string exePath;
    if (pos != std::string::npos) {
        exePath = std::string(buffer).substr(0, pos);
    }

	//this is only to make sure hl2.exe exists and is not used to launch the game, STARTUPINFOW is used to launch the game
    else {
        exePath = ".";
    }    std::string hl2ExePath = exePath + "\\hl2.exe";

    // no hl2.exe? PANIC!!! SOUND THE FUCKING ALARM!!!! AAHHHHHHHHHHHHH!!!!!!!!
    if (!fileExists(hl2ExePath)) {
        MessageBoxA(NULL, "Error: hl2.exe not found. Please place this file in the same directory as hl2.exe. It seems you did not do that.", "HL2 Launcher Error", MB_OK | MB_ICONERROR);
        return 1;
    }

    // the actual running of hl2.exe
    STARTUPINFOW si = { sizeof(si) };
    PROCESS_INFORMATION pi;

	// Run hl2.exe with proper launch arguments to start up Half-Life 2: Survivor Ver2.0, uses the launch arguments from the bat script instead
    std::wstring commandLine = L"hl2.exe -game hl2mp -windowed -w 1360 -h 768 -ac -nesys 0 -english";
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

	// a'ight, so we gots a problem here - it failed to run hl2.exe and i have no clue why. chances are it probably doesn't exist (to the launcher, i mean).
    // make sure you can see the standard hl2.exe with the basic icon, if you can see it, just give my launcher the middle finger. it won't be hurt by it nor will it know.
    if (!result) {
        DWORD error = GetLastError();
        std::cerr << "Error: Failed to launch hl2.exe. Error code: " << error << std::endl;
        system("pause");
        return 1;
    }
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}
