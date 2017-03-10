#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 50
#define DATA_PIN    5
#define BRIGHTNESS  128

int val;

// Define the array of leds
CRGB leds[NUM_LEDS];


void setup() { 
      Serial.begin(9600);
      delay(3000);
      //FastLED.addLeds(leds, NUM_LEDS);
      FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
      FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  if (Serial.available()) {            // If data is available,  
    val = Serial.read();               // read it and store it in val
    Serial.println(val); 
  } 
  
  fill_solid( leds, NUM_LEDS, CRGB::Black);
  
  if (val >= 0 && val <= 50){          
  leds[val] = CRGB::Red; 
  FastLED.show(); 
  }
}
