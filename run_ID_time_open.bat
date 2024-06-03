@echo off
setlocal

REM Eliminar experiment_output.csv si existe
if exist "experiment_output_open.csv" (
    del experiment_output_open.csv
)

REM Verificar si test_ID.cpp existe en el directorio actual
if not exist "test_time_open.cpp" (
    echo Error: test_ID.cpp no se encuentra en el directorio actual.
    exit /b 1
)

REM Compilar el archivo test_ID.cpp  test_basico
g++ -o test_ID.exe test_time_open.cpp
if %errorlevel% neq 0 (
    echo Error: la compilación de test_ID.cpp falló.
    exit /b 1
)

REM Crear o limpiar el archivo de log
> experiment_results_ID_open.log echo.

REM Imprimir el encabezado CSV en el archivo de salida final
echo numElementos;tiempo > experiment_output_open.csv
REM Repetir el experimento 30 veces
for /L %%c in (1,1,30) do (
    REM Ejecutar test_ID con diferentes tamaños de entrada, máximo 21070
    for %%n in (1000, 5000, 10000, 20000) do (
        .\test_ID.exe %%n >> experiment_results_ID_open.log
    )
)

REM Redirigir la salida del log al archivo CSV final
type experiment_results_ID_open.log >> experiment_output_open.csv

REM Eliminar los archivos .exe y .log
del test_ID.exe
del experiment_results_ID_open.log

endlocal
