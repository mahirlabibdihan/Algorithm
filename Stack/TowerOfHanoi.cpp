#include <iostream>
#include <stack>
using namespace std;
void ToH(int n, char start, char tmp, char goal)
{
    if (n == 0)
    {
        return;
    }
    ToH(n - 1, start, goal, tmp);
    cout << "Disk " << n << " is moved from " << start << " to " << goal << endl;
    ToH(n - 1, tmp, start, goal);
}

void ToH_stack(int n, char start, char tmp, char goal)
{
    enum TOHop
    {
        DOMOVE,
        DOTOH
    };
    class TOHobj
    { // An operation object
    public:
        TOHop op;              // This operation type
        int num;               // How many disks
        char start, goal, tmp; // Define pole order
        // DOTOH operation constructor
        TOHobj(int n, char s, char g, char t)
        {
            op = DOTOH;
            num = n;
            start = s;
            goal = g;
            tmp = t;
        }
        // DOMOVE operation constructor
        TOHobj(int n, char s, char g)
        {
            op = DOMOVE;
            num = n;
            start = s;
            goal = g;
        }
    };
    stack<TOHobj *> S; // Allocates memory in stack
    // stack<TOHobj *> *S = new stack<TOHobj *>(); // Allocates memory in heap

    S.push(new TOHobj(n, start, goal, tmp)); // Initial
    TOHobj *t;
    while (S.size() > 0)
    { // Grab next task
        t = S.top();
        S.pop();
        if (t->op == DOMOVE) // Do a move
        {
            cout << "Disk " << t->num << " is moved from " << t->start << " to " << t->goal << endl;
        }
        else if (t->num > 0)
        {
            // Store (in reverse) 3 recursive statements
            int num = t->num;
            char tmp = t->tmp;
            char goal = t->goal;
            char start = t->start;
            // Operations must be push in the reverse order from the actual recursion.
            S.push(new TOHobj(num - 1, tmp, goal, start));
            S.push(new TOHobj(num, start, goal));
            S.push(new TOHobj(num - 1, start, tmp, goal));
        }
        delete t; // Must delete the TOHobj we made
    }
}
int main()
{
    ToH_stack(2, 'A', 'B', 'C');
}