// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Tree Structure
struct Node
{
    char data;
    struct Node *left, *right;
};

// Function to create new Node
Node* newNode(char c)
{
    Node* n = new Node;
    n->data = c;
    n->left = n->right = nullptr;
    return n;
}

void operate(stack<Node*> &stN, stack<char> &stC)
{
    Node *t, *t1, *t2;
    // Get and remove the top element
    // from the character stack
    t = newNode(stC.top());
    stC.pop();

    // Get and remove the top element
    // from the Node stack
    t1 = stN.top();
    stN.pop();

    // Get and remove the currently top
    // element from the Node stack
    t2 = stN.top();
    stN.pop();

    // Update the tree
    t->left = t2;
    t->right = t1;

    // Push the Node to the Node stack
    stN.push(t);
}
// Function to build Expression Tree
Node* build(string& s)
{

    // Stack to hold nodes
    stack<Node*> stN;

    // Stack to hold chars
    stack<char> stC;
    

    // Prioritising the operators
    int p[123] = { 0 };
    p['+'] = p['-'] = 1;
    p['/'] = p['*'] = 2;
    p['^'] = 3;
    p[')'] = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') {

            // Push '(' in char stack
            stC.push(s[i]);
        }

        // Push the operands in Node stack
        else if (isalpha(s[i]))
        {
            stN.push(newNode(s[i]));
        }

        else if (p[s[i]] > 0)
        {
            // If an operator with lower or
            // same associativity appears
            // while ( !stC.empty() && stC.top() != '(' && ((s[i] != '^' && p[stC.top()] >= p[s[i]]) || (s[i] == '^' && p[stC.top()] > p[s[i]])))
            while ( !stC.empty() && stC.top() != '(' && p[stC.top()] >= p[s[i]] )
            {
                operate(stN,stC);
            }

            // Push s[i] to char stack
            stC.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!stC.empty() && stC.top() != '(')
            {
                operate(stN,stC);
            }
            stC.pop();
        }
    }
    return stN.top();
}

// Function to print the post order
// traversal of the tree
void postorder(Node* root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
}

void preorder(Node* root)
{
    if (root)
    {
        cout << root->data;
        preorder(root->left);
        preorder(root->right);  
    }
}

void inorder(Node* root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}

// Driver code
int main()
{
    string s = "(a*b+c/d)";
    // cin >> s;
    s = "(" + s;
    s += ")";
    Node* root = build(s);

    // Function call
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);


    return 0;
}
