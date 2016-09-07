#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m;
	long long sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		sum=sum+(i+m)/5-i/5;
	}
	cout<<sum;
	return 0;
}
