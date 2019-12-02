//LCD Project 

//Include Section 
#include "tm4c123gh6pm.h"
#include "LCDHeader.h"
#include "keyPad.h"
#include "functions.h"
#include <math.h>

#define RED       0x02
#define BLUE      0x04
#define GREEN     0x08

//Code section
void SystemInit(){};
	
void keypad_init(void);
unsigned char keypad_getkey(void);
float change_decimal (char X[], int i);
void Dec_char(int n);
float compute ( float x, float y, char z);
int decimal_nu(float n);
void PortF_Output(uint32_t data);
void PortF_Init(void);
	
	
int main(){
		unsigned char ch, opp;
		int i, deg;
		float num;
		char chart[16];
		uint8_t flag = 0;
	  LCD_init();
		keypad_init();
		PortF_Init();
		LCD_command(1);       /* clear display */
		LCD_command(0x80);    /* lcd cursor location */
	
    while(1)
    {
				i = 0;
				while(i<16){
					while(keypad_getkey() == 0){}
					ch = keypad_getkey();
					LCD_data(ch);
					Delay_ms(500000);
					if ((ch!= '+')&& (ch!='-')&& (ch!='*')&& (ch!='/')&&(ch!='=')){
						chart[i] = ch;
						i++;
					}
					else if (ch == '=' && i !=0 && flag == 1){   
						LCD_command(0xC0);
						num = compute(num, change_decimal(chart, i), opp);
						Dec_char(num);
						if((num - (int) num) !=0){
							num = (num - (int) num) * pow(10, decimal_nu(num));
							LCD_data('.');
							Dec_char(num);
						}
						PortF_Output(GREEN);
						break;
					}
					else if (((ch == '+')|| (ch =='-')|| (ch =='*')|| (ch =='/')) && (flag == 0)){
						opp = ch;
						num = change_decimal(chart, i);
						flag = 1;
						break;
					}
					else{
						PortF_Output(RED);
						LCD_command(0xC0);
						LCD_data('E');
						LCD_data('R');
						LCD_data('R');
						LCD_data('O');
						LCD_data('R');
						flag = 1;
						break;
					}
				}
				
    }
}
