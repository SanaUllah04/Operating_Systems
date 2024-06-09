#include <stdio.h>
#include <stdbool.h>

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

int main() 
{
    int Total_Processes = 5;
    int Process[Total_Processes], current = 0, max_no;

    // Initializing all processes with Zero as a starting point.
    for (int i = 0; i < Total_Processes; i++) 
    {
        Process[i] = 0;
    }


    do 
    {
        bool choosing = true;
        
        // Choosing the maximum ticket number
        max_no = 0;
        for (int i = 0; i < Total_Processes-1; i++) 
        {
            max_no = max(Process[i], Process[i+1]);
        }
        
        Process[current] = 1 + max_no;
        current++;
        choosing = false;

        // Waiting for other processes to complete
        for (int k = 0; k < Total_Processes; k++) 
        {
            while (k != current && Process[k] != 0 && (Process[k] < Process[current] || (Process[k] == Process[current] && k < current))) 
            {
                // If true Wait........
            }
        }
        
        // Critical Section
        printf("Process %d is in critical section.\n", current);
        // Perform critical section operation
        
        Process[current] = 0;
    } while (current < Total_Processes);
    
    return 0;
}
