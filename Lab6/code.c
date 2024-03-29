#include<reg51.h>


#include<absacc.h>


typedef unsigned char uchar;


typedef unsigned int uint;


#define LLCD_CMD_WR PBYTE[0x10]


#define LLCD_CMD_RD PBYTE[0x11]


#define LLCD_DATA_WR PBYTE[0x12]


#define LLCD_DATA_RD PBYTE[0x13]





#define RLCD_CMD_WR PBYTE[0x20]


#define RLCD_CMD_RD PBYTE[0x21]


#define RLCD_DATA_WR PBYTE[0x22]


#define RLCD_DATA_RD PBYTE[0x23]


sbit busy=P0^1;





uchar code hz0[]=


{


/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x04,0x24,0x44,0x84,0x64,0x9C,0x40,0x30,0x0F,0xC8,0x08,0x08,0x28,0x18,0x00,0x00,


0x10,0x08,0x06,0x01,0x82,0x4C,0x20,0x18,0x06,0x01,0x06,0x18,0x20,0x40,0x80,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x40,0x40,0x42,0xCC,0x00,0x00,0xFC,0x04,0x02,0x00,0xFC,0x04,0x04,0xFC,0x00,0x00,


0x00,0x40,0x20,0x1F,0x20,0x40,0x4F,0x44,0x42,0x40,0x7F,0x42,0x44,0x43,0x40,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x80,0x60,0xF8,0x07,0x04,0xE4,0x24,0x24,0x24,0xFF,0x24,0x24,0x24,0xE4,0x04,0x00,


0x00,0x00,0xFF,0x00,0x80,0x81,0x45,0x29,0x11,0x2F,0x41,0x41,0x81,0x81,0x80,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0x00,0xFE,0x22,0x22,0x22,0x22,0xFE,0x22,0x22,0x22,0x22,0xFE,0x00,0x00,0x00,


0x80,0x60,0x1F,0x02,0x02,0x02,0x02,0x7F,0x02,0x02,0x42,0x82,0x7F,0x00,0x00,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0x00,0xF8,0x49,0x4A,0x4C,0x48,0xF8,0x48,0x4C,0x4A,0x49,0xF8,0x00,0x00,0x00,


0x10,0x10,0x13,0x12,0x12,0x12,0x12,0xFF,0x12,0x12,0x12,0x12,0x13,0x10,0x10,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0x00,0x00,0xFE,0x20,0x20,0x20,0x20,0x20,0x3F,0x20,0x20,0x20,0x20,0x00,0x00,


0x00,0x80,0x60,0x1F,0x02,0x02,0x02,0x02,0x02,0x02,0xFE,0x00,0x00,0x00,0x00,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x10,0x10,0xD0,0xFF,0x90,0x10,0x00,0xFE,0x02,0x02,0x02,0xFE,0x00,0x00,0x00,0x00,


0x04,0x03,0x00,0xFF,0x00,0x83,0x60,0x1F,0x00,0x00,0x00,0x3F,0x40,0x40,0x78,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0x00,0xFE,0x02,0x02,0xF2,0x92,0x9A,0x96,0x92,0x92,0xF2,0x02,0x02,0x02,0x00,


0x80,0x60,0x1F,0x40,0x20,0x17,0x44,0x84,0x7C,0x04,0x04,0x17,0x20,0x40,0x00,0x00,


};





uchar code hz1[]=


{


/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x04,0x84,0x84,0xFC,0x84,0x84,0x00,0xFE,0x92,0x92,0xFE,0x92,0x92,0xFE,0x00,0x00,


0x20,0x60,0x20,0x1F,0x10,0x10,0x40,0x44,0x44,0x44,0x7F,0x44,0x44,0x44,0x40,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0x00,0x02,0x02,0xFE,0x42,0x82,0x02,0x42,0x72,0x4E,0x40,0xC0,0x00,0x00,0x00,


0x80,0x40,0x30,0x0C,0x83,0x80,0x41,0x46,0x28,0x10,0x28,0x46,0x41,0x80,0x80,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0x00,0xFC,0x04,0x44,0x84,0x04,0x25,0xC6,0x04,0x04,0x04,0x04,0xE4,0x04,0x00,


0x40,0x30,0x0F,0x40,0x40,0x41,0x4E,0x40,0x40,0x63,0x50,0x4C,0x43,0x40,0x40,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0x00,0xFE,0x22,0x22,0x22,0x22,0xFE,0x22,0x22,0x22,0x22,0xFE,0x00,0x00,0x00,


0x80,0x60,0x1F,0x02,0x02,0x02,0x02,0x7F,0x02,0x02,0x42,0x82,0x7F,0x00,0x00,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x10,0x10,0x10,0xFF,0x10,0x90,0x08,0x88,0x88,0x88,0xFF,0x88,0x88,0x88,0x08,0x00,


0x04,0x44,0x82,0x7F,0x01,0x80,0x80,0x40,0x43,0x2C,0x10,0x28,0x46,0x81,0x80,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0x10,0x10,0x10,0x10,0xD0,0x30,0xFF,0x30,0xD0,0x12,0x1C,0x10,0x10,0x00,0x00,


0x10,0x08,0x04,0x02,0x01,0x00,0x00,0xFF,0x00,0x00,0x01,0x02,0x04,0x08,0x10,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x20,0xA4,0xA4,0xA4,0xFF,0xA4,0xB4,0x28,0x84,0x70,0x8F,0x08,0x08,0xF8,0x08,0x00,


0x04,0x0A,0x49,0x88,0x7E,0x05,0x04,0x84,0x40,0x20,0x13,0x0C,0x33,0x40,0x80,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x24,0x24,0xA4,0xFE,0x23,0x22,0x00,0x3E,0x22,0x22,0x22,0x22,0x22,0x3E,0x00,0x00,


0x08,0x06,0x01,0xFF,0x01,0x06,0x40,0x49,0x49,0x49,0x7F,0x49,0x49,0x49,0x41,0x00,


};





uchar code hz2[]=


{


/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x08,0x04,0x93,0x92,0x96,0x9A,0x92,0xFA,0x94,0x93,0x92,0x96,0xFA,0x02,0x02,0x00,


0x40,0x40,0x47,0x24,0x24,0x14,0x0C,0xFF,0x04,0x04,0x24,0x44,0x24,0x1C,0x00,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,0x00,


0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0xFE,0x20,0x20,0x3F,0x20,0x00,0xFC,0x24,0xE4,0x24,0x22,0x23,0xE2,0x00,0x00,


0x80,0x7F,0x01,0x01,0xFF,0x80,0x60,0x1F,0x80,0x41,0x26,0x18,0x26,0x41,0x80,0x00,





/*--  ??:  ,  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,


0x00,0x00,0x58,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x40,0x40,0x42,0xCC,0x00,0x00,0x00,0x00,0x00,0xFF,0x40,0x40,0x40,0x40,0x00,0x00,


0x00,0x00,0x00,0x3F,0x50,0x48,0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x40,0x40,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x20,0x24,0x24,0x24,0xFE,0x23,0x22,0x20,0x20,0xFF,0x20,0x22,0x2C,0xA0,0x20,0x00,


0x00,0x08,0x48,0x84,0x7F,0x02,0x41,0x40,0x20,0x13,0x0C,0x14,0x22,0x41,0xF8,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0x80,0x60,0xF8,0x07,0x00,0xF8,0x01,0x06,0x00,0x04,0x04,0x04,0xFC,0x00,0x00,


0x01,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x40,0x80,0x7F,0x00,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0x00,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x00,0x00,


0x00,0x04,0x84,0x44,0x24,0x17,0x04,0x04,0x04,0x04,0x17,0x24,0x44,0x84,0x04,0x00,








};





uchar code hz3[]=


{


/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0x00,0xFE,0x02,0x12,0x92,0x92,0x92,0x92,0x92,0x92,0x12,0x02,0xFE,0x00,0x00,


0x00,0x00,0xFF,0x00,0x00,0x1F,0x08,0x08,0x08,0x08,0x1F,0x40,0x80,0x7F,0x00,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x40,0x40,0x42,0xCC,0x00,0x80,0x88,0x88,0xFF,0x88,0x88,0xFF,0x88,0x88,0x80,0x00,


0x00,0x40,0x20,0x1F,0x20,0x40,0x50,0x4C,0x43,0x40,0x40,0x5F,0x40,0x40,0x40,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x40,0x40,0x40,0x7C,0x40,0x40,0x40,0xFF,0x44,0x44,0x44,0x44,0x44,0x40,0x40,0x00,


0x80,0x90,0x88,0x46,0x40,0x40,0x20,0x2F,0x10,0x10,0x08,0x04,0x02,0x00,0x00,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,


0x00,0x00,0x04,0x08,0x18,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0x00,0xF8,0x88,0x88,0x88,0x88,0x08,0x08,0xFF,0x08,0x09,0x0A,0xC8,0x08,0x00,


0x80,0x60,0x1F,0x00,0x10,0x20,0x1F,0x80,0x40,0x21,0x16,0x18,0x26,0x41,0xF8,0x00,





/*--  ??:  ?  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x80,0x80,0x80,0x80,0xFF,0x80,0x80,0xA0,0x90,0x88,0x84,0x82,0x80,0x80,0x80,0x00,


0x00,0x00,0x00,0x00,0xFF,0x40,0x21,0x12,0x04,0x08,0x10,0x20,0x20,0x40,0x40,0x00,





/*--  ??:  !  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,


0x00,0x00,0x00,0x33,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,





/*--  ??:  !  --*/


/*--  ??12;  ??????????:?x?=16x16   --*/


0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,


0x00,0x00,0x00,0x33,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,








};





void lcd_cmd_wr(uchar cmdcode,uchar f);


void lcd_data_wr(uchar ldata,uchar f);


void chech_busy(uchar f);


void lcd_hz_wr(uchar posx,uchar posy,uchar *hz);


void lcd_str_wr(uchar row,uchar col,uchar n,uchar *str);


void lcd_rol();


void lcd_init();


void delay(uint n);





void main()


{


  while(1)


  {


   lcd_init();


   lcd_str_wr(0,0,8,hz0);


   delay(100);


   lcd_str_wr(1,0,8,hz1);


   delay(100);


   lcd_str_wr(2,0,8,hz0);


   delay(100);


   lcd_str_wr(3,0,8,hz1);


   delay(100);


   lcd_rol();


   delay(1000);


   lcd_rol();


   delay(1000);


  }


}





void lcd_init()


{


  uint i;


  lcd_cmd_wr(0x3f,0);


  lcd_cmd_wr(0xc0,0);


  lcd_cmd_wr(0xb8,0);


  lcd_cmd_wr(0x40,0);


  lcd_cmd_wr(0x3f,1);


  lcd_cmd_wr(0xc0,1);


  lcd_cmd_wr(0xb8,1);


  lcd_cmd_wr(0x40,1);


  for(i=0;i<256;i++)


  {


    lcd_data_wr(0x00,0);


	lcd_data_wr(0x00,1);


  }


  lcd_cmd_wr(0xb8+4,0);


  lcd_cmd_wr(0xb8+4,1);


  for(i=0;i<256;i++)


  {


    lcd_data_wr(0x00,0);


	lcd_data_wr(0x00,1);


  }


}





void lcd_cmd_wr(uchar cmdcode,uchar f)


{


  chech_busy(f);


  if(f==0) LLCD_CMD_WR=cmdcode;


  else RLCD_CMD_WR=cmdcode;


}





void chech_busy(uchar f)


{


  if(f==0) LLCD_CMD_RD;


  else RLCD_CMD_RD;


  while(busy);


}





void lcd_str_wr(uchar row,uchar col,uchar n,uchar *str)


{


  uchar i;


  for(i=0;i<n;i++)


  {


    lcd_hz_wr(row,col,str+i*32);


	delay(50);


	col++;


  }


}





void lcd_hz_wr(uchar posx,uchar posy,uchar *hz)


{


  uchar i;


  if(posy<4)


  {


    lcd_cmd_wr(0xb8+2*posx,0);


	lcd_cmd_wr(0x40+16*posy,0);


	for(i=0;i<16;i++) lcd_data_wr(hz[i],0);


	lcd_cmd_wr(0xb8+2*posx+1,0);


	lcd_cmd_wr(0x40+16*posy,0);


	for(i=16;i<32;i++) lcd_data_wr(hz[i],0);


  }


  else


  {


    lcd_cmd_wr(0xb8+2*posx,1);


	lcd_cmd_wr(0x40+16*(posy-4),1);


	for(i=0;i<16;i++) lcd_data_wr(hz[i],1);


	lcd_cmd_wr(0xb8+2*posx+1,1);


	lcd_cmd_wr(0x40+16*(posy-4),1);


	for(i=16;i<32;i++) lcd_data_wr(hz[i],1); 


  }


}





void lcd_data_wr(uchar ldata,uchar f)


{


  chech_busy(f);


  if(f==0) LLCD_DATA_WR=ldata;


  else RLCD_DATA_WR=ldata;


}





void lcd_rol()


{


  uchar i;


  for(i=0;i<64;i++)


  {


    lcd_cmd_wr(0xc0+i,0);


	lcd_cmd_wr(0xc0+i,1);


	delay(10);


  }


}





void delay(uint n)


{


  uint i;


  for(;n>0;n--)


	  for(i=500;i>0;i--);


}
