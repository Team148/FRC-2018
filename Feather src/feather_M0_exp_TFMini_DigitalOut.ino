#include <TFMini.h>
#include <Adafruit_NeoPixel.h>




Adafruit_NeoPixel led = Adafruit_NeoPixel(1, 8);
TFMini tfm;

#define threshold_dist 80
#define rio_out 19

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(13, OUTPUT);
  pinMode(rio_out, OUTPUT);
  led.begin();
  led.setPixelColor(0, 127,127,127);
  led.show();
  Serial.begin(115200);
  Serial1.begin(115200);
  tfm.begin(&Serial1);

}

// the loop function runs over and over again forever
void loop() {

  uint16_t dist = tfm.getDistance();
  uint16_t strength = tfm.getRecentSignalStrength();
  bool out;
  if(dist > threshold_dist)
    out = LOW;
  else
    out = HIGH;
  

  Serial.print(dist);
  Serial.print(" cm      sigstr: ");
  Serial.print(strength);
  Serial.print("      out: ");
  Serial.println(out);

  if(dist > threshold_dist) {
    led.setPixelColor(0, 255,0,0);
    digitalWrite(rio_out,out);
  }
  else {
    led.setPixelColor(0, 0,255,0);
    digitalWrite(rio_out,out);
  }
  led.show();

  delay(10);              // wait for a second

}
