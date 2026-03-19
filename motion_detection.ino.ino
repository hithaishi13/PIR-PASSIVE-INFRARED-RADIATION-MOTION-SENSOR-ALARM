#include <LiquidCrystal_I2C.h> 
#include <Wire.h> 
int motion=0; 
int pirpin=8; 
int buzzpin=10; 
// Initialize the liquid crystal library 
// First parameter: I2C address 
// Second parameter: columns 
// Third parameter: rows 
LiquidCrystal_I2C lcd(0x27, 16, 2); 
void setup() { 
// Initialize LCD screen 
lcd.init(); 
// Turn on the backlight 
lcd.backlight(); 
pinMode(buzzpin,OUTPUT); 
pinMode(pirpin,INPUT); 
} 
void loop() { 
// Wait for a second 
motion=digitalRead(pirpin); 
if(motion==HIGH) 
{ 
digitalWrite(buzzpin,HIGH); 
lcd.setCursor(0, 0); 
// Print message on top row 
Dept. of CSE,SJBIT                                                                                                             
15 
2024-2025 
PIR MOTION SENSOR ALARM                                                               
      IMPLEMENTATION 
lcd.print("Motion Detected"); 
//  delay(1000); 
} 
else 
{ 
digitalWrite(buzzpin,LOW); 
lcd.setCursor(0, 0); 
// Print message on bottom row 
lcd.print("Not Detected"); 
} 
// Set cursor to top row, first column 
// Set cursor to bottom row, first column 
}