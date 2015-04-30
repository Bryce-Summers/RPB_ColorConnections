#include "BridgeModel.h"


BridgeModel::BridgeModel()
{
  travelers = (TravelingColor**)malloc(sizeof(TravelingColor*) * NUM_TRAVELERS);
  for (int i = 0; i < NUM_TRAVELERS; i++)
  {
    travelers[i] =  new TravelingColor();
  }

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
}//end initializer

void BridgeModel::update (float timestep){
  //map over travelors updating postions
  time = (time + 1) % MAXTIME;
  //  cout << "Bridge Model : Model Updating \n";

  //  std::lock_guard<std::mutex> lock(travel_mutex);

  for(int i = 0 ; i<  NUM_TRAVELERS; i++)
  {
    if(travelers[i])
    {
      travelers[i]->update(timestep);

      if(travelers[i]->getPanel() < 1 ||
	 travelers[i]->getPanel() > NUM_PANELS)
      {
	travelers[i]->active = false;
      }
    }//end null check
  }//end for


  //Update the Bridge Model
  fadeBridge();
  baseTwinkle();
  displayTravelers();
  displayLinks();

}

void BridgeModel::addTravelingColor(TravelingColor* t_color)
{
    for(int i = 0; i < NUM_TRAVELERS; i++)
  {
    if (travelers[i] && !travelers[i]->active)
    {
      travelers[i] =  t_color;
      break;
    }
  }
}

void BridgeModel::removeAllTravelers()
{
  //  cout << "Removing Travelers" << endl;
  for(int i = 0; i < NUM_TRAVELERS; i++)
  {
    if(travelers[i])
    {
      travelers[i]->active = false;    
    }
  }
  //  cout << "Removing Travelers done" << endl;
}

int BridgeModel::getNumTravelers()
{
  //  cout << "Counting Travelers" << endl;
  int count = 0;
  for(int i = 0; i < NUM_TRAVELERS; i++)
  {
    if(travelers[i] && travelers[i]->active)
    {
      count ++;
    }
  }
  return count;
}

ColorPanel* BridgeModel::getBridge ()
{
  //  cout << "Bridge Model Exported.\n";
  return pausch;
}

void BridgeModel::setBridge (ColorPanel * bridge)
{

  //  cout << "Bridge Model Set.\n";
  for (int i = 0; i< NUM_PANELS; i++)
  {
    pausch[i] = bridge[i];
  }
}

//Reduce the colors on the bridge before update
// Currently zero out the bridge, but could leave residual trails here
void BridgeModel::fadeBridge ()
{
  for( int i = 0; i < NUM_PANELS; i++)
  {
    Color c = pausch[i].getColor();
    int new_r = (int)(c.red / 51) - 1;
    new_r = max(new_r, 0) * 51;
    int new_g = (int)(c.green / 51) - 1;
    new_g = max(new_g, 0) * 51;
    int new_b = (int)(c.blue / 51) - 1;
    new_b = max(new_b, 0) * 51;


    pausch[i].setColor(new_r, new_g , new_b);
    //pausch[i].setColor(0,0,0);
  }
}//end fadeBridge

void BridgeModel::displayTravelers ()
{
  for(int it_id = 0; it_id < NUM_TRAVELERS; it_id++)
  {
    TravelingColor* it = travelers[it_id];
    if (it && it->active)
    {
      int tgt = it->getPanel();
      int src = it->getOldPanel();
      for (int i = min(src,tgt); i <= max(src,tgt); i ++){
	if (pausch[i].getColor().isGray()) {
	  pausch[i].setColor(it->getColor());
	}
	else{
	  Color c = it->getColor().add(pausch[i].getColor());
	  pausch[i].setColor(c);
	}
      }
    }// end null check
  }// end traveler loop
  //  cout << "Finished displaying travelers" << endl;
}//end displayTravlers

//Determines behavior of panels when interacting with link color c
// REQUIRES: left < pos < right
void BridgeModel::link(int pos, int left, int right, Color c)
{
  if(left != right)
  {
    /*    int dist = std::max(pos - left, right - pos);
    int maxDist = right - left;
    Color scaledC = c.scale((double)dist / (double)maxDist);
    Color scaledBridge = 
      pausch[pos].getColor().scale(1.0 - ((double)dist / (double)maxDist));
    pausch[pos].setColor(scaledC.add(scaledBridge));
    */
    if(pausch[pos].getColor().isGray())
    {
      int red = 0;
      int blue = 0;
      int green = 0;
      if(c.red > 0)
      {
	red = 51;
      }
      if(c.blue > 0)
      {
	blue = 51;
      }
      if(c.green > 0)
      {
	green = 51;
      }	
      pausch[pos].setColor(Color(red,blue,green));
    }
  }
}

void BridgeModel::displayLinks()
{
  for (int send_id = 0; send_id < NUM_TRAVELERS; send_id ++)
  {
    for(int rec_id = send_id + 1; rec_id < NUM_TRAVELERS; rec_id ++)
    {
      TravelingColor* sender = travelers[send_id];
      TravelingColor* recieve = travelers[rec_id];
      if (sender->active && recieve->active
	  && sender->getColor() == recieve->getColor())
      {
	int minPos = std::min(sender->getPanel(), recieve->getPanel());
	int maxPos = std::max(sender->getPanel(), recieve->getPanel());
	for (int j = minPos; j <= maxPos; j++)
	 {
	   link(j, minPos, maxPos, sender->getColor());
	 }
       }
     }//end recieve loop
   }//end send loop
}//end displayLinks

//Add shimmer effect to empty panels
void BridgeModel::baseTwinkle ()
{
  for( int i = 0; i < NUM_PANELS/ 2; i++)
  {
    int intensity = 51 + (time % 51);
    if ((i - time) % 5 == 0 && getNumTravelers() == 0)
    {
      intensity = 102;
    }
    if (pausch[i].getColor() == Color(0,0,0) )
    {
	pausch[i].setColor(intensity, intensity, intensity);
    }
  }
  for( int i = NUM_PANELS/2; i < NUM_PANELS; i++)
  {
    int intensity = 51 + (time % 51);
    if ((i + time) % 5 == 0 && getNumTravelers() == 0)
    {
      intensity = 102;
    }
    if (pausch[i].getColor() == Color(0,0,0) )
    {
	pausch[i].setColor(intensity, intensity, intensity);
    }
  }
}
