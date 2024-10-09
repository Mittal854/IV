@echo off

if not ""%1"" == ""START"" goto stop

cmd.exe /C start /B /MIN "" "D:\chitkara\fee2\xampp\apache\bin\httpd.exe"

if errorlevel 255 goto finish
if errorlevel 1 goto error
goto finish

:stop
cmd.exe /C start "" /MIN call "D:\chitkara\fee2\xampp\killprocess.bat" "httpd.exe"

if not exist "D:\chitkara\fee2\xampp\apache\logs\httpd.pid" GOTO finish
del "D:\chitkara\fee2\xampp\apache\logs\httpd.pid"
goto finish

:error
echo Error starting Apache

:finish
exit
