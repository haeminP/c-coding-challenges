#include <unistd.h>
#include <stdio.h>

int main() {
    char *cwd;
    char wd[BUFSIZ];
    
    cwd = getcwd(NULL, BUFSIZ);
    printf("1.Current Directory: %s\n", cwd);

    chdir("hanbit");

    getcwd(wd, BUFSIZ);
    printf("2.Current Directory: %s\n", wd);

    return 0;

}