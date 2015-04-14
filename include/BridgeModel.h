#ifndef BRIDGEMODEL_H
#define BRIDGEMODEL_H

#include <array>

class BridgeModel
{
 public:
  static const NUM_PANELS = 50;
  typedef bridge std::array<ColorPanel, NUM_PANELS>;

  void update (int timeStep);

  void addTravelingColor(TravelingColor t_color);

  bridge getBridge ();

 protected:

 private:
  bridge pausch[NUM_PANELS];
  std::vector<TravelingColor> travelors;

  void fadeBridge ();
  void displayTravelers ();
  void displayLinks ();
  void baseTwinkle ();


};//end BridgeModel

#endif //BRIDGEMODEL_H
