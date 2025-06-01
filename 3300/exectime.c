#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
int
main(int argc, char *argv[])
{
    int pid, start_time, end_time;
    int status;
    
    // Check if at least one command is provided
    if(argc < 2) {
        printf("Usage: exectime <command> [args...]\n");
        exit(1);
    }
    
    // Get start time
    start_time = uptime();
    printf("Start time: %d ticks\n", start_time);
    
    // Fork a child process
    pid = fork();
    
    if(pid < 0) {
        printf("exectime: fork failed\n");
        exit(1);
    }
    else if(pid == 0) {
        // Child process: execute the command
        // argv[1] is the command, argv+1 points to command and its arguments
        exec(argv[1], argv + 1);
        
        // If exec returns, it means it failed
        printf("exectime: exec %s failed\n", argv[1]);
        exit(1);
    }
    else {
        // Parent process: wait for child to complete
        wait(&status);
        
        // Get end time
        end_time = uptime();
        printf("Completion time: %d ticks\n", end_time);
        printf("Elapsed time: %d ticks\n", end_time - start_time);
    }
    
    exit(0);
}
