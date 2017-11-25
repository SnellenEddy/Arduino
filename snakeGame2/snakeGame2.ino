#include <Entropy.h>



#define number_of_74hc595s 2 //How many of the shift registers 
#define numOfRegisterPins number_of_74hc595s * 8

int SER_Pin = 8;   //pin 14 on the 75HC595
int RCLK_Pin = 9;  //pin 12 on the 75HC595
int SRCLK_Pin = 10; //pin 11 on the 75HC595
int XAXIS_Pin = A5; //VRx 
int YAXIS_Pin = A4; //VRy

byte asciiLengths [128] = {0,0,0,0,0,0,0,0,0,5,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,3,5,5,5,5,1,2,2,3,3,1,3,1,4,5,3,5,5,5,5,5,5,5,5,1,1,4,5,4,5,5,5,5,5,5,5,5,5,5,3,5,5,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,4,2,3,5,1,4,4,4,4,4,4,4,4,3,4,4,3,5,4,4,4,4,4,4,3,4,5,5,5,4,4,3,1,3,5,0};
byte asciiChars [128] [5] = {{},{},{},{},{},{},{},{},{},{B00000000,B00000000,B00000000,B00000000,B00000000},{},{},{},{B00000000,B00000000,B00000000,B00000000,B00000000},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{B00000000,B00000000},{B11111010},{B11000000,B00000000,B11000000},{B00010100,B00111110,B00010100,B00111110,B00010100},{B00100100,B01010100,B11111110,B01010100,B01001000},{B00100010,B01010100,B00111100,B00101010,B01000100},{B00101100,B01010010,B00101010,B00000100,B00001010},{B11000000},{B01111110,B10000001},{B10000001,B01111110},{B10100000,B01000000,B10100000},{B00001000,B00011100,B00001000},{B00000011},{B00010000,B00010000,B00010000},{B00000010},{B00000011,B00001100,B00110000,B11000000},{B01111100,B10000010,B10010010,B10000010,B01111100},{B01000010,B11111110,B00000010},{B01100010,B10000110,B10001010,B10010010,B01100010},{B01000100,B10000010,B10010010,B10010010,B01101100},{B11110000,B00010000,B00010000,B00010000,B11111110},{B11100100,B10010010,B10010010,B10010010,B10001100},{B01111100,B10010010,B10010010,B10010010,B00011100},{B10000000,B10000000,B10011110,B10100000,B11000000},{B01101100,B10010010,B10010010,B10010010,B01101100},{B01100000,B10010010,B10010010,B10010010,B01111100},{B00100010},{B00100011},{B00010000,B00101000,B01000100,B10000010},{B00101000,B00101000,B00101000,B00101000,B00101000},{B10000010,B01000100,B00101000,B00010000},{B01100000,B10000000,B10001010,B10010000,B01100000},{B00111100,B01000010,B01011010,B01011010,B00111000},{B00111110,B01001000,B10001000,B01001000,B00111110},{B11111110,B10010010,B10010010,B10010010,B01101100},{B01111100,B10000010,B10000010,B10000010,B01000100},{B11111110,B10000010,B10000010,B10000010,B01111100},{B11111110,B10010010,B10010010,B10010010,B10000010},{B11111110,B10010000,B10010000,B10010000,B10000000},{B01111100,B10000010,B10010010,B10010010,B01011100},{B11111110,B00010000,B00010000,B00010000,B11111110},{B10000010,B11111110,B10000010},{B10000100,B10000010,B10000010,B10000010,B11111100},{B11111110,B00010000,B00101000,B01000100,B10000010},{B11111110,B00000010,B00000010,B00000010},{B11111110,B01000000,B00100000,B01000000,B11111110},{B11111110,B00100000,B00010000,B00001000,B11111110},{B01111100,B10000010,B10000010,B10000010,B01111100},{B11111110,B10010000,B10010000,B10010000,B01100000},{B01111100,B10000010,B10001010,B10000110,B01111110},{B11111110,B10010000,B10011000,B10010100,B01100010},{B01100100,B10010010,B10010010,B10010010,B01001100},{B10000000,B10000000,B11111110,B10000000,B10000000},{B11111100,B00000010,B00000010,B00000010,B11111110},{B11110000,B00001100,B00000010,B00001100,B11110000},{B11111100,B00000110,B00001100,B00000110,B11111100},{B10000010,B01101100,B00010000,B01101100,B10000010},{B11100100,B00010010,B00010010,B00010010,B11111100},{B10000110,B10001010,B10010010,B10100010,B11000010},{B11111110,B10000010},{B11000000,B00110000,B00001100,B00000011},{B10000010,B11111110},{B01000000,B10000000,B01000000},{B00000001,B00000001,B00000001,B00000001,B00000001},{B11000000},{B00101100,B00101010,B00101010,B00011110},{B11111110,B00100010,B00100010,B00011100},{B00011100,B00100010,B00100010,B00010000},{B00011100,B00100010,B00100010,B11111110},{B00011100,B00101010,B00101010,B00011000},{B00010000,B01111110,B10010000,B10010000},{B00011000,B00100101,B00100101,B00011110},{B11111110,B00100000,B00100000,B00011110},{B00100010,B10111110,B00000010},{B00000010,B00000001,B00000001,B10111110},{B11111110,B00101000,B00101100,B00010010},{B10000010,B11111110,B00000010},{B00111110,B00100000,B00010000,B00100000,B00011110},{B00111110,B00100000,B00100000,B00011110},{B00011100,B00100010,B00100010,B00011100},{B00111111,B00100010,B00100010,B00011100},{B00011100,B00100010,B00100010,B00011111},{B00111110,B00100000,B00100000,B00010000},{B00010010,B00101010,B00101010,B00100100},{B11111100,B00100010,B00100010},{B00111100,B00000010,B00000010,B00111110},{B00110000,B00001100,B00000010,B00001100,B00110000},{B00111100,B00000010,B00000100,B00000010,B00111100},{B00100010,B00010100,B00001000,B00010100,B00100010} ,{B00111000,B00000101,B00000101,B00111110},{B00100110,B00101010,B00110010,B00100010},{B00010000,B01101100,B10000010},{B11111110},{B10000010,B01101100,B00010000},{B01000000,B10000000,B01000000,B00100000,B01000000},{}};

String messageString = "";
boolean registers[numOfRegisterPins];
int loops = 0;
int maxLoops = 60; //was: 48
boolean gameOver = false;
int snake [64] [2] = {{0,4},{1,4},{2,4}}; // the snake can have maximum 64 positions (8x8 display). Every position has an (x,y) coordinate.
int snakeLength = 3; // number of dots in the snake
int snakeVector [2] = {1,0}; 
int nextSnakeVector [2] = {1,0}; 
int target [2];

void setup(){
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);

  //Serial.begin(9600);

  Entropy.Initialize();
  
  target[0] = Entropy.random(0,8);
  target[1] = Entropy.random(0,8);
  
  //reset all register pins
  clearRegisters();
  
}               

//set all register pins to LOW
void clearRegisters(){
  for(int i = 7; i >=  0; i--){
     setRegisterPin(i, LOW);
  }

  for(int i = 15; i >=  8; i--){
     setRegisterPin(i, HIGH);
  }
  writeRegisters();
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

void loop() {
  if (gameOver) {
    //scroll "game over" text
    textLoop();
  } else {
    //still in game
    snakeLoop();
  }
}

/*
 * Determine which vector the joystick position results in
 */ 
byte determineVector () {
  int xAxis = analogRead (XAXIS_Pin); //0-1023
  int yAxis = analogRead (YAXIS_Pin); //0-1023

  /*
  Serial.print("xAxis: ");
  Serial.print(xAxis);
  Serial.print(", yAxis: ");
  Serial.println(yAxis);
  */
  
  if (xAxis < 10) { //up
    if (snakeVector [1] != 1) {
      nextSnakeVector [0] = 0;
      nextSnakeVector [1] = -1;
    }
  } else if (xAxis > 1010) { //down
    if (snakeVector [1] != -1) {
      nextSnakeVector [0] = 0;
      nextSnakeVector [1] = 1;
    }
  } else if (yAxis < 10) { //right
    if (snakeVector [0] != -1) {
      nextSnakeVector [0] = 1;
      nextSnakeVector [1] = 0;
    }
  } 
  else if (yAxis > 1010) { //left 
    if (snakeVector [0] != 1) {
      nextSnakeVector [0] = -1;
      nextSnakeVector [1] = 0;
    }
  }
}

void snakeLoop () {
  //determine vector
  determineVector ();

  loops++;

  //every maxLoops tix: lengthen or move snake
  if (loops > maxLoops) {
    loops = 0;

    // if the head touches the target, do not move but instead lengthen the snake and get a new target
    if ((target[0] == snake [snakeLength-1][0]) && (target[1] == snake [snakeLength-1][1])) {
      // lengthen the snake
      snakeLength ++; 
      maxLoops = 60 - (snakeLength/2);
      // get a new target
      target[0] = Entropy.random(0,8);
      target[1] = Entropy.random(0,8);
    } else {
      // move the snake
      for (int i=0; i<(snakeLength-1); i++) { //copy all existing snake parts except for the tail (first one)
        snake [i][0] = snake [i+1][0];
        snake [i][1] = snake [i+1][1];
      }
    }

    snakeVector [0] = nextSnakeVector [0];
    snakeVector [1] = nextSnakeVector [1];
    
    // insert a new head
    snake [snakeLength-1][0] = (snake [snakeLength-2][0]) + snakeVector [0];
    snake [snakeLength-1][1] = (snake [snakeLength-2][1]) + snakeVector [1];

    /*
    Serial.print ("new head: (x: ");
    Serial.print (snake [snakeLength-1][0]);
    Serial.print (", y: ");
    Serial.print (snake [snakeLength-1][1]);
    Serial.print ("), snake length: ");
    Serial.print (snakeLength);
    Serial.println ();
    */
    //delay(1000);
    
    // if the head is offscreen, you die.
    if (snake [snakeLength-1][0] < 0 || snake [snakeLength-1][0] > 7 || snake [snakeLength-1][1] < 0 || snake [snakeLength-1][1] > 7) {
       gameOver = true;
       messageString = messageString + "Boem... ";
    }

    
    // collision detection of the new head with existing body parts
    for (int snakeParts = 0; snakeParts < snakeLength-1; snakeParts++) {
      if ((snake[snakeParts][0] == snake [snakeLength-1][0]) && (snake[snakeParts][1] == snake [snakeLength-1][1])) {
        gameOver = true;
        messageString = messageString + "Auw... ";
      }
    }

  }

  //print snake
  if (!gameOver) {
    printSnake (loops<(maxLoops / 2));
  } else { //game over
    maxLoops = 15; //30 voor tragere tekst
    loops = 0;
    messageString = messageString + snakeLength + " punten.    Druk reset...        ";
  }
}


void printSnake (boolean drawTarget) {
  //loop through screen columns & draw
  for (int printedColumn = 0; printedColumn < 8; printedColumn++) {
    clearRegisters();   
    setRegisterPin(printedColumn+8, LOW);
    //Serial.print ("Printed Column (x): ");
    //Serial.print (printedColumn);
            
    for (int snakeParts = 0; snakeParts < snakeLength; snakeParts++) {
      if (snake[snakeParts][0] == printedColumn) {
        /*
        Serial.print (" Snake on row (y): ");
        Serial.print (snake[snakeParts][1]);
        Serial.print (", ");
        */
        setRegisterPin(snake[snakeParts][1],HIGH);
      } 
    }
    
    if (drawTarget && target[0] == printedColumn) {
      setRegisterPin(target[1],HIGH);
    }
    
    //Serial.println();        
    writeRegisters();
  }
  
}



int firstDisplayedColumn = 0;
int displayedCharacterIndex = 0; //index of the first character in the string that is being displayed
int displayedCharacterColumnIndex = 0; //every char has different columns (determined in asciiLengths). This keeps track of the column that is first displayed.

void textLoop(){
  int activeCharacterIndex = displayedCharacterIndex;
  char activeCharacter;
  int activeColumnIndex = displayedCharacterColumnIndex;
  int activeColumn;
  int printedColumn = 0;
  
  do {
    //find a column to print
    activeColumn = -1;
    if (messageString [activeCharacterIndex] == '\0') {
      activeCharacterIndex = 0;
    }
    activeCharacter = messageString [activeCharacterIndex];
 
    if (activeColumnIndex == getCharacterLength(activeCharacter)) { //puts 1 space after the character
      activeColumn = B00000000; 
      activeColumnIndex++;
    } else if (activeColumnIndex > getCharacterLength(activeCharacter)) { //we skip to the next character; do nothing this loop
      activeCharacterIndex++;
      activeColumnIndex = 0;
    } else { //pick the correct (active) column from the character
      activeColumn = asciiChars [activeCharacter] [activeColumnIndex++];
    }

    if (activeColumn >=0) {
      clearRegisters();
      setRegisterPin(printedColumn+8, LOW); //activate column 
      byte mask = 1;
      for (int j = 7; j >= 0; j--) {

        if ((activeColumn & mask) > 0) {  
          setRegisterPin(j, HIGH); //activate all relevant rows in the column
        } 
      
        mask = mask << 1;
      }
      writeRegisters();
      printedColumn++;
    }
  } while (printedColumn < 8);
  
  loops++;
    
  if (loops > maxLoops) {
    scrollText();
    loops = 0;
  }
}

void scrollText() {
  displayedCharacterColumnIndex++;
  
  //skip to next character. skip to front if needed
  if (displayedCharacterColumnIndex > getCharacterLength (messageString[displayedCharacterIndex])) {
    displayedCharacterColumnIndex = 0;         
    displayedCharacterIndex++;
    if (messageString [displayedCharacterIndex] == '\0') {
      displayedCharacterIndex = 0;
    }
  } 
  
  //skip to previous character; no skipping to back of message.
  else if (displayedCharacterColumnIndex < 0) {
    displayedCharacterIndex--;
    if (displayedCharacterIndex < 0) {
      displayedCharacterIndex = 0;
      displayedCharacterColumnIndex = 0;
    } else {
      displayedCharacterColumnIndex = getCharacterLength (messageString [displayedCharacterIndex]);
    }  
  }

}

int getCharacterLength (char character) {
    return asciiLengths[character];
}


