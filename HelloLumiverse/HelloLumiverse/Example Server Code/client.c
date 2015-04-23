#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <netinet/tcp.h>
#include <dlfcn.h>
#include <assert.h>


void main(void) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in srv;
    memset(&srv, 0, sizeof(srv));	       // clear it first
    srv.sin_family = AF_INET;		       // IP family
    srv.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP address of server
    srv.sin_port = htons(15440);		       // server port
    int rv = connect(sockfd, (struct sockaddr*)&srv, sizeof(struct sockaddr));
    assert(rv >= 0);
    int flag = 1;
    setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, (char*)&flag, sizeof(int));

    while (1) {
        printf("sending?\n");
        send(sockfd, "hello", 5, 0);
        printf("sent?\n");
        sleep(1);
    }
}
