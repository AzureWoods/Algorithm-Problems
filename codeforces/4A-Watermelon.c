#include <stdio.h>
int main()
{
	int weight;
	scanf("%d",&weight);
	if(weight%2==1 || weight==2)
		printf("NO");
	else printf("YES");
}