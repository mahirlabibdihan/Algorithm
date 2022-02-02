#ifndef __FIBONACCI__
#define __FIBONACCI__
// Traditional recursive function to find N-th fibonacci number
// 1
/*
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
*/
// Time complexity: O(2^n)
// But it has redundancy
/*
                                f(5)
                f(4)              +             f(3)
        f(3)     +      f(2)             f(2)     +      f(1)
    f(2) + f(1)     f(1) + f(0)      f(1) + f(0)
 f(1)+f(0)
So, here we are calling f(3),f(2) multiple times. If we stores the value of every previous recursive call the tree will look like.
                        f(5)
               f(4)      +      f(3)
        f(3)    +   f(2)                
    f(2) + f(1)                        
 f(1)+f(0)
So, in this optimized tree we will have at most 2 same recursive calls. So, for Nth-fibonacci number the tree will contain at most 2n node.
Time complexity: O(n)
*/
// 2
/*
int fib(int n, int *dp)
{
    if (dp[n] == -1)
    {
        if (n <= 1)
        {
            dp[n] = n;
        }
        else
        {
            dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
        }
    }
    return dp[n];
}
*/
// We can implement this without recursive function. Space optimized
// 3
/*
int fib(int n)
{
    int dp[n + 1];
    for (i = 0; i <= n; i++)
    {
        if (i < 2)
        {
            dp[i] = i;
        }
        else
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }
    return dp[n];
}
*/
// 4
// We can find nth fibonacci number without using an array. Space optimized
int fib(int n)
{
    int last = 0, current = 1;
    if (n == 0)
    {
        return last;
    }
    for (int i = 2; i <= n; i++)
    {
        int temp = current;
        current += last;
        last = temp;
    }
    return current;
}

// Extraa
// If we want to store all fibonacci numbers from 1 to n for future use
void storefib(int n, int *dp)
{
    for (int i = 0; i <= n; i++)
    {
        if (i < 2)
        {
            dp[i] = i;
        }
        else
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }
}
#endif