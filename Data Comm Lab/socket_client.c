#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(int x, char *argv[]){
    char buf[100];
    struct sockaddr_in client;
    int c_check;

    c_check = socket(AF_INET, SOCK_STREAM, 0);

    client.sin_family = AF_INET;
    client.sin_addr.s_addr = inet_addr(argv[1]);
    client.sin_port = htons(atoi(argv[2]));

    bind(c_check, (struct sockaddr *)&client, sizeof(client));

    do{
        recv(c_check, buf, 100, 0);
        printf("recieved data is: %s\n", buf);
        printf("\nenter the data: ");
        fflush(stdin);
        scanf("%s", buf);
        send(c_check, buf, 100, 0);
    }while(strcmp(buf, "bye") != 0);

    close(c_check);

    return(0);
}
