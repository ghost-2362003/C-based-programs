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

int main(int argc, char *argv[])
{
    char buf[100];
    int s_check, c_check;
    struct sockaddr_in client, server;

#ifdef _WIN32
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
#endif

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    s_check = socket(AF_INET, SOCK_STREAM, 0);
    if (s_check < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(argv[1]));

    if (bind(s_check, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    listen(s_check, 1);

    socklen_t size = sizeof(client);
    c_check = accept(s_check, (struct sockaddr *)&client, &size);
    if (c_check < 0)
    {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    do
    {
        memset(buf, 0, sizeof(buf));
        printf("\nEnter the data: ");
        fgets(buf, sizeof(buf), stdin);
        buf[strcspn(buf, "\n")] = 0;

        if (send(c_check, buf, strlen(buf), 0) < 0)
        {
            perror("Send failed");
            break;
        }

        printf("Client IP address: %s\n", inet_ntoa(client.sin_addr));

        memset(buf, 0, sizeof(buf));
        if (recv(c_check, buf, sizeof(buf), 0) < 0)
        {
            perror("Receive failed");
            break;
        }

        printf("Received message: %s\n", buf);

    } while (strcmp(buf, "bye") != 0);

#ifdef _WIN32
    closesocket(c_check);
    closesocket(s_check);
    WSACleanup();
#else
    close(c_check);
    close(s_check);
#endif

    return 0;
}
