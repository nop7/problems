@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin\vcvars32.bat" > nul 2>&1
cl.exe %* /nologo /EHsc
