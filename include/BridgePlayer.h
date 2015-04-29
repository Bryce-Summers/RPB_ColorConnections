#ifndef BPLAYER_H
#define BPLAYER_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "Color.h"
#include "ColorPanel.h"
#include "BridgeModel.h"

class BridgePlayer
{
 public:

  BridgePlayer();
  virtual ~BridgePlayer();
  vector <ColorPanel *> bridgeData;

  void readFile();
  void lineToBridge(std::string line, ColorPanel* bridge);
 protected:

 private:
  Color ctable[7] = {Color(255,255,255), Color(255,0,0), Color(0,255,0), 
	    Color(0,0,255), Color(170,0,255), Color(255,143,0), 
	    Color(255,255,0)};
};

#endif
