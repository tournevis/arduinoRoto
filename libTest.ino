#include <rotoPhone.h>

//Declare Rotophone Object
int number ;
RotoPhone roto(4,5);
int pickUp;
int lastPickUp;
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;  
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay =50;    // the debounce time; increase if the output flickers

void setup() {
  // if you use debug don't forget to init Serial
   Serial.begin(9600);
   pinMode(3,INPUT_PULLUP);
   pinMode(2,INPUT_PULLUP);
  pickUp = digitalRead(3);
  lastPickUp = pickUp;
}
void loop() {
  number = roto.number();
  if(number>= 0){
    Serial.println(number-1);
   // Serial.println(roto.numTime());
  }
  pickUp = digitalRead(3);
  
  if(roto.isNum()){
    Serial.println("i");
  }
  if(pickUp != 1 && lastPickUp == 1 ) {
    Serial.println("p");
  }
  if(pickUp == 1 && lastPickUp != 1 ) {
    Serial.println("r");
  }
  
  int shoot = digitalRead(2);
  
  if (shoot != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
   if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (shoot != buttonState) {
      buttonState = shoot;
       if (buttonState == LOW) {
        Serial.println("s");
      }
      // only toggle the LED if the new button state is HIGH
    }
  }

  lastButtonState = shoot;
  lastPickUp = pickUp;
  // print value on each loop
  //roto.debug();
  delay(20);
}
