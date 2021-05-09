#include <reg52.h>
#define uchar unsigned char;
uchar i,j,num;
unsigned char display[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
void delay(k)
{ while(k--)
   { j=9650;while(j--);}
}

 main()
{    
   SCON=0x00;
 while(i<8)
 {  
   SBUF=display[i];
  while(!TI);
  TI=0;
  delay(8);
    i++;
  }
}