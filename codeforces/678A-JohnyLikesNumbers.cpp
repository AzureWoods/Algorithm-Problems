#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	int Div;
	cin>>n>>k;
	Div=n/k;
	Div=(Div+1)*k;
	cout<<Div;
	return 0;
}