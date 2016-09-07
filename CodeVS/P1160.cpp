#include <bits/stdc++.h>
using namespace std;
int pattern[105][105];
int main()
{
	int n;
	int sum=1;
	cin>>n;
	pattern[(n+1)/2][(n+1)/2]=1;
	int x,y;
	int count=2;
	int it;
	x=(n+1)/2;
	y=(n+1)/2+1;
	it=2;
	while(it<n)
	{
		for(int i=0;i<it;i++)
		{
			sum = (x==y || x+y==n+1)?sum+count:sum;
			pattern[x--][y]=count++;
		}
		x++;y--;
		for(int i=0;i<it;i++)
		{
			sum = (x==y || x+y==n+1)?sum+count:sum;
			pattern[x][y--]=count++;
		}
		y++;x++;
		for(int i=0;i<it;i++)
		{
			sum = (x==y || x+y==n+1)?sum+count:sum;
			pattern[x++][y]=count++;
		}
		x--;y++;
		for(int i=0;i<it;i++)
		{
			sum = (x==y || x+y==n+1)?sum+count:sum;
			pattern[x][y++]=count++;
		}
		it+=2;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<pattern[i][j]<<' ';
		cout<<endl;
	}
	cout<<sum;
	return 0;
}
