void showStrip() {

  strip.show();
}

void setPixel(int Pixel, byte red, byte green, byte blue, byte white) {

  strip.setPixelColor(Pixel, strip.Color(red, green, blue, white));
}

void setAll(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < NUM_LEDS; i++) {
    setPixel(i, red, green, blue, white);
  }
  showStrip();
}

void meteorRain(byte red, byte green, byte blue, byte white, byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay, int SpeedDelay) {
  setAll(0, 0, 0, 0);

  for (int i = 0; i < NUM_LEDS + NUM_LEDS; i++) {


    // fade brightness all LEDs one step
    for (int j = 0; j < NUM_LEDS; j++) {
      if ((!meteorRandomDecay) || (random(10) > 5)) {
        fadeToBlack(j, meteorTrailDecay);
      }
    }

    // draw meteor
    for (int j = 0; j < meteorSize; j++) {
      if ((i - j < NUM_LEDS) && (i - j >= 0)) {
        setPixel(i - j, red, green, blue, white);
      }
    }

    showStrip();
    delay(SpeedDelay);
  }
}

void fadeToBlack(int ledNo, byte fadeValue) {
  uint32_t oldColor;
  uint8_t r, g, b;
  int value;

  oldColor = strip.getPixelColor(ledNo);
  r = (oldColor & 0x00ff0000UL) >> 16;
  g = (oldColor & 0x0000ff00UL) >> 8;
  b = (oldColor & 0x000000ffUL);

  r = (r <= 10) ? 0 : (int)r - (r * fadeValue / 256);
  g = (g <= 10) ? 0 : (int)g - (g * fadeValue / 256);
  b = (b <= 10) ? 0 : (int)b - (b * fadeValue / 256);

  strip.setPixelColor(ledNo, r, g, b);
}

/*
void kitt2_dim(int red, int green, int blue, int white) {

  for (int i = 0; i < 34; i++) {
    for (float bright = 0; bright < 256; bright = bright + 20) {

      strip_bot.setPixelColor(34 - i, strip.Color(red * (bright / 255), green * (bright / 255), (blue / (i*0.1 + 1)) * (bright / 255), (white / (i * 1 + 1)) * (bright / 255)));
      strip_bot.setPixelColor(34 + i, strip.Color(red * (bright / 255), green * (bright / 255), (blue / (i*0.1 + 1)) * (bright / 255), (white / (i * 1 + 1)) * (bright / 255)));
      strip.setPixelColor(34 - i, strip_bot.Color(255 * (bright / 255), 255 * (bright / 255), 255 * (bright / 255), 255 * (bright / 255)));
      strip.setPixelColor(34 + i, strip_bot.Color(255 * (bright / 255), 255 * (bright / 255), 255 * (bright / 255), 255 * (bright / 255)));

      strip.show();
      strip_bot.show();

      if ((Break_flag == 1) || (State_flag == 1)) {
          strip.clear();
          strip.show();
          strip_bot.clear();
          strip_bot.show();
          Break_flag = 0;
          State_flag = 0;
          return;
        }
    }
  }
}
*/
