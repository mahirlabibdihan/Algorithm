int decbin(int n) 
{ 
    if(n) return n%2+10*decbin(n/2);
}

int main()
{
	printf("%d",decbin(5));
}