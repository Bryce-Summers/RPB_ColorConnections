#include "BridgeModel.h"



BridgeModel::BridgeModel()
{
    int len = NUM_PANELS;
    for(int i = 0; i < len; i++)
    {
        pausch[i] = ColorPanel();

	if(i % 2 == 0)
	{
	  pausch[i].setColor(255, 0, 0);
	}
	else
	{
	  pausch[i].setColor(0, 255, 0);
	}
    }
}

void BridgeModel::update (float timestep){
  //map over travelors updating postions

  cout << "Bridge Model : Model Updating \n";

  int len = travelers.size();

  for(int i = 0; i < len; i++)
  {
    travelers[i].update(timestep);
  }

  //Update the Bridge Model
  fadeBridge();
  displayTravelers();
  displayLinks();
  baseTwinkle();
}

void BridgeModel::addTravelingColor(TravelingColor t_color)
{
  cout << "Add Traveling Color\n";
  travelers.push_back(t_color);
}

ColorPanel* BridgeModel::getBridge ()
{

  cout << "Bridge Model Exported.\n";

  return pausch;
}

//Reduce the colors on the bridge before update
// Currently zero out the bridge, but could leave residual trails here
void BridgeModel::fadeBridge ()
{
  for( int i = 0; i < NUM_PANELS; i++)
  {
    pausch[i].setTop (0,0,0);
    pausch[i].setBottom(0,0,0);
  }
}//end fadeBridge

void BridgeModel::displayTravelers ()
{
   for(std::vector<TravelingColor>::iterator it = travelers.begin();
       it != travelers.end(); ++it) {
     pausch[it->getPanel()].setTop(it->getColor());
     pausch[it->getPanel()].setBottom(it->getColor());
  }
}//end displayTravlers

//Determines behavior of panels when interacting with link color c
void BridgeModel::link(int pos, Color c)
{
  pausch[pos].setTop(c);
}

void BridgeModel::displayLinks()
{
   for(std::vector<TravelingColor>::iterator sender = travelers.begin();
       sender != travelers.end(); ++sender)
   {
     for(std::vector<TravelingColor>::iterator recieve = sender;
	 recieve != travelers.end(); ++recieve)
     {
       if (sender->getColor() == recieve->getColor())
       {
	 int minPos = std::min(sender->getPanel(), recieve->getPanel());
	 int maxPos = std::max(sender->getPanel(), recieve->getPanel());
	 for (int j = minPos; j <= maxPos; j++)
	 {
	   link(j, sender->getColor());
	 }
       }
     }//end recieve loop
   }//end send loop
}//end displayLinks

//Add shimmer effect to empty panels
void BridgeModel::baseTwinkle ()
{

}
