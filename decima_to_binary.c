#include<stdio.h>
int decbin(int n)
{
	if(n) return n%2+10*decbin(n/2);
}

int dec_bin(int n) 
{ 
    int i,s=0;
    
    for(i=1;n;i*=10)
    {
       s+=(n%2)*i;
       n/=2;
    }
    return s; 
} 

int main()
{
	printf("%d",decbin(5));
}
