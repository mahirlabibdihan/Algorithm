int x[100001];
vector<ll> sum;
void prefix_sum()
{
	sum.p_b(x[0]);

	_for(i,1,n)
	{
		sum.p_b(sum.back()+x[i]);
	}   
}

void prefix_sum()
{
	_for(i,1,n) x[i]+=x[i-1];   
} 
