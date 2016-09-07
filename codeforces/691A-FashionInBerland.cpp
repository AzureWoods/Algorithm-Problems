#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n == 1)
	{
		int x;
		cin>>x;
		if(x)
			cout<<"YES";
		else cout<<"NO";
		return 0;
	}
	int count=0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(!x)
		{
			count++;
		}
	}
	if(count == 1)
		cout<<"YES";
	else cout<<"NO";
	return 0;
}