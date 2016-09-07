#include <bits/stdc++.h>
using namespace std;
int dp[15][1005];
int main()
{
	int n;
	int sum=1;
	cin>>n;
	memset(dp,0,sizeof(dp));
	dp[1][n]=1;
	for(int i=2;n >> (i-1)>0;i++)
	{
		int tmp=n >> (i-1);
		for(int j=1;j<=tmp;j++)
		{
			int tmp1=n >> (i-2);
			for(int k=j*2;k<=tmp1;k++)
				dp[i][j]+=dp[i-1][k];
			sum+=dp[i][j];
		}
	}
	cout<<sum;
	return 0;
}
