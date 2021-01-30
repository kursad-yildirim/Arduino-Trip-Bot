#include <SPI.h>          // f.k. for Arduino-1.5.2
#include "Adafruit_GFX.h"// Hardware-specific library
#include <HX8347D_kbv.h>
HX8347D_kbv tft;
#include <XPT2046_Touchscreen.h>

#define XPT_CS  4
#define XPT_IRQ 255
#define TS_LEFT 3900
#define TS_RT   300
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