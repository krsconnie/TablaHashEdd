#!/bin/bash

# Print CSV header
echo "ejecutable;numElementos;tiempo"

# Repeat experiments 30 times
for (( c=1; c<=30; c++ ))
do
    # Execute test_ID with different input sizes, max 21070
    for n in 5000 10000 15000 20000 21070
    do
        ./test_ID $n >> experiment_results_ID.log  # Redirect output to a log file
    done
done > experiment_output.csv  # Redirect script output to a CSV file
