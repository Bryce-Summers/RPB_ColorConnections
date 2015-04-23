
#ifndef indoor_main_H_

#define indoor_main_H_

//#define ADC_LIGHT_PIN (0)
#define PIR_INPUT_PIN_0 (11)
#define PIR_INPUT_PIN_1 (12)

#define PIR_DETECT_LOW (0)
#define PIR_DETECT_THRESH (100)
#define DISTANCE (2)
#define SENSOR_NUM (1)
#define ERROR_TIME (3)

void setup_indoor_sensors();

int read_pir();

#endif

