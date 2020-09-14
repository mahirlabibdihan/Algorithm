#include<stdio.h>
int decoct(int n)
{
	if(n) return n%8+10*decoct(n/8);
}

int dec_oct(int n) 
{ 
    int i,s=0;    
    for(i=1;n;i*=10)
    {
       s+=(n%8)*i;
       n/=8;
    }
    return s;
} 

int main()
{
	printf("%d",decoct(8));
}