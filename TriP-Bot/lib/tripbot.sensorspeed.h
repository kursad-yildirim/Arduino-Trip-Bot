// TriP-BoT Spped Sensor Related Definitions

unsigned long start_time = 0;
unsigned long end_time = 0;
int steps=0;
float steps_old=0;
float temp=0;
float rpm=0;



void setupSensorSpeed(){
	Serial.begin(9600);
	pinMode(sensorSpeedPin, INPUT_PULLUP);
}
int getSpeed(){
 start_time=millis();
 end_time=start_time+1000;
 while(millis()<end_time)
 {
   if(digitalRead(sensorSpeedPin))
   {
    steps=steps+1; 
    while(digitalRead(sensorSpeedPin));
   }
 //  Serial.print("Steps => ");
 //  Serial.println(steps);
 }
    temp=steps-steps_old;
    steps_old=steps;
    rpm=(temp * 3);
   Serial.print("RPMM => ");
   Serial.println(rpm);
	return rpm;
}