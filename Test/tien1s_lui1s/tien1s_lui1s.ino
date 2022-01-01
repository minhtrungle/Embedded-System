void setup() {
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop() {
 digitalWrite(6,HIGH);
 digitalWrite(7,LOW);
 delay(1000);
 digitalWrite(7,HIGH);
 digitalWrite(6,LOW);
 delay(1000);
}
