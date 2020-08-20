#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;

    if(n&1) cout<<"Odd"; //if(n%2) cout<<"Odd";

    if(n&n-1) cout<<"NO";
    else cout<<"YES";   //2^n check

    if(n&n+1) cout<<"NO";
    else cout<<"YES";   //2^n-1 check



    1<<n; //2^n;

    x<<n; //x*(2^n);
    x>>n; //x/(2^n);

    x&(2^n-1); //x%(2^n);








}
