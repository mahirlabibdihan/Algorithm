#include<stdio.h>
#include<string.h>
int Pallindrome(char* s)
{
    int i,n=strlen(s);
    for(i=0;i<n-i-1;i++)
    {
        if(s[i]!=s[n-i-1])
            return 0;
    }
    return 1;
}

main()
{
    printf("%d",Pallindrome("madmadam"));
}
