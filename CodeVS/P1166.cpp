#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	int Map[100][100];
	int dp[100][100];
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>Map[i][j];
	for(int i=1;i<=n;i++)
	{
		memset(dp,0,sizeof(dp));
		for(int j=m-2;j>=0;j--)
		{
			int tmp=m-(j+1);
			for(int k=1;k+j<=m;k++)
			{
				int Max=0;
				if(k>1 && dp[k-1][k+j]+(1 << tmp)*Map[i][k-1]>Max)
					Max=dp[k-1][k+j]+(1 << tmp)*Map[i][k-1];
				if(k+j<m && dp[k][k+j+1]+(1 << tmp)*Map[i][j+k+1]>Max)
					Max=dp[k][k+j+1]+(1 << tmp)*Map[i][j+k+1];
				dp[k][k+j]=Max;
			}
		}
		int Max=0;
		for(int j=1;j<=m;j++)
		{
			if((1 << m)*Map[i][j]+dp[j][j]>Max)
				Max=(1 << m)*Map[i][j]+dp[j][j];
		}
		ans+=Max;
	}
	cout<<ans<<endl;
	return 0;
}