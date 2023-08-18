@echo off
set /p id=Enter id: 
echo %id%
echo print it into a file
echo %id%>file.txt

:: Read from the file the id
echo read from the file "file.txt"
set /p var=<file.txt
echo id = %var%
:: Read from the file the id

:: CPU percentage work
:: wmic cpu get loadpercentage > file.txt (command)
:: CPU percentage work

:: The command print the battery remaining on the command window
:: wmic path win32_battery get estimatedchargeremaining
:: The command print the battery remaining on the command window

:: Print in the command window GPU parameters
:: wmic PATH Win32_videocontroller
:: Print in the command window GPU parameters

pause