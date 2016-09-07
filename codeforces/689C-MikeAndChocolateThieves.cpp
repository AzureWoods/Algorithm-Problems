#include <bits/stdc++.h>
using namespace std;
#define IFINITY 10000000000000000
typedef long long ll;
int main()
{
	ll m;
	ll min=IFINITY;
	cin>>m;
	ll l,r;
	l=8;
	r=m*8;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		ll sum=0;
		for(ll i=2;i*i*i<=mid;i++)
		{
			sum=sum+mid/(i*i*i);
		}
		if(sum>=m)
		{
			if(sum==m && mid<min)
				min=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	if(min!=IFINITY)
		cout<<min;
	else cout<<"-1";
	return 0;
}