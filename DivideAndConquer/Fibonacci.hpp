#ifndef __FIBONACCI__
#define __FIBONACCI__
// O(2^n)
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
#endif