#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll quickPow(ll a,ll b)
{
	ll res;
	if(b==0)
		return 1;
	ll tmp = quickPow(a,b/2);
	if(b%2==0)
		res=(tmp*tmp)%MOD;
	else res=(((a*tmp)%MOD)*tmp)%MOD;
	return res;
}
int main()
{
	ll a,b,n,x;
	ll sum=0;
	ll p=1000000005;
	ll tmp;
	cin>>a>>b>>n>>x;
	if(n==0)
		sum=x;
	else {
		sum=(quickPow(a,n)*x)%MOD;
		if(a>1)
		{
			tmp=(b*(quickPow(a,n)-1))%MOD;
			tmp=(tmp*quickPow(a-1,p))%MOD;
		}
		else {
			tmp=(b*(n%MOD))%MOD;
		} 
		sum=(sum+tmp)%MOD;
	}
	cout<<sum;
	return 0;
}
