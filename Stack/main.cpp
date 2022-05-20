#include <iostream>
#include <stack>
using namespace std;
void Recursion(int n)
{
    cout << n << " ";
    Recursion(n + 1);
}
int DEQUEUE(stack<int> &s)
{
    int tmp1 = s.top();
    s.pop();
    if (s.empty())
    {
        return tmp1;
    }
    int tmp2 = DEQUEUE(s);
    s.push(tmp1);
    return tmp2;
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(2);
    cout << DEQUEUE(s) << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
// 64888