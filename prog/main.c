#include <mega16.h>
#include <alcd.h>
#include <delay.h>
#include <stdio.h>

void main(void)
{
int A=0,B=0,C=0,D=0;
char Buffer[32];

DDRB=0x00;          //Input
PORTB=0xff;         //Pull Up

// Alphanumeric LCD init
lcd_init(16);
lcd_clear();

lcd_gotoxy(0,0);
lcd_puts(" A   B   C   D  ");
lcd_gotoxy(0,1); 
lcd_puts("--- --- --- --- "); 

while (1)
      {
      while((PINB&0x0f)==0x0f);    // Wait until Key press
       
      if(PINB.0==0)A++;
      if(PINB.1==0)B++;
      if(PINB.2==0)C++;
      if(PINB.3==0)D++; 
       
      sprintf(Buffer,"%03d %03d %03d %03d",A,B,C,D);
      lcd_gotoxy(0,1);
      lcd_puts(Buffer);
       
      while((PINB&0x0f)!=0xf);    // Wait for drop Key  
      delay_ms(5);                // Debuncing 
      }
}
