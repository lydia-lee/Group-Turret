//pins
int motor1a = P1_0;
int motor1b = P1_1;
int potJoy = P1_4;
int potSensor = P1_5;

//constants
int sensorTolerance = .1;

int main(){
  pinMode(P2_0, OUTPUT);
  pinMode(P2_1, OUTPUT);
  pinMode(P1_4, INPUT);
  pinMode(P1_5, INPUT);

  int potJoyVal = 0;
  int potSensorVal = 0;
  while(1){
    potJoyVal = analogRead(potJoy);
    potSensorVal = analogRead(potSensor);
    if(abs(potJoyVal - potSensorVal) < sensorTolerance){
      digitalWrite(motor1a, LOW);
      digitalWrite(motor1b, LOW);
    }
    else if(potJoyVal > potSensorVal){
      digitalWrite(motor1a, HIGH);
      digitalWrite(motor1b, LOW);
    }
    else{
      digitalWrite(motor1a, LOW);
      digitalWrite(motor1b, HIGH);
    }
    delay(100);
  }
}