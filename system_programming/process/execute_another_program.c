#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[], char* envp[]) {

    char* arr[] = {
        "ping",
        "google.com",
        NULL
    };

    char* env[] = {
        "TEST=environment variable",
        NULL
    };

    execvpe("ping", arr, env);

    return 0;
}