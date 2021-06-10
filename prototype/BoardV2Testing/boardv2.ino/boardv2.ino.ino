#include <Wire.h>

//Mux enables
#define Enable1 1
#define Enable2 11

//Mux selects
#define S0 5
#define S1 6
#define S2 9  
#define S3 10

#define ADDRESS 24
#define MAX_EZO_RESPONSE_SIZE 40


void setup() {

  //Mux Pinmodes
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(Enable1, OUTPUT);
  pinMode(Enable2, OUTPUT);
  pinMode(13, OUTPUT);

  //LED
  digitalWrite(13, HIGH);
  
  //Mux select
  digitalWrite(S0, LOW);
  digitalWrite(S1, LOW);
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  
  //Mux Enable
  digitalWrite(Enable1, LOW);
  digitalWrite(Enable2, LOW);
}

void loop() {
  digitalWrite(Enable1, LOW);
  Wire.beginTransmission(ADDRESS);
  Wire.write("R");
  Wire.endTransmission();

  delay(1000);

  Wire.requestFrom(ADDRESS, MAX_EZO_RESPONSE_SIZE, true);
  
  unsigned int responseCode = Wire.read();

  if( responseCode == 1 ) { // 1 means the response is valid
    char current;
    String response;
    response.reserve(MAX_EZO_RESPONSE_SIZE);
    while(Wire.available()){
      current = Wire.read();
      response += current;
    }
    Serial.println(response);
  } else { // Anything other than one is an error
    Serial.println("ERR");
  }

  delay(5000);

}
