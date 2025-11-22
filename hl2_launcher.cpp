/* Hi, this is a simple C++ launcher to launch Half-Life 2 and subsequently all Source Engine games.
* This code can be edited to your liking or however you need it for the game you want to launch.
* I will be making more variants of this launcher for other Source Engine games, specifically the ones I own and play.
* Black Mesa, Half-Life 2 (steam_legacy branch), Portal, etc etc. 
* Make sure to place this file in the same directory as hl2.exe, otherwise it will not work.
* Also, make sure to change the icon too, if you don't it'll have the default Steam Half-Life 2 icon lol.
*/
#include <windows.h>
#include <fstream>
#include <string>
#include <iostream>

// Function to check if a file exists
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

	// Run hl2.exe with proper launch arguments to start up Half-Life 2, NOTE: this is for the steam_legacy branch and will cause problems if run with the main branch (aka 20th Anniversary Update)
    std::wstring commandLine = L"hl2.exe -game hl2";
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

	// The horror! The absolute horror! IT FAILED TO LAUNCH HL2.EXE AHHHHHHHHHHHH!!!!!!!!
	// (i don't know why this happened, there's no way to know why it failed to launch either, so it's entirely on your end)
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
