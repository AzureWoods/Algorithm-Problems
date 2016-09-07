#include <bits/stdc++.h>
using namespace std;
int main()
{
	char a;
	char ch;
	char d[200];
	int b;
	memset(d,0,sizeof(d));
	cin>>a>>ch;
	if(a=='0' && ch=='e')
	{
		cin>>b;
		cout<<'0';
		return 0;
	}
	if(ch=='e')
	{
		cin>>b;
		cout<<a;
		for(int i=0;i<b;i++)
			cout<<'0';
	}
	else {
		int len=0;
		cin>>ch;
		while(ch!='e')
		{
			d[++len]=ch;
			cin>>ch;
		}
		cin>>b;
		if(a!='0' || b==0)
			cout<<a;
		if(len>b)
		{
			for(int i=1;i<=b;i++)
				cout<<d[i];
			int j=len;
			while(d[j]=='0')j--;
			if(j>b)
			{
				cout<<'.';
				for(int i=b+1;i<=j;i++)
					cout<<d[i];
			}
		}
		else {
			for(int i=1;i<=len;i++)
				cout<<d[i];
			for(int i=len+1;i<=b;i++)
				cout<<'0';
		}
	}
	return 0;
}
