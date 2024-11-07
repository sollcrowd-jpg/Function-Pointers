#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "util.h"

#define DEBUG 0  // Change to 1 for verbose output

typedef int (*Comparer)(const void *a, const void *b);

/**
 * Compares two processes based on priority, and if priorities are the same, then by arrival time.
 */
int my_comparer(const void *this, const void *that) {
    Process *p1 = (Process *)this;
    Process *p2 = (Process *)that;

    // First compare by priority
    if (p1->priority != p2->priority) {
        return p2->priority - p1->priority; // Higher priority comes first
    }
    
    // If priorities are the same, compare by arrival time
    return p1->arrival_time - p2->arrival_time;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./func-ptr <input-file-path>\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Error: Invalid filepath\n");
        return 1;
    }

    Process *processes = parse_file(input_file);
    fclose(input_file);

    Comparer process_comparer = &my_comparer;
    qsort(processes, P_SIZE, sizeof(Process), process_comparer);

    for (int i = 0; i < P_SIZE; i++) {
        printf("%d (%d, %d)\n", processes[i].pid, processes[i].priority, processes[i].arrival_time);
    }

    free(processes);
    return 0;
}
