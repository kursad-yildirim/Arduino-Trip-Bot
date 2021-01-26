// TriP-BoT Motor Related Definitions

int fullMotorSpeed = 123;
int halfMotorSpeed = 123;

void setupMotor(){
  pinMode(motor_A_direcPin, OUTPUT);
  pinMode(motor_A_brakePin, OUTPUT);
  pinMode(motor_A_speedPin, OUTPUT);
  pinMode(motor_B_direcPin, OUTPUT);
  pinMode(motor_B_brakePin, OUTPUT);
  pinMode(motor_B_speedPin, OUTPUT);
}
void goForward(){
  digitalWrite(motor_A_direcPin, LOW);
  digitalWrite(motor_A_brakePin, LOW);
  digitalWrite(motor_B_direcPin, HIGH);
  digitalWrite(motor_B_brakePin, LOW);

  analogWrite(motor_A_speedPin, fullMotorSpeed);
  analogWrite(motor_B_speedPin, fullMotorSpeed);
}
void goBackward(){
  digitalWrite(motor_A_direcPin, HIGH);
  digitalWrite(motor_A_brakePin, LOW);
  digitalWrite(motor_B_direcPin, LOW);
  digitalWrite(motor_B_brakePin, LOW);

  analogWrite(motor_A_speedPin, fullMotorSpeed);
  analogWrite(motor_B_speedPin, fullMotorSpeed);
}
void turnRight(){
  digitalWrite(motor_A_direcPin, LOW);
  digitalWrite(motor_A_brakePin, LOW);
  digitalWrite(motor_B_direcPin, LOW);
  digitalWrite(motor_B_brakePin, LOW);

  analogWrite(motor_A_speedPin, halfMotorSpeed);
  analogWrite(motor_B_speedPin, halfMotorSpeed);
}
void turnLeft(){
  digitalWrite(motor_A_direcPin, HIGH);
  digitalWrite(motor_A_brakePin, LOW);
  digitalWrite(motor_B_direcPin, HIGH);
  digitalWrite(motor_B_brakePin, LOW);

  analogWrite(motor_A_speedPin, halfMotorSpeed);
  analogWrite(motor_B_speedPin, halfMotorSpeed);
}
void fullStop(){
  digitalWrite(motor_A_brakePin, HIGH);
  digitalWrite(motor_B_brakePin, HIGH);
}