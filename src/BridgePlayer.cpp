#include "BridgePlayer.h"

BridgePlayer::BridgePlayer()
{

}

BridgePlayer::~BridgePlayer()
{

}

void BridgePlayer::readFile()
{

  using namespace std;

  ifstream classFile("../worldofcolor.csv");
  string line;

  while(getline(classFile, line)){
    ColorPanel bridge[BridgeModel::NUM_PANELS];
    lineToBridge(line, bridge);
    bridgeData.push_back(bridge);
  }
}

void  BridgePlayer::lineToBridge (std::string line, ColorPanel * bridge)
{
  using namespace std;
  std::istringstream iss (line);
  string panel;
  int i = 0;
  while(getline(iss, panel, ',')){
      int color = std::stoi(panel);
      bridge[i] = ColorPanel();
      bridge[i].setColor(ctable[color]);
      i++;
  }
}
