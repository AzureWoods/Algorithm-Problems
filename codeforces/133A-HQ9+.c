#include <stdio.h>
#include <string.h>
int main()
{
	char s[100];
	int i;
	int flag;
	scanf("%s",&s);
	flag=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='H' || s[i]=='Q' || s[i]=='9')
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