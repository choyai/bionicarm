int state =0,count =0,p;
void setup() {
  Serial.begin(115200);
  delay(1000);
  ledcSetup(0, 50, 8);
  ledcAttachPin(4,0);
  ledcWrite(0, p);
}

void loop() {
  int Value = analogRead(0);
  Serial.println(Value);
  Serial.println(count);
  Serial.println(state);
  if(Value>=1000)
  { 
    Serial.println("wtf");
    if(count >=2)
    { 
      if(state == 0)
      {
        state = 1;
      }
      else{
        state =0;
      }
      count =0;
    }else
    {
      count +=1;
    }
  }
  switch (state){
    case 0:  p = map(0, 0, 4095, 10, 33); break;
    case 1:  p = map(4000, 0, 4095, 10, 33); break;
  }
  ledcWrite(0, p);
  delay(100);
}
