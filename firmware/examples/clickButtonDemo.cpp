/* ClickButton library demo

  OUtput a message on Serial according to different clicks on one button.
  
  Short clicks:

    Single click - 
    Double click - 
    Triple click - 
    
  Long clicks (hold button for one second or longer on last click):
    
    Single LONG click - 
    Double LONG click - 
    Triple LONG click -
    
    button2 will report release

  2010, 2013 raron
 
 GNU GPLv3 license
*/
#include "clickButton/clickButton.h"

// the Button
const int buttonPin1 = 0;
const int buttonPin2 = 1;
//ClickButton button1(buttonPin1, LOW, CLICKBTN_PULLUP);
ClickButton button1(buttonPin1, HIGH, CLICKBTN_PULLDOWN, false);
ClickButton button2(buttonPin2, LOW, CLICKBTN_PULLUP, true);

// Button results 
int function = 0;
int function2 = 0;


void setup()
{
  Serial.begin(9600);
  //pinMode(D0, INPUT_PULLUP);
  pinMode(D0, INPUT);

  // Setup button timers (all in milliseconds / ms)
  // (These are default if not set, but changeable for convenience)
  button1.debounceTime   = 20;   // Debounce timer in ms
  button1.multiclickTime = 250;  // Time limit for multi clicks
  button1.longClickTime  = 1000; // time until "held-down clicks" register
}


void loop()
{
  // Update button state
  button1.Update();
  button2.Update();

  // Save click codes in LEDfunction, as click codes are reset at next Update()
  if(button1.clicks != 0) function = button1.clicks;
  
  if(function == 1) Serial.println("SINGLE click 1");

  if(function == 2) Serial.println("DOUBLE click 1");

  if(function == 3) Serial.println("TRIPLE click 1");

  if(function == -1) Serial.println("SINGLE LONG click 1");

  if(function == -2) Serial.println("DOUBLE LONG click 1");

  if(function == -3) Serial.println("TRIPLE LONG click 1");
  
  if(function >= 100){
    Serial.print("Release 1: ");
     Serial.println(function);
  }
  
  function = 0;
  
  if(button2.clicks != 0) function2 = button2.clicks;
  
  if(function2 == 1) Serial.println("SINGLE click 2");

  if(function2 == 2) Serial.println("DOUBLE click 2");

  if(function2 == 3) Serial.println("TRIPLE click 2");

  if(function2 == -1) Serial.println("SINGLE LONG click 2");

  if(function2 == -2) Serial.println("DOUBLE LONG click 2");

  if(function2 == -3) Serial.println("TRIPLE LONG click 2");
  
  if(function2 >= 100){
    Serial.print("Release 2: ");
     Serial.println(function2);
  }
  
  function2 = 0;
  delay(5);
}
