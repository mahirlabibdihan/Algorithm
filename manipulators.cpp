#include<bits/stdc++.h>
using namespace std;

int main()
{
   double n=100.345;
   int m=10;


   //prefix 'no' means undo

   cout<<boolalpha<<(n==10)<<endl;  boolalpha(cout); //prints in boolean format (true/false);
   cout<<noboolalpha<<(n==10)<<endl<<endl;

   cout<<showbase<<m<<endl; showbase(cout); //shows the base of number(hex->0x, oct->0, dec,bin->nothing);
   cout<<hex<<m<<endl;  
   cout<<uppercase<<m<<endl;   uppercase(cout); //prints in uppercase letter
   cout<<noshowbase<<m<<endl;  
   cout<<nouppercase<<m<<endl;
   cout<<dec<<m<<endl<<endl;

   cout<<showpos<<n<<endl;   showpos(cout); //prints '+' before positive number
   cout<<noshowpos<<n<<endl<<endl;

   cout<<setprecision(10)<<n<<endl;  //total 10 digits including float digits
   cout<<fixed<<setprecision(5)<<n<<endl;  fixed(cout);  //5 digits after floating point
   cout<<setprecision(6)<<n<<endl;
   cout<<defaultfloat<<setprecision(10)<<n<<endl<<endl; ; //cout.unsetf(ios::fixed);  //default format

   
   cout<<setw(15)<<n<<endl;  //set width of the line
   cout<<setfill('_');  //set white spaces of a line to '_'
   cout<<setw(15)<<n<<endl;
   cout<<setfill(' ');
   cout<<setw(15)<<n<<endl;
   cout<<left<<setw(15)<<n<<endl;   //left alligned
   cout<<right<<setw(15)<<n<<endl<<endl;  //right aligned(default)



   cout<<scientific<<n<<endl;  //prints in scientific format
   cout<<defaultfloat<<n<<endl;  //undo

}
