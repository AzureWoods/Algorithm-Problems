#include <stdio.h>
int main()
{
	int Able[14]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
	int n;
	int i;
	int flag=0;
	scanf("%d",&n);
	for(i=0;i<14;i++)
	{
		if(n%Able[i]==0)
		{
			flag=1;
			break;
		}
	}
	if(flag)
		printf("YES");
	else printf("NO");
	return 0;
}