#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,d;
	string ch;
	int count=0;
	int max=-1;
	cin>>n>>d;
	for(int i=0;i<d;i++)
	{
		cin>>ch;
		int temp=0;
		for(int j=0;j<n;j++)
		{
			if(ch[j]=='1')
				temp++;
		}
		if(temp<n)
			count++;
		else {
			if(count>max)
				max=count;
			count=0;
		}
	}
	if(count>max)
		max=count;
	cout<<max;
	return 0;
}
