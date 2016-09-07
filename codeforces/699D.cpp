#include <bits/stdc++.h>
using namespace std;
int h[200005];
bool T[200005];
int fa[200005]={0};
int find(int x)
{
	if(fa[x]==0)
		return x;
	else {
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
void join(int x,int y)
{
	int fx,fy;
	fx=find(x);
	fy=find(y);
	fa[fx]=fy;
}
int main()
{
	int n;
	int count=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
		if(find(i) != find(h[i]))
			join(i,h[i]);
	}
	memset(T,false,sizeof(T));
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		if(h[i]==i)
		{
			cur=i;
			break;
		}
	}
	if(!cur)
	{
		cur=1;
		while(!T[cur])
		{
			T[cur]=true;
			cur=h[cur];
		}
		count++;
		h[cur]=cur;
	}
	else {
		T[cur]=true;
	}
	for(int i=2;i<=n;i++)
	{
		if(T[i] || find(i)==find(cur))
			continue;
		else {
			int tmp=i;
			while(!T[tmp])
			{
				T[tmp]=true;
				tmp=h[tmp];
			}
			h[tmp]=cur;
			count++;
			join(cur, tmp);
		}
	}
	cout<<count<<endl;
	for(int i=1;i<=n;i++)
		cout<<h[i]<<' ';
	return 0;
}