!/bin/bash
# Verify username and date
whoami
date

# Declare an array of processes with their burst times
processes=(P1 P2 P3 P4 P5)
burst_times=(10 4 6 2 8)

# Get the length of the processes array
num_processes=${#processes[@]}

# Sort the processes based on their burst times using bubble sort
for ((i=0; i < $num_processes-1; i++))
do
  for ((j=0; j < $num_processes-i-1; j++))
  do
    if [[ ${burst_times[j]} -gt ${burst_times[j+1]} ]]
    then
      # Swap the burst times
      temp=${burst_times[j]}
      burst_times[j]=${burst_times[j+1]}
      burst_times[j+1]=$temp

      # Swap the process names
      temp=${processes[j]}
      processes[j]=${processes[j+1]}
      processes[j+1]=$temp
    fi
  done
done

echo "Processes in order of execution (Shortest Job First):"

for ((i=0; i < $num_processes; i++))
do
  echo "Process: ${processes[i]}, Burst Time: ${burst_times[i]}"
done
