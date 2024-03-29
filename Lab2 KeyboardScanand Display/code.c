#include<reg52.h>
#define RELOAD_H  ( 65536-50000)/256;  //?????0???
#define RELOAD_L  ( 65536-50000)%256;
extern void BEEP(unsigned int time);
extern void Timer0_Init(void);
extern void Delay(unsigned int n);
extern void Scan_Key(void);
unsigned char ptr,m;
unsigned char dispcode[6];             //????????????

sbit Beep=P2^0;                     //???????
void main(void)
{ 
  Timer0_Init( );
   BEEP(100);
   while(1)
   { 
  Scan_Key();              //????
  }                 
}
void Timer0_Init(void)          //???0???  
{ 
  TMOD=0x01;                  //???0,??1
   TL0=RELOAD_L;               //TL0???0?8????
   TH0=RELOAD_H;              //TH0???0?8????
   TR0=1;                 //???/???0???.
                    //TR0=1:??????? 
  ET0=1;                       //???/???0????
  EA=1;                  //??????
}
void Timer0_ISR(void) interrupt 1      //???0??????
{
  
   static unsigned char j=0;
   P0=(j<<4)|dispcode[j];          //?????????        
  if((++j)>1) {j=0;}
  TL0=RELOAD_L;               //???0???? 
   TH0=RELOAD_H; 
}
void Delay(unsigned int n)            //??
{ 
  unsigned int i,j;
    for(i=0;i<n;i++)
    {
    for(j=0;j<10;j++); 
  }
}
void BEEP(unsigned char n)
{ 
  Beep=0;
   Delay(50);
   Beep=1;
}
unsigned  char tab[16]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
            0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0x10  };//?????
void Scan_Key(void)                 // ?????? 
{
  char a1,i;
  bit FLAG0=0;
  a1=0xf7;                         //?????
  ptr=0;                  
  for(i=0;i<4;i++)                //??4????
  {   P1=a1;
     Delay(10);
      m=P1;
      switch(m&0xf0)              //????4?,???????????
      { 
      case 0x70:  ptr=i*4;    //???????  ????tab[i*4]?
      FLAG0=1;            //?????
      break;          
       case 0xb0:  ptr=i*4+1;    //???????  ????tab[i*4+1]?
      FLAG0=1;
      break;
       case 0xd0:  ptr=i*4+2;    //???????  ????tab[i*4+2]?
      FLAG0=1;
        break;
      case 0xe0:  ptr=i*4+3;    //???????????tab[i*4+3]?
      FLAG0=1;
      break;
      default:  break;
    }
       if( FLAG0 ) 
     {                          //????????????
      dispcode[0]=tab[ptr] % 10;  //??????
       dispcode[1]=tab[ptr] / 10;  //???????
       BEEP(200);
      break;  
    }
    a1=a1>>1 | 0x80;          //???1,??P1.4~P1.7??+5V,
                    //?????????
  }
}
