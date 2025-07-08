void showstrip() {

  strip.show();
}

void setPixel(int Pixel, byte red, byte green, byte blue, byte white) {

  strip.setPixelColor(Pixel, strip.Color(red, green, blue, white));
}

void setAll(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < NUM_LEDS; i++) {
    setPixel(i, red, green, blue, white);
  }
  showstrip();
}

void showstrip_bot() {

  strip_bot.show();
}

void setPixel_bot(int Pixel, byte red, byte green, byte blue, byte white) {

  strip_bot.setPixelColor(Pixel, strip_bot.Color(red, green, blue, white));
}

void setAll_bot(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < NUM_LEDS; i++) {
    setPixel_bot(i, red, green, blue, white);
  }
  showstrip_bot();
}