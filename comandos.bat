cd C:/Users/desca/OneDrive/Escritorio/AlanCenfo
mkdir carpeta1 carpeta2
cd carpeta1
echo "codigo desde C++ estamos ejecutando" >>temperatura.txt
echo .>presion.txt
copy temperatura.txt presion.txt

@echo off
setlocal enabledelayedexpansion

(for /l %%i in (1,1,1000) do (

	set /a numero=!random! %%100 +1
	echo !numero!
))> temperatura.doc
cd ..
cd carpeta2
(for /l %%i in (1,1,1000) do (

	set /a numero=!random! %%100 +1
	echo !numero!
))> presion.txt