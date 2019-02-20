#include <Mouse.h>
#include <Keyboard.h>
#include <Keypad.h>

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
double xMoves[200] = {};
double yMoves[200] = {};


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
  // put your setup code here, to run once:
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Mouse.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  char customKey = customKeypad.getKey();
  
  for(int i = 0; i < 200; i++){
    double x = (analogRead(X_pin) - 512)/64;
    double y = (analogRead(Y_pin) - 512)/64;
    Mouse.move(x, y);
    delay(20);
    if(x != 0 && y != 0){
    xMoves[i] = x;
    yMoves[i] = y;
    }
  }
  for(int i = 0; i < 200; i++){
     Mouse.move(xMoves[i], yMoves[i]);
     delay(5);
  }

  Keyboard.print(customKey);
}
