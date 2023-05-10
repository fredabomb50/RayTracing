@echo off

:: Compile and link staticly a new build executable
cd C:\msys64\mingw64\bin\
g++.exe -static -g C:\Users\lpacheco\Documents\GitHub\RayTracing\src\main.cpp -o C:\Users\lpacheco\Documents\GitHub\RayTracing\build\main.exe

:: Go to build path and run executable
cd C:\Users\lpacheco\Documents\GitHub\RayTracing\build\
main.exe