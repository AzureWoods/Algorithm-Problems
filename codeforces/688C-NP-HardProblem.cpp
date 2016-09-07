#include <bits/stdc++.h>
#define NOT_USED -1
using namespace std;
vector <int> edge[100005];
vector <int> Set[2];
int used[100005];
int dfs(int node, int color)
{
	used[node]=color;
	Set[color].push_back(node);
	for(int temp=0; temp<edge[node].size(); temp++)
	{
		int i=edge[node][temp];
		if(used[i]==1-color)
			continue;
		if(used[i]==color)
			return 0;
		else {
			int flag=dfs(i,1-color);
			if(!flag)
				return 0;
		}
	}
	return 1;
}
int main()
{
	int n,m;
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		used[i]=NOT_USED;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(used[i]==NOT_USED && !edge[i].empty())
		{
			int flag=dfs(i,0);
			if(!flag)
			{
				cout<<"-1";
				return 0;
			}
		}
	}
	for(int i=0;i<2;i++)
	{
		cout<<Set[i].size()<<endl;
		for(int temp=0; temp<Set[i].size(); temp++)
		{
			int j=Set[i][temp];
			cout<<j<<" ";
	}
		cout<<endl;
	}
	return 0;
}
