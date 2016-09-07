#include <stdio.h>
int main()
{
	int n,k;
	int num[100];
	int i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",&num[i]);
	i=1;
	while(num[i]>=num[k] && num[i]>0 && i<=n)
		i++;
	printf("%d",i-1);
	return 0;
}