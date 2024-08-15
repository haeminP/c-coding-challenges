#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    
    char buf1[100] = "Great!\n";
    char buf2[100];

    int sd2;
    socklen_t len;
    struct sockaddr_in addr1;

    sd2 = socket(AF_INET, SOCK_STREAM, 0);
    addr1.sin_family = AF_INET;
    addr1.sin_addr.s_addr = inet_addr(argv[1]);
    addr1.sin_port = 55558;
    connect(sd2, (struct sockaddr*)&addr1,sizeof(addr1));
    write(sd2, buf1, strlen(buf1)+1);
    read(sd2, buf2, 20);
    printf("Message from server: %s\n", buf2);
}