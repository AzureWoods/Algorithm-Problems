#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> M;
ll getFather(ll x, ll y)
{
	int a[100],b[100];
	int len1=-1,len2=-1;
	ll f=0;
	while(x)
	{
		a[++len1]= x & 1;
		x = x >> 1;
	}
	while(y)
	{
		b[++len2]= y & 1;
		y = y >> 1;
	}
	while(len1>=0 && len2>=0 && a[len1]==b[len2])
	{
		f = f*2+a[len1];
		len1--;len2--;
	}
	return f;
}
void solve1()
{
	ll x,y,v;
	ll f;
	cin>>x>>y>>v;
	f = getFather(x, y);
	while(x!=f)
	{
		if(M[x])
			M[x]+=v;
		else M[x]=v;
		x = x >> 1;
	}
	while(y!=f)
	{
		if(M[y])
			M[y]+=v;
		else M[y]=v;
		y = y >> 1;
	}
}
void solve2()
{
	ll x,y;
	ll sum=0;
	ll f;
	cin>>x>>y;
	f=getFather(x,y);
	while(x!=f)
	{
		if(M[x])
			sum+=M[x];
		x = x >> 1;
	}
	while(y!=f)
	{
		if(M[y])
			sum+=M[y];
		y = y >> 1;
	}
	cout<<sum<<endl;
}
int main()
{
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int Case;
		cin>>Case;
		if(Case==1)
			solve1();
		else solve2();
	}
	return 0;
}
