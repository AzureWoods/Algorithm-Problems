#include <bits/stdc++.h>
using namespace std;	
int a[200];
void swap(int x,int y)
{
	int temp;
	temp=a[x];
	a[x]=a[y];
	a[y]=temp;
}
int main()
{
	int n;
	int min;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=n; i++)
	{
		min = i;
		for(int j=i; j<=n; j++)
		{
			if(a[j] < a[min])
				min = j;
		}
		if(min == i)
			continue;
		else {
			for(int j=min; j>i; j--)
			{
				cout<<j-1<<" "<<j<<endl;
				swap(j-1,j);
			}
		}
	}
	return 0;
}
