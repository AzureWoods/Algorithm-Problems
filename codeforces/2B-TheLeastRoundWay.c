#include <stdio.h>
#include <math.h>	
int map_2[1000][1000];
int map_5[1000][1000];
char trace_2[1000][1000];
char trace_5[1000][1000];
int main()
{
	int n,x,y;
	int i,j;
	int temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&x);
			if(x==0)
			{
				map_2[i][j]=map_5[i][j]=-1;
				continue;
			}
			temp=x;
			map_2[i][j]=map_5[i][j]=0;
			while(temp%2==0)
			{
				map_2[i][j]++;
				temp/=2;
			}
			temp=x;
			while(temp%5==0)
			{
				map_5[i][j]++;
				temp/=5;
			}
			
		}
	for(i=n-2;i>=0;i--)
	{
		map_2[n-1][i]=(map_2[n-1][i+1]==-1)?-1:map_2[n-1][i]+map_2[n-1][i+1];
		trace_2[n-1][i]='R';
		map_2[i][n-1]=(map_2[i+1][n-1]==-1)?-1:map_2[i][n-1]+map_2[i+1][n-1];
		trace_2[i][n-1]='D';
		map_5[n-1][i]=(map_5[n-1][i+1]==-1)?-1:map_5[n-1][i]+map_5[n-1][i+1];
		trace_5[n-1][i]='R';
		map_5[i][n-1]=(map_5[i+1][n-1]==-1)?-1:map_5[i][n-1]+map_5[i+1][n-1];
		trace_5[i][n-1]='D';
	}
	for(i=n-2;i>=0;i--)
		for(j=n-2;j>=0;j--)
		{
			if(map_2[i][j]==-1)
			{
				trace_2[i][j]='D';
				trace_5[i][j]='D';
				continue;
			}
			x=(map_2[i+1][j]==-1)?-1:map_2[i+1][j]+map_2[i][j];
			y=(map_2[i][j+1]==-1)?-1:map_2[i][j+1]+map_2[i][j];
			if(abs(x)<=abs(y))
			{
				map_2[i][j]=x;
				trace_2[i][j]='D';
			}
			else {
				map_2[i][j]=y;
				trace_2[i][j]='R';
			}
			x=(map_5[i+1][j]==-1)?-1:map_5[i+1][j]+map_5[i][j];
			y=(map_5[i][j+1]==-1)?-1:map_5[i][j+1]+map_5[i][j];
			if(abs(x)<=abs(y))
			{
				map_5[i][j]=x;
				trace_5[i][j]='D';
			}
			else {
				map_5[i][j]=y;
				trace_5[i][j]='R';
			}
		}
	if(abs(map_2[0][0])<abs(map_5[0][0]))
	{
		printf("%d\n",abs(map_2[0][0]));
		i=0;
		j=0;
		while(!(i==n-1 && j==n-1))
		{
			printf("%c",trace_2[i][j]);
			if(trace_2[i][j]=='D')
				i++;
			else j++;
		}
	}
	else {
		printf("%d\n",abs(map_5[0][0]));
		i=0;
		j=0;
		while(!(i==n-1 && j==n-1))
		{
			printf("%c",trace_5[i][j]);
			if(trace_5[i][j]=='D')
				i++;
			else j++;
		}
	}
	return 0;
}
