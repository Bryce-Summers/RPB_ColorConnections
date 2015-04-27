//#define OFFLINE

#include "BridgeInterface.h"

BridgeInterface::BridgeInterface()
{
    #ifndef OFFLINE
      rig = new Rig("/home/teacher/Lumiverse/PBridge.rig.json");

      rig -> init();
      //rig -> run();

      rig->getAllDevices().setRGBRaw(0, 1, 0);

      for(int i = 0; i < 20; i++)
      {
        rig->select("$panel=" + i).setRGBRaw(1, 0, 0);
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
    // FIXME : Use Lumiverse.
    for(int i = 1; i < size; i++)
    {
       ColorPanel panel = panel_array[i];

       Color c = panel.getColor();

       float r = c.red;
       float g = c.green;
       float b = c.blue;

       // THIS SHOULD WORK !!!!!!!

       //rig->select("$panel=" + i).setRGBRaw(r/255.0, g/255.0, b/255.0);
       #ifndef OFFLINE
       rig->select("$panel=" + i).setRGBRaw(1, 0, 0);
       #endif
       cout << c.colorString("_");
    }
    cout << "\n";
    #ifndef OFFLINE
    rig->updateOnce();
    cout << "Updated Rig. \n";
    #endif
    //    cout << "Sending Blue to All \n";
    //    rig -> getAllDevices().setRGBRaw(1, 0, 0);
    //rig->getAllDevices().setRGBRaw(0, 0, 1);
    //    rig->update();


}

// This method should be used to query whether a sensor has been triggered since the last call to this method.
// ENSURES : Returns the time the latest trigger occurred.
//           Returns NO_TRIGGER if the sensor has not been triggered since the last time this function was called.
int BridgeInterface::poll_sensor_trigger(const Sensor_ID id)
{

    // FIXME Interface with Bailiang!

}
