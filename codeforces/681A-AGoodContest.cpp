#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int flag=0;
	char handle[15];
	int after;
	int before;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>handle>>before>>after;
		if(before>=2400 && after>before)
		{
			flag=1;
		}
	}
	if(flag)
		cout<<"YES";
	else cout<<"NO";
	return 0;
}
