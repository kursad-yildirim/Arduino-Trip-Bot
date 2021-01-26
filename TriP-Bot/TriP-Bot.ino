/*************************************************************
  Ultimate Robot TriP-Bot by TriP
  Motor Fucntions:
    goForward()
    goBackward()
    turnLeft()
    turnRight()
    fullStop()
  UltraSonic Sensor Fucntions:
    getDistance()
  Bluetooth Fucntions:
    sendToBlueTooth(String bluetoothMessageToSend)
    readFromBlueTooth()
*************************************************************/

#include "lib/tripbot.h"

tripMotor tripMotor;

int contour = 20.5;
int speedSecond = 0;

void setup() {
  setupSensorUltraSonic(); // Ultrasonic Sensor Setup
  setupSensorSpeed(); // Speed Sensor Setup
  setupBluetooth(); // Bluetooth Shield Setup
}

void loop() {
  tripMotor.goForward();
  speedSecond = getSpeed() * contour / 60;
  sendToBlueTooth("Speed => " + String(speedSecond) + " cm/sec" );
  delay(3000);
  tripMotor.fullStop();
  delay(10000);
}
