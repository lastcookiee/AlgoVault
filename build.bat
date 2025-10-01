@echo off
REM Build script for AlgoVault - Interactive Algorithm Visualizer
REM This script compiles the project using g++ (MinGW)

echo =====================================
echo   AlgoVault Build Script
echo =====================================

REM Check if g++ is available
g++ --version >nul 2>&1
if errorlevel 1 (
    echo ERROR: g++ compiler not found!
    echo Please install MinGW or add g++ to your PATH.
    pause
    exit /b 1
)

echo Compiling AlgoVault...
echo.

REM Compile the project
g++ -std=c++11 -Wall -Wextra -O2 -o AlgoVault.exe main.cpp utils.cpp sorting.cpp graph.cpp

REM Check if compilation was successful
if errorlevel 1 (
    echo.
    echo ERROR: Compilation failed!
    echo Please check the error messages above.
    pause
    exit /b 1
) else (
    echo.
    echo SUCCESS: AlgoVault compiled successfully!
    echo Executable created: AlgoVault.exe
    echo.
    
    REM Ask user if they want to run the program
    set /p run_choice="Do you want to run AlgoVault now? (y/n): "
    if /i "%run_choice%"=="y" (
        echo.
        echo Starting AlgoVault...
        echo =====================================
        AlgoVault.exe
    ) else (
        echo.
        echo You can run AlgoVault later by executing: AlgoVault.exe
    )
)

echo.
pause