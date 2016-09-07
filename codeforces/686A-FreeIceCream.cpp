#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long num;
	long long sum=0;
	long long n;
	long long x;
	char op;
	cin>>n>>num;
	for(int i = 0; i<n ;i++)
	{
		cin>>op>>x;
		if(op == '+')
			num+=x;
		else 
		{
			if(x>num)
				sum++;
			else num-=x;
		}
	}
	cout<<num<<" "<<sum;
	return 0;
}