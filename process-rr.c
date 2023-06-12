// C Program to Simulate Round Robin CPU Scheduling by Nived Kannada
// https://www.nanogalaxy.org/2020/10/c-program-to-simulate-round-robin-cpu.html
// NOTE: IN THIS, WE ARE ASSUMING THAT ARRIVAL TIME IS 0 FOR ALL PROCESSES.

#include<stdio.h>
//We are defining functions to calculate Turnaroundtime and waiting time.
//Function to find Turnaround time
int turnarroundtime(int p[], int n,
int bt[], int wt[], int tat[]) {
    int i;
   for (i = 0; i < n ; i++)
   tat[i] = bt[i] + wt[i];
   return 1;
}
//Function to calculate waiting time
int waitingtime(int p[], int n,
int bt[], int wt[], int quantum) 
{
   int rem_bt[n];  //rem_bt is remaining burst time for each process(stored as array). It is initially set as equal to bt[].
   //Copying bt[] to rem_bt[]
   for (int i = 0 ; i < n ; i++)
   rem_bt[i] = bt[i];
   int t = 0; //Setting initial time as 0
   //Traversing processes in Round Robin manner until all of them are not done.
   while (1) {
      int finished = 1;
      for (int i = 0 ; i < n; i++) //Traversing through each process one by one repeatedly.
      {
         //We have to process only if remaining burst time of a process is greater than zero.
         if (rem_bt[i] > 0) //Checking if remaining burst time of current process is greater than zero.
         {   
            finished = 0; // rem_bt[i]>0 means the current process is not finished yet.
            if (rem_bt[i] > quantum) {
               t = t+quantum;    //Adding time_quantum to current time t.
               rem_bt[i] = rem_bt[i] - quantum; //Subtracting time_quantum from remaining burst time.
            }
            else    // ie. if remaining burst time is less than time_quantum
            {
               t = t + rem_bt[i];   //adding the remaining burst time with current time t.  
               wt[i] = t - bt[i];   // Waiting time = current time - burst time of current process.
               //in this case, rem_bt[i] is less than the time_quantum. 
               //ie. process will be finished in this cycle. So we can set rem_bt[i] as 0.
               rem_bt[i] = 0;   
            }
         }
      }
      //If all processes are finished
      if (finished == 1)
       {  break; }
   }
   return 1;
}

//Main Function
void main()
{
    int n, bt[20], at[20],p[20],wt[20],tat[20] ,i, total=0, time_quantum; //Here a new variable is introduced --> time_quantum
    int x;
    float avgwt=0, avgtat=0;
    
    //Reading number of processes from input.
    printf("Enter number of processes: ");
    scanf("%d",&n);
    
    //Reading Burst times of all processes. (( ASSUMING ARRIVAL TIME IS 0 FOR ALL PROCESSES. ))
    printf("Enter the Burst time value of each process: \n");
    for(i=0;i<n;i++)
    {
        p[i]=i;
        at[i]=0;
        printf("Burst Time of P[%d]: ",i);
        scanf("%d",&bt[i]);
    }
    
    //Reading the Time Quantum value
    printf("Enter the Time Quantum: ");
    scanf("%d",&time_quantum);
    
    //Calling the functions to calculate waiting time and turnaround time
    waitingtime(p, n, bt, wt, time_quantum);
    turnarroundtime(p, n, bt, wt, tat);
    
    //Displaying Table
    printf("\n\tPID\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
    {
        printf("\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],wt[i],tat[i]);
    }
    
    //Calculating Average Waiting time and Average Turnaround Time
    for(i=0;i<n;i++)
    {
        avgwt = avgwt + wt[i];
        avgtat = avgtat + tat[i];
    }
    avgwt = avgwt/n;
    avgtat = avgtat/n;
    
    //Displaying Average WT and Average TAT 
    printf("\nAverage WT = %f\n", avgwt);
    printf("\nAverage TAT = %f\n", avgtat);
}

//END OF PROGRAM