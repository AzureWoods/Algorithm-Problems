#include <bits/stdc++.h>
using namespace std;
int Price[100005]={0};
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int P;
		scanf("%d",&P);
		Price[P]++;
	}
	for(int i=1;i<=100000;i++)
		Price[i]+=Price[i-1];
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int Coins;
		scanf("%d",&Coins);
		if(Coins>=100000)
			printf("%d\n",n);
		else printf("%d\n",Price[Coins]);
	}
	return 0;
}