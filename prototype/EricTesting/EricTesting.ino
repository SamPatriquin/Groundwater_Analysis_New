

//Pin 2-5 are control for mux
//Select 15 for temp at 11
//Select 14 for DO at 12
//Select 13 for Conductivity at 13
//Select 12 for ORP at 14


void setup() {
 digitalWrite(HIGH, 2);
 digitalWrite(HIGH, 3);
 digitalWrite(HIGH, 4);
 digitalWrite(HIGH, 5);
}

void loop() {
  takeReading(11);
}

void takeReading(int address){
  Wire.beginTransmission(address);
  Wire.write("R");
  Wire.endTransmission();
}
