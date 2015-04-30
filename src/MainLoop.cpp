#include "MainLoop.h"

MainLoop::MainLoop(Rig * rig)
{
    /*
     * User is responsible for implementing a looping and timing policy.
     *
     */
    //ctor


  // Important initializations.
  bridge_model = BridgeModel();
  bridge = new BridgeInterface(rig);
  player = BridgePlayer();

  standard_colors[0] = Color(255, 0, 0);
  standard_colors[1] = Color(0, 255, 0);
  standard_colors[2] = Color(0, 0, 255);
  standard_colors[3] = Color(255, 255, 0);

}

MainLoop::~MainLoop()
{
    //dtor
  delete bridge;
}


// -- Normal Looping Code.

void MainLoop::update()
{
    //   pollSensors();

    if(current_mode == WORLD_OF_COLOR)
    {  
      world_of_color();
      sendDataToBridge();
      return;
    }  

    num_people = bridge_model.getNumTravelers();

    if(num_people >= WORLD_OF_COLOR_THRESHOLD)
    {

       current_mode = WORLD_OF_COLOR;
       woc_index = 0;
       num_people = 0;
       bridge_model.removeAllTravelers();
       return;
    }


    //    cout << "Update Lights \n";
    updateLights();

    //    cout << "Send Data to Bridge\n";

    sendDataToBridge();

    //    cout << "Done with Update.\n";

}

void MainLoop :: world_of_color()
{

  int max_index = player.getShowSize() - 1;

  // Show has ended.
  if(woc_index > max_index)
  {
    current_mode = SINGULAR;
    woc_index = 0;
    return;
  }
  // Display a frame.

  ColorPanel * bridge_frame = player.getFrame(woc_index);
  bridge_model.setBridge(bridge_frame);
  // Increment frame counter.
  woc_index++;
   
}


// Signals the main loop that a new traveling color should be added to the bridge with at the given location and velocity.
void MainLoop::addTravelingColor(int location, float velocity)
{

  // Do not allow people to be added
  if(current_mode == WORLD_OF_COLOR || abs(velocity) < .4)
  {
    return;
  }


    Color c = standard_colors[current_color];

    current_color = (current_color + 1) % NUM_COLORS;

    TravelingColor* t_color = new TravelingColor(c, velocity, location);

    bridge_model.addTravelingColor(t_color);
    num_people = bridge_model.getNumTravelers();
#ifdef DEBUG
    cout << "Added Traveler number "<< num_people << " with Color " 
	 << c.red << "," << c.green << "," << c.blue 
	 << " with velocity " << velocity
	 << " and position " << location << "\n";
#endif
};

void MainLoop::sendDataToBridge()
{
    ColorPanel * panel = bridge_model.getBridge();
    int size = bridge_model.NUM_PANELS;
    bridge -> sendCurrentState(panel, size);
}


void MainLoop::updateLights()
{
  bridge_model.update(1);
  
}

