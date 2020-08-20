// C++ program to demonstrate working of 
// Variadic function Template 
#include <bits/stdc++.h> 
using namespace std; 
  
// To handle base case of below recursive 
// Variadic function Template 
void print() 
{ 
    cout <<endl; 
}
  
// Variadic function Template that takes  
// variable number of arguments and prints 
// all of them. 
template <typename T, typename... Types> 
void print(T var1, Types... var2) 
{ 
    cout << var1 << endl ; 
  
    print(var2...) ; 
} 

/*void print(int n, ... )
{
   va_list lst;
   va_start(lst,n);
   for(int i=0;i<n;i++)
   	cout<<va_arg(lst,int)<<" ";
   va_end(lst);
   cout<<endl;
}*/

// Driver code 
int main() 
{ 
    print(2,1,2.8);  
    return 0; 
} 