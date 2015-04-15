#include "BridgeInterface.h"

BridgeInterface::BridgeInterface()
{
    //ctor
}

BridgeInterface::~BridgeInterface()
{
    //dtor
}

// Updates the bridge with the current state of colors.
// We will need to specify the format for representing the every panel's colors.
void BridgeInterface::sendCurrentState(ColorPanel * panel_array, int size)
{

    // FIXME : Use Lumiverse.
}

// This method should be used to query whether a sensor has been triggered since the last call to this method.
// ENSURES : Returns the time the latest trigger occurred.
//           Returns NO_TRIGGER if the sensor has not been triggered since the last time this function was called.
int BridgeInterface::poll_sensor_trigger(const Sensor_ID id)
{

    // FIXME Interface with Bailiang!

}
