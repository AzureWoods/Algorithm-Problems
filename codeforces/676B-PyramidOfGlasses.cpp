#include <bits/stdc++.h>
using namespace std;
double pyramid[20][20];
int main()
{
	int n,Time;
	int Total;
	int sum=0;
	double tmp;
	cin>>n>>Time;
	Total=n*(n+1)/2;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			pyramid[i][j]=0;
	for(int i=0;i<Time;i++)
	{
		if(sum==Total)
			break;
		pyramid[1][1]+=1;
		for(int j=1;j<=n;j++)
			for(int k=1;k<=j;k++)
			{
				if(pyramid[j][k]<=1)
					continue;
				tmp=(pyramid[j][k]-1)/2;
				pyramid[j][k]=1;
				pyramid[j+1][k]+=tmp;
				pyramid[j+1][k+1]+=tmp;
			}
		sum=0;
		for(int j=1;j<=n;j++)
			for(int k=1;k<=j;k++)
			{
				if(pyramid[j][k]==1)
					sum++;
			}
			
	}
	cout<<sum;
	return 0;
}
