
#include "sensor_main.h"
#include "pir.h"
#include "message.h"

// Setup

// Poll and message loop iterations
void serialWrite(int num, int speed) {
  String msg = String(num) + " " + String(speed) + "\n";
  int msgLen = msg.length();
  char msgArr[msgLen+1];
  msg.toCharArray(msgArr, msgLen+1);
  Serial.write(msgArr);
}

// performs an average to approximate detected motion
void pir_iteration(){
  for(int i=0; i<10; i++){
    serialWrite(SENSOR_NUM, 0);
    delay(1000);
  }
  serialWrite(SENSOR_NUM, 1);
  delay(1000);
}


// Poll each sensor every five seconds
void run_iterations(){
  pir_iteration();
  //delay(1000);
}

void setup() {
  Serial.begin(9600);
  delay(5000);
}

void loop() {
  run_iterations();
}
