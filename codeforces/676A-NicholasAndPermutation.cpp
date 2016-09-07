#include <iostream>
using namespace std;
int main()
{
	int n;
	int Array[500];
	int pos_1,pos_n;
	int k1,k2;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>Array[i];
		if(Array[i]==1)
			pos_1=i;
		if(Array[i]==n)
			pos_n=i;
	}
	if(pos_1==1 || pos_n==n)
		cout<<n-1;
	else {
		k1=((pos_1-1)>(n-pos_1))?pos_1-1:n-pos_1;
		k2=((pos_n-1)>(n-pos_n))?pos_n-1:n-pos_n;
		k1=(k1>k2)?k1:k2;
		cout<<k1;
	}
	return 0;
}
