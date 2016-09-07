#include <stdio.h>
int main()
{
	int n;
	int i,j;
	int max;
	int temp;
	int num[100];
	int sum;
	int tot;
	scanf("%d",&n);
	tot=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		tot+=num[i];
	}
	for(i=0;i<n-1;i++)
	{
		max=i;
		for(j=i+1;j<n;j++)
		{
			if(num[j]>num[max])
				max=j;
		}
		temp=num[i];
		num[i]=num[max];
		num[max]=temp;
	}
	sum=0;
	for(i=0;i<n;i++)
	{
		sum+=num[i];
		if(sum>tot/2)
			break;
	}
	printf("%d",i+1);
	return 0;
}