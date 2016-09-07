#include <iostream>
using namespace std;
int main()
{
	int d,sumTime;
	int minTime[50],maxTime[50];
	int sumOfMin=0,sumOfMax=0;
	int bk;
	cin>>d>>sumTime;
	for(int i=0;i<d;i++)
	{
		cin>>minTime[i]>>maxTime[i];
		sumOfMin+=minTime[i];
		sumOfMax+=maxTime[i];
	}
	if(sumTime<sumOfMin || sumTime>sumOfMax)
		cout<<"NO";
	else {
		cout<<"YES"<<endl;
		sumTime-=sumOfMin;
		for(int i=0;i<d;i++)
		{
			if(maxTime[i]-minTime[i]<sumTime)
			{
				cout<<maxTime[i]<<" ";
				sumTime=sumTime-(maxTime[i]-minTime[i]);
			}
			else {
				bk=i+1;
				cout<<minTime[i]+sumTime<<" ";
				break;
			}
		}
		for(int i=bk;i<d;i++)
			cout<<minTime[i]<<" ";
	}
	return 0;
}
