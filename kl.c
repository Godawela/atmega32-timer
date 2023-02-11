

#include <mega32a.h>  // atmega 32A header file
#include <alcd.h>  // Alphanumeric LCD Module functions
#include <stdlib.h>  //int to string
#include <delay.h>   // delay header
     
#define BUTTON PORTD.0;
#define LDR_INPUT PORTB.0
#define LAMP_OUTPUT PORTD.2
#define BUZZER_OUTPUT PORTD.3

unsigned char z,s,m,h=2,ss[4],sm[4],sh[4],ts=0,tm=0,th=0,sts[4],stm[4],sth[4];

 

 

interrupt [TIM2_OVF] void timer2_ovf_isr(void)
{
if (PIND.0==0) { 
        
          
if(s==60){s=0;m++;};
if (m==60){s=0;m=0;h++;};
if(h==24){s=0;m=0;h=0;};
lcd_clear();

lcd_gotoxy(6,0);
itoa(s,ss);
lcd_puts(ss);

lcd_gotoxy(5,0);
lcd_putchar(':');

lcd_gotoxy(3,0);
itoa(m,sm);
lcd_puts(sm);

lcd_gotoxy(2,0);
lcd_putchar(':');

lcd_gotoxy(0,0);
itoa(h,sh);
lcd_puts(sh);




s++;



if (h==2) { 
        z=h; 
       s=0;  
       h=0;
       m=0;
   lcd_gotoxy(16,0);
   lcd_puts("Get Up"); 
   BUZZER_OUTPUT=1;
   delay_ms(200); 
   BUZZER_OUTPUT=0;
   
   
   
};

 

}


};

// Timer2 output compare interrupt service routine
interrupt [TIM2_COMP] void timer2_comp_isr(void)
{
   


if (PIND.0==1) {  
                
                    
                ts=ts+s; 
                tm=tm+m;
                th=th+h+z;   
                
                if(ts>=60){
                    
                    ts=ts-60;
                    tm++;
                } ;
                
               
                if (tm>=60){
                    ts=0;
                    tm=tm-60;
                    th++;
                } ;
               
                if(th>=24){
                    ts=0;
                    tm=0;
                    th=0;
                };                

                lcd_clear();
                lcd_gotoxy(6,0);
                itoa(ts,sts);
                lcd_puts(sts);

                lcd_gotoxy(5,0);
                lcd_putchar(':');

                lcd_gotoxy(3,0);
                itoa(tm,stm);
                lcd_puts(stm);

                lcd_gotoxy(2,0);
                lcd_putchar(':');

                lcd_gotoxy(0,0);
                itoa(th,sth);
                lcd_puts(sth);   
                
                lcd_gotoxy(16,0);
                lcd_puts("Daily Prograss");
                
                delay_ms(200);      
                
                s=0;
                m=0;
                h=0; 
                z=0;
                
                
               
};



if (PIND.0==1) {
         s=0;
         
};

}
 
  


void main(void){



 

DDRA=0xFF;    //lcd display 
DDRB=0X00;   //ldr input
DDRD=0x00;  // pir input
DDRD.2=0XFF; // lamp output
DDRD.3=0XFF;   //buzzer output

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=0x00;
TCNT0=0x00;
OCR0=0x00;


TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: TOSC1 pin
// Clock value: PCK2/128
// Mode: Fast PWM top=0xFF
// OC2 output: Non-Inverted PWM
ASSR=0x08;
TCCR2=0x6D;
TCNT2=0x00;
OCR2=0x80;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0xC0;

// USART initialization
// USART disabled
UCSRB=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC disabled
ADCSRA=0x00;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;


lcd_init(16);
       

// Global enable interrupts
#asm("sei")
          
while (1) 
      
    { 
      while (1)
      {
            if (PINB.0==1) { 
                LAMP_OUTPUT=1; 
                
    }
          else  { 
                LAMP_OUTPUT=0; 
                   
            };


      }

  }
}