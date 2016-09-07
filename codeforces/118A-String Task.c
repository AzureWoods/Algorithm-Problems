#include <stdio.h>
#include <string.h>
int main()
{
	char String[150];
	int i;
	scanf("%s",&String);
	for(i=0;i<strlen(String);i++)
	{
		if(String[i]<='Z' && String[i]>='A')
			String[i]+=32;
		if(String[i]=='a'|| String[i]=='e'|| String[i]=='i'|| String[i]=='o'|| String[i]=='u'|| String[i]=='y')
			continue;
		printf(".%c",String[i]);
	}
	return 0;
}