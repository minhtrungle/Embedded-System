#include "reg51.h"
#include "string.h"

#define LCD_DATA P2
sbit EN=P0^2;
sbit RS=P0^0;
sbit RW=P0^1;
sbit SPK  = P3^7;	
char uart_data;
//verify this table according to your CPU clock
unsigned char note_name[11][3]={"C4","d4","e4","f4","g4","a4","b4","C5","d5","e5","f5"};
code unsigned int note_table[]={
    0xf9,0x1e,        //1 c4
    0xf9,0xde,        //2 d4
    0xfa,0x89,        //3 e4
    0xfa,0xd8,        //4 f4
    0xfb,0x68,        //5 g4
    0xfb,0xe8,        //6 a4
    0xfc,0x5a,        //7 b4
	0xfc,0x8f,		  //8 c5
	0xfc,0xef,		  //9 d5 
	0xfd,0x44,		  //10 e5
	0xfd,0x6c,		  //11 f5
};
unsigned int unravel[]={7,8,7,6,5,8,7,6,5,4,3,3,4,2,
						2,2,2,2,9,9,7,6,6,6,7,7,7};
unsigned char note_index;	
unsigned char play_sound=0;	
void init();		
void Wait_For_LCD();
void LCD_Send_Command(unsigned char x);
void LCD_Write_One_Char(unsigned char c);
void LCD_Write_String(unsigned char *s);
void delay(unsigned int time); 

void main(void) 
{
	 unsigned int i;
	note_index=0;
	init();
		  LCD_Send_Command(0x01);
		LCD_Write_String("Hello");
		LCD_Send_Command(0xC0); //Chuyen con tro xuong dong thu 2
		LCD_Write_String("world...");
	for(i=0;i<27; i++){	
		note_index=unravel[i]*2;		
		TH0=note_table[note_index];
		TL0=note_table[note_index+1];			
		TR0=1;
		if((i==13)||(i==19)||(i==25))
			delay(50000);
		else 
			delay(25000);
		TR0=0;
		SPK=1;
		play_sound=0;
		delay(3000);	
	}
	while(1){

		if(play_sound==1){	
			LCD_Send_Command(0x01);	
			LCD_Write_String(note_name[note_index/2]);			
			TH0=note_table[note_index];
			TL0=note_table[note_index+1];			
			TR0=1;
			delay(50000);
			TR0=0;
			SPK=1;
			play_sound=0;		
		}
	}			
}
void LCD_Send_Command(unsigned char x)
{
	LCD_DATA=x;
	RS=0; //Chon thanh ghi lenh
	RW=0; //De ghi du lieu
	EN=1;
	delay(500);
	EN=0;		
	Wait_For_LCD(); //Doi cho LCD san sang
	EN=1;		  
}
//Ham kiem tra va cho den khi LCD san sang
void Wait_For_LCD()
{
	delay(5000);
}

//Ham de LCD hien thi mot ky tu
void LCD_Write_One_Char(unsigned char c)
{
	LCD_DATA=c; //Dua du lieu vao thanh ghi 
	RS=1; //Chon thanh ghi du lieu
	RW=0;
	EN=1;
	delay(500);	
	EN=0;
	Wait_For_LCD();	
	EN=1;
}
//Ham de LCD hien thi mot xau
void LCD_Write_String(unsigned char *s)
{
	unsigned char length;
	length=strlen(s); //Lay do dai xau
	while(length!=0)
	{
		LCD_Write_One_Char(*s); //Ghi ra LCD gia tri duoc tro boi con tro
		s++; //Tang con tro
		length--;	  		 
	}
}



void init()
{
	RW=1;
	LCD_Send_Command(0x38); //Chon che do 8 bit, 2 hang cho LCD
	LCD_Send_Command(0x0E); //Bat hien thi, nhap nhay con tro	
	LCD_Send_Command(0x01); //Xoa man hinh	
	LCD_Send_Command(0x80); //Ve dau dong
	TMOD=0x01;
	EA=1;
	ET0=1;
	TR0=0;
	  SCON = 0x50; 			/* uart in mode 1 (8 bit), REN=1 */
  TMOD = TMOD | 0x20 ; 	/* Timer 1 in mode 2 */
  TH1 = 0xFD; 			/* 9600 Bds at 11.0592MHz */
  TL1 = 0xFD; 			/* 9600 Bds at 11.0592MHz */
  ES = 1; 				/* Enable serial interrupt*/
  EA = 1; 				/* Enable global interrupt */
  TR1 = 1; 				/* Timer 1 run */
}

void timer0() interrupt 1
{
	TH0=note_table[note_index];
	TL0=note_table[note_index+1];
	SPK=~SPK;
}

void delay(unsigned int time)
{
	while(time--);
}
void serial_IT(void) interrupt 4
{
  if (RI == 1)
  { 
    RI = 0;	/* prepare for next reception */
    uart_data = SBUF; 	/* Read receive data */
			
		switch(uart_data){
			case 'a':
				note_index=0;
				play_sound=1;
				break;
			case 's':
				note_index=2;
				play_sound=1;
				break;
			case 'd':
				note_index=4;
				play_sound=1;
				break;
			case 'f':
				note_index=6;
				play_sound=1;
				break;
			case 'g':
				note_index=8;
				play_sound=1;
				break;
			case 'h':
				note_index=10;
				play_sound=1;
				break;
			case 'j':
				note_index=12;
				play_sound=1;
				break;
			case 'k':
				note_index=14;
				play_sound=1;
				break;
			case 'l':
				note_index=16;
				play_sound=1;
				break;
			case ';':
				note_index=18;
				play_sound=1;
				break;
			case '\'':
				note_index=20;
				play_sound=1;
				break;
			default:
				play_sound=0;
				break;				
		}
    SBUF = uart_data; 	/* Send back same data on uart*/
  }
  else 
    TI = 0; 			/* if emission occur */
}
