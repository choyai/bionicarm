int c1 =0,c2=0,p;
void setup() {
  Serial.begin(115200);
  delay(1000);
  ledcSetup(0, 50, 8);
  ledcAttachPin(4,0);
  ledcWrite(0, p);
}

void loop() {
  // read the input on analog pin 0:
  int Value = analogRead(0);
  Serial.println(Value);
  Serial.println(c1);
  Serial.println(c2);
  if(Value > 1000){
    c1++;
    if(c1 > 2){
      c1=2;
      c2++;
    }
    delay(300);
  }
  if(c1 >= 2){
    p = map(4000, 0, 4095, 10, 33);
    delay(700);
  }
  if(c2 == 2){
    p = map(0, 0, 4095, 10, 33);
    delay(700);
    c1 = 0;
    c2 = 0;    
  }
  ledcWrite(0, p);
  // print out the value you read:
  delay(100);
}
