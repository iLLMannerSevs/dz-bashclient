@ECHO OFF

cd /D "%~dp0"

IF exist "P:\WRDG\" (
	mklink /J "P:\WRDG\BashClient" "%cd%\WRDG\BashClient\"
) ELSE (
	mkdir "P:\WRDG\"
	mklink /J "P:\WRDG\BashClient" "%cd%\WRDG\BashClient\"
)