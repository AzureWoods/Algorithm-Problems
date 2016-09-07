#include <bits/stdc++.h>
using namespace std;
class KeyBoard
{
public:
	int x;
	int y;
};
int main()
{
	KeyBoard keyBoard[11];
	int len=1;
	keyBoard[0].x=4;
	keyBoard[0].y=2;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		{
			keyBoard[len].x=i;
			keyBoard[len].y=j;
			len++;
		}
	int n;
	char seq[15];
	cin>>n>>seq;
	int flag=0;
	for(int i=0;i<=9;i++)
	{
		if(i == seq[0]-'0')
			continue;
		int cur=i;
		int j;
		for(j=1;j<n;j++)
		{
			int xa,ya;
			int next=-1;
			xa=keyBoard[cur].x+(keyBoard[seq[j]-'0'].x-keyBoard[seq[j-1]-'0'].x);
			ya=keyBoard[cur].y+(keyBoard[seq[j]-'0'].y-keyBoard[seq[j-1]-'0'].y);
			for(int k=0;k<=9;k++)
			{
				if(keyBoard[k].x==xa && keyBoard[k].y==ya)
					next=k;
			}
			if(next==-1)
				break;
			cur=next;
		}
		if(j==n)
		{
			flag=1;
			break;
		}
	}
	if(flag)
		cout<<"NO";
	else cout<<"YES";
	return 0;
}
