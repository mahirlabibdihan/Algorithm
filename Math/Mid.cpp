#include <iostream>
using namespace std;
long long midPoint(long long a, long long b)
{
    // Same sign -> a + b will cause overflow -> Mid = a + (b - a) / 2;
    // Positive and Positive
    // Negative and Negative
    if (a >= 0 && b >= 0)
    {
        return a + (b - a) / 2;
    }
    if (a < 0 && b < 0)
    {
        return a + (b - a) / 2;
    }
    // Different sign -> b - a will cause overflow -> Mid = (a + b)/2
    // Positive and Negative
    // Negative and Positive
    if (a >= 0 && b < 0)
    {
        return (a + b) / 2;
    }
    if (a < 0 && b >= 0)
    {
        return (a + b) / 2;
    }
}
int main()
{
    long long a, b;
    cin >> a >> b;
    cout << midPoint(a, b) << endl;
}