#include <iostream>
#include <vector>
using namespace std;

// Strassen's Matrix multiplication can be performed only on square matrices where n is a power of 2. 
// Order of both of the matrices are n × n.

vector<vector<int>> split(vector<vector<int>> a,int r,int c,int n)
{
    vector<vector<int>> b(n,vector<int>(n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[i][j]=a[i+r*n][j+c*n];
        }
    }

    return b;
}

void join(vector<vector<int>> &a,vector<vector<int>> b,int r,int c,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i+r*n][j+c*n]=b[i][j];
        }
    }
}

vector<vector<int>> add(vector<vector<int>> a,vector<vector<int>> b)
{
    int n=a.size();

    vector<vector<int>> c(n,vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}

vector<vector<int>> sub(vector<vector<int>> a,vector<vector<int>> b)
{
    int n=a.size();

    vector<vector<int>> c(n,vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    return c;
}

vector<vector<int>> mul(vector<vector<int>> a,vector<vector<int>> b,int n)
{
    if(n==1)
    {
        int a11=a[0][0];

        int b11=b[0][0];

        int c11=a11*b11;

        vector<vector<int>> c(n,vector<int>(n));
        c[0][0]=c11;

        return c;
    }
    else if(n==2)
    {
        int a11=a[0][0];
        int a12=a[0][1];
        int a21=a[1][0];
        int a22=a[1][1];

        int b11=b[0][0];
        int b12=b[0][1];
        int b21=b[1][0];
        int b22=b[1][1];

        int p=(a11+a22)*(b11+b22);
        int q=(a21+a22)*b11;
        int r=a11*(b12-b22);
        int s=a22*(b21-b11);
        int t=(a11+a12)*b22;
        int u=(a21-a11)*(b11+b12);
        int v=(a12-a22)*(b21+b22);

        int c11=p+s-t+v;
        int c12=r+t;
        int c21=q+s;
        int c22=p+r-q+u;

        /*
        int c11=a11*b11+a12*b21;
        int c12=a11*b12+a12*b22;
        int c21=a21*b11+a22*b21;
        int c22=a21*b12+a22*b22;
        */

        vector<vector<int>> c(n,vector<int>(n));
        c[0][0]=c11;
        c[0][1]=c12;
        c[1][0]=c21;
        c[1][1]=c22;

        return c;
    }
    else
    {
        vector<vector<int>> a11=split(a,0,0,n/2);
        vector<vector<int>> a12=split(a,0,1,n/2);
        vector<vector<int>> a21=split(a,1,0,n/2);
        vector<vector<int>> a22=split(a,1,1,n/2);

        vector<vector<int>> b11=split(b,0,0,n/2);
        vector<vector<int>> b12=split(b,0,1,n/2);
        vector<vector<int>> b21=split(b,1,0,n/2);
        vector<vector<int>> b22=split(b,1,1,n/2);

        // O(n^2.81)
        // * -> 7
        // + -> 12
        // - -> 6
        vector<vector<int>> p=mul(add(a11,a22),add(b11,b22),n/2);
        vector<vector<int>> q=mul(add(a21,a22),b11,n/2);
        vector<vector<int>> r=mul(a11,sub(b12,b22),n/2);
        vector<vector<int>> s=mul(a22,sub(b21,b11),n/2);
        vector<vector<int>> t=mul(add(a11,a12),b22,n/2);
        vector<vector<int>> u=mul(sub(a21,a11),add(b11,b12),n/2);
        vector<vector<int>> v=mul(sub(a12,a22),add(b21,b22),n/2);

        vector<vector<int>> c11=add(sub(add(p,s),t),v);
        vector<vector<int>> c12=add(r,t);
        vector<vector<int>> c21=add(q,s);
        vector<vector<int>> c22=add(sub(add(p,r),q),u); 

        // O(n^3)
        // * -> 8
        // + -> 4
        /*
        vector<vector<int>> c11=add(mul(a11,b11,n/2),mul(a12,b21,n/2));
        vector<vector<int>> c12=add(mul(a11,b12,n/2),mul(a12,b22,n/2));
        vector<vector<int>> c21=add(mul(a21,b11,n/2),mul(a22,b21,n/2));
        vector<vector<int>> c22=add(mul(a21,b12,n/2),mul(a22,b22,n/2)); 
        */

        vector<vector<int>> c(n,vector<int>(n));
        join(c,c11,0,0,n/2);
        join(c,c12,0,1,n/2);
        join(c,c21,1,0,n/2);
        join(c,c22,1,1,n/2);

        return c;
    }
}
int main()
{
    vector<vector<int>> a={
        {1,2,3,4},
        {3,4,5,6},
        {5,6,7,8},
        {6,7,8,9}
    };

    vector<vector<int>> b={
        {1,2,3,4},
        {3,4,5,6},
        {5,6,7,8},
        {6,7,8,9}
    };

    vector<vector<int>> c=mul(a,b,4);

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}