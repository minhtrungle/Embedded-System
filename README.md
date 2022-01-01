CHƯƠNG 1: PHÂN TÍCH YÊU CẦU

1.1. Yêu cầu thiết kế
Thiết kế phần cứng và phần mềm cho robot dò đường theo quy đạo cho sẵn. Quỹ đạo di chuyển của xe theo hình vẽ  có chiều dài 2 m và rộng 1 m.

![image](https://user-images.githubusercontent.com/59023235/147855880-e6b68dab-078f-439c-b0d6-a03f815f11e7.png)

1.2. Yêu cầu phần cứng
Thiết bị robot dò đường, mạch điều khiển xe chạy được.

1.3. Yêu cầu phần mềm
Thiết kế chương trình điều khiển xe chạy đúng đường đã thiết kế (theo hình vẽ), xe chạy ổn định với tốc độ tối ưu.
CHƯƠNG 2: PHÂN TÍCH THIẾT KẾ

2.1. Phân tích thiết kế hệ thống
Robot dò đường bao gồm 2 module chính:
-	Phần 1: Module thiết kế phần cứng.
-	Phần 2: Module thiết kế phần mềm.

2.2. Module thiết kế phần cứng 
Các module phần cứng sử dụng thiết kế robot bao gồm các thành phần như sau:
![image](https://user-images.githubusercontent.com/59023235/147855924-54fb63fa-3ec7-46cb-9c9b-e23acd9dba29.png)

2.2.1. Module điều khiển động cơ

![image](https://user-images.githubusercontent.com/59023235/147855978-9d3e7b2e-06f1-4be1-b3b2-234bb714d816.png)

Hình 1: Module điều khiển L298

-	Dùng để điều chỉnh điện áp cho arduino UNO và động cơ.
-	Tích hợp sẵn 2 mạch cầu H 
-	Nguồn vào: 12V 
-	Cung cấp nguồn ra 5V cho UNO 
-	Dòng tối đa cho mỗi cầu H là 2A 
-	Điện áp của tín hiệu điều khiển: 5-7V
-	Dòng tín hiệu điều khiển:  0-36mA 

2.2.2. Động cơ và Khung xe

![image](https://user-images.githubusercontent.com/59023235/147855992-c14716e3-0c31-4d9d-84a4-8532e2bb9c4f.png)

Hình 2: Khung xe + bánh xe


Nguyên lý hoạt động:  Động cơ được điều khiển thông qua mạch cầu H của module 1298n. 
Mạch cầu H: 

![image](https://user-images.githubusercontent.com/59023235/147855998-24ece14f-2b0c-4bd5-b989-765c4058b077.png)

Hình 3: Sơ đồ mạch cầu H điều khiển động cơ

Mỗi động cơ sẽ được nối với  mạch cầu H của module 1298n. Khi tín hiệu in là LOW thì bánh xe không quay. Ngược lại khi tín hiệu in là HIGH thì bánh sẽ quay. Tốc độ quay được điều chỉnh bằng cách điều chỉnh điện áp đặt vào 2 đầu mạch cầu này. 

2.2.3. Module Hồng Ngoại V3 - Dò Đường

![image](https://user-images.githubusercontent.com/59023235/147856001-31c2598c-991d-4036-abe4-f303a987cabd.png)

Hình 4: Module Hồng Ngoại V3 - Dò Đường

-	Phát hiện vùng màu đen và vùng màu sáng 
-	Module Hồng Ngoại V3 - Dò Đường sử dụng 8 mắt thu quang đọc dữ liệu. Module được ứng dụng trong các xe thông minh hoặc một robot đi theo đường màu đã xác định trước. Module được ứng dụng trong xe thông minh để tránh những vách đá, vật cản. Module cảm biến hồng ngoại đã được tích hợp sẵn một vi điều khiển để giải mã tín hiệu dò đường, giúp giảm thiểu công việc xử lý cho mạch điều khiển chính.
-	Nguồn hoạt động: 3.3V từ UNO
-	
2.2.4. Arduino UNO R3 chíp dán

![image](https://user-images.githubusercontent.com/59023235/147856010-238511b9-0cec-45ec-9b05-31464a10d0c6.png)

Hình 5: Module Arduino Uno R3 chíp dán

Trên Board Arduino Uno có 14 chân Digital được sử dụng để làm chân đầu vào và đầu ra và chúng sử dụng các hàm pinMode(), digitalWrite(), digitalRead(). Giá trị điện áp trên mỗi chân là 5V, dòng trên mỗi chân là 20mA và bên trong có điện trở kéo lên là 20-50 ohm. Dòng tối đa trên mỗi chân là I/O không vượt quá 40mA để tránh trường hợp gây hỏng board mạch. 

Ngoài ra, một số chân Digital có chức năng đặc biệt: 
-	Serial: 0(RX) và 1(TX): Được sử dụng để nhận dữ liệu (RX) và truyền dữ liệu (TX) TTL. 
-	Ngắt ngoài: Chân 2 và 3
-	PWM: 3, 5, 6, 9 và 11 cung cấp đầu ra xung PWM với độ phân giải 8 bit bằng hàm analogWrite().
-	SPI: Có 1 LED được tích hợp trên bảng mạch và được nối vào chân D13. Khi chân có giá trị mức cao (HIGH) thì LED sẽ sáng và LED tắt khi ở mức thấp (LOW). 
-	TWI/I2C: A4 (SDA) và A5 (SCL) hỗ trợ giao tiếp I2C/TWI với các thiết bị khác. 
Arduino Uno R3 có 6 chân Analog từ A0 đến A5, đầu vào cung cấp độ phân giải là 10 bit.

2.3. Thiết kế mạch phần cứng

![image](https://user-images.githubusercontent.com/59023235/147856020-b76a0aba-077b-400d-91fd-e9ef51de053d.png)

Hình 6: Sơ đồ nối dây mạch robot dò line

Sơ đồ lắp ghép mạch phần cứng được thể hiện như hình bên trên, cụ thể như sau:
-	Các cảm biến lần lượt từ bên trái sang phải sẽ được nối tương ứng vào các chân 10, 11, 12, 13 của Arduino Uno R3
-	Nguồn âm được cấp chia 2 đường, một đường cho Arduino, 1 đường cho L298
-	Nguồn dương qua công tắc rồi chia 2 đường, một đường cho Arduino, 1 đường cho L298
-	Các cổng output của mạch điều khiển động cơ L298 nối với 2 motor để điều khiển bánh xe trái và phải
-	Các chân tín hiệu của L298 là IN1, IN2, IN3, IN4 nối lần lượt vào chân 6, 7, 8, 9 của Arduino
-	Các chân ENA và ENB của L298 nối vào chân 3 và 5 của Arduino để thực hiện băm xung

2.4. Module thiết kế phần mềm

Thuật toán dò đường thường sử dụng trong thiết kế các robot dò đường là đặt một dãy các cảm biến sắp xếp đều nhau phía trước robot. Việc lệch đường đi trong quá trình di chuyển sẽ được robot phát hiện thông qua các trạng thái của cảm biến, cụ thể: 
-	 Nếu hai cảm biến ở giữa cảm nhận được đường đi thì robot đang tiến thẳng về phía trước (hình 7.a).
-	 Nếu các cảm biến bên phải cảm nhận được đường đi thì robot di chuyển lệch về bên trái (hình 7.b).
-	 Nếu các cảm biến bên trái cảm nhận được đường đi thì robot đang di chuyển lệch sang phải (hình 7.c). 
Thuật toán này được ứng dụng khá thành công trong việc thiết kế robot dò đường. 

![image](https://user-images.githubusercontent.com/59023235/147856028-b7575f41-682f-4a0f-841f-8b585f2b2924.png)

Hình 7. Sự lệch trong quá trình di chuyển của robot. 

(a) Robot đi thẳng, (b) Robot lệch trái, (c) Robot lệch phải

Ý tưởng chính để điều khiển robot dò đường: 
-	 Khi robot di chuyển lệch sang trái của đường đi thì robot sẽ giảm dòng điện động cơ phải (giảm tốc độ bánh phải) trong khi động cơ trái vẫn hoạt động bình thường, điều này sẽ giúp cho robot quay lại đường đi ban đầu;
-	 Khi robot di chuyển lệch sang phải của đường đi thì robot sẽ giảm dòng điện động cơ trái (giảm tốc độ bánh trái) trong khi động cơ phải vẫn hoạt động bình thường để giúp robot quay trở lại đường đi ban đầu.
-	 
2.4.1. Thư viện và công cụ sử dụng

Ngôn ngữ phát triển: ngôn ngữ lập trình Arduino.
IDE phát triển: phần mềm chuyên dụng Arduino IDE.
Quản lý mã nguồn: Github.

2.4.2. Mã nguồn phát triển

Lưu đồ xử lý trong mã nguồn:

![image](https://user-images.githubusercontent.com/59023235/147856037-801d1311-a2a5-4b84-b504-0e7517849671.png)

Hình 8: Lưu đồ thuật toán mã nguồn điều khiển xe dò line 
	Thuật toán đo độ lệch:

![image](https://user-images.githubusercontent.com/59023235/147856396-c3551236-6af3-43cf-b89d-46244fdce3fa.png)


![image](https://user-images.githubusercontent.com/59023235/147856045-7ad28399-4808-4a45-a435-5416822ce864.png)

2.4.3. Phương pháp điều chế độ rộng xung (PWM)
	Tốc độ quay của động cơ một chiều tỉ lệ thuận với điện áp đầu vào. Do đó, cách đơn giản nhất để điều khiển tốc độ động cơ là thay đổi mức điện áp đặt vào động cơ. 
	Nguyên tắc cơ bản để thay đổi tốc độ đó là phương pháp PWM, cụ thể là giữ nguyên giá trị điện áp vào và thay đổi thời gian đặt điện áp vào động cơ.
	 Khi thời gian mức cao Ton trong một chu kỳ của xung ngõ vào động cơ càng lớn thì điện áp trung bình đặt vào động cơ càng cao và ngược lại khi mức thời gian thấp ta có Toff .
	Đại lượng mô tả mối quan hệ giữa khoảng thời gian Ton và Toff được gọi là độ xung (duty_cycle), được tính theo công thức sau: 
duty_cycle  = Ton/(Ton + Toff)x 100 

![image](https://user-images.githubusercontent.com/59023235/147856048-8c98bbac-67b0-455d-8565-35296356b4b9.png)

Hình 9. Giản đồ thời gian của xung PWM 

CHƯƠNG 4: QUẢN LÝ THIẾT BỊ MUA SẮM
4.1. Danh sách các thiết bị đã mua

![image](https://user-images.githubusercontent.com/59023235/147856140-48c0093e-d86e-4bbf-8803-22ac0dacc3dc.png)


4.2. So sánh và đánh giá 

![image](https://user-images.githubusercontent.com/59023235/147856154-c5fabd52-5ac2-476b-9f56-8ea720dbfbe3.png)

Kết luận: Qua các đánh giá trên nhóm quyết định mua hàng trực tiếp tại cửa hàng để đảm bảo chất lượng các linh kiện, dễ giải quyết khi phát sinh vấn đề liên quan đến linh kiện. 
Khi mua sắm trực tiếp được tư vấn để bổ sung các linh kiện còn thiếu trong dự kiến ban đầu, chênh lệch chi phí dự kiến và thực tế nằm trong khoảng cho phép. 
 
CHƯƠNG 5: QUẢN LÝ RỦI RO

Danh sách quản lý các rủi ro đã xảy ra và các hướng đề xuất:

![image](https://user-images.githubusercontent.com/59023235/147856178-04da96ab-6a3e-4ddc-bb0f-1caf726b17c9.png)


=> Lựa chọn giải quyết theo phương án 3. 
Kết luận: Thông qua những rủi ro trên nhóm đã ghi nhận được các trường hợp có thể xảy ra rủi ro đối với dự án của nhóm. Sau đó đã đưa ra được các giải pháp khắc phục kịp thời và hiệu quả để hạn chế chi phí, thời gian để đảm bảo tiến độ và chất lượng dự án.

CHƯƠNG 6: ĐÁNH GIÁ KẾT QUẢ VÀ HƯỚNG PHÁT TRIỂN

6.1. Kết quả đạt được 
- Xe Robot tự động có khả năng di chuyển theo một đường đã định sẵn 

![image](https://user-images.githubusercontent.com/59023235/147856203-07d8dd68-b8aa-44c7-a486-89460c9b3821.png)

-	Ưu điểm 
•	Thể hiện được khả năng hoàn toàn tự động của mô hình
-	Nhược điểm 
•	Thiết kế mạch , lắp ráp mất nhiều thời gian 
•	Khó khăn trong việc mua phụ kiện trong thời gian dịch bệnh

6.2. Đánh giá kết quả
-	Sau một thời gian nghiên cứu dưới sự hướng dẫn của thầy GV. Ngô Lam Trung và tìm hiểu từ các nguồn thông tin hữu ích trên mạng. Nhóm đã tận dụng tốt những thông tin và tri thức liên quan đến xe dò line để áp dụng và phát triển cho sản phẩm của nhóm. 
-	Trong quá trình từ khi lắp ráp thiết bị đến khi thực hiện code phần mềm điều khiển thiết bị, nhóm cũng gặp một số khó khăn liên quan đến phần cứng (cháy diot điều chỉnh nguồn đầu vào; mắt dò line quá nhạy), và một số khó khăn vì tình hình dịch bệnh nên cả nhóm không làm việc chung được để phát triển sản phẩm. 
-	Trước những thuận lợi và khó khăn trên, nhóm cũng đã cố gắng hoàn thiện sản phẩm ở mức độ khá tốt. Xe có thể chạy dò line theo yêu cầu được đề ra.  
6.3. Hướng phát triển trong tương lai 
-	Như đã được định hướng từ trước, sản phẩm của nhóm có thể được phát triển thêm các module tiếp theo như là ứng dụng các công nghệ thông minh AI để giúp xe thực hiện được một số chức năng thông minh khác. Những chức năng ấy có thể là nhận biết các loại tín hiệu biển báo giao thông để có thể đưa ra các hành động phù hợp với từng loại tín hiệu giao thông đó. 
