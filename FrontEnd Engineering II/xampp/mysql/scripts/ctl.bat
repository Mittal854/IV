@echo off
rem START or STOP Services
rem ----------------------------------
rem Check if argument is STOP or START

if not ""%1"" == ""START"" goto stop


"D:\chitkara\fee2\xampp\mysql\bin\mysqld" --defaults-file="D:\chitkara\fee2\xampp\mysql\bin\my.ini" --standalone
if errorlevel 1 goto error
goto finish

:stop
cmd.exe /C start "" /MIN call "D:\chitkara\fee2\xampp\killprocess.bat" "mysqld.exe"

if not exist "D:\chitkara\fee2\xampp\mysql\data\%computername%.pid" goto finish
echo Delete %computername%.pid ...
del "D:\chitkara\fee2\xampp\mysql\data\%computername%.pid"
goto finish


:error
echo MySQL could not be started

:finish
exit
