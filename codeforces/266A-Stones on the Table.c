#include <stdio.h>
int main()
{
	int i,n;
	int sum=0;
	char s[55];
	scanf("%d",&n);
	scanf("%s",&s);
	i=0;
	s[n]='E';
	while(i<n)
	{
		while(s[i]==s[i+1])i++;
		sum++;
		i++;
	}
	printf("%d",n-sum);
	return 0;
}