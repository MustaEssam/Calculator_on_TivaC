#include "tm4c123gh6pm.h"
#include "functions.h"
//#include <stdlib.h>
#include <math.h>


float compute ( float x, float y, char z)
{
	switch(z){
		case '+':
			return x+y;
		case '-':
			return x-y;
		case '*':
			return x*y;
		default:
			return x/y;
	}
}
