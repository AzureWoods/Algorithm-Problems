#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int main()
{
	double a,b;
	int n;
	double x,y,v;
	double Min;
	Min=INF;
	cin>>a>>b;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y>>v;
		double tmp;
		tmp=sqrt((x-a)*(x-a)+(y-b)*(y-b))/v;
		if(tmp<Min)
			Min=tmp;
	}
	printf("%.20lf",Min);
	return 0;
}