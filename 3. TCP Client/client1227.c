#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT (10000 + 227)   // Must match the server's port
#define BUF_SIZE 1024

int main()
{
    int sock;
    struct sockaddr_in server;
    char buffer[BUF_SIZE];
    int num1, num2;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // Replace with the server PC's IP address
    server.sin_addr.s_addr = inet_addr("10.17.60.51");

    connect(sock, (struct sockaddr *)&server, sizeof(server));

    while (1)
    {
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);

        sprintf(buffer, "%d %d", num1, num2);

        send(sock, buffer, strlen(buffer), 0);

        memset(buffer, 0, BUF_SIZE);

        read(sock, buffer, BUF_SIZE);

        printf("Server Response: %s\n", buffer);
    }

    close(sock);

    return 0;
}
