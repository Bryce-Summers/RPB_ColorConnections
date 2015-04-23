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

#include <LumiverseCore.h>
#include <LumiverseShowControl/LumiverseShowControl.h>

using namespace Lumiverse;
using namespace Lumiverse::ShowControl;

void toggleLights(Rig* rig, int mode)
{
    for(int i = 1; i < 57; i++)
    {
        rig->select("$panel=" + i).setRGBRaw(mode, mode, mode);
    }

}

int main()
{

    Rig* rig = new Rig("/home/teacher/Lumiverse/PBridge.rig.json");

    rig -> init();
    rig -> run();

    //rig->getDevice("CG4_9")->setRGBRaw(0,1,0);
    rig->getAllDevices().setRGBRaw(0, 1, 0);

    // On.
    int mode = 1;
    int panel_number = 1;

    /*
    while(true)
    {
      sleep(1);
      mode = mode ^ 1;
      rig->getAllDevices().setRGBRaw(mode ^ 1, mode, 0);
    }
    */

    // -- Server
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
        socklen_t sa_size = sizeof(struct sockaddr_in);
        int sessfd = accept(sockfd, (struct sockaddr *)&cli, &sa_size);

        // Accept input strings of size up to 5;
        char buf[6];

        recv(sessfd, buf, 5, 0);
        buf[5] = '\0';// Make a proper string by adding a new line character.

	sleep(1);
        mode = mode ^ 1;

        // Toggle the Bridge.
	rig->getAllDevices().setRGBRaw(mode ^ 1, mode, 0);
        rig->select("$panel=" + panel_number).setRGBRaw(0, 0, 1);
	panel_number = (panel_number + 1) % 57;
        //toggleLights(rig, mode);

	// printf("Toggle");

        // Print out the message in the bridge's console.
        printf("buf = %s\n", buf);
        
    }


}
