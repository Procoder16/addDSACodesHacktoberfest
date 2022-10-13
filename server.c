//Using TCP socket client should send an unsorted array containg elements(30,10,50,8,9,20) to server. Server will sort this and send back to client.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

int main()
{
    int sockfd, fd1, i;
    char buf[100];
    struct sockaddr_in sa, tal, length;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = INADDR_ANY;
    sa.sin_port = 60018;

    i = bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));
    printf("test%d%d\n", sockfd, i);

    listen(sockfd, 5);

    length = sizeof(sa);
    // fd1 = accept(sockfd, (struct sockaddr *)&tal, &length);
    fd1 = accept(sockfd, (struct sockaddr *)&tal, sizeof(sa));

    for (int i = 0; i < 100; i++)
    {
        buf[i] = '\0';
        strcpy(buf, "Message from server");
        send(fd1, buf, 100, 0);
    }

    for (i = 0; i < 100; i++)
    {
        recv(fd1, buf, 100, 0);
        printf("%s\n", buf);
    }
    close(fd1);
    return 0;
}