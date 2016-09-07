#include <stdio.h>
#include <string.h>
int main()
{
	char str1[150];
	char str2[150];
	int i;
	scanf("%s%s",&str1,&str2);
	for(i=0;i<strlen(str1);i++)
	{
		if(str1[i]<='Z' && str1[i]>='A')
			str1[i]+=32;
		if(str2[i]<='Z' && str2[i]<='Z')
			str2[i]+=32;
	}
	printf("%d",strcmp(str1,str2));
	return 0;
}