// CPP Program to convert given
// decimal number into decimal
// equivalent of its gray code form
#include <bits/stdc++.h>
using namespace std;

int grayCode(int n)
{
	/* Right Shift the number by 1
	taking xor with original number */
	return n ^ (n >> 1);
}

// Driver Code
int main()
{
	int n = 10;
	cout << grayCode(n) << endl;
	return 0;
}
