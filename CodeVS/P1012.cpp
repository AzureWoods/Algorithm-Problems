#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x,y;
	int k;
	int sum=0;
	cin>>x>>y;
	k=y/x;
	for(int i=2;i<=1000;i++)
	{
		if(k%i!=0)
			continue;
		sum++;
		while(k%i==0)
			k/=i;
	}
	if(!k)
		sum++;
	int ans=1<<sum;
	cout<<ans<<endl;
	return 0;
}