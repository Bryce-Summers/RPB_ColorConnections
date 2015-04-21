
#include "pir.h"

void setup_pir(int inputPin){
  pinMode(inputPin, INPUT);
}

int read_pir(int inputPin){
  return digitalRead(inputPin);
}
