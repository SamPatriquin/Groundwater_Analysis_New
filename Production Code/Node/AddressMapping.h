#ifndef _ADDRESS_MAPPING_H
#define _ADDRESS_MAPPING_H

#define S0 5
#define S1 6
#define S2 9  
#define S3 10

#define Enable1 1
#define Enable2 11

void setMuxPinModes(){
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(Enable1, OUTPUT);
  pinMode(Enable2, OUTPUT);
}

void enableMux(){
  digitalWrite(Enable1, LOW);
  digitalWrite(Enable2, LOW);
}

void disableMux(){
  digitalWrite(Enable1, HIGH);
  digitalWrite(Enable2, HIGH);
}

void muxSelect(int address){
  switch(address){
    case 11: //Select 0
      digitalWrite(S0, LOW);
      digitalWrite(S1, LOW);
      digitalWrite(S2, LOW);
      digitalWrite(S3, LOW);
      break;
    case 12: //Select 1
      digitalWrite(S0, HIGH);
      digitalWrite(S1, LOW);
      digitalWrite(S2, LOW);
      digitalWrite(S3, LOW);
      break;
    case 13: //Select 2
      digitalWrite(S0, LOW);
      digitalWrite(S1, HIGH);
      digitalWrite(S2, LOW);
      digitalWrite(S3, LOW);
      break;
    case 14: //Select 3
      digitalWrite(S0, HIGH);
      digitalWrite(S1, HIGH);
      digitalWrite(S2, LOW);
      digitalWrite(S3, LOW);
      break;
    case 21: //Select 4
      digitalWrite(S0, LOW);
      digitalWrite(S1, LOW);
      digitalWrite(S2, HIGH);
      digitalWrite(S3, LOW);
      break;
    case 22: //Select 5
      digitalWrite(S0, HIGH);
      digitalWrite(S1, LOW);
      digitalWrite(S2, HIGH);
      digitalWrite(S3, LOW);
      break;
    case 23: //Select 6
      digitalWrite(S0, LOW);
      digitalWrite(S1, HIGH);
      digitalWrite(S2, HIGH);
      digitalWrite(S3, LOW);
      break;
    case 24: //Select 7
      digitalWrite(S0, HIGH);
      digitalWrite(S1, HIGH);
      digitalWrite(S2, HIGH);
      digitalWrite(S3, LOW);
      break;
    case 31: //Select 8
      digitalWrite(S0, LOW);
      digitalWrite(S1, LOW);
      digitalWrite(S2, LOW);
      digitalWrite(S3, HIGH);
      break;
    case 32: //Select 9
      digitalWrite(S0, HIGH);
      digitalWrite(S1, LOW);
      digitalWrite(S2, LOW);
      digitalWrite(S3, HIGH);
      break;
    case 33: //Select 10
      digitalWrite(S0, LOW);
      digitalWrite(S1, HIGH);
      digitalWrite(S2, LOW);
      digitalWrite(S3, HIGH);
      break;
    case 34: //Select 11
      digitalWrite(S0, HIGH);
      digitalWrite(S1, HIGH);
      digitalWrite(S2, LOW);
      digitalWrite(S3, HIGH);
      break;
    /*
     * The U# labels on pod 4 are inverted compared to the other 3 pods.
     * In pods 1-3, the U# labeling increases from left to right, temperature to DO.
     * This is necessary because of compensation for certain EZOs.
     * In pod 4, the U# labeling is inverted, meaning that it increases from right to left,
     * from DO to temperature. This causes bad data to be sent, because compensation is not
     * properly sent.
     * So pod 4's select cases had to be inverted as a result of this.
     */
    case 44: //Select 12
      digitalWrite(S0, LOW);
      digitalWrite(S1, LOW);
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      break;
    case 43: //Select 13
      digitalWrite(S0, HIGH);
      digitalWrite(S1, LOW);
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      break;
    case 42: //Select 14
      digitalWrite(S0, LOW);
      digitalWrite(S1, HIGH);
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      break;
    case 41: //Select 15
      digitalWrite(S0, HIGH);
      digitalWrite(S1, HIGH);
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      break;
    default:
      Serial.println("No address matching");
  }
}

#endif // _ADDRESS_MAPPING_H
