#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int k;
	int level;
	cin>>n;
	k=sqrt(n);
	for(int i=k;;i++)
	{
		if(i*(i+1)/2>=n)
		{
			n=n-i*(i-1)/2;
			level=i+1;
			break;
		}
	}
	if(level & 1)
		cout<<n<<'/'<<level-n;
	else cout<<level-n<<'/'<<n;
	return 0;
}