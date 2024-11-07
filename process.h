#ifndef PROCESS_H
#define PROCESS_H

#define P_SIZE 7  // Example size, adjust as needed

typedef struct Process {
    int pid;         // Process ID
    int priority;    // Process priority
    int arrival_time; // Arrival time
} Process;

#endif // PROCESS_H
