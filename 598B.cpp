#include<stdio.h>

class Char{
	char c;
public:
	void swap(Char *a)
	{
		char temp = this->c;
		this->c = a->c;
		a->c = temp;
	}
};

class String
{
	Char s[10001];
public:
	void in(int width=10000)
	{
		scanf("\n%10000[^\n]", s), scanf("%*[^\n]"), getchar();
	}
	void rightRotate(int l, int r, int k)
	{
		int n = r - l + 1, i;
		k %= n;		// To avoid extra rotation

		for (i = r - 1; i > l - 1; i--)
		{
			if (i - k >= l - 1)
			{
				s[i].swap(&s[i - k]);
			}
			else
			{
				if (n % k == 0) break;
				k -= n % k;
				i++;
				n = i - l + 1;
			}
		}
	}
	void out(char end='\n')
	{
		printf("%s%c",s,end);
	}
};


int main()
{
	String s;
	s.in();	// String Input

	int m;
	scanf("%d", &m);

	while (m--)
	{
		int k , l, r;
		scanf("%d %d %d", &l, &r, &k);
		s.rightRotate(l, r, k);
	}
	s.out();
}