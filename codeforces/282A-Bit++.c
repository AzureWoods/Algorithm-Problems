#include <stdio.h>
int main()
{
	int n;
	char op[4];
	int i;
	int x=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",&op);
		if(op[0]=='+' || op[1]=='+' || op[2]=='+')
			x++;
		else if(op[0]=='-' || op[1]=='-' || op[2]=='-')
			x--;
	}
	printf("%d",x);
	return 0;
}