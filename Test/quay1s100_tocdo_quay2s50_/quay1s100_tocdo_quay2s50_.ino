void setup() {
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
}

void loop() {
digitalWrite(6,1);
digitalWrite(7,0);
analogWrite(5,255);
delay(1000);
digitalWrite(6,1);
digitalWrite(7,0);
analogWrite(5,122);
delay(2000);

}
