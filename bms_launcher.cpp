#include <windows.h>
#include <fstream>
#include <string>
#include <iostream>

// Function to check if a file exists
bool fileExists(const std::string& filePath) {
    std::ifstream file(filePath);
    return file.good();
}

// now we get to the good stuff, the main function, the function that will launch bms.exe, that function
int main() {

	// Set the path that this executable is in as the working directory to make sure the bms.exe is found
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    std::string exePath;
    if (pos != std::string::npos) {
        exePath = std::string(buffer).substr(0, pos);
    }

	//this is only to make sure bms.exe exists and is not used to launch the game, STARTUPINFOW is used to launch the game
    else {
        exePath = ".";
    }    std::string hl2ExePath = exePath + "\\bms.exe";

    // no bms.exe? PANIC!!! SOUND THE FUCKING ALARM!!!! AAHHHHHHHHHHHHH!!!!!!!!
    if (!fileExists(hl2ExePath)) {

		// whoops, accidentally left a remnant of hl2 code - my bad. it *is* literally just my code for hl2 launcher, so it doesn't really matter to me.
		// but it might confuse someone else seeing HL2 instead of BMS, soooo... (also, i didn't fix it yet for base Black Mesa so ignore it if you're reading this)
        MessageBoxA(NULL, "Error: bms.exe not found. Please place this file in the same directory as bms.exe. It seems you did not do that.", "BMS Launcher Error", MB_OK | MB_ICONERROR);
        return 1;
    }

    // the actual running of bms.exe
    STARTUPINFOW si = { sizeof(si) };
    PROCESS_INFORMATION pi;

	// Black Mesa: Military launch command line arguments, -disabledvk and -forceuid3d9 are required or else the game will crash on launch. Thanks, crowbar collective.
    std::wstring commandLine = L"bms.exe -game bmmilitary -disabledxvk -forceuid3d9";
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

	// The horror! The absolute horror! IT FAILED TO LAUNCH BMS.EXE AHHHHHHHHHHHH!!!!!!!!
	// (i don't know why this happened, there's no way to know why it failed to launch either, so it's entirely on your end)
    if (!result) {
        DWORD error = GetLastError();
        std::cerr << "Error: Failed to launch bms.exe. Error code: " << error << std::endl;
        system("pause");
        return 1;
    }
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}
