#define inA1 6 //Định nghĩa chân in1 của động cơ A
#define inA2 7 //Định nghĩa chân in2 của động cơ A
#define inB1 8 //Định nghĩa chân in1 của động cơ B
#define inB2 9 //Định nghĩa chân in2 của động cơ B
void setup() {
  pinMode(inA1, OUTPUT);//Set chân in1 của dc A là output
  pinMode(inA2, OUTPUT);//Set chân in2 của dc A là output
  pinMode(inB1, OUTPUT);//Set chân in1 của dc B là output
  pinMode(inB2, OUTPUT);//Set chân in2 của dc B là output
}
 
void loop() {
 
  robotMover (inA1, inA2, inB1, inB2, 1);
  delay (1000);
  robotMover (inA1, inA2, inB1, inB2, 2);
  delay (1000);
  robotMover (inA1, inA2, inB1, inB2, 3);
  delay (1000);
  robotMover (inA1, inA2, inB1, inB2, 4);
  delay (1000);
  
}
 
void robotMover (byte inR1, byte inR2, byte inL1, byte inL2, byte action)
{
  /*
  inR1 inR2 là 2 chân tín hiệu động cơ bên phải
  inL1 inL2 là 2 chân tín hiệu động cơ bên trái
  action= 0 đứng yên
  action =1 đi thẳng
  action =2 lùi lại
  action =3 quay trái
  action =4 quay phải
  action =5 rẽ trái
  action =6 rẽ phải
  action =7 rẽ lùi trái
  action =8 rẽ lùi phải
 
  */
  switch (action)
  {
  case 0:// không di chuyển
      motorControlNoSpeed(inR1, inR2, 0);
      motorControlNoSpeed(inL1, inL2, 0);
    break;
  case 1://đi thẳng
      motorControlNoSpeed(inR1, inR2, 1);
      motorControlNoSpeed(inL1, inL2, 1);
    break;
  case 2:// lùi lại
      motorControlNoSpeed(inR1, inR2, 2);
      motorControlNoSpeed(inL1, inL2, 2);
    break;
  case 3:// quay trái
      motorControlNoSpeed(inR1, inR2, 1);
      motorControlNoSpeed(inL1, inL2, 2);
    break;
  case 4:// quay phải
      motorControlNoSpeed(inR1, inR2, 2);
      motorControlNoSpeed(inL1, inL2, 1);
    break;
  case 5:// rẽ trái
      motorControlNoSpeed(inR1, inR2, 1);
      motorControlNoSpeed(inL1, inL2, 0);
    break;
  case 6:// rẽ phải
      motorControlNoSpeed(inR1, inR2, 0);
      motorControlNoSpeed(inL1, inL2, 1);
    break;
  case 7:// rẽ lùi trái
      motorControlNoSpeed(inR1, inR2, 2);
      motorControlNoSpeed(inL1, inL2, 0);
    break;
  case 8:// rẽ lùi phải
      motorControlNoSpeed(inR1, inR2, 0);
      motorControlNoSpeed(inL1, inL2, 2);
    break;
  default:
    action = 0;
 
  }
}
 
 
void motorControlNoSpeed (byte in1, byte in2, byte direct)
{
  // in1 and in2 are 2 signal pins to control the motor
  // en is the enable pin
  // the defauspeed is the highest
  // direct includes:
  //  0:Stop
  //  1:Move on 1 direct
  //  2:Move on another direct
  switch (direct)
  {
  case 0:// Dừng không quay
    digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
    break;
  case 1:// Quay chiều thứ 1
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
    break;
  case 2:// Quay chiều thứ 2
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      break;
    //default:
  }
}
