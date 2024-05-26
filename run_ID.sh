#!/bin/bash

# Print CSV header
echo "ejecutable;numElementos;tiempo"

# Repeat experiments 30 times
for (( c=1; c<=30; c++ ))
do
    # Execute test_ID with different input sizes
    for n in 100000 200000 300000 400000 500000
    do
        ./test_ID $n >> experiment_results_ID.log  # Redirect output to a log file
    done
done > experiment_output.csv  # Redirect script output to a CSV file
