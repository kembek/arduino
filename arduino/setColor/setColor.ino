#include <Adafruit_NeoPixel.h>


Adafruit_NeoPixel Lol = Adafruit_NeoPixel(4, 7, NEO_RGB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  Lol.setPixelColor(0, 0x00FF00);
  Lol.setPixelColor(1, 0x00FF00);
  Lol.setPixelColor(2, 0x00FF00);
  Lol.setPixelColor(3, 0x00FF00);
  Lol.show();
}
