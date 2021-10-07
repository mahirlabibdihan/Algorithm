#include<bits/stdc++.h>
using namespace std;

int main()
{
     //index 0 is the right most bit

     bitset<10> x;  //00000000000

     bitset<8> y( ((1<<3)-1)<<2);  //0000000111

     bitset<10> z("1001"); //0000001001

     x.set(6);
     x[7]=1;  //if use 0 then the bit becomes 0. Bit becomes 1 for everything except 0;


     //if(x.test(7))//check if 1//if(x[7])


    // cout<<(y^z).count(); //cout the different bits of two numbers

    cout<<y; //decimal representation



}
