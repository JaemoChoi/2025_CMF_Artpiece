void FadeInOut(byte red, byte green, byte blue, byte white) {
  float r, g, b, w;

  for (int k = 0; k < 256; k = k + 2) {
    r = (k / 256.0) * red;
    g = (k / 256.0) * green;
    b = (k / 256.0) * blue;
    w = ((255-k) / 256.0) * white;
    setAll_bot3(r, g, b, w);
    showStrip_bot();
    //delay(1);
  }

  for (int k = 0; k < 256; k = k + 2) {
    r = (k / 256.0) * red;
    g = (k / 256.0) * green;
    b = (k / 256.0) * blue;
    w = ((255-k) / 256.0) * white;
    setAll_bot4(r, g, b, w);
    showStrip_bot();
    //delay(1);
  }

  for (int k = 0; k < 256; k = k + 2) {
    r = (k / 256.0) * red;
    g = (k / 256.0) * green;
    b = (k / 256.0) * blue;
    w = ((255-k) / 256.0) * white;
    setAll_bot5(r, g, b, w);
    showStrip_bot();
    //delay(1);
  }

  for (int k = 255; k >= 0; k = k - 4) {
    r = (k / 256.0) * red;
    g = (k / 256.0) * green;
    b = (k / 256.0) * blue;
    w = ((255-k) / 256.0) * white;
    setAll_bot5(r, g, b,w);
    showStrip_bot();
    //delay(1);
  }

  for (int k = 255; k >= 0; k = k - 4) {
    r = (k / 256.0) * red;
    g = (k / 256.0) * green;
    b = (k / 256.0) * blue;
    w = ((255-k) / 256.0) * white;
    setAll_bot4(r, g, b,w);
    showStrip_bot();
    //delay(1);
  }

  for (int k = 255; k >= 0; k = k - 4) {
    r = (k / 256.0) * red;
    g = (k / 256.0) * green;
    b = (k / 256.0) * blue;
    w = ((255-k) / 256.0) * white;
    setAll_bot3(r, g, b,w);
    showStrip_bot();
    //delay(1);
  }
}

void setAll_bot3(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < 55; i++) {
    setPixel_bot(i, red, green, blue, white);
  }
  showStrip_bot();
}

void setAll_bot4(byte red, byte green, byte blue, byte white) {
  for (int i = 55; i < 110; i++) {
    setPixel_bot(i, red, green, blue, white);
  }
  showStrip_bot();
}

void setAll_bot5(byte red, byte green, byte blue, byte white) {
  for (int i = 110; i < 165; i++) {
    setPixel_bot(i, red, green, blue, white);
  }
  showStrip_bot();
}


void showStrip_front() {

  strip_front.show();
}

void showStrip_bot() {

  strip_bot.show();
}


void setPixel_front(int Pixel, byte red, byte green, byte blue, byte white) {

  strip_front.setPixelColor(Pixel, strip_front.Color(red, green, blue, white));
}

void setPixel_bot(int Pixel, byte red, byte green, byte blue, byte white) {

  strip_bot.setPixelColor(Pixel, strip_bot.Color(red, green, blue, white));
}



void setAll_front(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < FRONT_NUM_LEDS; i++) {
    setPixel_front(i, red, green, blue, white);
  }
  showStrip_front();
}

void setAll_bot2(byte red, byte green, byte blue, byte white) {
  for (int bright = 0; bright < 256; bright=bright+1) {
    for (int i = 0; i < 55; i++) {
      setPixel_bot(i, red * (bright/255), green * (bright/255), blue * (bright/255), white * (bright/255));
    }
    showStrip_bot();
  }
   
  for (int bright = 0; bright < 256; bright=bright+1) {
    for (int i = 55; i < 110; i++) {
      setPixel_bot(i, red * (bright/255), green * (bright/255), blue * (bright/255), white * (bright/255));
    }
    showStrip_bot();
  }

  for (int bright = 0; bright < 256; bright=bright+1) {
    for (int i = 110; i < 165; i++) {
      setPixel_bot(i, red * (bright/255), green * (bright/255), blue * (bright/255), white * (bright/255));
    }
    showStrip_bot();
  }

}

void setAll_bot(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < BOT_NUM_LEDS; i++) {
    setPixel_bot(i, red, green, blue, white);
  }
  showStrip_bot();
}

void FadeOutLed_front(int red, int green, int blue, int white) {

  for (float bright = 255; bright < 256; bright++) {

    for (int i = 0; i < strip_front.numPixels(); i++) {
      for (int16_t time = 0; time < 5; time++) {
        strip_front.setPixelColor(i, strip_front.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255), white * (bright / 255)));
      }
    }
    strip_front.show();
  }
}

void FadeInLed_front(byte red, byte green, byte blue, byte white) {

  for (float bright = 255; bright > -1; bright--) {

    for (int i = 0; i < strip_front.numPixels(); i++) {
      for (int16_t time = 0; time < 5; time++) {
        strip_front.setPixelColor(i, strip_front.Color(red * (bright / 255), green * (bright / 255), blue * (bright / 255), white * (bright / 255)));
      }
    }
    strip_front.show();
  }
}

void LED_init() {

  strip_front.begin();
  strip_front.show();

  strip_bot.begin();
  strip_bot.show();

  strip_front.setBrightness(255);
  strip_bot.setBrightness(255);
}
