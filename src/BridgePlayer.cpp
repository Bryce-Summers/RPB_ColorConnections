#include "BridgePlayer.h"

BridgePlayer::BridgePlayer()
{
  bridgeData.reserve(10);
  cout << "BridgeData initial size" << bridgeData.size() << endl;
  readFile();
  cout << "BridgeData after read size" << bridgeData.size() << endl;
}

BridgePlayer::~BridgePlayer()
{

}

void BridgePlayer::readFile()
{

  using namespace std;

  ifstream file("./worldofcolor.csv");
  string line;


  if (file.is_open())
  {

    // ignore header line.
    getline(file, line);

    while ( getline (file,line) )
    {
      //	cout << line << '\n';
	
      ColorPanel * bridge = (ColorPanel *)malloc(sizeof(ColorPanel)*BridgeModel::NUM_PANELS);
      lineToBridge(line, bridge);
      bridgeData.push_back(bridge);
    }

    file.close();
  }
  else
  {
    cout << "Unable to open file" << endl; 
    exit(0);
  }

}

void  BridgePlayer::lineToBridge (std::string line, ColorPanel * bridge)
{
  using namespace std;
  std::istringstream iss (line);
  string panel;
  int i = 0;

  while(getline(iss, panel, ',')){

    if(panel == " \r")
    {
	continue;
    }
    
      int color = std::stoi(panel);

      // Print the color.

      //      cout<< ctable[color] << ",";

      bridge[i] = ColorPanel();
      bridge[i].setColor(ctable[color]);

      //      printColor(bridge[i].getColor());      

      i++;
  }
  if (i != BridgeModel::NUM_PANELS)
  {
    cout << "Only have " << i << " panels when we needed " 
	 << BridgeModel::NUM_PANELS << endl;
    exit(0);
  }
}


void BridgePlayer::printColor(Color c)
{

// print something from v to str, e.g: Str << v.getX();
  cout << "Color[r = " + std::to_string(c.red) +
	         "g = " + std::to_string(c.green) +
		 "b = " + std::to_string(c.blue) + "]\n";


}

ColorPanel * BridgePlayer::getFrame(int i)
{
  return bridgeData[i];
}

int BridgePlayer::getShowSize()
{
  return bridgeData.size();
}
