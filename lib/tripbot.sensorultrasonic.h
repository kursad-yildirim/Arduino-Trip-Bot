// TriP-BoT UltraSonic Sensor Related Definitions

#define distanceDenominator 29.2 // 1 / (speed of sound cm/microsec )

void setupSensorUltraSonic(){
  pinMode(sensorUltraSonicEchoPin, INPUT);
  pinMode(sensorUltraSonicTrigPin, OUTPUT);
}
int getDistance(){
	long duration = 0;
	long distance = 0;
	digitalWrite(sensorUltraSonicTrigPin, LOW);
    delay(5);
    digitalWrite(sensorUltraSonicTrigPin, HIGH);
    delay(10);
    digitalWrite(sensorUltraSonicTrigPin, LOW);

    duration = pulseIn(sensorUltraSonicEchoPin, HIGH);
    distance = duration / distanceDenominator / 2;
	
	return distance;
}
