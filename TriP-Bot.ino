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

int contour = 20.5;
int speedSecond = 0;

void setup() {
  setupMotor(); // Motor Shield Set Up
  setupSensorUltraSonic(); // Ultrasonic Sensor Setup
  setupSensorSpeed(); // Speed Sensor Setup
  setupBluetooth(); // Bluetooth Shield Setup
}

void loop() {
  goForward();
  speedSecond = getSpeed() * contour / 60;
  sendToBlueTooth("Speed => " + String(speedSecond) + " cm/sec" );
  delay(3000);
  fullStop();
  delay(10000);
}
