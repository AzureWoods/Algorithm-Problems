#include <iostream>
using namespace std;
int main()
{
	int n,h,k;
	int height[100005];
	long long totTime=0;
	int curHeight=0;
	int useTime;
	cin>>n>>h>>k;
	for(int i=0;i<n;i++)
		cin>>height[i];
	int i=0;
	while(true)
	{
		while(curHeight+height[i]<=h && i<n)
		{
			curHeight+=height[i];
			i++;
		}
		if(i==n)
		{
			totTime=totTime+(curHeight-1)/k+1;
			break;
		}
		else {
			useTime=(height[i]-(h-curHeight)-1)/k+1;
			totTime=totTime+useTime;
			curHeight=((curHeight-useTime*k)>=0)?curHeight-useTime*k:0;
		}
	}
	cout<<totTime;
	return 0;
}