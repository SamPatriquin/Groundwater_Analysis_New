#ifndef ANALOG_H

#define ANALOG_H
#define SIZE_ANALOG_BUFFER 20
#include "wiring_private.h"

#define BAT_PIN 9
//change this to 9 but not now cause the python and for testing purposes
#define BAT_STRING "7"

char analog_reading_buffer[SIZE_ANALOG_BUFFER] = {0};


//Precondition: result_buffer is a pointer to allocated space
//Postcondition: Stores the analog reading from the battery pin 
//in result_buffer.
void format_battery_reading(char* result_buffer)
{
  //Note: BAT_STRING = "7" and "7"":%d" is treated the same as "7:%d" by the compiler
pinMode(BAT_PIN,INPUT);

//int mux=ADMUX;
//int sra=ADCSRA;
//int srb=ADCSRB;

//ADMUX=68;
//ADCSRA=150;
//ADCSRB=32;

sprintf(result_buffer, BAT_STRING":%d", analogRead(BAT_PIN));//, mux, sra, srb);
//sprintf(result_buffer, BAT_STRING":%d", 37);
//ADMUX = 0;
//ADCSRB = 0;
//ADCSRA = 0;
//  cbi(ADCSRA, ADEN);
}
//Precondition: result_buffer is a pointer to allocated space
//Postcondition: since the pins are documented with an of offset of
//18, 18 is subtracted from the pin number to get the proper number.
//The analog reading from the pin and the formatted pin number is stored in
//result_buffer.
void format_analog_reading(int analog_pin_number, char* result_buffer)
{
  sprintf(result_buffer, "%d:%d", analog_pin_number-18, analogRead(analog_pin_number));
}

//Precondition: void
//Postcondition: returns the boolean value of the
//statement "battery pin reading is less than 500".
//Returns true if battery reading is lower than 500.
bool battery_low()
{
  return analogRead(BAT_PIN) < 500;
}

#endif
