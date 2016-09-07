#include <bits/stdc++.h>
using namespace std;
int main()
{
	int array[100005];
	int n;
	int mex=1;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>array[i];
	sort(array,array+n);
	for(int i=0;i<n;i++)
	{
		if(array[i]>=mex)
		{
			mex++;
			continue;
		}
	}
	mex;
	cout<<mex;
	return 0;
}
