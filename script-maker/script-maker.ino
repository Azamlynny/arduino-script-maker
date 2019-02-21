#include <Mouse.h>
#include <Keyboard.h>
#include <Keypad.h>

const byte SW_pin = 13; // digital pin connected to switch output
const byte X_pin = 0; // analog pin connected to X output
const byte Y_pin = 1; // analog pin connected to Y output

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'a','b','c','d'},
  {'e','f','g','h'},
  {'i','j','k','l'},
  {'m','n','o','p'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

boolean recording = true;
short displacementX = 0;
short displacementY = 0;

byte movey[500] = {}; // Fills up with 0

byte movex[500] = {}; // Fills up with 0
byte instructionIndex = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(SW_pin, INPUT);
//  digitalWrite(SW_pin, HIGH);
  Mouse.begin();
  Keyboard.begin();
}

void loop() {
  char customKey = customKeypad.getKey();

  if(customKey == 'p'){
      recording = false;
  }
  if(customKey == 'o'){
      recording = true;
  }

for(int i =0; i < 500; i++){
    short x = ((analogRead(X_pin) - 512)) / 64;
    short y = ((analogRead(Y_pin) - 512)) / 64;
    Mouse.move(x, y);

    delay(20);

    movex[i] = x;
        movey[i] = y;

}

    for(int i = 0; i < 500; i++){
      
      
        Mouse.move(movex[i], movey[i]);
//      if(instructions[i] == 12){
//        Mouse.click();      
//      }
//      if(instructions[i] == 8){
//        delay(1000);
//      }
//      if(instructions[i] == 4){
//        instructionIndex = 0;
//        for(int i = 0; i < 100; i++){
//          instructions[i] = 0;
//        }
//        break;
//      }
      delay(20);
    }

 
  
}
