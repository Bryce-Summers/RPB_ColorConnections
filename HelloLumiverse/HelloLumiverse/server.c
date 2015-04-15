#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <err.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <sys/wait.h>
#include <pthread.h>
#include <netinet/tcp.h>
#include <assert.h>

void main(void) {
// server
    int port = 15440;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);   // TCP/IP socket
    struct sockaddr_in srv, cli;
    memset(&srv, 0, sizeof(srv));               // clear it first
    srv.sin_family = AF_INET;                   // IP family
    srv.sin_addr.s_addr = htonl(INADDR_ANY);    // don't care IP address
    srv.sin_port = htons(port);                 // server port
    int rv = bind(sockfd, (struct sockaddr*)&srv, sizeof(struct sockaddr));
    assert(rv >= 0);
    int flag = 1;
    setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, (char*)&flag, sizeof(int));

    rv = listen(sockfd, 5);
    assert(rv >= 0);
    while (true) {
        printf("accepting\n");
        int sa_size = sizeof(struct sockaddr_in);
        int sessfd = accept(sockfd, (struct sockaddr *)&cli, &sa_size);
        while (true) {
            char buf[6];
            recv(sessfd, buf, 5, 0);
            buf[5] = '\0';
            printf("buf = %s\n", buf);
        }
    }
}
