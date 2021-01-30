#include "lib/tripcontroller.h"

int LED = 255;

void setup()
{
  Serial.begin(9600);
  setupTouchscreen();
}

void loop()
{
  if (ts.touched()) {
    TS_Point p = ts.getPoint(); //XPT_2046_touchscreen returns in Landscape
    uint16_t y = map(p.y, TS_TOP, TS_BOT, 0, tft.height());
    uint16_t x = map(p.x, TS_LEFT, TS_RT, 0, tft.width());

    Serial.println("x=" + String(x) + " y=" + String(y) + " z=" + String(p.z) + "   ");
    if (LED == 255) {
      LED = 0;
    } else {
      LED = 255;
    }
    analogWrite(LEDPIN, LED);
  }
}
