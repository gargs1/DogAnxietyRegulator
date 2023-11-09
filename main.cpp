int speaker = 9; //the pin that the LED is attached to
const int sensor = 2; // the pin that the sensor is attached to
int state = 0; // by default, no motion detected
int val = 1;
#define SD_ChipSelectPin 4 // MicroSD card adapter connected to Pin 4
#include "SD.h"      //SD Card Library - Play WAV files with microSD card and Arduino
#include "TMRpcm.h"  // Creating a TMRpcm object
#include "SPI.h"    // SPI Library
TMRpcm tmrpcm

void setup() { // initialization
  tmrpcm.speakerPin = 9;
  Serial.begin(9600);  // Start serial communication
  if(!SD.begin(SD_ChipSelectPin)) { // if initialization unsuccessful, print SD fail
    Serial.println("SD fail");
    return;
  }
  
  pinMode(speaker, OUTPUT); 
  pinMode(sensor, INPUT);

void loop() {
  val = digitalRead(sensor); // read sensor value
  Serial.println(val); // Print sensor value (binary) 
  if(val == 0) { // If val 0, check if sensor is equal to the HIGH state
    Serial.println("Dog barking detected"); //print message in serial monitor 
state = 1; // change state to 1 
tmrpcm.play("AAA.wav"); // play owner message audio file
delay(2800); // delay 2800 milliseconds
state = 0; // audio file done, state back to LOW
if(state == 0) {  // if owner file finished, play music
  Serial.println("Message from owner stopped!"); // print message
  tmrpcm.play("CCC.wav"); // play calming music file
    }
  }
}
        
