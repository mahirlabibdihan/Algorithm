#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
	

	//If we don't use srand() it will generate the same sets of numbers in every execution. Because random number uses a fixed algorithm to generate numbers . So every it will use the same algorithm and generate same number .
	printf("%d\n",rand());//Generates Same number every time

	//If we use srand() and a pass an unsigned integer to it , rand() will generate numbers on the basis of this integer . But to generate different number on every execution we need to pass different numbers to srand() everytime .
	srand(11);printf("%d\n",rand()); //Generates Same number every time

	// To automatically pass different number to srand() each time we can pass time(NULL) to srand() . time(NULL) returns  the number of seconds elapsed since January 1,1970 . So the value time(NULL) is increasing every second . Thus the generated random numbers will be different each time .
	srand(time(NULL)); printf("%d\n",rand());//Generates Different number every time
	

	// Generates 10 Random Numbers from min to max
	int i,min=1,max=6;
	for(i=0;i<10;i++)
	printf("%d\n",rand()%(max-min+1)+min);
} 