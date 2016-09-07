#include <iostream>
#include <cstring>
using namespace std;
int A[100005],dp[100005],D[100005];
int main()
{
	int T;
	cin>>T;
	for(int x=0;x<T;x++)
	{
		int n;
		cin>>n;
		memset(A,0,sizeof(A));
		memset(dp,0,sizeof(dp));
		memset(D,0,sizeof(D));
		for(int i=0;i<n;i++)
			cin>>A[i];
		dp[0]=1;
		D[0]=1;
		D[1]=A[0];
		for(int i=1;i<n;i++)
		{
			int l,r;
			int ans=0;
			l=1;r=D[0];
			while(l<=r)
			{
				int mid;
				mid=(l+r) >> 1;
				if(A[i]>D[mid])
				{
					ans=mid;
					l=mid+1;
				}
				else r=mid-1;
			}
			dp[i]=ans+1;
			if(A[i]<D[ans+1] || D[ans+1]==0)
			{
				if(D[ans+1]==0)
					D[0]++;
				D[ans+1]=A[i];
			}
		}
		for(int i=0;i<n-1;i++)
			cout<<dp[i]<<' ';
		cout<<dp[n-1];
		cout<<endl;
	}
	return 0;
}