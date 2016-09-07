#include <iostream>
using namespace std;
int min(int a,int b)
{
	if(a<b)
		return a;
	else return b;
}
int main()
{
	int T;
	cin>>T;
	for(int x=0;x<T;x++)
	{
		int n,m;
		cin>>n>>m;
		int tmp;
		for(int i=0;;i++)
		{
			tmp = 1 << i;
			if(tmp>n)
			{
				tmp = i;
				break;
			}
		}
		tmp = min(tmp-1, m);
		int sum=0;
		for(int i=tmp; i>=0 ;i--)
		{
			int k;
			k = 1 << i;
			if(n/k==0)
				continue;
			else {
				sum = sum+n/k;
				n%=k;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}