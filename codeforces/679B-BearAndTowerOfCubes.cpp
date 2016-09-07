#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll,ll> res;
ll cubeV(ll a)
{
	return a*a*a;
}
void dfs(ll m,ll step,ll sum)
{
	ll maxSide;
	ll maxCube;
	if(m==0)
	{
		res=max(res,make_pair(step,sum));
		return ;
	}
	maxSide=1;
	while(cubeV(maxSide+1)<=m)maxSide++;
	maxCube=cubeV(maxSide);
	dfs(m-maxCube,step+1,sum+maxCube);
	if(maxSide>1)
		dfs(cubeV(maxSide)-1-cubeV(maxSide-1),step+1,sum+cubeV(maxSide-1));
}
int main()
{
	ll m;
	cin>>m;
	dfs(m,0,0);
	cout<<res.first<<" "<<res.second;
	return 0;
}