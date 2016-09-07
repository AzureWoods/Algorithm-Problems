#include <iostream>
using namespace std;
int main()
{
	int sum=0;
	int num[200]={0};
	int x;
	int max;
	int tmp;
	for(int i=0;i<5;i++)
	{
		cin>>x;
		num[x]++;
		sum+=x;
	}
	max=0;
	for(int i=1;i<=100;i++)
	{
		if(num[i]<=1)
			continue;
		else if(num[i]==2)
			tmp=2*i;
		else tmp=3*i;
		if(tmp>max)
			max=tmp;
	}
	sum-=max;
	cout<<sum;
	return 0;
}