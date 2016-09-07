#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string S[100005];
string rev_S[100005];
ll Cost[100005];
ll dp[100005][2];
int main()
{
	int n;
	int flag=1;
	ll INF=1;
	cin>>n;
	for(int i=0;i<16;i++)
		INF*=10;
	for(int i=0;i<n;i++)
		cin>>Cost[i];
	for(int i=0;i<n;i++)
	{
		cin>>S[i];
		rev_S[i].assign(S[i].rbegin(),S[i].rend());
	}

	// cout<<endl;
	// for(int i=0;i<n;i++)
	// 	cout<<rev_S[i]<<endl;
	// cout<<endl;
	
	dp[0][0]=0;
	dp[0][1]=Cost[0];
	for(int i=1;i<n;i++)
	{
		int count1=0;
		ll Min=INF;
		if(S[i].compare(S[i-1])<0 || dp[i-1][0]==-1)
			count1++;
		else{
			if(dp[i-1][0]<Min)
				Min=dp[i-1][0];
		}
		if(S[i].compare(rev_S[i-1])<0 || dp[i-1][1]==-1)
			count1++;
		else{
			if(dp[i-1][1]<Min)
				Min=dp[i-1][1];
		}
		if(count1==2)
			dp[i][0]=-1;
		else dp[i][0]=Min;
		int count2=0;
		Min=INF;
		if(rev_S[i].compare(S[i-1])<0 || dp[i-1][0]==-1)
			count2++;
		else{
			if(dp[i-1][0]<Min)
				Min=dp[i-1][0];
		}
		if(rev_S[i].compare(rev_S[i-1])<0 || dp[i-1][1]==-1)
			count2++;
		else{
			if(dp[i-1][1]<Min)
				Min=dp[i-1][1];
		}
		if(count2==2)
			dp[i][1]=-1;
		else dp[i][1]=Min+Cost[i];
		if(count1+count2==4)
		{
			flag=0;
			break;
		}
	}
	if(!flag)
		cout<<-1;
	else {
		ll ans;
		if(dp[n-1][0]==-1)
			ans=dp[n-1][1];
		else if(dp[n-1][1]==-1)
			ans=dp[n-1][0];
		else ans=(dp[n-1][0]<dp[n-1][1])?dp[n-1][0]:dp[n-1][1];
		cout<<ans;
	}
	return 0;
}
