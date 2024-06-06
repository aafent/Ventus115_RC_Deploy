@echo off
title starting Ventus R115
if EXIST "c:\pcadev\" set PCA=C
if EXIST "z:\pcadev\" set PCA=Z
if EXIST "v:\pcadev\" SET PCA=V
set SYBASE=%PCA%:\pcadev\sybase.ase12
PATH %SYBASE%\DataAccess\ADONET\dll;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;%SYBASE%\OCS-12_5\dll;%SYBASE%\OCS-12_5\lib3p;C:\Windows\Microsoft.NET\Framework\v4.0.30319;C:\Program Files\;%PCA%:\pcadev\locbin;
set SYBASE_ASE=ASE-12_5
set SYBASE_FTS=EFTS-12_5_2
set SYBASE_JRE=%PCA%:\pcadev\sybase.ase12\Shared\Sun\jre142
set SYBASE_JS=JS-12_5
set SYBASE_OCS=OCS-12_5
set SYBASE_SYSAM=SYSAM-1_0
set SYBASE_WS=WS-12_5
cd %SYBASE%
cd ..\ventus115
start ventus2.exe



