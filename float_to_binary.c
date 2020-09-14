#include <stdio.h>

int decbin(int n)
{
	if(!n) return 0;
    return n%2+10*decbin(n/2);
}

float floatbin(float n)
{
	int i,a=0,c=n;  
	float j,b=0,d=n-c;  

    for(i=1;c;i*=10)
    {
        a+=(c%2)*i;
        c/=2;
    }

	for(j=1;d;j/=10)
	{	
		b+=int(d)*j;	
		d=(d-int(d))*2;		
	}

	return a+b;
}
int main()
{
	float n; 
	scanf("%f",&n);    
	printf("%f",floatbin(n));
}

