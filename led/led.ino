#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel RGB = Adafruit_NeoPixel(4, 7, NEO_RGB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  RGB.setPixelColor(0, 0x00FF00);
  RGB.show();
}
