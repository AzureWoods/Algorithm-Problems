#include <bits/stdc++.h>
using namespace std;
void Hanoi(int step, char A, char B, char C)
{
	if(step==1)
	{
		cout<<step<<" from "<<A<<" to "<<C<<endl;
		return ;
	}
	Hanoi(step-1, A, C, B);
	cout<<step<<" from "<<A<<" to "<<C<<endl;
	Hanoi(step-1, B, A, C);
}
int main()
{
	int n;
	cin>>n;
	int ans;
	ans=(1<<n) -1;
	cout<<ans<<endl;
	Hanoi(n,'A','B','C');
	return 0;
}
