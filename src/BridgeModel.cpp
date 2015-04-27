#include "BridgeModel.h"



BridgeModel::BridgeModel()
{
    int len = NUM_PANELS;
    for(int i = 0; i < len; i++)
    {
        pausch[i] = ColorPanel();

	if(i % 2 == 0)
	{
	  pausch[i].setColor(0, 0, 0);
	}
	else
	{
	  pausch[i].setColor(0, 0, 0);
	}
    }
}

void BridgeModel::update (float timestep){
  //map over travelors updating postions
  time += 1;
  cout << "Bridge Model : Model Updating \n";

  int len = travelers.size();

  for(int i = len-1 ; i >= 0; i--)
  {
    if (travelers[i].getPanel() >=0 || 
	travelers[i].getPanel() <= NUM_PANELS)
    {
	travelers[i].update(timestep);
    }
    else
    {
      travelers.erase(travelers.end()-i);
    }
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
    Color c = pausch[i].getColor();
    pausch[i].setColor(c.scale(.5));

  }
}//end fadeBridge

void BridgeModel::displayTravelers ()
{
   for(std::vector<TravelingColor>::iterator it = travelers.begin();
       it != travelers.end(); ++it) {
     int tgt = it -> getPanel();
     int src = it -> getOldPanel();
     for (int i = min(src,tgt); i <= max(src,tgt); i ++){
       double sf = 0.5/ (double)(tgt - src) * (tgt - i) + 1.0;
       pausch[i].setColor(it->getColor().scale(sf));
     }
  }
}//end displayTravlers

//Determines behavior of panels when interacting with link color c
void BridgeModel::link(int pos, Color c)
{
  pausch[pos].setColor(c);
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
  for( int i = 0; i < NUM_PANELS; i++)
  {
    double intensity = (double)((i + time) % MAXTIME) / (double)MAXTIME * 255;
    pausch[i].setColor(intensity/4.0, intensity/4.0, intensity/4.0);
  }
}
