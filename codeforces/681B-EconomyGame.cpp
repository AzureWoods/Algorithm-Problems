#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int flag=0;
	cin>>n;
	for(int i=0;i*1234567<=n;i++)
	{
		for(int j=0;j*123456<=n-i*1234567;j++)
		{
			if((n-i*1234567-j*123456)%1234==0)
			{
				flag=1;
				break;
			}
		}
		if(flag)
			break;
	}
	if(flag)
		cout<<"YES";
	else cout<<"NO";
	return 0;
}
