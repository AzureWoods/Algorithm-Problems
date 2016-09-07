#include <bits/stdc++.h>
#define INF 1000000001
using namespace std;
int pos[200005];
int main()
{
	int N;
	string dir;
	cin>>N;
	cin>>dir;
	for(int i=0;i<N;i++)
	{
		cin>>pos[i];
	}
	int min=INF;
	for(int i=0;i<N-1;i++)
	{
		if(dir[i]=='R' && dir[i+1]=='L' && pos[i+1]-pos[i]<min)
			min=pos[i+1]-pos[i];
	}
	if(min==INF)
		cout<<-1;
	else 
		cout<<min/2;
	return 0;
}