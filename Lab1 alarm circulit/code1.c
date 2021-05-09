#include <reg52.h>
unsigned char count;
unsigned char i=0;
sbit LS1=P1^0;
sbit SW1=P1^7;
unsigned char code table[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f,0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe,0x00,0xff,0x01};//??????????


/******???????**********/
void delay(void)
{
  unsigned char m,n,s;
  for(m=20;m>0;m--)
  for(n=20;n>0;n--)
  for(s=248;s>0;s--);
}
//////////////////////////////



/********?????*********/
void dely500(void)
{
  unsigned char i;
  for(i=250;i>0;i--);
}
/////////////////////////////

void main(void)
{
  while(1)
  {
    if(SW1==0)
    {
      for(count=200;count>0;count--)
      {
        
          LS1=~LS1;//???????????
        dely500();
      }   
  if (table[i]!=0x01)
      {
      P2=table[i];
         i++;
      delay();
    }
    else i=0;
  }    
  }
}
