#include <Adafruit_SleepyDog.h>
#include <avr/power.h>
#include "I2C.h"
#include "EZO.h"
#include "radio.h"
#include "analog.h"
#include "radio.h"

#define EZO_POWER_PIN 11

void setup() {
 //Steps:
 //init wire, radio, maybe serial?
  Serial.begin(9600);
  pinMode(EZO_POWER_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  //ADMUX=68;
  //ADCSRA=150;
  //ADCSRB=32;
  
  bool radio_success = setup_radio();

  
  if(radio_success)
  {
    Serial.println("SUCCESS");
  }
  else
  {
    Serial.println("FAILURE");
  }
  
 //scan i2c addresses
  setup_i2c(address_array);

 //maybe send some sort of diagnostic report over serial if it is connected?
  for(int i=0; i<MAX_DEVICES;i++)
  {
    if(address_array[i]!=0)Serial.println(address_array[i]);
  }
  send_sleep_command(20);
  send_sleep_command(21);
  send_sleep_command(30);
  send_sleep_command(31);
}

void loop() {
  get_sensor_reading(20, ezo_reading_buffer);
  send_radio_message(ezo_reading_buffer);
  get_temperature_calibrated_sensor_reading(21, _ezo_response, SIZE_EZO_RESPONSE, ezo_reading_buffer);
  send_radio_message(ezo_reading_buffer);
  get_sensor_reading(30, ezo_reading_buffer);
  send_radio_message(ezo_reading_buffer);
  get_temperature_calibrated_sensor_reading(31, _ezo_response, SIZE_EZO_RESPONSE, ezo_reading_buffer);
  send_radio_message(ezo_reading_buffer);
  //The power issue is coming from reading the battery
  format_battery_reading(analog_reading_buffer);
  send_radio_message(analog_reading_buffer);
  //Sleep
  long milis_left = 600000;
  while(milis_left>0)milis_left-=Watchdog.sleep();

}
 
