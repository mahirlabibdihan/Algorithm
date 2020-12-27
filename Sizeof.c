int main()
{
	int a[10];
	printf("%d\n",((int)(&a+1)-(int)(&a))/((int)(a+1)-(int)(a)));

	// int *b=malloc(4*10);
	// printf("%d\n",((int)(&b+1)-(int)(&b))/((int)(b+1)-(int)(b)));

	int b=10;
	printf("%d %d\n",sizeof b,sizeof(b));
	printf("%d %d\n",sizeof 10,sizeof(10));
	printf("%d\n",sizeof(int));
}