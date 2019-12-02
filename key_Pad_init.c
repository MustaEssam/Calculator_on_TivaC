#include "tm4c123gh6pm.h"
#include "keyPad.h"

/* this function initializes the ports connected to the keypad */
void keypad_init(void)
{
    SYSCTL_RCGCGPIO_R |= 0x04;   /* enable clock to GPIOC */
    SYSCTL_RCGCGPIO_R |= 0x10;   /* enable clock to GPIOE */
    while((SYSCTL_PRGPIO_R & 0x14) == 0){}
	  GPIO_PORTE_DIR_R |= 0x0F;     /* set row pins 3-0 as output */
    GPIO_PORTE_DEN_R |= 0x0F;     /* set row pins 3-0 as digital pins */
    //GPIOE->ODR |= 0x0F;     /* set row pins 3-0 as open drain */
    
    GPIO_PORTC_DIR_R &= ~0xF0;    /* set column pin 7-4 as input */
    GPIO_PORTC_DEN_R |= 0xF0;     /* set column pin 7-4 as digital pins */
    GPIO_PORTC_PUR_R |= 0xF0;     /* enable pull-ups for pin 7-4*/

}
