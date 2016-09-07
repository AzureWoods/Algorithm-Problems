#include <bits/stdc++.h>
using namespace std;
int mark[200];
int main()
{
	string s;
	int n;
	int tot=0;
	int Min;
	cin>>n>>s;
	memset(mark,0,sizeof(mark));
	for(int i=0;i<n;i++)
	{
		if(!mark[s[i]])
			tot++;
		mark[s[i]]++;
	}
	memset(mark,0,sizeof(mark));
	int head,tail;
	int sum=1;
	Min=n+1;
	head=tail=0;
	mark[s[0]]=1;
	while(true)
	{
		if(sum==tot)
		{
			if(head-tail+1<Min)
				Min=head-tail+1;
			// memset(mark,0,sizeof(mark));
			// head++;
			// tail=head;
			// mark[s[head]]=1;
			// sum=1;
		}
		if(head>=n)
			break;
		if(!mark[s[++head]])
			sum++;
		mark[s[head]]++;
		while(mark[s[tail]]>1 && tail<head)
			mark[s[tail++]]--;
	}
	cout<<Min;
	return 0;
}
