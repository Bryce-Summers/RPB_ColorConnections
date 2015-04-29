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

#include "include/MainLoop.h"

#include <thread>

using namespace Lumiverse;
using namespace Lumiverse::ShowControl;

void looper(MainLoop * loop, int usecond_sleep_delay)
{
    while(true)
    {
      cout << "Update Step.\n";
      loop->update();
      cout << "Sleeping\n";

      usleep(usecond_sleep_delay);
      //sleep(1);
    }
}

void simple_test()
{
  Rig * rig = new Rig("/home/teacher/Lumiverse/PBridge.rig.json");
  rig -> init();
  rig->getAllDevices().setRGBRaw(0, 1, 0);

  
  rig->select("$panel=0").setRGBRaw(1, 0, 0);
  rig->select("$panel=1").setRGBRaw(1, 0, 0);
  rig->select("$panel=2").setRGBRaw(1, 0, 0);
  rig->select("$panel=3").setRGBRaw(1, 0, 0);
  rig->select("$panel=4").setRGBRaw(1, 0, 0);
  rig->select("$panel=5").setRGBRaw(1, 0, 0);
  rig->select("$panel=6").setRGBRaw(1, 0, 0);
  rig->select("$panel=7").setRGBRaw(1, 0, 0);
  rig->select("$panel=8").setRGBRaw(1, 0, 0);
  rig->select("$panel=9").setRGBRaw(1, 0, 0);
  rig->select("$panel=10").setRGBRaw(1, 0, 0);


  rig->select("$panel=50").setRGBRaw(1, 0, 0);
  rig->select("$panel=49").setRGBRaw(1, 0, 0);
  rig->select("$panel=48").setRGBRaw(1, 0, 0);
  rig->select("$panel=47").setRGBRaw(1, 0, 0);



  rig->select("$panel=20").setRGBRaw(1, 0, 0);
  rig->select("$panel=30").setRGBRaw(1, 0, 0);
  rig->select("$panel=40").setRGBRaw(1, 0, 0);


  
  for(int i = 0; i < 57; i++)
  {
    string str = "$panel=" + std::to_string(i);
    rig->select(str).setRGBRaw(1, 0, 0);
  }
  

  rig->updateOnce();

}

//#define TEST

int main()
{



#ifdef TEST
    simple_test();
    return 0;
#endif

    // -- Non test code does not run in test.

    
    Rig * rig = new Rig("/home/teacher/Lumiverse/PBridge.rig.json");
    rig -> init();
    rig->getAllDevices().setRGBRaw(0, 1, 0);
    
    int milliseconds = 1000;// 10 frames per second.
    unsigned int microseconds = milliseconds*1000;

    // Create a start the Main Loop.
    MainLoop loop = MainLoop(rig);
    std::thread worker(looper, &loop, microseconds);
    loop.addTravelingColor(1, 1.0);
    loop.addTravelingColor(57,-1.0);
    sleep(10);
    loop.addTravelingColor(1, 1.0);
    sleep(5);
    loop.addTravelingColor(57, -1.0);
    //    sleep(10);
    //loop.addTravelingColor(0, 1.0);

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

        // Accept input strings of size 1 and 9 respectively
        char s_buf[2];
        recv(sessfd, s_buf, 1, 0);
        s_buf[5] = '\0';// Make a proper string by adding a new line character.
	
	char v_buf[10] = {};
	recv(sessfd, v_buf, 9, 0);
	v_buf[9] = '\0';

	// turn received message into server number and velocity
	int sensor = s_buf[0] - 48;
	float velocity = atof(v_buf); 

	printf("sensor = %d\n", sensor);
	printf("velocity = %f\n", velocity);

	loop.addTravelingColor(sensor, velocity);
    }
}
