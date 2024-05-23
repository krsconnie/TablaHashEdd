#!/bin/bash

# Imprimimos una cabecera para nuestro archivo CSV
echo "ejecutable;numElementos;tiempo"

# Repetiremos los experimentos 30 veces
for (( c=1; c<=30; c++ ))
do
    # Ejecutamos la primera versión de heapsort con 5 entradas distintas
    for n in 100000 200000 300000 400000 500000
    do
	./test_ID $n
    done
done
