#include<stdio.h>

int gcd(int a, int b)
{
    if(!a) return b;
    return gcd(b%a,a);
}


int Gcd(int a,int b)

{
    while(a)
     {
        int c=a;
        a=b%a;
        b=c;
     }

     return b;

}

int main()
{
    int a=540,b=648;
    printf("%d",gcd(a,b));
}
