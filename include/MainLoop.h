#ifndef MAINLOOP_H
#define MAINLOOP_H

#include "BridgeInterface.h"
#include <vector>
#include "TravelingColor.h"


// For The Timer Implementation.
#include<sys/time.h>
#include<stdio.h>


/*
 * Written by Bryce Summers on 4/5/2015.
 *
 * Purpose : This class is used to drive a regular update loop on the bridge that manages the procedural animation of the colored bridge lights.
 *
 * this class contains the logic for each of the three modes.
 */
class MainLoop
{

    public:

        // FIXME : Move this to a Global constants class.
        const int SIZE = 57;

        const int LEFT = 0;
        const int RIGHT = SIZE - 1;

        // Should not be equal to 0.
        float dist_left;
        float dist_right;

        int num_people = 0;

        // -- Methods.

        MainLoop();
        virtual ~MainLoop();

        // Every step of the loop, we should call update();
        void update();

        BridgeInterface bridge;
	BridgeModel bridge_model;

        // REQUIRES : location should equal LEFT or RIGHT.
        void addTravelingColor(int location, float velocity);


	// Call this function to start the looping.
	// Non blocking, returns after spawning a pthread.
	void loop();

    protected:

        void pollSensors();

        void updateLights();

        void sendDataToBridge();

        // Stores the latest times that any of the sensors have been hit.
        int latest_times[4];

    private:

	int SetTimer(struct timeval &tv, int usec);
	int CheckTimer(struct timeval &tv, int usec);


        // This will store the 4 standard colors that we will be using.
        const static int NUM_COLORS = 4;

        Color standard_colors[NUM_COLORS];

        int current_color = 0;

        typedef int Mode;

        const Mode SINGULAR = 0;
        const Mode CONNECTIONS = 1;
        const Mode WORLD_OF_COLOR = 2;

        // transition to the connections mode if the number of people is >= this value.
        const int CONNECTIONS_THRESHOLD   = 6;
        const int WORLD_OF_COLOR_THRESHOLD = 11;

        Mode current_mode = SINGULAR;
};
#endif // MAINLOOP_H
