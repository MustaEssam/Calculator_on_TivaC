#include "tm4c123gh6pm.h"
#include "functions.h"
#include <math.h>


float change_decimal (char X[], int size)
{
    int j;
		float res=0;
		int i=0;
    float counter1=0;
    float counter2=0;
    int num[10];
	
			while (X[i]!='.' && (i < size)){
					switch (X[i])
					{
							case '1':
							num[i]=1;
							counter1=counter1+1;
							i++;
							break;

							case '2':
							num[i]=2;
							counter1=counter1+1;
							i++;
							break;

							case '3':
							num[i]=3;
							counter1=counter1+1;
							i++;
							break;

							case '4':
							num[i]=4;
							counter1=counter1+1;
							i++;
							break;

							case '5':
							num[i]=5;
							counter1=counter1+1;
							i++;
							break;

							case '6':
							num[i]=6;
							counter1=counter1+1;
							i++;
							break;

							case '7':
							num[i]=7;
							counter1=counter1+1;
							i++;
							break;

							case '8':
							num[i]=8;
							counter1=counter1+1;
							i++;
							break;

							case '9':
							num[i]=9;
							counter1=counter1+1;
							i++;
							break;

							}
					}


			 if (X[i]=='.')
			 {

							i++;

							while (i < size)
							{


									switch (X[i])
									{
										 case '1':
											num[i-1]=1;
											counter2=counter2+1;
											i++;
											break;

											case '2':
											num[i-1]=2;
											counter2=counter2+1;
											i++;
											break;

											case '3':
											num[i-1]=3;
											counter2=counter2+1;
											i++;
											break;

											case '4':
											num[i-1]=4;
											counter2=counter2+1;
											i++;
											break;

											case '5':
											num[i-1]=5;
											counter2=counter2+1;
											i++;
											break;

											case '6':
											num[i-1]=6;
											counter2=counter2+1;
											i++;
											break;

											case '7':
											num[i-1]=7;
											counter2=counter2+1;
											i++;
											break;

											case '8':
											num[i-1]=8;
											counter2=counter2+1;
											i++;
											break;

											case '9':
											num[i-1]=9;
											counter2=counter2+1;
											i++;
											break;
									}
					}
			}

    i=0;
    j =counter1+counter2;
    while (i<j)
    {
        res=res+num[i]*(pow(10,counter1-1));
        i++;
        counter1--;
    }
     return res;
}

