@echo off
set tit=Prepare and push on GIT
title %tit%
echo **************************************************
echo %tit%
echo **************************************************
tar cvf executables.tar *.exe
git add .
git commit -a -m "Release"
git push
