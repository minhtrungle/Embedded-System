void setup() {
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

}

void loop() {
  if ((digitalRead(10) == 1)&&(digitalRead(11) == 1) && (digitalRead(12) == 1)&&(digitalRead(13) == 1))
  {
    digitalWrite(6, 1);
    digitalWrite(7, 0);
  }
  else
  {
    digitalWrite(6, 0);
    digitalWrite(7, 0);
  }


}
