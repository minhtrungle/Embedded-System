void setup()
{
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  Serial.begin (9600);
}
void loop()
{
  if (IFSensor(10) == 1)
    Serial.println("Cam bien 1 trong vach");
  else
    Serial.println("Cam bien 1 ngoai vach");


  if (IFSensor(11) == 1)
    Serial.println("Cam bien 2 trong vach");
  else
    Serial.println("Cam bien 2 ngoai vach");


  if (IFSensor(12) == 1)
    Serial.println("Cam bien 3 trong vach");
  else
    Serial.println("Cam bien 3 ngoai vach");


  if (IFSensor(13) == 1)
    Serial.println("Cam bien 4 trong vach");
  else
    Serial.println("Cam bien 4 ngoai vach");
  Serial.println("");
  delay(1000);
}

boolean IFSensor (byte PinNumb)
{
  //0 ngoài vạch
  //1 trong vạch
  return (digitalRead (PinNumb));
}
