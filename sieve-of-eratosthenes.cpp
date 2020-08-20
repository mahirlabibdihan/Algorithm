#include<bits/stdc++.h>
using namespace std;

/*int main()
{
  int n,i,j;  cin>>n; int y[n+1]={};

  for(i=3;i<=n;i+=2)  y[i]=1; y[2]=1;

  for(i=3;i*i<=n;i+=2)  if(y[i]) for(j=i*i;j<=n;j+=2*i)  y[j]=0;

  for(i=0;i<n;i++) if(y[i]) cout<<i<<" ";
}*/
  bool x[1000000001]={};
//int main()
//{
//
//    int n,i,j;
//    cin>>n;
//    bitset<10000000>y;
//    for(i=2;i*i<=n;i++)if(!y[i])for(j=i*i;j<=n;j+=i)y[j]=1;
//
//    cout<<y.count()<<endl;
//    //for(i=2; i<n; i++) if(!y[i]) cout<<i<<" ";
//}

//int main()
//{ int n,i,j;  cin>>n;
//
//for(i=2;i*i<=n;i++) if(!(n%i)) break; if(i*i>n&n>1) cout<<"PRIME"; else cout<<"NOT PRIME";}



void siv()
{
    int i,j,c=n-1;
    for(i=2;i*i<MAX;i++)if(!x[i])for(j=i*i;j<=n;j+=i){if(!x[j]) c--; x[j]=1;}

    outn(c);
    for(i=2;i<MAX;i++)if(!x[i])cout<<i<<" ";
}

int main()
{
  siv();
}