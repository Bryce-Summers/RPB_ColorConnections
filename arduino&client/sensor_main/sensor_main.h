
#ifndef indoor_main_H_

#define indoor_main_H_

#define SENSOR_NUM (1)

#define PIR_INPUT_PIN_0 (9)
#define PIR_INPUT_PIN_1 (10)

#define PIR_DETECT_LOW (0)
#define PIR_DETECT_THRESH (100)
#define DISTANCE (20)
#define ERROR_TIME (3)

void setup_indoor_sensors();

int read_pir();

#endif

