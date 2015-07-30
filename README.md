# RPB_ColorConnections
A project for the Randy Pausch Bridge Lighting Couse at CMU.

![alt text](https://github.com/Bryce-Summers/RPB_ColorConnections/blob/master/Photos/RPB.jpg "RPB")

What it Does
----------
This project when run on a server with Lumniverse installed that is connected to the Randy Pausch Bridge at Carnegie Mellon University, performs an interactive ligh show that attempts to use Arduinos and sensors to allow lights to follow pedestrians across the bridge with velocity matching.

The project was demoed at the Randy Pausch Bridge Lighting Class demo day on 5/1/2015.


Components
------

**Arduino code** that talks to sensors (we used mac os labtops and port numbers for the demo)

**Sensor client code**, that talks takes sensor readings from the arduino code, proccesses them into velocity readings and sends them to the main server.

**Main Server** that runs on the Bridge CServer Computer and  talks to the Pharos Light Controller through the Lumiverse Framework.

- Bridge Show Logic for displaying and interpreting the traveling velocity induced colors.
- A fixed show for when the bridge reaches a threshold around 10 people. This show plays and then the bridge resets.

Please see
---------

https://github.com/ebshimizu/Lumiverse
