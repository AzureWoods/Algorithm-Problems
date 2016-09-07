#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,s,x;
	cin>>t>>s>>x; 
	if((t==x || (x-t)%s==0 || ((x-t-1)%s==0 && x!=t+1)) && x>=t)
		cout<<"YES";
	else cout<<"NO";
	return 0;
}
