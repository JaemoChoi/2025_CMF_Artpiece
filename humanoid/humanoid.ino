
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif
#define CHEST_PIN 4
#define HEAD_PIN 5

#define NUM_LEDS_CHEST 108
#define NUM_LEDS_HEAD 62

uint8_t LIGHT_MODE = 0;

#define CHEST1  4
#define CHEST2  8

int CHEST_PATTERN1[CHEST1] = { 13, 40, 67, 94};
int CHEST_PATTERN2[CHEST2] = { 12, 14, 39, 41, 66, 68, 93, 95};
int CHEST_PATTERN3[CHEST2] = { 11, 15, 38, 42, 65, 69, 92, 96};
int CHEST_PATTERN4[CHEST2] = { 10, 16, 37, 43, 64, 70, 91, 97};
int CHEST_PATTERN5[CHEST2] = {  9, 17, 36, 44, 63, 71, 90, 98};
int CHEST_PATTERN6[CHEST2] = {  8, 18, 35, 45, 62, 72, 89, 99};
int CHEST_PATTERN7[CHEST2] = {  7, 19, 34, 46, 61, 73, 88, 100};
int CHEST_PATTERN8[CHEST2] = {  6, 20, 33, 47, 60, 74, 87, 101};
int CHEST_PATTERN9[CHEST2] = {  5, 21, 32, 48, 59, 75, 86, 102};
int CHEST_PATTERN10[CHEST2] = {  4, 22, 31, 49, 58, 76, 85, 103};
int CHEST_PATTERN11[CHEST2] = {  3, 23, 30, 50, 57, 77, 84, 104};
int CHEST_PATTERN12[CHEST2] = {  2, 24, 29, 51, 56, 78, 83, 105};
int CHEST_PATTERN13[CHEST2] = {  1, 25, 28, 52, 55, 79, 82, 106};
int CHEST_PATTERN14[CHEST2] = {  0, 26, 27, 53, 54, 80, 81, 107};


// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip_chest(NUM_LEDS_CHEST, CHEST_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_head(NUM_LEDS_HEAD, HEAD_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {

  Serial.begin(9600);
  Serial2.begin(9600);  // BT serial

 LED_init();

}

// *** REPLACE FROM HERE ***
void loop() {
//dimming_ALL(10,15,255);
 //setAll_head(10, 15, 255,0);
  //xmas(13, 1000);

  // FadeOutLed(255, 255, 255, 255);
  // FadeInLed(255, 255, 255, 0);
  // FadeOutLed(0, 0, 0, 0);
  /*
  FadeOutLed(150, 20, 255, 0);
  FadeInLed(150, 20, 255, 0);
  FadeOutLed(0, 0, 0, 0);
*/
  //setAll_uv(255,255,255);
  //setAll_seq(0,0,0);

  switch (LIGHT_MODE) {
    case 1:
      //pulse_chest(10,15,255);
      dimming_ALL(10,15,255);
      //LIGHT_MODE = 99;
      break;

    case 2:
      setAll_head(10, 15, 255,0);
      LIGHT_MODE = 99;
      break;

    case 3:
      setAll_chest(0, 0, 0);
      setAll_head(0,0,0,0);
      LIGHT_MODE = 99;
      break;

    case 99:
     
      break;


    default:

      break;
  }
}

void serialEvent2() {

  uint8_t bt_command = Serial2.read();

  if (bt_command == 1) LIGHT_MODE = 1;
  if (bt_command == 2) LIGHT_MODE = 2;
  if (bt_command == 3) LIGHT_MODE = 3;


  Serial.println(bt_command);
}
