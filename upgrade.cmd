@echo off
set tit=Ventus - r115 - Upgrade Utility
set upgradeFolder=ventus.auto.upgrade

rem *** (v) retrieve the date into a variable
for /f "skip=1" %%x in ('wmic os get localdatetime') do if not defined MyDate set MyDate=%%x
set today=%MyDate:~0,4%-%MyDate:~4,2%-%MyDate:~6,2%


rem
title %tit%
echo **************************************************
echo %tit%
echo Today is:%today%
echo Please, wait
echo **************************************************

rem ****
rem **** Change current directory to the directory of the upgrade.cmd command
rem ****
cd /D "%~dp0"
echo Working directrory is:
cd

rem ***
echo Upgrade command ran on: %today% >> upgrades.log


rem ****
rem **** Clean up previous upgrade folder
rem ****
if exist %upgradeFolder%\ (
  echo Removing old upgrade folder
  del /q "%upgradeFolder%\*"
  FOR /D %%p IN ("%upgradeFolder%") DO rmdir "%%p" /s /q
) else (
  echo Upgrade folder will be created
)


rem ****
rem **** Download new version 
rem ****
git clone https://github.com/aafent/Ventus115_RC_Deploy.git %upgradeFolder%

rem ****
rem **** Clean up prev forgoten new_upgrade command
rem ****
if exist new_upgrade.cmd (
    echo Cleanup old upgrade update program 
    del /q new_upgrade.cmd
) 


rem ****
rem **** Prepare the upgrade folder
rem ****
pushd %upgradeFolder%
for /f "usebackq delims=|" %%f in (`dir /b "*.tar"`) do (
echo Unpack tarball %%f
tar xvf "%%f"
del /q "%%f"
)
echo Ignore next "File Not Found" message (if appears) 
for /f "usebackq delims=|" %%f in (`dir /b "*.log"`) do (
del /q "%%f"
)
rem remove upgrade command (new_upgrade.cmd will remain)
if exist upgrade.cmd  del /q upgrade.cmd
popd

rem ****
rem **** copy files from upgrade to current folder
rem ****
echo Deploy files to the Ventus Home directory
xcopy "%upgradeFolder%" . /s /e /c /y /q


:end
rem ****
rem **** Try to replace current file with newer version of upgrade.cmd command
rem ****
if exist new_upgrade.cmd (
    echo Updating upgrade procedure
    move new_upgrade.cmd upgrade.cmd
) 
