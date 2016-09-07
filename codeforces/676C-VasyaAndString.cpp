#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	int flag_a,flag_b;
	int sum_a,sum_b;
	char S[200000];
	cin>>n>>k;
	cin>>S;
	int l,r,mid;
	int max;
	l=1;
	r=n;
	while(l<=r)
	{
		mid=(l+r)/2;
		sum_a=0;
		sum_b=0;
		for(int i=0;i<mid;i++)
		{
			if(S[i]=='a')
				sum_a++;
			else sum_b++;
		}
		flag_a=0;
		flag_b=0;
		for(int i=mid;i<=n;i++)
		{
			if(sum_a+k>=mid)
			{
				flag_a=1;
				break;
			}
			if(S[i]=='a')sum_a++;
			if(S[i-mid]=='a')sum_a--;
		}
		for(int i=mid;i<=n;i++)
		{
			if(sum_b+k>=mid)
			{
				flag_b=1;
				break;
			}
			if(S[i]=='b')sum_b++;
			if(S[i-mid]=='b')sum_b--;
		}
		if(flag_a==0 && flag_b==0)
			r=mid-1;
		else {
			max=mid;
			l=mid+1;
		}
		mid=(l+r)/2;
	}
	cout<<max;
	return 0;
}