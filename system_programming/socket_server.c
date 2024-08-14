#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    
    char buf1[100] = "You are connected!\n";
    char buf2[100];

    int sd1, sd3;
    socklen_t len;
    struct sockaddr_in addr1, addr2;

    sd1 = socket(AF_INET, SOCK_STREAM, 0);
    addr1.sin_family = AF_INET;
    addr1.sin_addr.s_addr = INADDR_ANY;
    addr1.sin_port = 55558;
    bind(sd1, (struct sockaddr*)&addr1,sizeof(addr1));
    listen(sd1, 5);
    while (1) {
        printf("Waiting for connection.....\n");
        len = sizeof(addr2);
        sd3 = accept(sd1, (struct sockaddr*)&addr2, &len);
        printf("Got connection from port number: %d\n", addr2.sin_port);
        write(sd3, buf1, strlen(buf1) + 1);
        read(sd3, buf2, 20);
        printf("Message from client: %s\n", buf2);
        close(sd3);
    }
}