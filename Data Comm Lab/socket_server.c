#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#endif

int main(int x, char *argv[])
{
    char buf[100];
    int c_check, s_check;
    struct sockaddr_in client, server;

    s_check = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(argv[1]));

    bind(s_check, (struct sockaddr *)&server, sizeof(server));

    listen(s_check, 1);

    int size = sizeof(client);
    c_check = accept(s_check, (struct sockaddr *)&client, &size);

    do
    {
        memset(buf, '\0', 100);
        printf("\n enter the data: ");
        fflush(stdin);
        scanf("%s", buf);
        send(c_check, buf, 100, 0);
        printf("\n client IP address is: %s", inet_ntoa(client.sin_addr));
        recv(c_check, buf, 100, 0);
        printf("recieved message is: %s", buf);
    } while (strcmp(buf, "bye") != 0);

    close(c_check);
    close(s_check);

    return (0);
}
