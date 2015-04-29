#ifndef BRIDGEINTERFACE_H
#define BRIDGEINTERFACE_H

#include "ColorPanel.h"
#include "BridgeModel.h"

#include <LumiverseCore.h>
#include <LumiverseShowControl/LumiverseShowControl.h>

using namespace Lumiverse;
using namespace Lumiverse::ShowControl;


/*
 * Written by Bryce Summers on 4/5/2015.
 *
 * Purpose : The Bridge Interface should contain the methods that allow our looping system to
 *           1. Communicate information to the bridge system and
 *           2. allow the sensors to communicate information to our looping system.
 */

class BridgeInterface
{
    public:

        typedef int Sensor_ID;

        // The initial sensor on the left.
        const static Sensor_ID LEFT_1 = 0;

        // The secondary sensor on the left.
        const static Sensor_ID LEFT_2 = 1;

        // THe initial sensor on the right.
        const static Sensor_ID RIGHT_1 = 2;

        // The secondary sensor on the right.
        const static Sensor_ID RIGHT_2 = 3;

        const static Sensor_ID NO_TRIGGER = -1;

        // Constructors.
        BridgeInterface(Rig * rig);
        virtual ~BridgeInterface();

        // Updates the bridge with the current state of colors.
        // We will need to specify the format for representing the every panel's colors.
        void sendCurrentState(ColorPanel * panel_array, int size);

        // This method should be used to query whether a sensor has been triggered since the last call to this method.
        // ENSURES : Returns the time the latest trigger occurred.
        //           Returns NO_TRIGGER if the sensor has not been triggered since the last time this function was called.
        int poll_sensor_trigger(const Sensor_ID id);

    protected:

    private:

	// This is the object that allows us to talk to Lumiverse.
	Rig* rig;


};

#endif // BRIDGEINTERFACE_H
