#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
vector<vector<ull>> pascal(ull n)
{
   vector<vector<ull>> x(n+1);
   for(int i=0;i<=n;i++)
   {
      for(int j=0;j<=i;j++)
      {
         x[i].push_back((j==0)?1:(j<i)?x[i-1][j]+x[i-1][j-1]:1);
      }
   }
   return x;
}

ull ncr(ull n,ull r)
{
   ull s=1,i; 
   if(r>n-r)r=n-r;
   for(i=1;i<r+1;i++)
      s=(s*(n-r+i))/i; 
    return s;
}

vector<ull> npascal(ull n)
{
   vector<ull> y;
   for(int i=0;i<(n/2)+1;i++)
   {
       y.push_back(ncr(n,i));
   }
   
   for(int i=ceil(n/2.0)-1;i>-1;i++)
   {
       y.push_back(y[i]);
   }
   return y;
}


int main()
{
   ull n; cin>>n;
   for(ull i=0;i<=n;i++)
   {
     for(ull j=0;j<=2*n;j++)
     {
        if(j<n-i|j>n+i) cout<<' ';
        else
        {
          if(((n%2)+(i%2)+(j%2))%2==0)
             cout<<ncr(i,(j-n+i)/2);
          else cout<<' ';
        }   
     }
     cout<<endl;
   }
}

