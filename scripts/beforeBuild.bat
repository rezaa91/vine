echo "Make build folder and set target to x86"
mkdir build
cd build
cmake -G "Visual Studio 16 2019" -A Win32 -S ../ -B "build32"