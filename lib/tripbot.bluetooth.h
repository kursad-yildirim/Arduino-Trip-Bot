// TriP-BoT SeedStudio BlueTooth Shiled
#include <SoftwareSerial.h>

SoftwareSerial blueToothSerial(bluetoothReceivePin, bluetoothTransmitPin);
String bluetoothMessageToSend;



void setupBlueToothConnection()
{
  blueToothSerial.begin(9600);
  blueToothSerial.print("AT");
  delay(1000);
  blueToothSerial.print("AT+DEFAULT");
  delay(5000);
  blueToothSerial.print("AT+NAMEBlueBotBlue");
  delay(1000);
  blueToothSerial.print("AT+PIN1010");
  delay(1000);
  blueToothSerial.print("AT+AUTH1");
  delay(1000);
  blueToothSerial.println("-DONE-");
  blueToothSerial.flush();
}

void setupBluetooth(){
  pinMode(bluetoothReceivePin, INPUT);
  pinMode(bluetoothTransmitPin, OUTPUT);
  setupBlueToothConnection();
}
void sendToBlueTooth(String bluetoothMessageToSend)
{
	if (bluetoothMessageToSend.length() > 0){
		blueToothSerial.println(bluetoothMessageToSend);
	}
}

String readFromBlueTooth()
{
  String blueInput = "";
  char blueChar = ' ';
  if (blueToothSerial.available()) {

    while (blueChar != '|') {
      if (blueToothSerial.available()) {
        blueChar = blueToothSerial.read();
        if (blueChar != '|') {
          blueInput += blueChar;
        }
      }
    }
  }
  return blueInput;
}