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

byte instructionIndex = 0;
double displacementX = 0;
double displacementY = 0;
int index = 0;
const int instructionSize = 100;
boolean moveOrType[instructionSize] = {false}; // true means move
char type[instructionSize] = {0};
double x[instructionSize] = {0};
double y[instructionSize] = {0};
int tempIndex = 0;

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
      tempIndex = 0;
  }
  if(customKey == 'o'){
      recording = true;
  }

  if(recording){
    short xM = ((analogRead(X_pin) - 512)) / 64;
    short yM = ((analogRead(Y_pin) - 512)) / 64;
    Mouse.move(xM, yM);
    displacementX += xM;
    displacementY += yM;
    delay(20);

    if(customKey > 95){
      if(displacementX != 0 || displacementY !=0){
        x[index] =  displacementX;
        y[index] = displacementY;
        moveOrType[index] = true;
        index++;
        displacementX = 0;
        displacementY = 0;
      }
      type[index] = customKey;
      index++;
      if(customKey == 'a'){
        a();
      }
      else if(customKey == 'b'){
        b();
      }
      else if(customKey == 'c'){
        c();
      }
      else if(customKey == 'd'){
        d();  
      }
      else if(customKey == 'e'){
        e();
      }
      else if(customKey == 'f'){
        f();
      }
      else if(customKey == 'g'){
        g();
      }
      else if(customKey == 'h'){
        h();
      }
      else if(customKey == 'i'){
        i();
      }
      else if(customKey == 'j'){
        j();
      }
      else if(customKey == 'k'){
        k();
      }
      else if(customKey == 'l'){
        l();
      }
      else if(customKey == 'm'){
        m();
      }
      else if(customKey == 'n'){
        n();
      }
      if(customKey == 'o'){ // Escape function
      recording = true;
      }
    }
  }

  if(recording == false){
    for(int o = 0; o < instructionSize; o++){
      if(moveOrType[o]){
        for(int i = 0; i < 10; i++){
          Mouse.move(x[o] / 10, y[o] / 10);
          delay(10);
        }
      }
      else{
          customKey = type[o];
          if(customKey == 'a'){
          a();
        }
        else if(customKey == 'b'){
          b();
        }
        else if(customKey == 'c'){
          c();
        }
        else if(customKey == 'd'){
          d();  
        }
        else if(customKey == 'e'){
          e();
        }
        else if(customKey == 'f'){
          f();
        }
        else if(customKey == 'g'){
          g();
        }
        else if(customKey == 'h'){
          h();
        }
        else if(customKey == 'i'){
          i();
        }
        else if(customKey == 'j'){
          j();
        }
        else if(customKey == 'k'){
          k();
        }
        else if(customKey == 'l'){
          l();
        }
        else if(customKey == 'm'){
          m();
        }
        else if(customKey == 'n'){
          n();
        }
      }

      delay(50);
    }
    recording = true;
  }
    
}

void a(){

}
void b(){

}
void c(){

}
void d(){

}
void e(){

}
void f(){

}
void g(){

}
void h(){

}
void i(){

}
void j(){

}
void k(){

}
void l(){

}
void m(){
  Mouse.click();
}
void n(){

}
