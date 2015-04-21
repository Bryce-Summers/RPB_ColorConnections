
#ifndef indoor_main_H_

#define indoor_main_H_

#define ADC_LIGHT_PIN (0)
#define PIR_INPUT_PIN (3)

#define PIR_DETECT_LOW (0)
#define PIR_DETECT_THRESH (100)

void setup_indoor_sensors();

int read_pir();

#endif
// int read_temp();
// int read_hum();
// int read_dust();
// int read_light();
// int read_gas();



// #define ADC_GAS_PIN (1)
// #define ADC_DUST_PIN (2)


// Digital
// #define DUST_TRIGGER_PIN (2)

// #define RHT_INPUT_PIN (4)




// Methods

