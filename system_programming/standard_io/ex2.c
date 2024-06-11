#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *rfp, *wfp;
    char buf[BUFSIZ];
    printf("BUFSIZ = %d\n", BUFSIZ);

    if ((rfp = fopen("hello.txt", "r")) == NULL) {
        perror("fopen: hello.txt");
        exit(1);
    }

    if ((wfp = fopen("hello.out", "a")) == NULL) {
        perror("fopen: hello.out");
        exit(1);
    }

    while (fgets(buf, BUFSIZ, rfp) != NULL) {
        fputs(buf, wfp);
    }

    fclose(rfp);
    fclose(wfp);

    return 0;

}