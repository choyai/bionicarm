#include <Servo.h>
Servo servo;
int c, state;
int prevValue = 0;
void setup() {
  Serial.begin(9600);
  servo.attach(9);
  delay(1000);
  state = 0;
}

void loop() {
  // read the input on analog pin 0:
  int Value = analogRead(0);
  if(Value > 200){
    state = 1;
  }
  Serial.print(Value);
  Serial.print(',');
  Serial.print(prevValue);
  Serial.print(',');
  Serial.print(state);
  Serial.print(',');
  Serial.println(c);
  if(Value < 200 && state == 1){
    c++;
    if(c >= 2){
      servo.writeMicroseconds(800);
        if(c == 4){
        servo.writeMicroseconds(2250);
        c=0;
      }
    }
    state = 0;
  }
  prevValue = Value;
  delay(100);
}
