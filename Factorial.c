
int Recursive_Factorial(int n)
{
  if(!n) return 1;
  return n*fact(n-1);

  // return n?b*fact(n-1):1;
}

int Factorial(int n)
{
    int i,fact=1;

    for(i=2;i<=n;i++)
    {
       fact*=i;
    }

    // for(i=2;i<=n;fact*=i++);
    return fact;
}



int x[1<<31];
void fact()
{
  x[0]=x[1]=1;

	for(i=2;i<MAX;i++)
		x[i]=x[i-1]*i;
}



void multiply(int *x,int a)
{
    int c=0,b;

    f(j,0,sz(x))
    {
        b=x[j]*a+c;
        x[j]=b%10;
        c=b/10;
    }

    while(c)
    {
    	x.pb(c%10);
    	c/=10;
    }
}
void fact(int n)
{
   int x;
   x.pb(1);

   f(i,2,n+1) multiply(x,i);

   rf(i,x.sz-1,-1) x[i];
}

int main()
{

}