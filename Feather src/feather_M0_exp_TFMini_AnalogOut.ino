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
  unsigned char ad_out = dist;
  unsigned char led_val = -dist + 255;
  
  Serial.print(dist);
  Serial.print(" cm      sigstr: ");
  Serial.print(strength);
  Serial.print("    ad_out: ");
  Serial.print(ad_out);
  Serial.print("    led_val: ");
  Serial.println(led_val);
  
  analogWrite(rio_out, ad_out);
  led.setPixelColor(0,led_val,0,0);
  led.show();

  delay(10);              // wait for a second

}
