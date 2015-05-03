//pins
// D  on't use 2_3 or 2_4 (at least one is broken)
int motor1a = P1_1;
int motor1b = P1_2;
int potJoy = P1_5;
int potSensor = P1_4;

// int test1 = P1_0;
// int test2 = P1_6;

//constants
int sensorTolerance = 0.1;

int main(){
  // pinMode(GREEN_LED, OUTPUT);
  // pinMode(RED_LED, OUTPUT);
  // pinMode(P1_0, OUTPUT);
  // pinMode(P1_6, OUTPUT);

  pinMode(P1_1, OUTPUT);
  pinMode(P1_2, OUTPUT);
  pinMode(P1_5, INPUT);
  pinMode(P1_4, INPUT);

  int potJoyVal = 0;
  int potSensorVal = 0;
  while(1){
    potJoyVal = analogRead(potJoy);
    potSensorVal = analogRead(potSensor);
    if(abs(potJoyVal - potSensorVal) < sensorTolerance){
      digitalWrite(motor1a, LOW);
      digitalWrite(motor1b, LOW);
      // digitalWrite(RED_LED, LOW);
      // digitalWrite(GREEN_LED, LOW);
    }
    else if(potJoyVal > potSensorVal){
      digitalWrite(motor1a, HIGH);
      digitalWrite(motor1b, LOW);
      // digitalWrite(RED_LED, HIGH);
      // digitalWrite(GREEN_LED, LOW);
    }
    else{
      digitalWrite(motor1a, LOW);
      digitalWrite(motor1b, HIGH);
      // digitalWrite(RED_LED, LOW);
      // digitalWrite(GREEN_LED, HIGH);
    }
    delay(100);
  }
}