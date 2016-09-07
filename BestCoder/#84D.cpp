#include <iostream>
#include <cstring>
using namespace std;
bool check[40001];
int Prime[20001];
int mark[40001];
int len=0;
void setPrime()
{
	memset(check,true,sizeof(check));
	for(int i=2;i<=40000;i++)
	{
		if(!check[i])
			continue;
		for(int j=i*2;j<=40000;j+=i)
			check[j]=false;
	}
	mark[0]=0;
	mark[1]=0;
	for(int i=2;i<=40000;i++)
	{
		if(check[i])
		{
			mark[i]=mark[i-1]+1;
			Prime[++len]=i;
		}
		else mark[i]=mark[i-1];
	}
}
int main()
{
	setPrime();
	int T;
	cin>>T;
	for(int x=0;x<T;x++)
	{
		int n,d;
		cin>>n>>d;
		int tmp;
		tmp=(n-1)/d;
		for(int i=1;i<=len && Prime[i]<tmp;i++)
		{
			if(d%Prime[i]==0)
			{
				tmp=Prime[i];
				break;
			}
		}
		cout<<mark[tmp]<<endl;
	}
	return 0;
}