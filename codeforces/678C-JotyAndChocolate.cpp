#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	else gcd(b,a%b);
}
int main()
{
	ll n,a,b,p,q;
	ll num_a,num_b,num_ab;
	ll sum;
	cin>>n>>a>>b>>p>>q;
	num_a=n/a;
	num_b=n/b;
	num_ab=n/(a*b/gcd(a,b));
	if(p>q)
	{
		sum=p*num_a+q*(num_b-num_ab);
	}
	else {
		sum=p*(num_a-num_ab)+q*num_b;
	}
	cout<<sum;
	return 0;
}
