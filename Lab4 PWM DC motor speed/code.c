#include <reg52.h>
#define Tpwm 0xfc18  //PWM????????1ms,??12MHz??
unsigned int duty[]={0,/*0*/
0xff9c/*100us*/,0xff38/*200us*/,0xfed4/*300us*/,\
0xfe70/*400us*/,0xfe0c/*500us*/,0xfda8/*600us*/,\
0xfd44/*700us*/,0xfce0/*800us*/,0xfc7c/*900us*/,\
0xfc18/*1000us*/};//PWM????? 
unsigned char i=0;
sbit P32 = P3^2;
sbit P33 = P3^3;
sbit PWMOUT = P2^0;
sbit PWMIN1 = P2^1;
sbit PWMIN2 = P2^2;
bit flag = 1;//PWM??????,1????????,0????????    
void delay10ms(int n); 

void  main(void)
{
  PWMOUT = 0;//???L293D ,????
  PWMIN1 = 0;
  PWMIN2 = 1;
  EA = 1;  //????
  IT0 = 1;  //???????
  IT1 = 1;
  EX0 = 1;  //??????0  
  EX1 = 1;  //??????1 
  ET0 = 1;  //????0????
  TMOD = 0x01; //??????
  while(1)  //????
  {
  /*??????????*/
  }
}
//10ms????
void delay10ms(int n)
{
    int i=0,j;
  while(n--)
  { 
     for(i=0;i<10;i++)
     {
          for(j = 0; j < 125; j++);
      }
  }
}
void keySpeeddownISR() interrupt 0 //????????
{
  EA = 0;   //???
  delay10ms(2);  //????
  if (!P32)    //??????,????????
  {//??PWM????? 
   if(i>0)
    i--;  
   if((TR0=1) && (i == 0))
   {   
    TR0 = 0;   
    PWMOUT = 0;
   }
  }
  EA = 1;
}
void keySpeedupISR() interrupt 2 //????????
{
  EA = 0;   //???
  delay10ms(2);  //????
  if (!P33)    //??????,????????
  {//??PWM????? 
   if(i<=10)
    i++;
   if((TR0 == 0) && (i > 0))   
   {//??PWM,???????
    PWMIN1 = 0;
    PWMIN2 = 1;
    PWMOUT = 1;
    TH0 = duty[i]>>8;
    TL0 = duty[i]&0xff;
    TR0 = 1;
    flag = 1;   
   }
  }
  EA = 1;
}
void T0ISR() interrupt 1 //???0??????
{
  EA = 0;   //???
  if(flag)
  {//???????,???????PWM??
   PWMOUT = 0;
   TH0 = (65535-(duty[i]-Tpwm))>>8;
   TL0 = (65535-(duty[i]-Tpwm))&0xff;
   flag = 0;  
  }else
  {//????
   PWMOUT = 1;
   TH0 = duty[i]>>8;
   TL0 = duty[i]&0xff;
   flag = 1;
  } 
  EA = 1;
}