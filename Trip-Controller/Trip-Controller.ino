#include <SPI.h>          // f.k. for Arduino-1.5.2
#include "Adafruit_GFX.h"// Hardware-specific library
#include <HX8347D_kbv.h>
HX8347D_kbv tft;
#include <XPT2046_Touchscreen.h>

//edit begin() method in XPT2046_Touchscreen.cpp source code :
//        attachInterrupt( digitalPinToInterrupt(tirqPin), isrPin, FALLING );  //.kbv

#define XPT_CS  4
#define XPT_IRQ 255       //use 3 if you fix interrupts in library source code

#define TS_LEFT 3900    //The XPT2046_Touchscreen works in Landscape
#define TS_RT   300     //I would expect Touch in Portrait
#define TS_TOP  360
#define TS_BOT  3800

XPT2046_Touchscreen ts(XPT_CS, XPT_IRQ);

#define BLACK       0x0000
#define BLUE        0x001F
#define RED         0xF800
#define GREEN       0x07E0
#define CYAN        0x07FF
#define MAGENTA     0xF81F
#define YELLOW      0xFFE0
#define WHITE       0xFFFF
#define DARK_GREY   0x7BEF
#define LIGHT_GREY  0xC618

#define LEFT_MARGIN 30
#define TOP_MARGIN 40
#define SINGLE_WIDTH 120
#define SINGLE_HEIGHT 60
#define CHAR_WIDTH 16
#define CHAR_HEIGHT 24
#define BORDER_WEIGHT 3
#define PADDING_WEIGHT 20

#define LEDPIN 2
#define SCREEN_TITLE "Trp-Bot Controller"

class Rectangle {
  private:
    int goX1;
    int goY1;
    int goX2;
    int goY2;
  public:
    void draw (int row, int column, int colCount, long rectColor, String caption) {
      int xStart = 0;
      int yStart = 0;
      int xWidth = 0;
      if ( row == 1) {
        yStart = TOP_MARGIN;
      } else {
        yStart = TOP_MARGIN + SINGLE_HEIGHT + PADDING_WEIGHT;
      }
      if ( column == 1) {
        xStart = LEFT_MARGIN;
      } else {
        xStart = LEFT_MARGIN + SINGLE_WIDTH + PADDING_WEIGHT;
      }
      if ( colCount == 1) {
        xWidth = 2 * SINGLE_WIDTH + PADDING_WEIGHT;
      } else {
        xWidth = SINGLE_WIDTH;
      }
      tft.fillRect(xStart - BORDER_WEIGHT, yStart - BORDER_WEIGHT, xWidth + 2 * BORDER_WEIGHT, SINGLE_HEIGHT + 2 * BORDER_WEIGHT, BLACK);
      tft.fillRect(xStart, yStart, xWidth, SINGLE_HEIGHT, rectColor);
      if ( caption != "NONE") {
        tft.setTextColor(BLACK);
        tft.setTextSize(3);
        if ( colCount == 1) {
          tft.setCursor(xStart + SINGLE_WIDTH - ( PADDING_WEIGHT / 2 ) - (caption.length() / 2 * CHAR_WIDTH) , yStart + (SINGLE_HEIGHT / 2) - (CHAR_HEIGHT / 2) );
        } else {
          tft.setCursor(xStart + (SINGLE_WIDTH / 2) - (caption.length() / 2 * CHAR_WIDTH) , yStart + (SINGLE_HEIGHT / 2) - (CHAR_HEIGHT / 2) );
        }
        tft.println(caption);
      }
      init();
    }
    void isPushed() {
    }
    void setCaption() {
    }
};

int LED = 255;
Rectangle goButton;
void setup()
{
  Serial.begin(9600);
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);   //LANDSCAPE
  makeGUI();
  ts.begin();            //.kbv XPT2046_Touchscreen needs to start
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
void drawRectangle (int row, int column, int colCount, long rectColor, String caption) {
  int xStart = 0;
  int yStart = 0;
  int xWidth = 0;
  if ( row == 1) {
    yStart = TOP_MARGIN;
  } else {
    yStart = TOP_MARGIN + SINGLE_HEIGHT + PADDING_WEIGHT;
  }
  if ( column == 1) {
    xStart = LEFT_MARGIN;
  } else {
    xStart = LEFT_MARGIN + SINGLE_WIDTH + PADDING_WEIGHT;
  }
  if ( colCount == 1) {
    xWidth = 2 * SINGLE_WIDTH + PADDING_WEIGHT;
  } else {
    xWidth = SINGLE_WIDTH;
  }
  tft.fillRect(xStart - BORDER_WEIGHT, yStart - BORDER_WEIGHT, xWidth + 2 * BORDER_WEIGHT, SINGLE_HEIGHT + 2 * BORDER_WEIGHT, BLACK);
  tft.fillRect(xStart, yStart, xWidth, SINGLE_HEIGHT, rectColor);
  if ( caption != "NONE") {
    tft.setTextColor(BLACK);
    tft.setTextSize(3);
    if ( colCount == 1) {
      tft.setCursor(xStart + SINGLE_WIDTH - ( PADDING_WEIGHT / 2 ) - (caption.length() / 2 * CHAR_WIDTH) , yStart + (SINGLE_HEIGHT / 2) - (CHAR_HEIGHT / 2) );
    } else {
      tft.setCursor(xStart + (SINGLE_WIDTH / 2) - (caption.length() / 2 * CHAR_WIDTH) , yStart + (SINGLE_HEIGHT / 2) - (CHAR_HEIGHT / 2) );
    }
    tft.println(caption);
  }
}
void makeGUI()
{
  tft.fillScreen(WHITE);
  displayTitle();
  goButton.draw( 1, 1, 2, GREEN, "GO");
  //  drawRectangle( 1, 1, 2, GREEN, "GO");
  drawRectangle( 1, 2, 2, RED, "STOP");
  drawRectangle( 2, 1, 1, DARK_GREY, "NOTHING FRONT");
}
void displayTitle()
{
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.setCursor(45, 6);
  tft.println(SCREEN_TITLE);
}
