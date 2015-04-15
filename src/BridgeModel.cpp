#include "BridgeModel.h"


BridgeModel::BridgeModel()
{
    int len = pausch.length();
    for(i = 0; i < len; i++)
    {
        pausch[i] = new ColorPanel();
    }
}

void BridgeModel::update (int timestep){
  //map over travelors updating postions
  for(std::vector<TravelingColor>::iterator it = travelors.begin();
      it != travelors.end(); ++it) {
    it.update(timestep);
  }

  //Update the Bridge Model
  BridgeModel::fadeBridge();
  BridgeModel::displayTravelors();
  BridgeModel::displayLinks();
  BridgeModel::baseTwinkle();
}

void BridgeModel::addTravelingColor(TravelingColor t_color)
{
  this.travelors.push_back(t_color);
}

bridge BridgeModel::getBridge ()
{
  return pausch;
}

//Reduce the colors on the bridge before update
// Currently zero out the bridge, but could leave residual trails here
void BridgeModel::fadeBridge ()
{
  for( int i = 0; i < NUM_PANELS; i++)
  {
    pausch[i].setTop (0,0,0);
    pausch[i].setBot (0,0,0);
  }
}//end fadeBridge

void BridgeModel::displayTravelers ()
{
   for(std::vector<TravelingColor>::iterator it = travelors.begin();
       it != travelors.end(); ++it) {
     pausch[it.getPanel()].setTop(it.getColor());
     pausch[it.getPanel()].setBot(it.getColor());
  }
}//end displayTravlers

//Determines behavior of panels when interacting with link color c
void link(int pos, Color c)
{
  pausch[pos].setTop(c);
}

void BridgeModel::displayLinks()
{
   for(std::vector<TravelingColor>::iterator sender = travelors.begin();
       sender != travelors.end(); ++sender)
   {
     for(std::vector<TravelingColor>::iterator recieve = sender;
	 recieve != travelors.end(); ++recieve)
     {
       if (sender.getColor() == recieve.getColor())
       {
	 int minPos = min(sender.getPanel(), recieve.getPanel());
	 int maxPos = max(sender.getPanel(), recieve.getPanel());
	 for (int j = minPos; j <= maxPos; j++)
	 {
	   link(j, sender.getColor());
	 }
       }
     }//end recieve loop
   }//end send loop
}//end displayLinks

//Add shimmer effect to empty panels
void baseTwinkle ()
{

}
