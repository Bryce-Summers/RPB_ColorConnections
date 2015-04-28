#include "MainLoop.h"

MainLoop::MainLoop()
{

    /* FIXME :
     *
     * 1. We need to setup a regular event loop that updates the state of
     *    the bridge and communicates it to the bridge.
     *
     * 2. Initialize the logic for handling the sensors.
     *
     *
     * User is responsible for implementing a looping and timing policy.
     *
     */
    //ctor


  // Important initializations.
  bridge = BridgeInterface();
  bridge_model = BridgeModel();

  standard_colors[0] = Color(255, 0, 0);
  standard_colors[1] = Color(0, 255, 0);
  standard_colors[2] = Color(0, 0, 255);
  standard_colors[3] = Color(255, 255, 0);

}

MainLoop::~MainLoop()
{
    //dtor
}


// -- Normal Looping Code.

void MainLoop::update()
{
    //   pollSensors();

    cout << "Update Lights \n";
    updateLights();

    cout << "Send Data to Bridge\n";

    // FIXME : This is not real code.
    sendDataToBridge();

    cout << "Done with Update.\n";

}


// Polls the sensors and creates a traveling color if necessary.
void MainLoop::pollSensors()
{
    int left_end = bridge.poll_sensor_trigger(BridgeInterface::LEFT_2);

    if(left_end != BridgeInterface::NO_TRIGGER)
    {
        latest_times[BridgeInterface::LEFT_2] = left_end;

        // If LEFT_1 has a fresh trigger, then call addTravellingColor(), then set the latest_times back to NO_TRIGGER.

        if(latest_times[BridgeInterface::LEFT_1] != BridgeInterface::NO_TRIGGER)
        {
            float velocity = (latest_times[BridgeInterface::LEFT_2] - latest_times[BridgeInterface::LEFT_1])/dist_left;
            addTravelingColor(LEFT, velocity);

            // Reset the trigger time arrays.
            latest_times[BridgeInterface::LEFT_1] = BridgeInterface::NO_TRIGGER;
            latest_times[BridgeInterface::LEFT_2] = BridgeInterface::NO_TRIGGER;
        }

    }

    // Do the same for the RIGHT_2 trigger.

    int right_end = bridge.poll_sensor_trigger(BridgeInterface::RIGHT_2);

    if(right_end != BridgeInterface::NO_TRIGGER)
    {
        latest_times[BridgeInterface::RIGHT_2] = right_end;

        // If LEFT_1 has a fresh trigger, then call addTravellingColor(), then set the latest_times back to NO_TRIGGER.

        if(latest_times[BridgeInterface::RIGHT_1] != BridgeInterface::NO_TRIGGER)
        {
            float velocity = (latest_times[BridgeInterface::RIGHT_2] - latest_times[BridgeInterface::RIGHT_1])/dist_right;
            velocity *= -1; // Colors starting of the right need to go left!
            addTravelingColor(RIGHT, velocity);

            // Reset the trigger time arrays.
            latest_times[BridgeInterface::RIGHT_1] = BridgeInterface::NO_TRIGGER;
            latest_times[BridgeInterface::RIGHT_2] = BridgeInterface::NO_TRIGGER;
        }
    }


    // Now update the LEFt_1 and RIGHT_1 triggers if they are empty and can accept new triggers.

    if(latest_times[BridgeInterface::LEFT_1] == BridgeInterface::NO_TRIGGER)
    {
        int left_start = bridge.poll_sensor_trigger(BridgeInterface::LEFT_1);
        latest_times[BridgeInterface::LEFT_1] = left_start;
    }

    if(latest_times[BridgeInterface::RIGHT_1] == BridgeInterface::NO_TRIGGER)
    {
        int left_start = bridge.poll_sensor_trigger(BridgeInterface::RIGHT_1);
        latest_times[BridgeInterface::RIGHT_1] = left_start;
    }

}

// Signals the main loop that a new traveling color should be added to the bridge with at the given location and velocity.
void MainLoop::addTravelingColor(int location, float velocity)
{


    Color c = standard_colors[current_color];

    current_color = (current_color + 1) % NUM_COLORS;

    TravelingColor t_color = TravelingColor(c, velocity, location);

    bridge_model.addTravelingColor(t_color);


    num_people++;

    cout << "Added Traveler "<< num_people << " with Color" 
	 << c.red << "," << c.green << "," << c.blue << "\n";

    if(num_people > CONNECTIONS_THRESHOLD)
    {
        current_mode = CONNECTIONS;
    }

    if(num_people > WORLD_OF_COLOR_THRESHOLD)
    {
        current_mode = WORLD_OF_COLOR;
    }
};

// FIXME.
void MainLoop::sendDataToBridge()
{
    // FIXME : We need to construct these.
    ColorPanel * panel = bridge_model.getBridge();
    int size = bridge_model.NUM_PANELS;

    bridge.sendCurrentState(panel, size);
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

