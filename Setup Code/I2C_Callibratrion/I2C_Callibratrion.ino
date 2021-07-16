#include <Wire.h>

String getInput();
bool getConfirmation();
void setMuxPins(int add); 
void setCalibration(String address);
void readFromWire(int address);
void readingsUntilStabilized(int address);

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
  Serial.setTimeout(3000); // This gives user time to enter break keyword in readingsUntilStabilized function
  while(!Serial); // Wait for user to open Serial monitor

  //Mux stuff
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(Enable1, OUTPUT);
  pinMode(Enable2, OUTPUT);

  digitalWrite(Enable1, LOW);
  digitalWrite(Enable2, LOW);
}


void loop() {
  String address;
  bool confirmation = false;

  // Outer loop- choose address, confirm, select mux pins
  Serial.println("Please enter I2C address of EZO board with which you wish to communicate:");
  address = getInput();
  Serial.println("You entered address " + address);
  Serial.println("Please confirm that this is correct.");
  confirmation = getConfirmation();
  int add = address.toInt();
  if(confirmation &&                            // yes confirmation
    (add / 10 >= 1 && add / 10 <= 4) &&         // first digit on [1, 4]
    (add % 10 >= 1 && add % 10 <= 4)) {         // second digit on [1, 4]
      setMuxPins(add);
      setCalibration(address); // Sending string because Wire transmission needs String, not int
     }
  if(!((add / 10 >= 1 && add / 10 <= 4) &&
       (add % 10 >= 1 && add % 10 <= 4)))
       Serial.println("Please enter an appropriate address.");
     
  delay(1000); // 1 second delay
}




// Function Helpers

String getInput(){
  bool hasInput = false;
  String input;
  while(!hasInput){
    input = Serial.readString();
    if(input.length() > 0){hasInput = true;}
  }
  return input;
}

bool getConfirmation(){
  String input;
  Serial.println("y/n = yes or no");
  while(true){
    input = getInput();
    input.toLowerCase();
    input.trim();
    if(input == String('y')){ return true; }
    else if (input == String('n')){return false;}
    Serial.println("Invalid response, please input y or n");
  }
}

void setMuxPins(int add) {
  // Special case for pod 4
  // In pods 1-3, the U# footprints, which denote EZO boards,
  // increase from left to right when looking at that particular pod,
  // from temperature to DO.
  // This is not the case with pod 4. It increases from right to left,
  // from DO to temperature.
  // This special case is to account for this,
  // so that it can still go through the mathematical manipulation below, which
  // works for all addresses with the U# numbering described above.
  switch(add) {
    case 41:
      add = 44;
      break;
    case 42:
      add = 43;
      break;
    case 43:
      add = 42;
      break;
    case 44:
      add = 41;
      break;
    default:
      break;  
  }


  // Go from int address to decimal select number
  int select = ((add - 11) / 10 * 4) + ((add - 11) % 10);

  // Iterate through decimal select as binary number and set appropriate select bits
  // Turn on Muxs and select EZO at address given to function
  for(int i = 1; i <= 4; i++) {
    int selectBit;
    switch(i) {
      case 1:
        selectBit = S0;
        break;
      case 2:
        selectBit = S1;
        break;
      case 3:
        selectBit = S2;
        break;
      case 4:
        selectBit = S3;
        break;
      default:
        break;
    }

    if(select % 2 == 0) digitalWrite(selectBit, LOW);
    else                digitalWrite(selectBit, HIGH);
    select /= 2;
  }
}

void setCalibration(String address) {
  int add = address.toInt();
  String command = "";

  readingsUntilStabilized(add);

  Serial.println("Enter command(s) one by one to send to address " + address + ", or \"break\" to go to next EZO:");
  while(true) {
    command = getInput();
    command.trim();
    if(command == "break") break;
    Wire.beginTransmission(add);
    Wire.write(command.c_str());
    Wire.endTransmission();
    delay(1400);
    readFromWire(add);
    command.toLowerCase();
    if(command == "cal,dry" || command == "cal") readingsUntilStabilized(add); // Two step process for conductivity calibration, see EZO documentation sheets for more info
  }
}

void readFromWire(int address) {
  Wire.beginTransmission(address);
  Wire.requestFrom(address, MAX_EZO_RESPONSE, true);
  while(Wire.available()){
    Serial.print((char)Wire.read());
  }
  Serial.println();
  Wire.endTransmission();
}

void readingsUntilStabilized(int address) {
  String command = "";
  Serial.println("Wait until readings stabilize! Enter \"break\" to start/continue calibration.");
  while(command != "break") {
    Wire.beginTransmission(address);
    Wire.write("R");
    Wire.endTransmission();
    delay(1400);
    readFromWire(address);
    command = Serial.readString(); // Will time out if no input, go to next iteration of loop 
    command.trim();
  }
}
