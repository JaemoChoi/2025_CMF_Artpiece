
 //   setAll_front1(149, 184, 217, 0);
 //   setAll_front2(255, 130, 70, 0);



#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif
#define FRONT_LED_PIN 4
#define FRONT_NUM_LEDS 12
#define SPEED 0.002
uint8_t LIGHT_MODE = 0;

const byte SW = 3;

int State = 1;  // OFF

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 100;

Adafruit_NeoPixel strip_front(FRONT_NUM_LEDS, FRONT_LED_PIN, NEO_GRBW + NEO_KHZ800);

// 색상 정의 (핑크 -> 라이트 블루)
uint8_t startColor[3] = {255, 120, 60}; // Pink
uint8_t endColor[3]   = {149, 184, 217}; // Light Blue


float offset = 0; // 물결의 진행 상태

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(SW, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SW), SW_ISR, LOW);

  LED_init();
    setAll_front(0, 0, 0, 0);
}

void loop() {

  if (State == 1) {
    Serial.println("VD bar MODE 1");
    //FadeInOut(255, 255, 255,100);
    setAll_front1(149, 184, 217, 0);
    delay(3000);
   // setAll_front(0, 0, 0, 0);
    setAll_front2(255, 80, 20, 0);
    delay(3000);
 
  //  for (uint16_t c = 0 ; c < 500; c++) {
    //  cmf_color();
  //  }

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

void cmf_color() {

  for (int i = 0; i < FRONT_NUM_LEDS; i++) {
    // 각 LED마다 시간차를 주기 위해 위치 기반 오프셋 추가
    float phase = offset + (float)i / FRONT_NUM_LEDS;

    // 0~1 범위에서 반복 (사인파로 자연스럽게)
    float t = (sin(phase * 2 * PI) + 1) / 2;

    // 색 보간
    uint8_t r = (1 - t) * startColor[0] + t * endColor[0];
    uint8_t g = (1 - t) * startColor[1] + t * endColor[1];
    uint8_t b = (1 - t) * startColor[2] + t * endColor[2];

    strip_front.setPixelColor(i, strip_front.Color(r * 0.3, g * 0.3, b * 0.3, 0));
  }
  strip_front.show();

  // 물결 진행
  offset += SPEED;
  if (offset > 1) offset -= 1; // 값이 너무 커지지 않게

}
