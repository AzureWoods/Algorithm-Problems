#include <bits/stdc++.h>
using namespace std;
class Card
{
public:
	int value;
	int index;
};
Card C[105];
int comp(Card A, Card B)
{
	return A.value<B.value;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>C[i].value;
		C[i].index=i;
	}
	sort(C+1,C+n+1,comp);
	for(int i=1;i<=n/2;i++)
	{
		cout<<C[i].index<<' '<<C[n-i+1].index<<endl;
	}
	return 0;
}