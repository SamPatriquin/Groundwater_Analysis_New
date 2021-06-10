#include <Wire.h>

#define ADDRESS 13
#define MAX_EZO_RESPONSE 40

//Mux stuff
#define S0 5
#define S1 6
#define S2 9  
#define S3 10
#define Enable1 1
#define Enable2 11

void setup() {
  Wire.begin();
  Serial.begin(9600);

  //Mux stuff
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(Enable1, OUTPUT);
  pinMode(Enable2, OUTPUT);

  //Turn on Muxs and select 0
  digitalWrite(Enable1, LOW);
  digitalWrite(Enable2, LOW);
  digitalWrite(S0, LOW);
  digitalWrite(S1, LOW);
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
}

void loop() {
  Wire.beginTransmission(ADDRESS);
  Wire.write("R");
  Wire.endTransmission();
  Wire.beginTransmission(ADDRESS);
  String input = Serial.readString();
  input.trim();
  Wire.write(input.c_str());
  Wire.requestFrom(ADDRESS, MAX_EZO_RESPONSE, true);
  while(Wire.available()){
    Serial.print((char)Wire.read());
  }
  Serial.println();
  Wire.endTransmission();
  delay(1000);
}
