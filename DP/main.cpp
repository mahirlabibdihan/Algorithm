#include <iostream>

using namespace std;
#include "Fibonacci.hpp"
int dp[100000]; // This should be initialized with -1 in the main function
int main()
{
    cout << fib(10) << endl;
}