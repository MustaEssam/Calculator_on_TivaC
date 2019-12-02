#include "tm4c123gh.h"
#include "LCDHeader.h"



//This Function is used to send commands to the LCD
void LCD_command(unsigned char command)
{
    GPIO_PORTA_DATA_R = 0;     /* 0x20 = 0, R/W = 0 */
    GPIO_PORTB_DATA_R = command;
    GPIO_PORTA_DATA_R = 0x80;    /* pulse E */
    Delay_ms(1);			 /* Enable pulse Width */
    GPIO_PORTA_DATA_R = 0;
    if (command < 4)
        Delay_ms(2);         /* command 1 and 2 needs up to 1.64ms */
    else
        Delay_Us(40);        /* all others 40 us */
}

void LCD_data(unsigned char data)
{
    GPIO_PORTA_DATA_R = 0x20;    /* RS = 1, R/W = 0 */
    GPIO_PORTB_DATA_R = data;
    GPIO_PORTA_DATA_R = 0x80 | 0x20;   /* pulse E */
    Delay_ms(1);
    GPIO_PORTA_DATA_R = 0;
    Delay_Us(40);
}


void LCD_init(void){
	  SYSCTL_RCGCGPIO_R |=0x03;               //Enable Port A&B Clock
    while((SYSCTL_PRGPIO_R & 0x03) == 0){}; //Wait for clock stabilization
		 GPIO_PORTB_DIR_R |= 0xFF;
		 GPIO_PORTA_DIR_R |= 0xFF;
			
     GPIO_PORTB_DEN_R |= 0xFF;
		 GPIO_PORTA_DEN_R |= 0xFF;
			
		 GPIO_PORTB_AMSEL_R &= ~0xFF;
		 GPIO_PORTA_AMSEL_R &= ~0xFF;
			
		 GPIO_PORTB_AFSEL_R &= 0x00;
		 GPIO_PORTA_AFSEL_R &= 0x00;
		
			// Wake Up LCD Sequence
    Delay_ms(20);            /* initialization sequence */// Wait >15 ms after power is applied
    LCD_command(0x30);		// command 0x30 = Wake up
    Delay_ms(10);				// must wait 5ms, busy flag not available
    //LCD_command(0x30);		// command 0x30 = Wake up #2
    //Delay_ms(10);			// must wait 100us, busy flag not available
    //LCD_command(0x30);		// command 0x30 = Wake up #3
    Delay_ms(10);			// must wait 100us, busy flag not available
  // Prepare LCD Operation and Function  
    LCD_command(0x38);      /* set 8-bit data, 2-line, 5x7 font */
    LCD_command(0x06);      /* move cursor right */
    LCD_command(0x01);      /* clear screen, move cursor to home */
    LCD_command(0x0F);      /* turn on display, cursor blinking */
}



