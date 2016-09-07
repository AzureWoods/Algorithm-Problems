#include <stdio.h>
int main()
{
	int n;
	int ai,bi;
	int max;
	int sum;
	int i;
	scanf("%d",&n);
	max=-1;
	sum=0;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&ai,&bi);
		sum-=ai;
		sum+=bi;
		if(sum>max)
			max=sum;
	}
	printf("%d",max);
	return 0;
}