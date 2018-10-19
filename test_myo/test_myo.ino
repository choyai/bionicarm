#include <Servo.h>
Servo servo;
int c;

void setup() {
  Serial.begin(9600);
  servo.attach(9);
  delay(1000);
}

void loop() {
  // read the input on analog pin 0:
  int Value = analogRead(0);
  Serial.println(Value);
  Serial.println(c);
  if(Value > 200){
    c++;
    delay(300);
    if(c >= 2){
      servo.writeMicroseconds(800);
        if(c == 4){
        servo.writeMicroseconds(2250);
        c=0;
      }
    }
  }
  delay(100);
}