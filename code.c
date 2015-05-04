// Pins
int motor1a = P1_1; // Don't use 2_3 or 2_4 (at least one is broken)
int motor1b = P1_2;
int potJoy = P1_5;
int potSensor = P1_4;

// Constants
int sensorTolerance = 0.1;

int main(){
  // LEDs used for testing/demo purposes
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(P1_1, OUTPUT);  // motor one way
  pinMode(P1_2, OUTPUT);  // motor other way
  pinMode(P1_5, INPUT);   // joystick potentiometer
  pinMode(P1_4, INPUT);   // table potentiometer

  int potJoyVal = 0;
  int potSensorVal = 0;
  while(1){
    // Reads the two potentiometer values
    potJoyVal = analogRead(potJoy);
    potSensorVal = analogRead(potSensor);

    // Handles differences in potentiometer readings to choose the
    // direction of rotation
    if(abs(potJoyVal - potSensorVal) < sensorTolerance){
      digitalWrite(motor1a, LOW);
      digitalWrite(motor1b, LOW);
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
    }
    else if(potJoyVal > potSensorVal){
      digitalWrite(motor1a, HIGH);
      digitalWrite(motor1b, LOW);
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
    }
    else{
      digitalWrite(motor1a, LOW);
      digitalWrite(motor1b, HIGH);
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
    }
    delay(100);
  }
}