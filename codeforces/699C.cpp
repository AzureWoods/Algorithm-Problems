#include <bits/stdc++.h>
using namespace std;
int k[105][3];
bool f[105][3];
int a[105];
int Min(int x,int c)
{
	if(c==0)
	{
		int minn=k[x][0];
		for(int i=1;i<3;i++)
		{
			if(f[x][i]==true && k[x][i]<minn)
				minn=k[x][i];
		}
		return minn;
	}
	else {
		int minn=k[x][0];
		if(f[x][c]==true && k[x][c]<minn)
			minn=k[x][c];
		return minn;
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	switch(a[0])
	{
		case 0:
			k[0][0]=1;k[0][1]=0;k[0][2]=0;
			f[0][0]=true;f[0][1]=false;f[0][2]=false;
			break;
		case 1:
			k[0][0]=1;k[0][1]=0;k[0][2]=0;
			f[0][0]=true;f[0][1]=true;f[0][2]=false;
			break;
		case 2:
			k[0][0]=1;k[0][1]=0;k[0][2]=0;
			f[0][0]=true;f[0][1]=false;f[0][2]=true;
			break;
		case 3:
			k[0][0]=1;k[0][1]=0;k[0][2]=0;
			f[0][0]=true;f[0][1]=true;f[0][2]=true;
	}
	for(int i=1;i<n;i++)
	{
		switch(a[i])
		{
			case 0:
				k[i][0]=1+Min(i-1,0);
				k[i][1]=0;k[i][2]=0;
				f[i][0]=true;f[i][1]=false;f[i][2]=false;
				break;
			case 1:
				k[i][0]=1+Min(i-1,0);
				k[i][1]=Min(i-1,2);
				k[i][2]=0;
				f[i][0]=true;f[i][1]=true;f[i][2]=false;
				break;
			case 2:
				k[i][0]=1+Min(i-1,0);
				k[i][1]=0;
				k[i][2]=Min(i-1,1);
				f[i][0]=true;f[i][1]=false;f[i][2]=true;
				break;
			case 3:
				k[i][0]=1+Min(i-1,0);
				k[i][1]=Min(i-1,2);
				k[i][2]=Min(i-1,1);
				f[i][0]=true;f[i][1]=true;f[i][2]=true;
		}
	}
	int minn;
	minn=k[n-1][0];
	for(int i=1;i<3;i++)
	{
		if(f[n-1][i]==true && k[n-1][i]<minn)
			minn=k[n-1][i];
	}
	cout<<minn;
	return 0;
}