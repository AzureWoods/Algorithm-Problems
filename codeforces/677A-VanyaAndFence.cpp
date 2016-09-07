#include <iostream>
using namespace std;
int main()
{
	int n,h;
	int person;
	int i;
	int width;
	cin>>n;
	cin>>h;
	width=0;
	for(i=0;i<n;i++)
	{
		cin>>person;
		if(person>h)
			width+=2;
		else width+=1;
	}
	cout<<width;
	return 0;
}
