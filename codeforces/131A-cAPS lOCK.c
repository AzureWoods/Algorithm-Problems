#include <stdio.h>
#include <string.h>
int main()
{
	char s[100];
	int i;
	int sum=0;
	scanf("%s",&s);
	for(i=1;i<strlen(s);i++)
	{
		if(s[i]<='Z' && s[i]>='A')
			sum++;
	}
	if(sum==strlen(s)-1)
	{
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]<='Z' && s[i]>='A')
				s[i]+=32;
			else s[i]-=32;
		}
		
	}
	printf("%s",s);
	return 0;
}