CHƯƠNG 1: PHÂN TÍCH YÊU CẦU
1.1. Yêu cầu thiết kế
Thiết kế phần cứng và phần mềm cho robot dò đường theo quy đạo cho sẵn. Quỹ đạo di chuyển của xe theo hình vẽ  có chiều dài 2 m và rộng 1 m.

 
Hình 0: Quỹ đạo di chuyển của xe 

1.2. Yêu cầu phần cứng
Thiết bị robot dò đường, mạch điều khiển xe chạy được.
1.3. Yêu cầu phần mềm
Thiết kế chương trình điều khiển xe chạy đúng đường đã thiết kế (theo hình vẽ), xe chạy ổn định với tốc độ tối ưu.

 
CHƯƠNG 2: PHÂN TÍCH THIẾT KẾ
2.1. Phân tích thiết kế hệ thống
Robot dò đường bao gồm 2 module chính:
	Phần 1: Module thiết kế phần cứng.
	Phần 2: Module thiết kế phần mềm.

2.2. Module thiết kế phần cứng 
Các module phần cứng sử dụng thiết kế robot bao gồm các thành phần như sau:

STT	Tên thiết bị	Chức năng
1	Arduino UNO	Bộ xử lý trung tâm của robot, chứa các mã lệnh điều khiển chương trình của robot
2	Module Hồng Ngoại V3 - Dò Đường	Cảm biến phát hiện đường đi cho robot
3	Module điều khiển động cơ	Module dùng để điều chỉnh tốc độ dòng điện của motor, từ đó điều khiển tốc độ quay của bánh xe
4	Khung xe Robot	Khung xe của robot
6	Pin sạc + Khay Pin	Nguồn điện của robot
7	Dây cắm board	Kết nối các phần cứng với nhau
8	Bộ sạc Pin	Nạp lại nguồn cho pin

2.2.1. Module điều khiển động cơ

 
Hình 1: Module điều khiển L298

	Dùng để điều chỉnh điện áp cho arduino UNO và động cơ.
	Tích hợp sẵn 2 mạch cầu H 
	Nguồn vào: 12V 
	Cung cấp nguồn ra 5V cho UNO 
	Dòng tối đa cho mỗi cầu H là 2A 
	Điện áp của tín hiệu điều khiển: 5-7V
	Dòng tín hiệu điều khiển:  0-36mA 
2.2.2. Động cơ và Khung xe

 

Hình 2: Khung xe + bánh xe


Nguyên lý hoạt động:  Động cơ được điều khiển thông qua mạch cầu H của module 1298n. 
Mạch cầu H: 
 
Hình 3: Sơ đồ mạch cầu H điều khiển động cơ
Mỗi động cơ sẽ được nối với  mạch cầu H của module 1298n. Khi tín hiệu in là LOW thì bánh xe không quay. Ngược lại khi tín hiệu in là HIGH thì bánh sẽ quay. Tốc độ quay được điều chỉnh bằng cách điều chỉnh điện áp đặt vào 2 đầu mạch cầu này. 
2.2.3. Module Hồng Ngoại V3 - Dò Đường

 
Hình 4: Module Hồng Ngoại V3 - Dò Đường

	Phát hiện vùng màu đen và vùng màu sáng 
	Module Hồng Ngoại V3 - Dò Đường sử dụng 8 mắt thu quang đọc dữ liệu. Module được ứng dụng trong các xe thông minh hoặc một robot đi theo đường màu đã xác định trước. Module được ứng dụng trong xe thông minh để tránh những vách đá, vật cản. Module cảm biến hồng ngoại đã được tích hợp sẵn một vi điều khiển để giải mã tín hiệu dò đường, giúp giảm thiểu công việc xử lý cho mạch điều khiển chính.
	Nguồn hoạt động: 3.3V từ UNO
2.2.4. Arduino UNO R3 chíp dán

 
Hình 5: Module Arduino Uno R3 chíp dán

Trên Board Arduino Uno có 14 chân Digital được sử dụng để làm chân đầu vào và đầu ra và chúng sử dụng các hàm pinMode(), digitalWrite(), digitalRead(). Giá trị điện áp trên mỗi chân là 5V, dòng trên mỗi chân là 20mA và bên trong có điện trở kéo lên là 20-50 ohm. Dòng tối đa trên mỗi chân là I/O không vượt quá 40mA để tránh trường hợp gây hỏng board mạch. 

Ngoài ra, một số chân Digital có chức năng đặc biệt: 
	Serial: 0(RX) và 1(TX): Được sử dụng để nhận dữ liệu (RX) và truyền dữ liệu (TX) TTL. 
	Ngắt ngoài: Chân 2 và 3
	PWM: 3, 5, 6, 9 và 11 cung cấp đầu ra xung PWM với độ phân giải 8 bit bằng hàm analogWrite().
	SPI: Có 1 LED được tích hợp trên bảng mạch và được nối vào chân D13. Khi chân có giá trị mức cao (HIGH) thì LED sẽ sáng và LED tắt khi ở mức thấp (LOW). 
	TWI/I2C: A4 (SDA) và A5 (SCL) hỗ trợ giao tiếp I2C/TWI với các thiết bị khác. 
Arduino Uno R3 có 6 chân Analog từ A0 đến A5, đầu vào cung cấp độ phân giải là 10 bit.

2.3. Thiết kế mạch phần cứng

 
Hình 6: Sơ đồ nối dây mạch robot dò line

Sơ đồ lắp ghép mạch phần cứng được thể hiện như hình bên trên, cụ thể như sau:
	Các cảm biến lần lượt từ bên trái sang phải sẽ được nối tương ứng vào các chân 10, 11, 12, 13 của Arduino Uno R3
	Nguồn âm được cấp chia 2 đường, một đường cho Arduino, 1 đường cho L298
	Nguồn dương qua công tắc rồi chia 2 đường, một đường cho Arduino, 1 đường cho L298
	Các cổng output của mạch điều khiển động cơ L298 nối với 2 motor để điều khiển bánh xe trái và phải
	Các chân tín hiệu của L298 là IN1, IN2, IN3, IN4 nối lần lượt vào chân 6, 7, 8, 9 của Arduino
	Các chân ENA và ENB của L298 nối vào chân 3 và 5 của Arduino để thực hiện băm xung

2.4. Module thiết kế phần mềm
Thuật toán dò đường thường sử dụng trong thiết kế các robot dò đường là đặt một dãy các cảm biến sắp xếp đều nhau phía trước robot. Việc lệch đường đi trong quá trình di chuyển sẽ được robot phát hiện thông qua các trạng thái của cảm biến, cụ thể: 
	 Nếu hai cảm biến ở giữa cảm nhận được đường đi thì robot đang tiến thẳng về phía trước (hình 7.a).
	 Nếu các cảm biến bên phải cảm nhận được đường đi thì robot di chuyển lệch về bên trái (hình 7.b).
	 Nếu các cảm biến bên trái cảm nhận được đường đi thì robot đang di chuyển lệch sang phải (hình 7.c). 
Thuật toán này được ứng dụng khá thành công trong việc thiết kế robot dò đường. 

 
Hình 7. Sự lệch trong quá trình di chuyển của robot. 
(a) Robot đi thẳng, (b) Robot lệch trái, (c) Robot lệch phải

Ý tưởng chính để điều khiển robot dò đường: 
	 Khi robot di chuyển lệch sang trái của đường đi thì robot sẽ giảm dòng điện động cơ phải (giảm tốc độ bánh phải) trong khi động cơ trái vẫn hoạt động bình thường, điều này sẽ giúp cho robot quay lại đường đi ban đầu;
	 Khi robot di chuyển lệch sang phải của đường đi thì robot sẽ giảm dòng điện động cơ trái (giảm tốc độ bánh trái) trong khi động cơ phải vẫn hoạt động bình thường để giúp robot quay trở lại đường đi ban đầu.
2.4.1. Thư viện và công cụ sử dụng
Ngôn ngữ phát triển: ngôn ngữ lập trình Arduino.
IDE phát triển: phần mềm chuyên dụng Arduino IDE.
Quản lý mã nguồn: Github.
2.4.2. Mã nguồn phát triển
Liên kết lưu trữ mã nguồn: https://github.com/minhtrungle/Embedded-System
Lưu đồ xử lý trong mã nguồn:

 

Hình 8: Lưu đồ thuật toán mã nguồn điều khiển xe dò line 
	Thuật toán đo độ lệch:

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

    // Trả về 0 là không lệch
    // Âm là lệch trái (-1;-2)
    //Dương là lệch phải(1;2)
 
}
 
2.4.3. Phương pháp điều chế độ rộng xung (PWM)
	Tốc độ quay của động cơ một chiều tỉ lệ thuận với điện áp đầu vào. Do đó, cách đơn giản nhất để điều khiển tốc độ động cơ là thay đổi mức điện áp đặt vào động cơ. 
	Nguyên tắc cơ bản để thay đổi tốc độ đó là phương pháp PWM, cụ thể là giữ nguyên giá trị điện áp vào và thay đổi thời gian đặt điện áp vào động cơ.
	 Khi thời gian mức cao Ton trong một chu kỳ của xung ngõ vào động cơ càng lớn thì điện áp trung bình đặt vào động cơ càng cao và ngược lại khi mức thời gian thấp ta có Toff .
	Đại lượng mô tả mối quan hệ giữa khoảng thời gian Ton và Toff được gọi là độ xung (duty_cycle), được tính theo công thức sau: 
duty_cycle  = Ton/(Ton + Toff)x 100 
 
Hình 9. Giản đồ thời gian của xung PWM 
 
