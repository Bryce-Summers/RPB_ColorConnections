#ifndef BRIDGEMODEL_H
#define BRIDGEMODEL_H

#include <vector>
#include <mutex>
#include "TravelingColor.h"
#include "ColorPanel.h"

#include <iostream>
using namespace std;

class BridgeModel
{
 public:

  // -- Constructor;
  BridgeModel();

  static const int NUM_PANELS = 57;
  
  //typedef Bridge std::array<ColorPanel, NUM_PANELS>;

  void update (float timeStep);

  void addTravelingColor(TravelingColor* t_color);
  void removeAllTravelers();
  int getNumTravelers();


  ColorPanel * getBridge ();
  void setBridge(ColorPanel * bridge);


 protected:

 private:
  // The representation of the bridge.
  ColorPanel pausch[NUM_PANELS];
  static const int NUM_TRAVELERS = 4 * 2 + 1;
  TravelingColor** travelers;


  int time;
  static const int MAXTIME = 57;

  void fadeBridge ();
  void displayTravelers ();
  void displayLinks ();
  void baseTwinkle ();

  void link(int pos, int left, int right, Color c);


};//end BridgeModel

#endif //BRIDGEMODEL_H
