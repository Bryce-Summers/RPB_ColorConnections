
#include "sensor_main.h"
#include "pir.h"

// Setup
int motionDetected_0;
int motionDetected_1;
int currentSpeed;


void setup_sensors(){
  setup_pir(PIR_INPUT_PIN_0);
  setup_pir(PIR_INPUT_PIN_1);
}

int read_pir_0(){
  return read_pir(PIR_INPUT_PIN_0);
}

int read_pir_1(){
  return read_pir(PIR_INPUT_PIN_1);
}

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
  long unsigned int timer_0;
  long unsigned int timer_1;

  int sum = 0;
  for (int i = 0; i < PIR_DETECT_THRESH; i++) {
    sum += read_pir_0();
    delay(10); 
  }
  
  motionDetected_0 = (sum != PIR_DETECT_THRESH);
  if(motionDetected_0 == 1){
    timer_0 = millis()/1000;
    delay(100);
    while(true){
      sum = 0;
      for (int i = 0; i < PIR_DETECT_THRESH; i++) {
        sum += read_pir_1();
        delay(10); 
      }
      timer_1 = millis()/1000;
      motionDetected_1 = (sum != PIR_DETECT_THRESH); 
      if(motionDetected_1 == 1){
        // detect person in and send out the message;
        currentSpeed = DISTANCE / (timer_1-timer_0);
        serialWrite(SENSOR_NUM, currentSpeed);
        break;
      }
      if((timer_1-timer_0)>ERROR_TIME){
        break;
        // time out and we try it as an error;
      }
    }
  }
  else{
    serialWrite(SENSOR_NUM, 0);
  }
  delay(700);
}


// Poll each sensor every five seconds
void run_iterations(){
  pir_iteration();
}

void setup() {
  Serial.begin(9600);
  setup_sensors();
  delay(5000);
}

void loop() {
  run_iterations();
}
