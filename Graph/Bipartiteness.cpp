#include<iostream>
#include <vector>
#include<map>

using namespace std;
map<int,int> color;
map<int,bool> visited;
map<int,vector<int>> adj;

void isBipartite(int i)
{
	visited[i]=true;
	for(int a:adj[i])
	{
		if(!visited[a])
		{
			if(color[i]==1)
			{
				color[a]=2;
				c2++;
			}
			else
			{
				color[a]=1;
				c1++;
			}
			coloring(a);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	color[1]=1;
	c1++;
	isBipartite(1);
	cout<<result<<endl;
}