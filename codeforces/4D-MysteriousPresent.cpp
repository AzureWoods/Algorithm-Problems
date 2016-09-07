#include <iostream>
#include <algorithm>
using namespace std;
class Envelope
{
public:
	int width;
	int height;
	int index;
};
bool cmp(const Envelope &a,const Envelope &b)
{
	if(a.width==b.width)
		return a.height<b.height;
	else return a.width<b.width;
}
int main()
{
	int n;
	int w,h;
	int max;
	int index;
	int len;
	Envelope EnvSize[10000];
	int dp[10000];
	int res[10000];
	int stack[10000];
	int head;
	cin>>n>>w>>h;
	EnvSize[0].width=w;
	EnvSize[0].height=h;
	len=0;
	for(int i=1;i<=n;i++)
	{
		cin>>w>>h;
		if(w>EnvSize[0].width && h>EnvSize[0].height)
		{
			EnvSize[++len].width=w;
			EnvSize[len].height=h;
			EnvSize[len].index=i;
		}
	}
	sort(EnvSize,EnvSize+len+1,cmp);
	dp[0]=1;
	res[0]=-1;
	for(int i=1;i<=len;i++)
	{
		max=-1;
		for(int j=0;j<i;j++)
		{
			if(EnvSize[j].height<EnvSize[i].height && EnvSize[j].width<EnvSize[i].width && dp[j]>max)
			{
				max=dp[j];
				index=j;
			}
		}
		if(max==-1)
		{
			dp[i]=1;
			res[i]=-1;	
		}
		else {
			dp[i]=max+1;
			res[i]=index;
		}
	}
	head=-1;
	max=0;
	for(int i=1;i<=len;i++)
		if(dp[i]>dp[max])
			max=i;
	cout<<dp[max]-1<<endl;
	for(int i=max;res[i]!=-1;i=res[i])
	{
		stack[++head]=EnvSize[i].index;
	}
	while(head>=0)
	{
		cout<<stack[head]<<" ";
		head--;
	}
	return 0;
}