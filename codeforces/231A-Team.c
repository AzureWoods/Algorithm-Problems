#include <stdio.h>
int main()
{
	int N;
	int sum=0;
	int i,j;
	int x;
	int count;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		count=0;
		for(j=0;j<3;j++)
		{
			scanf("%d",&x);
			if(x)
				count++;
		}
		if(count>=2)
			sum++;
	}
	printf("%d",sum);
	return 0;
}