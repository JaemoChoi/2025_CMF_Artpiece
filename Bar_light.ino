void showstrip_front() {

  strip_front.show();
}

void showstrip_bot() {

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
  showstrip_front();
}

void setAll_front_dim(byte red, byte green, byte blue, byte white) {
  for (int i = 1; i < 100; i++) {
    int bright = map(i,1,137,1,40);
      setPixel_front(i-1, red/bright , green/bright , blue/bright , white/bright );
      showstrip_front();
      delay(20);
  }

   for (int i = 100; i < 137; i++) {
    red = 200;
    green = 30;
    blue = 50;
    white = 100;
    int bright = map(i,1,137,40,1);
      setPixel_front(i-1, red/bright , green/bright , blue/bright , white/bright );
      showstrip_front();
      delay(20);
  }
}



void setAll_bot(byte red, byte green, byte blue, byte white) {
  for (int i = 0; i < BOT_NUM_LEDS; i++) {
    setPixel_bot(i, red, green, blue, white);
  }
  showstrip_bot();
}



void LED_init() {

  strip_front.begin();
  strip_front.show();

  strip_bot.begin();
  strip_bot.show();

  strip_front.setBrightness(100);
  strip_bot.setBrightness(255);
}

void meteorRain(byte red, byte green, byte blue, byte white, byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay, int SpeedDelay) {
  setAll_bot(0, 0, 0, 0);

  for (int i = 0; i < FRONT_NUM_LEDS + FRONT_NUM_LEDS; i++) {


    // fade brightness all LEDs one step
    for (int j = 0; j < FRONT_NUM_LEDS; j++) {
      if ((!meteorRandomDecay) || (random(10) > 5)) {
        fadeToBlack(j, meteorTrailDecay);
      }
    }

    // draw meteor
    for (int j = 0; j < meteorSize; j++) {
      if ((i - j < FRONT_NUM_LEDS) && (i - j >= 0)) {
        setPixel_bot(i - j, red, green, blue, white);
      }
    }

    showstrip_bot();
    delay(SpeedDelay);
  }
}

void fadeToBlack(int ledNo, byte fadeValue) {
  uint32_t oldColor;
  uint8_t r, g, b;
  int value;

  oldColor = strip_bot.getPixelColor(ledNo);
  r = (oldColor & 0x00ff0000UL) >> 16;
  g = (oldColor & 0x0000ff00UL) >> 8;
  b = (oldColor & 0x000000ffUL);

  r = (r <= 10) ? 0 : (int)r - (r * fadeValue / 256);
  g = (g <= 10) ? 0 : (int)g - (g * fadeValue / 256);
  b = (b <= 10) ? 0 : (int)b - (b * fadeValue / 256);

  strip_bot.setPixelColor(ledNo, r, g, b);
}

void Fire(int Cooling, int Sparking, int SpeedDelay) {
  static byte heat[BOT_NUM_LEDS];
  int cooldown;
 
  // Step 1.  Cool down every cell a little
  for( int i = 0; i < BOT_NUM_LEDS; i++) {
    cooldown = random(0, ((Cooling * 10) / BOT_NUM_LEDS) + 2);
   
    if(cooldown>heat[i]) {
      heat[i]=0;
    } else {
      heat[i]=heat[i]-cooldown;
    }
  }
 
  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for( int k= BOT_NUM_LEDS - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
  }
   
  // Step 3.  Randomly ignite new 'sparks' near the bottom
  if( random(255) < Sparking ) {
    int y = random(7);
    heat[y] = heat[y] + random(160,255);
    //heat[y] = random(160,255);
  }

  // Step 4.  Convert heat to LED colors
  for( int j = 0; j < BOT_NUM_LEDS/3; j++) {
    setPixelHeatColor(j, heat[j] );
  }

  showstrip_bot();
  delay(SpeedDelay);
}

void setPixelHeatColor (int Pixel, byte temperature) {
  // Scale 'heat' down from 0-255 to 0-191
  byte t192 = round((temperature/255.0)*191);
 
  // calculate ramp up from
  byte heatramp = t192 & 0x3F; // 0..63
  heatramp <<= 2; // scale up to 0..252
 
  // figure out which third of the spectrum we're in:
  if( t192 > 0x80) {                     // hottest
    setPixel_bot(Pixel, heatramp, 255,255,50 );
  } else if( t192 > 0x40 ) {             // middle
    setPixel_bot(Pixel, 0, heatramp, 255,50);
  } else {                               // coolest
    setPixel_bot(Pixel, 0, 0, heatramp,50);
  }
}
