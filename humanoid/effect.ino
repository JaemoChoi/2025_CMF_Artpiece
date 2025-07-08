
void showStrip_chest() {

  strip_chest.show();
}

void showStrip_head() {

  strip_head.show();
}

void setPixel_chest(int Pixel, byte red, byte green, byte blue) {

  strip_chest.setPixelColor(Pixel, strip_chest.Color(red, green, blue));
}

void setPixel_head(int Pixel, byte red, byte green, byte blue, byte white) {

  strip_head.setPixelColor(Pixel, strip_head.Color(red, green, blue, white));
}

void setAll_chest(byte red, byte green, byte blue) {
  for (int i = 0; i < NUM_LEDS_CHEST; i++) {
    setPixel_chest(i, red, green, blue);
  }
  showStrip_chest();
}

void setAll_head(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < NUM_LEDS_HEAD; i++) {
    setPixel_head(i, red, green, blue, white);
  }
  showStrip_head();
}



void FadeOutLed_chest(int red, int green, int blue) {

  for (float bright = 255; bright < 256; bright++) {

    for (int i = 0; i < strip_chest.numPixels(); i++) {
      for (int16_t time = 0; time < 5; time++) {
        strip_chest.setPixelColor(i, strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
         }
    }
    strip_chest.show();
    }
}

void FadeInLed_chest(byte red, byte green, byte blue) {

  for (float bright = 255; bright > -1; bright--) {

    for (int i = 0; i < strip_chest.numPixels(); i++) {
      for (int16_t time = 0; time < 5; time++) {
        strip_chest.setPixelColor(i, strip_chest.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255)));
         }
    }
    strip_chest.show();
    
  }
}

void LED_init() {

  strip_chest.begin();
  strip_chest.show();

  strip_head.begin();
  strip_head.show();

  strip_chest.setBrightness(100);
  strip_head.setBrightness(100);
 
}
