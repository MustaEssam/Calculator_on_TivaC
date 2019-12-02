/* If a key is pressed, it returns the key label in ASCII*/
/*
The function will return 0 if non of the keys is pressed 
*/
#include "tm4c123gh6pm.h"
#include "keyPad.h"
unsigned char keypad_getkey(void)
{
    const unsigned char keymap[4][4] = {
        { '1', '2', '3', '+'},
        { '4', '5', '6', '-'},
        { '7', '8', '9', '*'},
        { '.', '0', '=', '/'},
    };    
    int row, col;
		int i, check;
		int output_E[4] = {0x0E, 0x0D, 0x0B, 0x07}; 
		GPIO_PORTE_DATA_R = 0;               /* enable all rows */
		Delay_ms(20); 		 //Switch debouncing 
		switch (GPIO_PORTC_DATA_R & 0xF0){
		case 0xF0: return 0;
		case 0xE0: col=0; break; /* key in column 0 */
    case 0xD0: col=1; break;/* key in column 1 */
    case 0xB0: col=2; break;/* key in column 2 */
    case 0x70: col=3; break;/* key in column 3 */ 
		}
	for (i=0 ;i<4; i++)
	{
	GPIO_PORTE_DATA_R = output_E[i];
	Delay_Us(2);                     /* wait for signal to settle */
	check = GPIO_PORTC_DATA_R & 0xF0;
  if (check != 0xF0) break;
	}
	row = i;
return keymap[row][col]; 
}
    /* check to see any key pressed first */
//    GPIO_PORTE_DATA_R = 0;               /* enable all rows */
//    col = GPIO_PORTC_DATA_R & 0xF0;      /* read all columns */
//    if (col == 0xF0) return 0;          /* no key pressed */

//    /* If a key is pressed, it gets here to find out which key. */
//    /* Although it is written as an infinite loop, it will take one of the breaks or return in one pass.*/
//		    while (1)
//    {
//        row = 0;
//        GPIO_PORTE_DATA_R = 0x0E;        /* enable row 0 */
//        Delay_Us(2);                     /* wait for signal to settle */
//        col = GPIO_PORTC_DATA_R & 0xF0;
//        if (col != 0xF0) break;
//        
//        row = 1;
//        GPIO_PORTE_DATA_R = 0x0D;        /* enable row 1 */
//        Delay_Us(2);                     /* wait for signal to settle */
//        col = GPIO_PORTC_DATA_R & 0xF0;
//        if (col != 0xF0) break;
//        
//        row = 2;
//        GPIO_PORTE_DATA_R = 0x0B;        /* enable row 2 */
//        Delay_Us(2);                     /* wait for signal to settle */
//        col = GPIO_PORTC_DATA_R & 0xF0;
//        if (col != 0xF0) break;
//        
//        row = 3;
//        GPIO_PORTE_DATA_R = 0x07;        /* enable row 3 */
//        Delay_Us(2);                     /* wait for signal to settle */
//        col = GPIO_PORTC_DATA_R & 0xF0;
//        if (col != 0xF0) break;
//        
//        return 0;   /* if no key is pressed */
//    }
//    
//    /* gets here when one of the rows has key pressed */
//    if (col == 0xE0) return keymap[row][0]; /* key in column 0 */
//    if (col == 0xD0) return keymap[row][1]; /* key in column 1 */
//    if (col == 0xB0) return keymap[row][2]; /* key in column 2 */
//    if (col == 0x70) return keymap[row][3]; /* key in column 3 */ 
//    return 0;   /* just to be safe */
//}
//GET KEY FUNCTION WITH SWITCH DEBOUNCING AND SINGLE PRESS SINGLE ENTRY PRECAUTION 
//unsigned char keypad_getkey(void)
//{
//    const unsigned char keymap[4][4] = {
//        { '1', '2', '3', 'A'},
//        { '4', '5', '6', 'B'},
//        { '7', '8', '9', 'C'},
//        { '*', '0', '#', 'D'},
//    };    
//    int row, col;
//    /* check to see any key pressed first */
//    GPIO_PORTE_DATA_R = 0;               /* enable all rows */
//    col = GPIO_PORTC_DATA_R & 0xF0;      /* read all columns */
//    if (col == 0xF0) return 0;          /* no key pressed */
//    Delay_ms(20);                       //Switch debouncing 
//    /* If a key is pressed, it gets here to find out which key. */
//    /* Although it is written as an infinite loop, it will take one of the breaks or return in one pass.*/
//		    while (1)
//    {
//        row = 0;
//        GPIO_PORTE_DATA_R = 0x0E;        /* enable row 0 */
//        Delay_Us(2);                     /* wait for signal to settle */
//        col = GPIO_PORTC_DATA_R & 0xF0;
//        if (col != 0xF0) break;
//        
//        row = 1;
//        GPIO_PORTE_DATA_R = 0x0D;        /* enable row 1 */
//        Delay_Us(2);                     /* wait for signal to settle */
//        col = GPIO_PORTC_DATA_R & 0xF0;
//        if (col != 0xF0) break;
//        
//        row = 2;
//        GPIO_PORTE_DATA_R = 0x0B;        /* enable row 2 */
//        Delay_Us(2);                     /* wait for signal to settle */
//        col = GPIO_PORTC_DATA_R & 0xF0;
//        if (col != 0xF0) break;
//        
//        row = 3;
//        GPIO_PORTE_DATA_R = 0x07;        /* enable row 3 */
//        Delay_Us(2);                     /* wait for signal to settle */
//        col = GPIO_PORTC_DATA_R & 0xF0;
//        if (col != 0xF0) break;
//        
//        return 0;   /* if no key is pressed */
//    }
//    while((GPIO_PORTC_DATA_R & 0xF0)!=0xF0);//wait for switch release
//		Delay_ms(20);                       //Switch debouncing 
//    /* gets here when one of the rows has key pressed */
//    if (col == 0xE0) return keymap[row][0]; /* key in column 0 */
//    if (col == 0xD0) return keymap[row][1]; /* key in column 1 */
//    if (col == 0xB0) return keymap[row][2]; /* key in column 2 */
//    if (col == 0x70) return keymap[row][3]; /* key in column 3 */ 
//    return 0;   /* just to be safe */
//}
