
Rectangle goButton;
Rectangle stopButton;
Rectangle displayArea;

void displayTitle()
{
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.setCursor(45, 6);
  tft.println(SCREEN_TITLE);
}

void makeGUI()
{
  tft.fillScreen(WHITE);
  displayTitle();
  goButton.draw( 1, 1, 2, GREEN, "GO");
  stopButton.draw( 1, 2, 2, RED, "STOP");
  displayArea.draw( 2, 1, 1, DARK_GREY, "NOTHING FRONT");
}

void setupTouchscreen(){
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  makeGUI();
  ts.begin();
}