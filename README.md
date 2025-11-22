Hi, this is a simple C++ launcher to launch Half-Life 2 and subsequently all Source Engine games.
This code can be edited to your liking or however you need it for the game you want to launch.
I will be making more variants of this launcher for other Source Engine games, specifically the ones I own and play.
Black Mesa, Half-Life 2 (steam_legacy branch), Portal, etc etc. 
Make sure to place this file in the same directory as hl2.exe, otherwise it will not work.
Also, make sure to change the icon too, if you don't it'll have the default Steam Half-Life 2 icon lol.

# Prebuilt binaries can be found in Releases or in each separate branch. 

## Building:

Necessary tools:
  - Visual Studio 2022
  - MSVC C++ compiler
  - Windows 10 SDK
  - Cmake

You can build it in CMD or in VS2022, simplest way is to just do it in CMD.
  - Open the folder containing the source files in CMD (click on the address bar at the top of Explorer and type in ``cmd`` and press enter.)
  - Create a folder named "build" either the standard way (right click menu) or by running ``mkdir build``
  - Run ``cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release`` | If you installed cmake correctly, it should work, if it doesn't then try rebooting your pc if you didn't already.
  - After it completes, which shouldn't take long at all, run ``cmake --build build --config Release`` and then it should build without any issues.
  - Build dir will be ``.\build\bin\examplename_launcher.exe``

## Any issues?
Open a pull request or contact me on discord (@vee.anti), I'll try to help the best I can.
