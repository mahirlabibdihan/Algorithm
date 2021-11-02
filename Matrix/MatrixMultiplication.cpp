#include <iostream>
#include <vector>
using namespace std;
// O(n^3)
#define N 100
/*void multiply(int a[][N],int rA, int cA,int b[][N],int rB,int cB,int c[][N])
{
    for (int i = 0; i < rA; i++)
    {
        for (int j = 0; j < cB; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < cA; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}*/


// Recursive Multiplication
vector<vector<int>> split(vector<vector<int>> a,int r,int c,int n)
{
    vector<vector<int>> b(n,vector<int>(n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[i][j]=a[i+r][j+c];
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
            a[i+r][j+c]=b[i][j];
        }
    }
}

// O(n^2)
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

vector<vector<int>> multiply(vector<vector<int>> a,vector<vector<int>> b,int n)
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

        int c11=a11*b11+a12*b21;
        int c12=a11*b12+a12*b22;
        int c21=a21*b11+a22*b21;
        int c22=a21*b12+a22*b22;

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
        vector<vector<int>> a12=split(a,0,n/2,n/2);
        vector<vector<int>> a21=split(a,n/2,0,n/2);
        vector<vector<int>> a22=split(a,n/2,n/2,n/2);

        vector<vector<int>> b11=split(b,0,0,n/2);
        vector<vector<int>> b12=split(b,0,n/2,n/2);
        vector<vector<int>> b21=split(b,n/2,0,n/2);
        vector<vector<int>> b22=split(b,n/2,n/2,n/2);

        // 8T(n/2)+4n^2
        // * -> 8
        // + -> 4
        vector<vector<int>> c11=add(multiply(a11,b11,n/2),multiply(a12,b21,n/2));
        vector<vector<int>> c12=add(multiply(a11,b12,n/2),multiply(a12,b22,n/2));
        vector<vector<int>> c21=add(multiply(a21,b11,n/2),multiply(a22,b21,n/2));
        vector<vector<int>> c22=add(multiply(a21,b12,n/2),multiply(a22,b22,n/2)); 

        vector<vector<int>> c(n,vector<int>(n));
        join(c,c11,0,0,n/2);
        join(c,c12,0,n/2,n/2);
        join(c,c21,n/2,0,n/2);
        join(c,c22,n/2,n/2,n/2);

        return c;
    }
}
int main()
{
    /*int a[N][N]=
    {
        {1,2,3},
        {3,4,5},
        {5,6,7}
    };
    int b[N][N]=
    {
        {4,5},
        {1,2},
        {3,4}
    };
    int c[N][N];
    multiply(a,3,3,b,3,2,c);*/


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

    vector<vector<int>> c=multiply(a,b,4);

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}