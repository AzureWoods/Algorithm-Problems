#include <bits/stdc++.h>
using namespace std;
#define IFINITY 100000007
vector<int> city[200005];
int dist[200005];
void spfa()
{
	queue<int> Q;
	Q.push(1);
	while(!Q.empty())
	{
		int h=Q.front();
		Q.pop();
		for(int it=0; it<city[h].size(); it++)
		{
			int k=city[h][it];
			if(1+dist[h]<dist[k])
			{
				Q.push(k);
				dist[k]=dist[h]+1;
			}
		}
	}
}
int main()
{
	int n;
	int x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i==1)
			city[i].push_back(2);
		else if(i==n)
			city[i].push_back(n-1);
		else {
			city[i].push_back(i-1);
			city[i].push_back(i+1);
		}
		cin>>x;
		if(x!=i)
			city[i].push_back(x);
	}
	for(int i=2;i<=n;i++)
		dist[i]=IFINITY;
	dist[1]=0;
	spfa();	
	for(int i=1;i<=n;i++)
		cout<<dist[i]<<" ";
	return 0;
}
