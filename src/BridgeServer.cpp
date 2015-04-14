//
// A simple Internet server application.
// It listens to the port written in command line (default 1234),
// accepts a connection, and sends the "Hello!\r\n" message
// to a client. Then it receives the answer from a client and terminates.
//
// Usage:
//      server [port_to_listen]
// Default is the port 1234.
//
// taken from: http://mech.math.msu.su/~vvb/Java/samples/Invert/server.cpp
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
/*
 * Server that exists on the bridge controls server, 
 * listens for inputs from an external server and 
 * processes it to change the colors 
 **/ 
using namespace std;

int changeColor(int sensor) {
    //TODO: COLOR LOGIC GOES HERE
    return 0;
}


int main(int argc, char *argv[]) {

    int listenPort = 1234; //TODO: change default port
    if (argc > 1)
        listenPort = atoi(argv[1]);

    // Create a socket
    int s0 = socket(AF_INET, SOCK_STREAM, 0);
    if (s0 < 0) {
        perror("Cannot create a socket"); exit(1);
    }

    // Fill in the address structure containing self address
    struct sockaddr_in myaddr;
    memset(&myaddr, 0, sizeof(struct sockaddr_in));
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(listenPort);        // Port to listen
    myaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind a socket to the address
    int res = bind(s0, (struct sockaddr*) &myaddr, sizeof(myaddr));
    if (res < 0) {
        perror("Cannot bind a socket"); exit(1);
    }

    // Set the "LINGER" timeout to zero, to close the listen socket
    // immediately at program termination.
    struct linger linger_opt = { 1, 0 }; // Linger active, timeout 0
    setsockopt(s0, SOL_SOCKET, SO_LINGER, &linger_opt, sizeof(linger_opt));

    // Now, listen for a connection
    // TODO: "1" is the maximal length of the queue
    while (listen(s0, 1) < 0) {
        // Accept a connection
        struct sockaddr_in peeraddr;
        socklen_t peeraddr_len;
        int s1 = accept(s0, (struct sockaddr*) &peeraddr, &peeraddr_len);
        if (s1 < 0) {
            perror("Cannot accept"); 
            exit(1);
        }

        //TODO: make buffer smaller?
        char buffer[1024];
        res = read(s1, buffer, 1023);
        if (res < 0) {
            perror("Read error"); exit(1);
        }

        //TODO: ALL THE BRIDE CODE
        changeColor(buffer[0] - '0');

        close(s1);          // Close the data socket
    }

    res = close(s0);    // Close the listen socket

    perror("Cannot listen"); 
    exit(1);
}
