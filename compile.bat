@echo off
echo Building Snake...
gcc -O2 -Wall -o snake.exe main.c logic.c input.c render.c
if %errorlevel% == 0 (
    echo.
    echo  Build OK!  Run:  snake.exe
) else (
    echo.
    echo  Build FAILED. Make sure gcc (MinGW) is on your PATH.
)
pause
