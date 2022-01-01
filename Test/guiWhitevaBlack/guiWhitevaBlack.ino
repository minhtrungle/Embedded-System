void setup()
{
  pinMode(12, INPUT);
  Serial.begin(9600);
}
void loop()
{
  if (digitalRead(12) == 1)Serial.println ("black");
  else Serial.println("white");
}
