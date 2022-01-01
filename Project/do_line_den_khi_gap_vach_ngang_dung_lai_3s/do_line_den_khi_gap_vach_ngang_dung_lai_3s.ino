
#define inA1 6       //Định nghĩa chân in1 của động cơ A
#define inA2 7       //Định nghĩa chân in2 của động cơ A
#define inB1 8       //Định nghĩa chân in1 của động cơ B
#define inB2 9       //Định nghĩa chân in2 của động cơ B
#define linesens1 10 //Định nghĩa chân cảm biến line 1
#define linesens2 11 //Định nghĩa chân cảm biến line 2
#define linesens3 12 //Định nghĩa chân cảm biến line 3
#define linesens4 13 //Định nghĩa chân cảm biến line 4

void setup() 
{
  Serial.begin(9600);
  pinMode(4,OUTPUT);         //Set chân cắm led
  pinMode(inA1, OUTPUT);     //Set chân in1 của dc A là output
  pinMode(inA2, OUTPUT);     //Set chân in2 của dc A là output
  pinMode(inB1, OUTPUT);     //Set chân in1 của dc B là output
  pinMode(inB2, OUTPUT);     //Set chân in2 của dc B là output
  pinMode(linesens1, INPUT); //Set chân cảm biến 1 là input
  pinMode(linesens2, INPUT); //Set chân cảm biến 2 là input
  pinMode(linesens3, INPUT); //Set chân cảm biến 3 là input
  pinMode(linesens4, INPUT); //Set chân cảm biến 4 là input
}
  // Hàm băm xung giảm tốc động cơ
void loop()
{ 
  darkLineFollower (inA1, inA2, inB1, inB2, linesens1, linesens2, linesens3, linesens4);
  analogWrite(3, 100);
  analogWrite(5, 100);
}
  //Hàm điều khiển robot bám line màu tối
  //inR1, inR2 và inL1, inL2 là các chân tín hiệu lần lượt điều khiển động cơ di chuyển bên phải và trái
  //sen1 đến sen4 là chân nhận tín hiệu từ cảm biến hồng ngoại
  
void darkLineFollower (byte inR1, byte inR2, byte inL1, byte inL2, byte sen1, byte sen2, byte sen3, byte sen4)
{
  switch (deviationDarkLine4Sensor (sen1, sen2, sen3, sen4))
  {
    case -1:
      robotMover( inR1, inR2, inL1, inL2, 6);// rẽ phải
      break;
    case -2:
      robotMover( inR1, inR2, inL1, inL2, 6);
      break;
    case 1:
      robotMover( inR1, inR2, inL1, inL2, 5);// rẽ trái
      break;
    case 2:
      robotMover( inR1, inR2, inL1, inL2, 5);
      break;
    case 0:
      robotMover( inR1, inR2, inL1, inL2, 1);// tiến thẳng
      break;
    case 3:
      robotMover( inR1, inR2, inL1, inL2, 2);// lệch vạch thì lùi
      break;
    case 4:
      robotMover( inR1, inR2, inL1, inL2, 0); // gap vach ngang thi led nhay 3s
      digitalWrite(4, 1);
      delay(500);
      digitalWrite(4, 0);
      delay(500);
      digitalWrite(4, 1);
      delay(500);
      digitalWrite(4, 0);
      delay(500);
      digitalWrite(4, 1);
      delay(500);
      digitalWrite(4, 0);
      delay(500);
      robotMover( inR1, inR2, inL1, inL2, 1);
      delay(500);
      break;
  }
}

  // Hàm thực hiện robot di chuyển
void robotMover (byte inR1, byte inR2, byte inL1, byte inL2, byte action)
{
   // inR1 inR2 là 2 chân tín hiệu động cơ bên phải
   // inL1 inL2 là 2 chân tín hiệu động cơ bên trái
   // action= 0 đứng yên
   // action =1 đi thẳng
   // action =2 lùi lại
   // action =3 quay trái
   // action =4 quay phải
   // action =5 rẽ trái
   // action =6 rẽ phải
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
      motorControlNoSpeed(inR1, inR2, 2);
      motorControlNoSpeed(inL1, inL2, 1);
      break;
    case 4:// quay phải
      motorControlNoSpeed(inR1, inR2, 1);
      motorControlNoSpeed(inL1, inL2, 2);
      break;
    case 5:// rẽ trái
      motorControlNoSpeed(inR1, inR2, 1);
      motorControlNoSpeed(inL1, inL2, 0);
      break;
    case 6:// rẽ phải
      motorControlNoSpeed(inR1, inR2, 0);
      motorControlNoSpeed(inL1, inL2, 1);
      break;
    default:
      action = 0;
  }
}

  // Hàm điều khiển chiều quay của động cơ
void motorControlNoSpeed (byte in1, byte in2, byte direct)
{
  //    0:Dừng lại
  //    1:Quay chiều thứ nhất
  //    2:Quay chiều thứ hai
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

boolean IFSensor (byte PinNumb)
{
  //0 sáng
  //1 tối
  return (digitalRead (PinNumb));
}

 // Hàm đo độ lệch
int deviationDarkLine4Sensor (int PinNumb1, int PinNumb2, int PinNumb3, int PinNumb4)
{
  int left = 0;    //biến kiểm tra lệch trái
  int right = 0;   // biến kiểm tra lệch phải
  left = IFSensor (PinNumb1) + IFSensor (PinNumb2); //kiểm tra mấy cảm biến trái ở trong màu đen
  right = IFSensor (PinNumb3) + IFSensor (PinNumb4); //kiểm tra mấy cảm biến phải ở trong màu đen
  Serial.print("left=");
  Serial.println(left);
  Serial.print("right=");
  Serial.println(right);
  if (IFSensor (PinNumb1) + IFSensor (PinNumb2) + IFSensor (PinNumb3) + IFSensor (PinNumb4) == 4)
  {
    Serial.println("Gap vach ngang dung lai");
    return 4;
  }
  if ((left != 0) || (right != 0))
      return left - right;
  else 
      return 3;

    // Trả về 0 là không lệch, trả về 3 là mất vạch
    // Âm là lệch trái (-1;-2)
    //Dương là lệch phải(1;2)
 
}