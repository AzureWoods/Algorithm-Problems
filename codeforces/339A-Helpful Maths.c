#include <stdio.h>
#include <string.h>
int main()
{
	char s[150];
	int num[4]={0};
	int i;
	scanf("%s",&s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='+')
			continue;
		num[s[i]-'0']++;
	}
	i=0;
	while(num[i]==0)i++;
	printf("%d",i);
	num[i]--;
	while(num[i]==0)i++;
	while(i<=3)
	{
		printf("+%d",i);
		num[i]--;
		while(num[i]==0)i++;
	}
	return 0;
}