#define OFFLINE

#include "BridgeInterface.h"

BridgeInterface::BridgeInterface(Rig * rig)
{

  // Very important
  this -> rig = rig;

  cout << "BridgeInterface Constructor." << endl;

    #ifndef OFFLINE

      // First set to green.
      rig->getAllDevices().setRGBRaw(0, 1, 0);

      // Then set each individual panel to red.
      for(int i = 0; i < 20; i++)
      {
	rig->select("$panel=" + std::to_string(i)).setRGBRaw(1, 0, 0);
      }
    #endif
}//end bridge interface constructor

BridgeInterface::~BridgeInterface()
{
#ifndef OFFLINE
  delete rig;
#endif
}

// Updates the bridge with the current state of colors.
// We will need to specify the format for representing the every panel's colors.
void BridgeInterface::sendCurrentState(ColorPanel * panel_array, int size)
{

  // 1 - 57 inclusive
  for(int i = 1; i <= size; i++)
    {
       ColorPanel panel = panel_array[i - 1];

       Color c = panel.getColor();

       float r = c.red;
       float g = c.green;
       float b = c.blue;

       // THIS SHOULD WORK !!!!!!!



       #ifndef OFFLINE
       Rig * temp_rig = rig;
       temp_rig->select("$panel=" + std::to_string(i)).setRGBRaw(r/255.0, g/255.0, b/255.0);
       #endif
       cout << c.colorString("_");
    }

    // The endline that signals the end of drawing the bridge.
    cout << "\n";
    #ifndef OFFLINE
    rig -> updateOnce();
    // cout << "Updated Rig. \n";
    // cout << "Rig Pointer Value : " << &rig << endl;
    #endif
    //    cout << "Sending Blue to All \n";
    //    rig -> getAllDevices().setRGBRaw(1, 0, 0);


}

// This method should be used to query whether a sensor has been triggered since the last call to this method.
// ENSURES : Returns the time the latest trigger occurred.
//           Returns NO_TRIGGER if the sensor has not been triggered since the last time this function was called.
int BridgeInterface::poll_sensor_trigger(const Sensor_ID id)
{

    // FIXME Interface with Bailiang!

}
