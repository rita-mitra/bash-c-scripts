#!/bin/bash

# Define the processes and their burst times
declare -A processes=( ["Process A"]=5 ["Process B"]=3 ["Process C"]=7 ["Process D"]=2 ["Process E"]=4 )
quantum=2  # Time quantum for each process

# Execute the round-robin scheduling algorithm
for process in "${!processes[@]}"; do
    burst_time=${processes[$process]}
    echo "Executing $process (Burst Time: $burst_time)"
    
    while [ $burst_time -gt 0 ]; do
        if [ $burst_time -gt $quantum ]; then
            sleep $quantum  # Simulating process execution for time quantum
            burst_time=$((burst_time - quantum))
        else
            sleep $burst_time  # Simulating process execution for remaining burst time
            burst_time=0
        fi
    done
    
    echo "$process completed"
    end_time=$(date +"%Y-%m-%d %H:%M:%S")  # Get the current timestamp
    echo "End time of $process: $end_time"
done
