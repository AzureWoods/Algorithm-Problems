#include <bits/stdc++.h>
using namespace std;
int main()
{
	int y;
	int sum=0;
	int i;
	int flag;
	int tmp;
	cin>>y;
	if(y%400==0 || (y%4==0 && y%100!=0))
		flag=1;
	else 
		flag=0;
	for(i=y;;i++)
	{
		if(i%400==0 || (i%4==0 && i%100!=0))
			sum+=366;
		else sum+=365;
		if((i+1)%400==0 || ((i+1)%4==0 && (i+1)%100!=0))
			tmp=1;
		else tmp=0;
		sum%=7;
		if(sum==0 && flag==tmp)
			break;
	}
	i++;
	cout<<i;
	return 0;
}
