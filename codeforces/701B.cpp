#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	bool row[100005],col[100005];
	ll R,C;
	ll n,m;
	ll tot;
	memset(row,false,sizeof(row));
	memset(col,false,sizeof(col));
	R=C=0;
	cin>>n>>m;
	tot=n*n;
	for(int i=0;i<m;i++)
	{
		int r,c;
		cin>>r>>c;
		if(!row[r])
		{
			R++;
			row[r]=true;
		}
		if(!col[c])
		{
			C++;
			col[c]=true;
		}
		ll ans;
		ans = tot-(R*n+C*n-R*C);
		cout<<ans<<' ';
	}
	return 0;
}