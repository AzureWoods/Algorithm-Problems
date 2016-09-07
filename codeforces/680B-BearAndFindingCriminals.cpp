#include <iostream>
using namespace std;
int main()
{
	int n,a;
	int city[200];
	int sum=0;
	cin>>n>>a;
	for(int i=1;i<=n;i++)
		cin>>city[i];
 	if(city[a])
 		sum++;
 	int i,j;
 	i=a-1;
 	j=a+1;
 	while(i>=1 && j<=n)
 	{
 		if(city[i] && city[j])
 			sum+=2;
 		i--;
 		j++;
 	}
 	if(i>=1)
 	{
 		while(i>=1)
 		{
 			if(city[i])
 				sum++;
 			i--;
 		}
 	}
 	else if(j<=n)
 	{
 		while(j<=n)
 		{
 			if(city[j])
 				sum++;
 			j++;
 		}
 	}
 	cout<<sum;
 	return 0;
}