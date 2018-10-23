#include <Adafruit_NeoPixel.h>

#define PIN 6       //信号端子のピン番号
#define LED_NUM 50  //LEDの数

const int vol_pin = 1;
int vol_value = 0;
int a;

Adafruit_NeoPixel ledtape = Adafruit_NeoPixel(LED_NUM, PIN, NEO_GRB + NEO_KHZ800);  //3つめのパラメータは使うLEDテープの制御ICがWS2812ならNEO_KHZ800 / WS2811ならNEO_KHZ400

void setup() {
  Serial.begin(9600);
  ledtape.begin();
  ledtape.show();   //一旦全てOFFの状態で反映
}

void loop() {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    vol_value = analogRead(vol_pin);
    Serial.println(vol_value);
    a = vol_value;


    if (a < 900) {
      for (i = 0; i < ledtape.numPixels(); i++) {
        ledtape.setPixelColor(i, rotateColor((((i) * 256 / ledtape.numPixels()) + j) & 255));
      }
    }
    if (a > 900) {
      for (i = 0; i < ledtape.numPixels(); i++) {
        ledtape.setPixelColor(i, kesu((((i) * 256 / ledtape.numPixels()) + j) & 255));
      }
    }
    ledtape.show();
    delay(20);
  }
}

//RGBの色の移り変わり関数
uint32_t rotateColor(byte WheelPos) {
  if (WheelPos < 85) {
    return ledtape.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return ledtape.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
    WheelPos -= 170;
    return ledtape.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

uint32_t kesu(byte WheelPos) {
  if (WheelPos < 85) {
    return ledtape.Color(0, 0, 0);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return ledtape.Color(0, 0, 0);
  } else {
    WheelPos -= 170;
    return ledtape.Color(0, 0, 0);
  }
}
