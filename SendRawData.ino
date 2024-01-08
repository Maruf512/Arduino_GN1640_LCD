#define SDA D1
#define SCL D2

void i2cStart() {
  //generates a high to low SDA transition during SCL high as a start condition
  pinMode(SDA, OUTPUT);
  pinMode(SCL, OUTPUT);
  digitalWrite(SCL, LOW);
  digitalWrite(SDA, HIGH);

  digitalWrite(SCL, HIGH);
  digitalWrite(SDA, LOW);

  digitalWrite(SCL,LOW);
}

void i2cStop() {
  //generates a low to high SDA transition during SCL high as a start condition
  pinMode(SDA, OUTPUT);
  pinMode(SCL, OUTPUT);
  digitalWrite(SCL, LOW);
  digitalWrite(SDA, LOW);

  digitalWrite(SCL, HIGH);
  digitalWrite(SDA, HIGH);

  digitalWrite(SCL,LOW); 
}

byte i2cSend(byte data) {
  //sends data to device and checks for ack
  byte ack = 2;
  pinMode(SDA, OUTPUT);
  pinMode(SCL, OUTPUT);

  digitalWrite(SCL, LOW);
  //send out data
  shiftOut(SDA,SCL,LSBFIRST,data);
  return ack;  
}

void setup() {
  
}

void loop() {
  //Sending the frame to the screen.
  i2cStart();
  i2cSend(B11000000); //Address 0
  i2cSend(B11101101);
  i2cSend(B11101101);
  i2cSend(B11101101);
  i2cSend(B11101101);
  i2cSend(B11101101);
  i2cSend(B11101101);
  i2cSend(B11101101);
  i2cSend(B11101101);
  i2cSend(B11101101);
  i2cSend(B11101101);
  i2cSend(B11101101);
  i2cSend(B11101101);
  i2cSend(B11101101);
  i2cSend(B11101101);
  i2cSend(B11101101);
  i2cSend(B11101101);
  i2cStop();

  i2cStart();
  i2cSend(B10001001); //Torning the screen on and using the last 3 bits setting the brightness
  i2cStop();

}
