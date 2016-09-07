#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int num1[110];
	int num2[110];
	int dp1[110][110],dp2[110][110];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num1[i];
		num2[n-i-1]=num1[i];
	}
	memset(dp1,0,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int Max1=0;
			int Max2=0;
			for(int k=j;k!=(j+i)%n;k=(k+1)%n)
			{
				if(dp1[j][k]+dp1[(k+1)%n][(j+i)%n]+num1[j]*num1[(k+1)%n]*num1[(i+j+1)%n]>Max1)
					Max1=dp1[j][k]+dp1[(k+1)%n][(j+i)%n]+num1[j]*num1[(k+1)%n]*num1[(i+j+1)%n];
				if(dp2[j][k]+dp2[(k+1)%n][(j+i)%n]+num2[j]*num2[(k+1)%n]*num2[(i+j+1)%n]>Max2)
					Max2=dp2[j][k]+dp2[(k+1)%n][(j+i)%n]+num2[j]*num2[(k+1)%n]*num2[(i+j+1)%n];
			}
			dp1[j][(i+j)%n]=Max1;
			dp2[j][(i+j)%n]=Max2;
		}
	}
	int ans1=0,ans2=0;
	for(int i=0;i<n;i++)
	{
		if(dp1[i][(i+n-1)%n]>ans1)
			ans1=dp1[i][(i+n-1)%n];
		if(dp2[i][(i+n-1)%n]>ans2)
			ans2=dp2[i][(i+n-1)%n];
	}
	ans1=(ans1>ans2)?ans1:ans2;
	cout<<ans1;
	return 0;
}