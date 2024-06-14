@echo off
set tit=Prepare and push on GIT
rem *** (v) retrieve the date into a variable
for /f "skip=1" %%x in ('wmic os get localdatetime') do if not defined MyDate set MyDate=%%x
set today=%MyDate:~0,4%-%MyDate:~4,2%-%MyDate:~6,2%
rem 
title %tit%
echo **************************************************
echo %tit%
echo **************************************************
tar cvf executables.tar *.exe
tar cvf dynamiclibraries.tar *.exe
git add .
git commit -a -m "Release of %today%"
git push
