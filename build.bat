@echo off
make clean
make
rd /s /q build
echo.
echo Press any key...
pause >nul