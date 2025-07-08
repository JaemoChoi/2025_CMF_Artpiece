#include <Adafruit_NeoPixel.h>
#ifdef __AVR__

#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif
#define LED_PIN 4
#define NUM_LEDS 62

uint8_t LIGHT_MODE = 0;

const byte SW = 2;

int State = 0;  // OFF

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 100;

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);


  pinMode(SW, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SW), SW_ISR, LOW);
  strip.begin();
  strip.show();
  strip.setBrightness(255);
}

void loop() {

  if (State == 1) {
   setAll(0, 165, 255, 0);
  }
  if (State == 0) {
    setAll(0, 0, 0, 0);
  }
}

// Debounce Key Interrupt Input //
void SW_ISR() {
  unsigned long currentTime = millis();

  if ((currentTime - lastDebounceTime) > debounceDelay) {
    State = 1 - State;
    Serial.println(State);
    lastDebounceTime = currentTime;
  }
}
