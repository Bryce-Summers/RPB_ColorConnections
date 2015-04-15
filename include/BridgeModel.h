#ifndef BRIDGEMODEL_H
#define BRIDGEMODEL_H

#include <array>

class BridgeModel
{
 public:

  // -- Constructor;
  BridgeModel();

  static const NUM_PANELS = 57;
  typedef Bridge std::array<ColorPanel, NUM_PANELS>;

  void update (int timeStep);

  void addTravelingColor(TravelingColor t_color);

  Bridge getBridge ();

 protected:

 private:
  Bridge pausch;
  std::vector<TravelingColor> travelers;

  void fadeBridge ();
  void displayTravelers ();
  void displayLinks ();
  void baseTwinkle ();


};//end BridgeModel

#endif //BRIDGEMODEL_H
