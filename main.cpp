#include <LumiverseCore.h>
#include <LumiverseShowControl.h>

using namespace Lumiverse;

using namespace Lumiverse::ShowControl;

int main()
{

Rig* rig = new Rig("/home/teacher/Lumiverse/PBridge.rig.json");

rig->select("$panel=31").setRGBRaw(1, 0, 0);


}
