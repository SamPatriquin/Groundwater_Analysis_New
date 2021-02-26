#include <Wire.h>

//Mux enables
#define Enable1 1
#define Enable2 11

//Mux selects
#define S0 5
#define S1 6
#define S2 9
#define S3 10

#define ADDRESS 11
#define MAX_EZO_RESPONSE_SIZE 40


void setup() {

  //Mux enable
  digitalWrite(1, LOW);
  digitalWrite(11, LOW);

  //Mux select
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

   
}

void loop() {
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
