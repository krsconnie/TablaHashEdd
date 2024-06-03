@echo off
setlocal
REM Ejecuta los otros archivos por lotes
call run_ID_time_lineal.bat
timeout /t 5
call run_ID_time_quadratic.bat
timeout /t 5
call run_ID_time_ht_double.bat
timeout /t 5
call run_ID_time_open.bat