#include <bits/stdc++.h>
using namespace std;
int n,m;
int digit_h,digit_m;
int sum=0;
int num[10]={0};
int main()
{ 
	digit_h=digit_m=0;
	cin>>n>>m;
	int nTmp=n-1;
	int mTmp=m-1;
	do{
		digit_h++;
		nTmp/=7;
	}while(nTmp>0);
	do{
		digit_m++;
		mTmp/=7;
	}while(mTmp>0);
	if(digit_m+digit_h>7)
	{
		cout<<"0";
	}
	else {
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				for(int a=i,k=0;k<digit_h;k++,a/=7)
					num[a%7]++;
				for(int b=j,k=0;k<digit_m;k++,b/=7)
					num[b%7]++;
				int flag=1;
				for(int k=0;k<7;k++)
				{
					if(num[k]>1)
					{
						flag=0;
						break;
					}
				}
				if(flag)
					sum++;
				for(int k=0;k<7;k++)
					num[k]=0; 
			}
			cout<<sum;
	}
	return 0;
}
