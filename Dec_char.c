#include "tm4c123gh6pm.h"
#include "functions.h"
#include "LCDHeader.h"


void Dec_char(int n){
  if(n >= 10){
    Dec_char(n/10);
    n = n%10;
  }
   LCD_data(n+'0');
}


int decimal_nu(float n){
	int i = 1;
	n *= 10;
	while(n-((int)n) != 0){
		i++;
		n *= 10;
	}
	return i;
}
