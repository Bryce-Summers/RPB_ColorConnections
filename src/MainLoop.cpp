#include "MainLoop.h"

MainLoop::MainLoop(Rig * rig)
{
    /*
     * User is responsible for implementing a looping and timing policy.
     *
     */
    //ctor


  // Important initializations.
  bridge = new BridgeInterface(rig);
  bridge_model = BridgeModel();
  player = BridgePlayer();
  player.readFile();

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
      return;
    }  

    
    int num_people = bridge_model.travelers.size();

    if(num_people >= WORLD_OF_COLOR_THRESHOLD)
    {

      cout << "Setting World of Color." << endl;
       current_mode = WORLD_OF_COLOR;
       woc_index = 0;
       num_people = 0;
       bridge_model.travelers.clear();
       return;
    }


    cout << "Update Lights \n";
    updateLights();

    cout << "Send Data to Bridge\n";

    // FIXME : This is not real code.
    sendDataToBridge();

    cout << "Done with Update.\n";

}

void MainLoop :: world_of_color()
{

  int max_index = player.bridgeData.size() - 1;

  // Show has ended.
  if(woc_index > max_index)
  {
    current_mode = SINGULAR;
    woc_index = 0;
    return;
  }

  // Display a frame.

  cout << "Sending WOC" << endl;

  ColorPanel * bridge_frame = player.bridgeData[woc_index];

  bridge -> sendCurrentState(bridge_frame, bridge_model.NUM_PANELS);


  // Increment frame counter.
  woc_index++;

}

// Polls the sensors and creates a traveling color if necessary.

// Signals the main loop that a new traveling color should be added to the bridge with at the given location and velocity.
void MainLoop::addTravelingColor(int location, float velocity)
{

  // Do not allow people to be a
  if(current_mode == WORLD_OF_COLOR || abs(velocity) < .4)
  {
    return;
  }


    Color c = standard_colors[current_color];

    current_color = (current_color + 1) % NUM_COLORS;

    TravelingColor t_color = TravelingColor(c, velocity, location);

    bridge_model.addTravelingColor(t_color);

    cout << "Added Traveler "<< num_people << " with Color" 
	 << c.red << "," << c.green << "," << c.blue << "\n";

};

// FIXME.
void MainLoop::sendDataToBridge()
{
    // FIXME : We need to construct these.
    ColorPanel * panel = bridge_model.getBridge();
    int size = bridge_model.NUM_PANELS;

    bridge -> sendCurrentState(panel, size);
}


void MainLoop::updateLights()
{

  bridge_model.update(1);


/* WORLD_OF_COLOR

For the World of Color Phase,
we need to set up some sort of queued event system
in order to specify a standard deterministic color.

 */

}

