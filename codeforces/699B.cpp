#include <bits/stdc++.h>
using namespace std;
char Map[1005][1005];
int row[1005],col[1005];
int main()
{
	int total=0;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>Map[i];
		for(int j=0;j<m;j++)
		{
			if(Map[i][j]=='*')
				total++;
		}
	}
	for(int i=0;i<n;i++)
	{
		int tmp=0;
		for(int j=0;j<m;j++)
		{
			if(Map[i][j]=='*')
				tmp++;
		}
		row[i]=tmp;
	}
	for(int i=0;i<m;i++)
	{
		int tmp=0;
		for(int j=0;j<n;j++)
		{
			if(Map[j][i]=='*')
				tmp++;
		}
		col[i]=tmp;
	}
	int flag=0;
	int x,y;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int tmp=row[i]+col[j];
			if(Map[i][j]=='*')
				tmp--;
			if(tmp==total)
			{
				flag=1;
				x=i+1;
				y=j+1;
				break;
			}
		}
		if(flag)
			break;
	}
	if(flag)
		cout<<"YES"<<endl<<x<<' '<<y;
	else cout<<"NO";
}