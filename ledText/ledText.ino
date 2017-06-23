int SER_Pin = 8;   //pin 14 on the 75HC595
int RCLK_Pin = 9;  //pin 12 on the 75HC595
int SRCLK_Pin = 10; //pin 11 on the 75HC595
int XAXIS_Pin = A5;
int YAXIS_Pin = A4;

#define MESSAGE_SIZE 264

int message [MESSAGE_SIZE] = {
//180 //B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B11111100,  B00000010,  B00000100,  B00000010,  B11111100,  B00000000,  B11111110,  B00100000,  B00100000,  B00100000,  B00011110,  B00000000,  B00011100,  B00100010,  B00100010,  B00100010,  B00011100,  B00000000,  B00000000,  B00000000,  B00000000,  B01100000,  B00000000,  B00010000,  B00101010,  B00101010,  B00101010,  B00000100,  B00000000,  B00000000,  B00000000,  B00000000,  B00100010,  B10111110,  B00000010,  B00000000,  B00111110,  B00100000,  B00100000,  B00100000,  B00011110,  B00000000,  B00000000,  B00000000,  B00000000,  B00010000,  B01111110,  B10010000,  B10010000,  B01000000,  B00000000,  B00011100,  B00100010,  B00100010,  B00100010,  B00011100,  B00000000,  B00111110,  B00100000,  B00100000,  B00100000,  B00010000,  B00000000,  B00000000,  B00000000,  B00000000,  B00101100,  B00101010,  B00101010,  B00101010,  B00011110,  B00000000,  B00000000,  B00000000,  B00000000,  B00011000,  B00100101,  B00100101,  B00100101,  B00111110,  B00000000,  B00101100,  B00101010,  B00101010,  B00101010,  B00011110,  B00000000,  B00111110,  B00100000,  B00010000,  B00100000,  B00011110,  B00000000,  B00011100,  B00101010,  B00101010,  B00101010,  B00011000,  B00000000,  B00000000,  B00000000,  B00000000,  B00100000,  B11111100,  B00100010,  B00100010,  B00000100,  B00000000,  B00011100,  B00100010,  B00100010,  B00100010,  B00011100,  B00000000,  B00111110,  B00100000,  B00100000,  B00100000,  B00011110,  B00000000,  B00100010,  B10111110,  B00000010,  B00000000,  B00011000,  B00100101,  B00100101,  B00100101,  B00111110,  B00000000,  B11111110,  B00100000,  B00100000,  B00100000,  B00011110,  B00000000,  B00100000,  B11111100,  B00100010,  B00100010,  B00000100,  B00000000,  B01000000,  B10000000,  B10011010,  B10100000,  B01000000,  B00000000,  B01000000,  B10000000,  B10011010,  B10100000,  B01000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000
B00000000,  B10000000,  B10000000,  B11111110,  B10000000,  B10000000,  B00000000,  B00011100,  B00100010,  B00100010,  B00100010,  B00011100,  B00000000,  B00111110,  B00100000,  B00100000,  B00100000,  B00011110,  B00000000,  B00100010,  B10111110,  B00000010,  B00000000,  B00000000,  B00000000,  B00000000,  B00100010,  B10111110,  B00000010,  B00000000,  B00010000,  B00101010,  B00101010,  B00101010,  B00000100,  B00000000,  B00000000,  B00000000,  B00000000,  B00100000,  B11111100,  B00100010,  B00100010,  B00100100,  B00000000,  B11111110,  B00100000,  B00100000,  B00100000,  B00011110,  B00000000,  B00011100,  B00101010,  B00101010,  B00101010,  B00011000,  B00000000,  B00000000,  B00000000,  B00000000,  B11111110,  B00100010,  B00100010,  B00100010,  B00011100,  B00000000,  B00011100,  B00101010,  B00101010,  B00101010,  B00011000,  B00000000,  B00010000,  B00101010,  B00101010,  B00101010,  B00000100,  B00000000,  B00100000,  B11111100,  B00100010,  B00100010,  B00100100,  B00000000,  B00000011,  B00000000,  B00000000,  B00000000,  B00000000,  B11111100,  B00100010,  B00100010,  B00100010,  B00011100,  B00000000,  B00111100,  B00000010,  B00000010,  B00000010,  B00111110,  B00000000,  B00100000,  B11111100,  B00100010,  B00100010,  B00100100,  B00000000,  B00000000,  B00000000,  B00000000,  B00111110,  B00100000,  B00100000,  B00100000,  B00011110,  B00000000,  B00011100,  B00100010,  B00100010,  B00100010,  B00011100,  B00000000,  B00111100,  B00000010,  B00000100,  B00000010,  B00111100,  B00000000,  B00000000,  B00000000,  B00000000,  B11111110,  B00100000,  B00100000,  B00100000,  B00011110,  B00000000,  B00011100,  B00101010,  B00101010,  B00101010,  B00011000,  B00000000,  B00000000,  B00000000,  B00000000,  B00011100,  B00100010,  B00100010,  B00100010,  B00011100,  B00000000,  B00111100,  B00000010,  B00000100,  B00000010,  B00111100,  B00000000,  B00011100,  B00101010,  B00101010,  B00101010,  B00011000,  B00000000,  B00010000,  B00101010,  B00101010,  B00101010,  B00000100,  B00000000,  B00000000,  B00000000,  B00000000,  B00111100,  B00000010,  B00000010,  B00000010,  B00111110,  B00000000,  B00010000,  B00101010,  B00101010,  B00101010,  B00000100,  B00000000,  B00000000,  B00000000,  B00000000,  B00001100,  B00101010,  B00101010,  B00101010,  B00011110,  B00000000,  B00000000,  B00000000,  B00000000,  B00111110,  B00100000,  B00100000,  B00100000,  B00010000,  B00000000,  B00100010,  B10111110,  B00000010,  B00000000,  B00011100,  B00100010,  B00100010,  B00100010,  B00010100,  B00000000,  B00011100,  B00101010,  B00101010,  B00101010,  B00011000,  B00000000,  B00011100,  B00100010,  B00100010,  B00100010,  B00010100,  B00000000,  B00001100,  B00101010,  B00101010,  B00101010,  B00011110,  B00000000,  B11111110,  B00101000,  B00101000,  B00101100,  B00010010,  B00000000,  B00011100,  B00101010,  B00101010,  B00101010,  B00011000,  B00000000,  B00000010,  B00000000,  B00000010,  B00000000,  B00000010,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000,  B00000000
};

//How many of the shift registers - change this
#define number_of_74hc595s 2 

//do not touch
#define numOfRegisterPins number_of_74hc595s * 8

boolean registers[numOfRegisterPins];

int row = 0;
int col = 0;



void setup(){
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);

  Serial.begin(9600);
  
  //reset all register pins
  clearRegisters();
  writeRegisters();
}               


//set all register pins to LOW
void clearRegisters(){
  for(int i = 7; i >=  0; i--){
     registers[i] = LOW;
  }

  for(int i = 15; i >=  8; i--){
     registers[i] = HIGH;
  }
} 

//call to output to the shift registers
void writeRegisters(){
  digitalWrite(RCLK_Pin, LOW);
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
    digitalWrite(SRCLK_Pin, LOW);

    int val = registers[i];

    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);

  }
  digitalWrite(RCLK_Pin, HIGH);
}

//set an individual pin HIGH or LOW
void setRegisterPin(int index, int value){
  registers[index] = value;
}

int currentTopDisplayColumn = 0;

int loops = 0;

int maxLoops =35;

void loop(){
  for (int i = 0; i < 8; i++) {
    clearRegisters();
    setRegisterPin(i+8, LOW); //activate column

    int messageCode = message[(0+currentTopDisplayColumn+i)%MESSAGE_SIZE];
  
    int mask = 1;
    for (int j = 7; j >= 0; j--) {

      if ((messageCode & mask) > 0) {  
        setRegisterPin(j, HIGH); //activate all relevant rows in the column
      } 
      
      mask = mask << 1;
    }
    writeRegisters();
  }

  loops++;
  if (loops > maxLoops) {
    determinePosition();
    loops = 0;
  }
}

void determinePosition() {
  int xValue = analogRead(XAXIS_Pin);
  int yValue = analogRead(YAXIS_Pin);
  
  if (xValue > 524) {
    maxLoops++;
  } else if (xValue < 500) {
    maxLoops--;
  } 

  if (maxLoops < 15) {
    maxLoops = 15; 
  }
  if (maxLoops > 100) {
    maxLoops = 100; 
  }
  
  if (yValue > 524) {
    currentTopDisplayColumn--;
  } else {
    //auto advance
      currentTopDisplayColumn++;
  }

  currentTopDisplayColumn = (currentTopDisplayColumn+MESSAGE_SIZE) % MESSAGE_SIZE;

}

