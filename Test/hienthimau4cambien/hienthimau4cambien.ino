#define sensor1 13
#define sensor2 12
#define sensor3 11
#define sensor4 10

void setup() {
  Serial.begin(9600); // thiet lap su dung serial gui tin hieu ve may tinh
  pinMode (sensor1, INPUT); //
  pinMode (sensor2, INPUT);
  pinMode (sensor3, INPUT);
  pinMode (sensor4, INPUT);
}

void loop() {
  if (digitalRead (sensor1) == 0)Serial.print("Sensor1 = white   ");
  else Serial.print("Sensor1 = black   ");
  if (digitalRead (sensor2) == 0)Serial.print("Sensor2 = white   ");
  else Serial.print("Sensor2 = black   ");
  if (digitalRead (sensor3) == 0)Serial.print("Sensor3 = white   ");
  else Serial.print("Sensor3 = black   ");
  if (digitalRead (sensor4) == 0)Serial.println("Sensor4 = white   ");
  else Serial.println("Sensor4 = black   ");
  delay(1000);
}
