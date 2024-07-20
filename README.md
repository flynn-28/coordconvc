# DMS to DD Coordinate Converter
Convert DMS coordinates into DD coordinates using C++

## Run
to run, compile the project into binary files for your system or download precompiled binaries [here](https://github.com/flynn-28/coordconvc/releases/tag/release)

## Build

### Windows
1. Create a new project in Visual Studio
2. Use the Windows Desktop Application Template
3. Copy and paste the contents of [coordconv.cpp](https://github.com/flynn-28/coordconvc/blob/main/coordconv.cpp) into the main c++ file
4. Build the project with the keyboard shortcut CTRL + SHIFT + B
5. Navigate to the x64 folder in your project root directory
6. enter the "debug" folder
7. run the program with this executable

### Linux and MacOS
1. install g++ compiler: `sudo apt install g++`
2. clone this repository: `git clone https://github.com/flynn-28/coordconvc.git`
3. enter the directory: `cd coordconv`
4. run build command: `g++ -std=c++11 coordconv.cpp -o coordconv.bin`
5. run the program with: `./coordconv.bin`
